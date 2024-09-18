function getDiff(s1, s2) {
    let i = 0;
    const min = Math.min(s1.length, s2.length)
    while (i < min) {
        if (s1[i] !== s2[i])
            return i;
        i++;
    }
    return min
}

module.exports = getDiff