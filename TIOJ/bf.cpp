#include <bits/stdc++.h>
using namespace std;

int u[1005], v[1005], w[1005];
vector<int> g[1005];
bitset<1005> t, p;

void M(int a, int b) {
	if (a == b) p |= t;
	for (int i : g[a]) {
		if (t[i]) continue;
		t[i] = 1;
		M(u[i] ^ v[i] ^ a, b);
		t[i] = 0;
	}
}

int Q(int a, int b, int c) {
	cerr << "Q " << a << ' ' << b << ' ' << c << endl;
	if (a == b) return c;
	int mn = INT_MAX;
	for (int i : g[a]) {
		cerr << "i = " << i << ", t = " << t[i] << endl;
		if (t[i]) continue;
		t[i] = 1;
		mn = min(mn, Q(u[i] ^ v[i] ^ a, b, max(c, w[i])));
		t[i] = 0;
	}
	return mn;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt; while (tt--) {
		int n, m, q; cin >> n >> m >> q;
		for (int i = 0; i < n; ++i) g[i].clear();
		for (int i = 0; i < m; ++i) { 
			cin >> u[i] >> v[i] >> w[i];
			g[u[i]].push_back(i);
			g[v[i]].push_back(i);
		}
		while (q--) {
			int c; cin >> c;
			if (c == 0) {
				int a, b, x; cin >> a >> b >> x;
				t.reset();
				p.reset();
				M(a, b);
				for (int i = 0; i < m; ++i) if (p[i]) w[i] += x;
			} else {
				int a, b; cin >> a >> b;
				t.reset();
				cout << Q(a, b, INT_MIN) << endl;
			}
		}
	}
}
