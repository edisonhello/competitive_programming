#include <bits/stdc++.h>
using namespace std;
// #include </home/edison/Coding/cpp/template/debug.cpp>

vector<int> g[55];
int dep[55], p[55];
int rule[25][2];
int lca[55][55];
vector<int> up[55], down[55];

int tag[55];

void dfs(int now, int pa) {
	p[now] = pa;
	for (int i : g[now]) if (i != pa) {
		dep[i] = dep[now] + 1;
		dfs(i, now);
	}
}

int get_lca(int u, int v) {
	if (dep[v] < dep[u]) swap(u, v);
	while (dep[v] > dep[u]) v = p[v];
	if (u == v) return u;
	while (u != v) u = p[u], v = p[v];
	return u;
}

long long dfs2(int now, int pa) {
	long long rt = 1;
	for (int i : g[now]) if (i != pa) {
		rt *= dfs2(i, now);
		tag[now] += tag[i];
	}
	if (tag[now] == 0) rt *= 2;
	return rt;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, 0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			lca[i][j] = get_lca(i, j);
		}
	}

	int m; cin >> m; for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		if (dep[v] < dep[u]) swap(u, v);
		rule[i][0] = u, rule[i][1] = v;
		up[u].push_back(i);
		down[v].push_back(i);
	}

	long long ans = 0;
	for (int z = 0; z < (1 << m); ++z) {
		int y = __builtin_popcount(z);
		memset(tag, 0, sizeof(tag));		
		for (int i = 0; i < m; ++i) if (z & (1 << i)) {
			++tag[rule[i][0]];
			++tag[rule[i][1]];
			----tag[lca[rule[i][0]][rule[i][1]]];
		}
		long long rr = dfs2(1, 0);
		// PDE(z, y, rr);
		ans += rr * (y & 1 ? -1 : 1);
	}
	cout << ans / 2 << endl;
}

