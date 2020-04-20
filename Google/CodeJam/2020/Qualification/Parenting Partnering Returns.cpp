#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; for (int ts = 1; ts <= t; ++ts) {
		int n; cin >> n;
		vector<tuple<int, int, int>> ev(n);
		vector<int> ans(n, 0);
		for (int i = 0; i < n; ++i) {
			int s, e; cin >> s >> e;
			ev[i] = make_tuple(s, e, i);
		}

		int la0 = -1, la1 = -1;
		sort(ev.begin(), ev.end());
		bool no = 0;
		for (auto t : ev) {
			int s, e, i; tie(s, e, i) = t;
			if (la0 <= s) {
				ans[i] = 1;
				la0 = e;
			} else if (la1 <= s) {
				ans[i] = 2;
				la1 = e;
			} else no = 1;
		}

		cout << "Case #" << ts << ": ";
		if (no) cout << "IMPOSSIBLE";
		else for (int i : ans) cout << (i == 1 ? "C" : "J");
		cout << '\n';
	}
}
