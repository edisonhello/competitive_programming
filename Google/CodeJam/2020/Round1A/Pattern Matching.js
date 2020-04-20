
const readline = require('readline')

let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false
})

let lines = []
rl.on('line', l => lines.push(l))
rl.on('close', () => Main(lines))

function Main(ip) {
	function GetLine() {
		return ip.splice(0, 1).toString()
	}

	let t = parseInt(GetLine())
	for (let T = 1; T <= t; T++) {
		let n = parseInt(GetLine())
		let s = []
		for (let i = 0; i < n; i++) s.push(GetLine())

		function Answer(s) {
			console.log(`Case #${T}: ${s}`)
		}

		function ExistEmpty() {
			return s.some(t => t.length === 0)
		}

		function AllEmpty() {
			return s.every(t => t.length === 0)
		}

		(() => {
			let head = '', tail = ''
			while (true) {
				if (ExistEmpty()) 
					return Answer(AllEmpty() ? head : '*')

				let same = '*'
				for (let i in s) {
					let t = s[i]
					if (t[0] == '*') continue
					if (t[0] != same && same != '*') same = '-'
					else same = t[0]
					s[i] = t.substr(1)
				}

				if (same == '-') return Answer('*')
				if (same == '*') break

				head += same
			}

			while (true) {
				if (ExistEmpty()) 
					return Answer(AllEmpty() ? head : '*')

				let same = '*'
				for (let i in s) {
					let t = s[i]
					if (t[t.length - 1] == '*') continue
					if (t[t.length - 1] != same && same != '*') same = '-'
					else same = t[t.length - 1]
					s[i] = t.substr(0, t.length - 1)
				}

				if (same == '-') return Answer('*')
				if (same == '*') break

				tail = same + tail
			}

			let all = ''
			for (let t of s) {
				for (let c of t) if (c != '*')
					all += c
			}

			Answer(head + all + tail)
		}) ()
	}

}
