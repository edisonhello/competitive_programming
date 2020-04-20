#include <bits/stdc++.h>
using namespace std;

char Ask(int pos) {
	cout << pos << endl;
	fflush(stdout);
	char c; 
	cin >> c;
	// cerr << "Ask " << pos << " Get " << c << endl;
	return c;
}

void Complement(string &s, string &t) {
	for (char &c : s) c = c == '0' ? '1' : '0';
	for (char &c : t) c = c == '0' ? '1' : '0';
}

void Reverse(string &s, string &t) {
	swap(s, t);
}

int main() {
	int t, b; cin >> t >> b;
	while (t--) {
		string fr, ed;
		int qn = 0;
		while ((int)(fr.size() + ed.size()) < b) {
			if (qn % 10 == 0) {
				// cerr << "Check quantum" << endl;

				for (int i = 0; i < (int)fr.size(); ++i) {
					if (fr[i] == ed[i]) {
						char f = Ask(i + 1); ++qn;
						// char e = Ask(b - i); ++qn;
						if (f != fr[i]) Complement(fr, ed);
						break;
					}
				}
				for (int i = 0; i < (int)fr.size(); ++i) {
					if (fr[i] != ed[i]) {
						char f = Ask(i + 1); ++qn;
						// char e = Ask(b - i); ++qn;
						if (f != fr[i]) Reverse(fr, ed);
						break;
					}
				}
			}

			if (qn % 10 == 9) {
				Ask(1); ++qn;
				continue;
			} else {
				fr += Ask(fr.size() + 1); ++qn;
				ed += Ask(b - fr.size() + 1); ++qn;
			}
		}

		// cerr << "Finish" << endl;

		reverse(ed.begin(), ed.end());
		cout << fr << ed << endl; fflush(stdout);
		char c; cin >> c;
		if (c == 'N') exit(0);
	}
}
