
const readline = require('readline');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');
const { isLibbsdInstalled, printInstallationInstructions, ensureTrailingSlash } = require('./check_libsd');
const { getParams } = require("./get_args")
const { update_git } = require("./update")
const { draw_done, draw_intro } = require('./ascii_drawing')
const { checkFiles } = require("./check_files")
const os = require('os');
const { tests_cases } = require('./data');
const getDiff = require('./get_duff')
const isRepoUpToDate = require('./check_is_up_to_date')
const {checkFilesByPath} = require('./check_by_path')
//working directory
const currentDirectory = process.cwd();


let failed = false;
const args = getParams();
const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color
const cyan = '\x1b[36m';

// check params
if (!args.l)
{
    console.log(` ERROR
        Missing arguments : -l
        try : testpf -l <your_library(s)_name>
        Example : testpf -l libprintf.a libft.a
        try : -h for help.
        `)
    process.exit(1);
}
let libraries = '';
args.l.forEach(lib => {
    libraries += ` ${currentDirectory}/${lib} `
})

const librarisDir = args.l.map(lib => ` ${currentDirectory}/${lib} `)


const parentPath = path.dirname(__dirname);
const command = `gcc ${parentPath}/tests/ft_printf.c ${libraries}    -o launch.out`
const command2 = `gcc ${parentPath}/tests/printf.c -o launch.out`

async function begin() {
    console.log("checking for update ...");
    const k = await isRepoUpToDate();
    console.log("Runnig...");
    const c1 = await start(command);
    const c2 = await start(command2);
    c1.forEach((res, index) => {
        if (res !== c2[index]) {
            const diffIndex = getDiff(res, c2[index])
            console.log(red, `Test ${index+1} Failed`)
            console.log(reset,`\r   test case : ${blue}ft_printf(${tests_cases[index]})`,reset);
            console.log(`   got       : ${red}"${res}"`,reset);
            diiff ='                ';
            for(i = 0;i<diffIndex;i++)
                diiff+=' ';
            diiff += '^'
            console.log(diiff)
            console.log(`   Expected  : ${green}"${c2[index]}"`)
        } else
            console.log(green, `Test ${index + 1} Passed!`, reset)
    })
}


checkFilesByPath(args.l).then((er) => {
    if(er)   {
        console.log("ERROR SOME FILES ARE MISSING");
        process.exit(1);
    }
    begin()
})
async function start(command) {
    return new Promise((resolve, reject) => {
        exec(command, (error, stdout, stderr) => {
            if (error) {
                console.log("⚠️ Compilation error occurred:");
                if (error.message.includes("undefined reference to")) {
                    const regex = /undefined reference to [`'"]([^`'"]+)['"]/g;
                    let match;
                    const missingFunctions = [];
                    while ((match = regex.exec(stderr)) !== null) {
                        missingFunctions.push(match[1]);
                    }
                    let missingFnames = '';
                    function removeDuplicates(arr) {
                        return arr.filter((item,
                            index) => arr.indexOf(item) === index);
                    }
                    if (missingFunctions) {
                        const missingFunctionsWithoutDuplicate = removeDuplicates(missingFunctions)
                        missingFunctionsWithoutDuplicate.forEach(fn => {
                            missingFnames += fn + ' '
                        })
                    }
                    console.log("Error: Undefined references to the following functions:");
                    console.log(red, missingFnames, reset)
                    console.log("Please include these functions in your C files.");
                } else
                    console.error(`Error executing command: ${error.message}`);
                return;
            }

            if (stderr) {
                console.log("⚠️ An error occurred:");
                console.error(`Command stderr: ${stderr}`);
                return;
            }
            let cmd = './testLaunch.out '
            runTests("").then(r => {
                resolve(r)
            });
        });
    })
}

async function launch(command, fname) {
    return new Promise((resolve, reject) => {
        exec(command, { timeout: 2500 }, (error, stdout, stderr) => {
            if (error && error.signal === 'SIGTERM') {
                console.log(yellow, "\r🕒  Time out... The function took too long to execute.");
                console.log(`${red}\r⚠️ ${fname} : Test failed${reset}`);
                failed = true;
                resolve(true);
                return;
            }
            if (error) {
                failed = true;
                console.log(error.message)
                console.log(`${red}\r⚠️ ${fname} Test failed${reset}`);
                reject(error);
                return;
            }

            if (stderr) {
                failed = true;
                console.log("⚠️ Test failed");
                console.error(`Command stderr: ${stderr}`);
                reject(new Error(stderr));  // Reject the promise on stderr
                return;
            }

            const output = stdout;
            const bd = output.split("##end")
            resolve(bd);  // Resolve the promise on success
        });
    });
}

async function runTests(fname) {
    if (fname !== 'all' || !fname) {
        try {
            const k = await launch(`./launch.out`, fname)
            return k
        } catch (error) {
        }
    }
}
