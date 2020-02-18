#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		vector<tuple<int, int, int>> req;
		for (int i = 0; i < n; ++i) {
			int t, l, r; cin >> t >> l >> r;
			req.emplace_back(t, l, r);
		}
		sort(req.begin(), req.end());
		int ll = m, rr = m;
		int nt = 0;
		bool no = 0;
		for (auto [t, l, r] : req) {
			int d = t - nt; nt = t;
			ll -= d, rr += d;
			ll = max(ll, l), rr = min(rr, r);
			if (rr < ll) { no = 1; }
		}
		if (no) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}
