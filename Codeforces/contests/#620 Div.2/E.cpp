#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int dep[100005];
int pa[18][100005];

void dfs1(int now, int p) {
	pa[0][now] = p;
	for (int i = 1; pa[i - 1][now]; ++i) pa[i][now] = pa[i - 1][pa[i - 1][now]];
	for (int i : g[now]) if (i != p) {
		dep[i] = dep[now] + 1;
		dfs1(i, now);
	}
}

int get_lca(int u, int v) {
	if (u == v) return u;
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 17; i >= 0; --i) if ((dep[v] - dep[u]) & (1 << i)) v = pa[i][v];
	if (u == v) return u;
	for (int i = 17; i >= 0; --i) if (pa[i][u] != pa[i][v]) v = pa[i][v], u = pa[i][u];
	return pa[0][u];
}

int get_dis(int u, int v) {
	int l = get_lca(u, v);
	return dep[u] + dep[v] - dep[l] * 2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	int q; cin >> q; while (q--) {
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
		int od = get_dis(a, b);
		auto meow = [&] () -> bool {
			int od = get_dis(x, a) + 1 + get_dis(b, y);
			// cerr << a << ' ' << x << ' ' << y << ' ' << b << " = " << od << endl;
			// cerr << get_dis(x, a) << ' ' << get_dis(b, y) << endl;
			return od <= k && (k - od) % 2 == 0;
		};
		if (od <= k && (k - od) % 2 == 0) {
			cout << "YES" << '\n';
		} else {
			if (meow()) {
				cout << "YES" << '\n';
			} else {
				swap(a, b);
				if (meow()) {
					cout << "YES" << '\n';
				} else {
					cout << "NO" << '\n';
				}
			}
		}
	}
}
