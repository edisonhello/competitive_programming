#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, T = 0; cin >> t; while (t--) {
		string s; cin >> s;
		string ans;
		int nd = 0;
		for (char c : s) {
			int d = c - '0';
			while (nd < d) {
				ans += "(";
				++nd;
			}
			while (nd > d) {
				ans += ")";
				--nd;
			}
			ans += c;
		}
		while (nd > 0) {
			--nd;
			ans += ")";
		}
		cout << "Case #" << (++T) << ": ";
		cout << ans << '\n';
	}
}
