#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		vector<long long> a(n);
		vector<vector<int>> g(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) {
			int u, v; cin >> u >> v;
			--u, --v;
			g[v].push_back(u);
		}
		map<long long, long long> mp;
		for (int i = 0; i < n; ++i) {
			if (g[i].empty()) continue;
			sort(g[i].begin(), g[i].end());
			int h0 = 0, h1 = 0;
			for (int j : g[i]) {
				h0 = (131ll * h0 + (j + 1)) % 1000000007;
				h1 = (7902131ll * h1 + (j + 1)) % 1000000009;
			}
			mp[2000000000ll * h0 + h1] += a[i];
		}

		long long gg = 0;
		for (auto &p : mp) gg = __gcd(gg, p.second);
		cout << gg << '\n';
	}
}
