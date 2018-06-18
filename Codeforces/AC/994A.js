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
    // console.log(input)
    a = input[1].split(' ')
    b = input[2].split(' ')
    // console.log(a, b)
    for(let i in a) {
        if(b.includes(a[i])) {
            process.stdout.write(a[i] + ' ')
        }
    }
    process.stdout.write('\n')
})

