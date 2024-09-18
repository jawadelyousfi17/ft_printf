const { exec } = require('child_process');

 module.exports = async function isRepoUpToDate() {
    return new Promise((resolve, reject) => {
        // Fetch latest changes from the remote
        exec('git fetch', (fetchError) => {
            if (fetchError) {
                console.error('Error fetching from remote:', fetchError);
                reject(fetchError)
            }

            // Check the status to see if we're behind or ahead of the remote branch
            exec('git status -uno', (statusError, stdout) => {
                if (statusError) {
                    console.error('Error checking git status:', statusError);
                    reject(statusError)
                }
                // Parse the output of 'git status'
                if (stdout.includes('Your branch is up to date')) {
                    console.log('Your repository is up to date.');
                } else if (stdout.includes('Your branch is behind')) {
                    console.log('Your repository is behind the remote. Consider pulling.');
                } else if (stdout.includes('Your branch is ahead')) {
                    console.log('Your repository is ahead of the remote. Consider pushing.');
                } else {
                    console.log('Your repository status is unclear. Check manually.');
                }
                resolve(true);
            });
        });
    })

}

