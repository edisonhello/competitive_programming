input = []
process.stdin.setEncoding('ascii');
process.stdin.on('data', z => {
    inp = z.split('\n').slice(0, -1)
    for(let i in inp) {
        if(inp[i].slice(-1) == '\r') {
            inp[i] = inp[i].slice(0, -1)
        }
        input.push(inp[i])
    }
})

process.stdin.on('end', z => {
})

