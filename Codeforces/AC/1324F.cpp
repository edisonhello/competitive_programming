#include <bits/stdc++.h>
using namespace std;

int c[200005], s[200005], b[200005], a[200005];
vector<int> g[200005];

void dfs(int now, int pa) {
	s[now] = c[now];
	for (int i : g[now]) if (i != pa) {
		dfs(i, now);
		s[now] += s[i];
		if (b[i] > 0) b[now] += b[i];
	}
	b[now] += c[now];
}

void dfs2(int now, int pa, int up) {
	a[now] = up + b[now];
	for (int i : g[now]) if (i != pa) 
		dfs2(i, now, max(0, up + b[now] - (b[i] > 0 ? b[i] : 0)));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i] == 0) c[i] = -1;
	}
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);

	dfs2(1, 0, 0);

	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	cout << endl;
}
