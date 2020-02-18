#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define hash hfsssssssssssse

int val[303][303];
int djs[303 * 303];
int sz;
int nt;
cc_hash_table<long long, int> edg;

vector<pair<int, int>> seg[2000006 * 4];
vector<stack<pair<int *, int>>> rec;

int encode(int x, int y) {
	return x * 300 + y;
}

long long hash(int x, int y) {
	if (y < x) swap(x, y);
	return 303ll * 305 * x + y;
}

void assign(int &o, int v) {
	rec.back().emplace(&o, o);
	o = v;
}

int F(int x) { return x == djs[x] ? x : F(djs[x]); }
void U(int x, int y) {
	// cerr << "U(" << x << ' ' << y << endl;
	x = F(x), y = F(y);
	// cerr << "U->(" << x << ' ' << y << endl;
	if (x == y) return;
	assign(sz, sz - 1);
	assign(djs[x], y);
}

#define mid ((l + r) >> 1)
void insert(int o, int l, int r, int ml, int mr, int x, int y) {
	// if (!o) cerr << "insert " << x << " " << y << " into [" << ml << ' ' << mr << ']' << endl;
	if (mr < l || r < ml) return;
	if (ml <= l && r <= mr) {
		seg[o].emplace_back(x, y);
		return;
	}
	insert(o * 2 + 1, l, mid, ml, mr, x, y);
	insert(o * 2 + 2, mid + 1, r, ml, mr, x, y);
}

void dfs(int o, int l, int r) {
	rec.push_back(stack<pair<int *, int>>());

	for (auto &p : seg[o]) U(p.first, p.second);

	if (l == r) {
		if (l) cout << sz << '\n';
	}
	else dfs(o * 2 + 1, l, mid), dfs(o * 2 + 2, mid + 1, r);

	while (rec.back().size()) {
		*rec.back().top().first = rec.back().top().second;
		rec.back().pop();
	}
	rec.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		if (i > 1) edg[hash(encode(i - 1, j), encode(i, j))] = 0;
		if (j > 1) edg[hash(encode(i, j - 1), encode(i, j))] = 0;
		djs[encode(i, j)] = encode(i, j);
		++sz;
		// cerr << "pos " << i << " " << j << " = " << encode(i, j) << endl;
	}

	for (int t = 1; t <= q; ++t) {
		int i, j, v; cin >> i >> j >> v;
		// cerr << i << ' ' << j << ' ' << v << ' ' << endl;
		if (val[i][j] == v) continue;
		if (i > 1) {
			if (val[i][j] == val[i - 1][j]) {
				long long o = hash(encode(i, j), encode(i - 1, j));
				insert(0, 0, q, edg[o], t - 1, encode(i, j), encode(i - 1, j));
				edg.erase(o);
				// cerr << "break1" << endl;
			} else if (val[i - 1][j] == v) {
				long long o = hash(encode(i, j), encode(i - 1, j));
				edg[o] = t;
				// cerr << "new1" << endl;
			}
		}
		if (j > 1) {
			if (val[i][j] == val[i][j - 1]) {
				long long o = hash(encode(i, j), encode(i, j - 1));
				insert(0, 0, q, edg[o], t - 1, encode(i, j), encode(i, j - 1));
				edg.erase(o);
				// cerr << "break2" << endl;
			} else if (val[i][j - 1] == v) {
				long long o = hash(encode(i, j), encode(i, j - 1));
				edg[o] = t;
				// cerr << "new2" << endl;
			}
		}
		if (i < n) {
			if (val[i][j] == val[i + 1][j]) {
				long long o = hash(encode(i, j), encode(i + 1, j));
				insert(0, 0, q, edg[o], t - 1, encode(i, j), encode(i + 1, j));
				edg.erase(o);
				// cerr << "break3" << endl;
			} else if (val[i + 1][j] == v) {
				long long o = hash(encode(i, j), encode(i + 1, j));
				edg[o] = t;
				// cerr << "new3" << endl;
			}
		}
		// cerr << "bruh " << j << ' ' << m << endl;
		if (j < m) {
			// cerr << "bruh " << val[i][j] << ' ' << val[i][j + 1] << endl;
			if (val[i][j] == val[i][j + 1]) {
				long long o = hash(encode(i, j), encode(i, j + 1));
				insert(0, 0, q, edg[o], t - 1, encode(i, j), encode(i, j + 1));
				edg.erase(o);
				// cerr << "break4" << endl;
			} else if (val[i][j + 1] == v) {
				long long o = hash(encode(i, j), encode(i, j + 1));
				edg[o] = t;
				// cerr << "new4" << endl;
			}
		}
		val[i][j] = v;
		// cerr << "mp: " << endl;
		// for (int i = 1; i <= n; ++i) {
		// 	for (int j = 1; j <= m; ++j) {
		// 		cerr << val[i][j] << ' ';
		// 	}
		// 	cerr << '\n';
		// }
	}

	// cerr << "final add " << endl;
	for (auto &p : edg) {
		long long z = p.first / (303 * 305);
		insert(0, 0, q, p.second, q, z, p.first - (z * 303 * 305));
	}
	dfs(0, 0, q);
}
