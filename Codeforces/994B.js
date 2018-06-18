input = []
process.stdin.setEncoding('ascii');
process.stdin.on('data', z => {
    inp = z.split('\n')
    for(let i in inp) {
        if(inp[i].slice(-1) == '\r') {
            inp[i] = inp[i].slice(0, -1)
        }
        input.push(inp[i])
    }
})

process.stdin.on('end', z => {
    console.log(input[0].slice(' '))
    let [n, m] = input[0].slice(' ').map(val => parseInt(val))
    console.log(n, m)
})

