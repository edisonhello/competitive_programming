#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int od = 0, ev = 0;
		while (n--) {
			int t; cin >> t;
			if (t & 1) ++od;
			else ++ev;
		}
		if ((od & 1) || (od && ev)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
// fkfekkko
