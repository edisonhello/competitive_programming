#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
int d[200005], cf[200005];
set<int> p;

void dfs1(int now, int pa) {
	for (int i : g[now]) if (i != pa) {
		d[i] = d[now] + 1;
		cf[i] = now;
		dfs1(i, now);
	}
}

void dfs2(int now) {
	if (d[now]) return;
	if (p.count(now)) return;
	dfs2(cf[now]);
	d[now] = d[cf[now]] + 1;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	int a = max_element(d, d + 1 + n) - d;
	d[a] = 0;
	dfs1(a, 0);
	int b = max_element(d, d + 1 + n) - d;

	if (d[b] == n - 1) {
		cout << n - 1 << '\n';
		cout << a << ' ' << b << ' ' << (a == 1 || b == 1 ? a == 2 || b == 2 ? 3 : 2 : 1) << '\n';
	} else {
		int z = d[b];
		p.insert(b);
		int now = b;
		while (now != a) {
			now = cf[now];
			p.insert(now);
		}
		memset(d, 0, sizeof(d));

		for (int i = 1; i <= n; ++i) if (!p.count(i)) {
			dfs2(i);
		}

		int c = max_element(d, d + 1 + n) - d;
		cout << z + d[c] << endl;
		cout << a << ' ' << b << ' ' << c << endl;
	}
}
