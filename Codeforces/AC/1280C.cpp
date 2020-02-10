#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[200005];
int sz[200005];

void dfs(int now, int pa) {
	sz[now] = 1;
	for (auto &p : g[now]) if (p.first != pa) {
		dfs(p.first, now);
		sz[now] += sz[p.first];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		int n; cin >> n; n *= 2;
		vector<tuple<int, int, int>> ed;
		for (int i = 1; i < n; ++i) {
			int u, v, w; cin >> u >> v >> w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
			ed.emplace_back(u, v, w);
		}
		dfs(1, 0);
		long long mn = 0, mx = 0;
		for (auto [u, v, w] : ed) {
			if (sz[u] < sz[v]) swap(u, v);
			if (sz[v] & 1) mn += w;
			mx += w * 1ll * min(sz[v], n - sz[v]);
		}
		cout << mn << ' ' << mx << endl;
		for (int i = 1; i <= n; ++i) g[i].clear();
	}
}
