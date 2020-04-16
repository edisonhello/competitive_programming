#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

// #define int long long
const int inf = 1000000000;

#ifdef DEBUG
#define debug(x) cerr << x
#else
#define debug(x) (0 == 0)
#endif

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; 
	int n, m, q; cin >> n >> m >> q;
	vector<vector<pair<int, int>>> g(n);
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	
	auto [cc, bel, mem] = [&] () {
		vector<int> dfn(n, 0), low(n, 0);
		int dtime = 0;
		int cc = 0;
		vector<int> bel(n);
		vector<vector<int>> mem;
		stack<int> st;
		function<void(int, int)> Tarjan = [&] (int now, int pa) {
			st.push(now);
			dfn[now] = low[now] = ++dtime;
			for (auto &p : g[now]) if (p.first != pa) {
				if (dfn[p.first]) low[now] = min(low[now], dfn[p.first]);
				else {
					Tarjan(p.first, now);
					low[now] = min(low[now], low[p.first]);
				}
			}
			if (low[now] == dfn[now]) {
				mem.push_back(vector<int>());
				int cur;
				do {
					cur = st.top(); st.pop();
					bel[cur] = cc;
					mem.back().push_back(cur);
				} while (cur != now);
				++cc;
			}
		};

		for (int i = 0; i < n; ++i) if (!dfn[i]) Tarjan(i, 0);

		return make_tuple(cc, bel, mem);
	} ();

	vector<vector<tuple<int, int, int>>> ic_es(cc); // [w, i, j]
	vector<vector<tuple<int, int, int, int>>> cg(cc); // [toc, w, oi, oj]
	for (int i = 0; i < n; ++i) for (auto &p : g[i]) {
		debug("i " << i << " p " << p.first << ',' << p.second << " bels = " << bel[i] << ' ' << bel[p.first] << endl);
		if (bel[i] != bel[p.first])
			cg[bel[i]].emplace_back(bel[p.first], p.second, i, p.first);
		else ic_es[bel[i]].emplace_back(p.second, i, p.first);
	}

	auto [ic_dep, ic_pa, ic_mx] = [&] () {
		vector<int> dep(n, 0), djs(n);
		vector<vector<int>> pa(__lg(n) + 1, vector<int>(n, -1)), mx(__lg(n) + 1, vector<int>(n, -inf));
		vector<vector<pair<int, int>>> mg(n);

		iota(djs.begin(), djs.end(), 0);

		function<int(int)> Find = [&] (int x) {
			return x == djs[x] ? x : djs[x] = Find(djs[x]);
		};

		auto Union = [&] (int x, int y) {
			djs[Find(x)] = Find(y);
		};
		
		function<void(int, int)> Dfs = [&] (int now, int p) {
			pa[0][now] = p;
			for (int i = 1; i < (int)pa.size(); ++i) {
				pa[i][now] = pa[i - 1][now] == -1 ? -1 : pa[i - 1][pa[i - 1][now]];
				mx[i][now] = max(mx[i - 1][now], pa[i - 1][now] == -1 ? -inf : mx[i - 1][pa[i - 1][now]]);
			}

			for (auto [v, w] : mg[now]) if (v != p) {
				dep[v] = dep[now] + 1;
				mx[0][v] = w;
				Dfs(v, now);
			}
		};

		for (int i = 0; i < cc; ++i) {
			sort(ic_es[i].begin(), ic_es[i].end());
			for (auto [w, x, y] : ic_es[i]) {
				if (Find(x) == Find(y)) continue;
				Union(x, y);
				mg[x].emplace_back(y, w);
				mg[y].emplace_back(x, w);
			}

			Dfs(mem[i][0], -1);
		}

		return make_tuple(dep, pa, mx);
	} ();

	auto MSTQuery = [&] (int u, int v) {
		assert(bel[u] == bel[v]);
		if (ic_dep[u] > ic_dep[v]) swap(u, v);
		int mx = -inf;
		debug("mstquery u v " << u << ' ' << v << endl);
		if (u == v) return mx;
		for (int i = 0; ic_dep[u] != ic_dep[v]; ++i) if ((ic_dep[v] - ic_dep[u]) & (1 << i)) {
			mx = max(mx, ic_mx[i][v]);
			v = ic_pa[i][v];
		}
		debug("mstquery u v " << u << ' ' << v << endl);
		if (u == v) return mx;
		for (int i = (int)ic_pa.size() - 1; i >= 0; --i) if (ic_pa[i][u] != ic_pa[i][v]) {
			mx = max(mx, max(ic_mx[i][u], ic_mx[i][v]));
			u = ic_pa[i][u];
			v = ic_pa[i][v];
		}
		mx = max(mx, max(ic_mx[0][u], ic_mx[0][v]));
		return mx;
	};

	struct Segtree {
		struct Node {
			Node *l, *r;
			int mx, tag;
			Node(int v) : l(0), r(0), mx(v), tag(0) {}
			void Assign(int x) { mx = x, tag = 0; }
			void AddTag(int x) { mx += x, tag += x; }
			void Push() { l->AddTag(tag), r->AddTag(tag), tag = 0; }
			void Pull() { mx = max(l->mx, r->mx); }
		} *root;
		int L, R;

#define mid ((l + r) >> 1)
		void _Build(Node *now, int l, int r, int v) {
			if (l == r) return;
			_Build(now->l = new Node(v), l, mid, v);
			_Build(now->r = new Node(v), mid + 1, r, v);
		}

		void Build(int _L, int _R, int v) {
			L = _L, R = _R;
			_Build(root = new Node(v), _L, _R, v);
		}

		void _Assign(Node *now, int l, int r, int x, int v) {
			if (l == r) {
				now->Assign(v);
				return;
			}
			now->Push();
			if (x <= mid) _Assign(now->l, l, mid, x, v);
			else _Assign(now->r, mid + 1, r, x, v);
			now->Pull();
		}

		void Assign(int x, int v) {
			assert(L <= x && x <= R);
			_Assign(root, L, R, x, v);
		}

		void _ModifyRange(Node *now, int l, int r, int ml, int mr, int v) {
			if (r < ml || mr < l) return;
			if (ml <= l && r <= mr) {
				now->AddTag(v);
				return;
			}
			now->Push();
			_ModifyRange(now->l, l, mid, ml, mr, v);
			_ModifyRange(now->r, mid + 1, r, ml, mr, v);
			now->Pull();
		}

		void ModifyRange(int l, int r, int v) {
			assert(L <= l && l <= r && r <= R);
			_ModifyRange(root, L, R, l, r, v);
		}

		int _Query(Node *now, int l, int r, int ql, int qr) {
			if (qr < l || r < ql) return -inf;
			if (ql <= l && r <= qr) return now->mx;
			now->Push();
			return max(_Query(now->l, l, mid, ql, qr),
					   _Query(now->r, mid + 1, r, ql, qr));
		}

		int Query(int l, int r) {
			assert(L <= l && l <= r && r <= R);
			int x = _Query(root, L, R, l, r);
			debug("Segtree query x = " << x << endl);
			return x;
		}
#undef mid
	};

	auto [ccc, cid, cpos, chead, segs1, segs2, segs3, u_to_up, u_up_to, u_c_to_down] = [&] () {
		int ccc = 0;
		vector<int> cid(cc), cpos(cc), sz(cc), mxszi(cc), cpa(cc), ec_to_up(cc), u_to_up(cc), u_up_to(cc), u_c_to_down(cc, -1);
		vector<int> cccsz, chead;

		function<void(int, int, int, int, int)> Dfs1 = [&] (int now, int pa, int nec_to_up, int nu_to_up, int nu_up_to) {
			// cerr << "now pa nec_to_up nu_to_up nu_up_to " << now << ' ' << pa << ' ' << nec_to_up << ' ' << nu_to_up << ' ' << nu_up_to << endl;
			sz[now] = 1;
			bool fi = 1;
			cpa[now] = pa;
			ec_to_up[now] = nec_to_up;
			u_to_up[now] = nu_to_up;
			u_up_to[now] = nu_up_to;
			for (auto [i, w, _i, _j] : cg[now]) if (i != pa) {
				Dfs1(i, now, w, _j, _i);
				sz[now] += sz[i];
				if (fi) mxszi[now] = i;
				fi = 0;
				if (sz[mxszi[now]] > sz[i]) mxszi[now] = i;
			}
		};

		function<void(int, int, int, int)> Dfs2 = [&] (int now, int pa, int ncid, int ncpos) {
			cid[now] = ncid;
			cpos[now] = ncpos;
			++cccsz[ncid];
			for (auto [i, w, _i, _j] : cg[now]) if (i != pa) {
				if (i != pa && i != mxszi[now]) {
					chead.push_back(i);
					cccsz.push_back(0);
					Dfs2(i, now, ccc++, 0);
				} else if (i == mxszi[now]) {
					u_c_to_down[now] = _i;
					Dfs2(i, now, ncid, ncpos + 1);
				}
			}
		};

		for (int i = 0; i < cc; ++i) if (!sz[i]) {
			Dfs1(i, 0, -inf, -1, -1);
			cccsz.push_back(0);
			chead.push_back(i);
			Dfs2(i, 0, ccc++, 0);
		}

		vector<Segtree> segs1(ccc), segs2(ccc), segs3(ccc);

		for (int i = 0; i < ccc; ++i) {
			segs1[i].Build(0, cccsz[i] - 1, -inf);
			segs2[i].Build(0, cccsz[i] - 1, -inf);
			segs3[i].Build(0, cccsz[i] - 1, 0);
		}

		for (int i = 0; i < cc; ++i) if (cpa[i] != -1) {
			segs1[cid[i]].Assign(cpos[i], ec_to_up[i]);
			if (u_c_to_down[i] != -1 && u_to_up[i] != -1) {
				segs2[cid[i]].Assign(cpos[i], MSTQuery(u_to_up[i], u_c_to_down[i]));
			}
		}

		return make_tuple(ccc, cid, cpos, chead, segs1, segs2, segs3, u_to_up, u_up_to, u_c_to_down);
	} ();

	auto [cdep, cpa, cmx] = [&] () {
		vector<int> dep(cc);
		vector<vector<int>> pa(__lg(cc) + 1, vector<int>(cc, -1)), mx(__lg(cc) + 1, vector<int>(cc, -inf));

		function<void(int, int)> Dfs = [&] (int now, int p) {
			pa[0][now] = p;
			for (int i = 1; i < (int)pa.size(); ++i) {
				pa[i][now] = pa[i - 1][now] == -1 ? -1 : pa[i - 1][pa[i - 1][now]];
				mx[i][now] = max(mx[i - 1][now], pa[i - 1][now] == -1 ? -inf : mx[i - 1][pa[i - 1][now]]);
			}

			for (auto [j, w, _i, _j] : cg[now]) if (j != p) {
				dep[j] = dep[now] + 1;
				mx[0][j] = w;
				Dfs(j, now);
			}
		};

		for (int i = 0; i < cc; ++i) if (pa[0][i] == -1) Dfs(i, -1);

		return make_tuple(dep, pa, mx);
	} ();

	auto GetCLCA = [&] (int a, int b) {
		debug("a b " << a << ' ' << b << endl);
		if (cdep[a] > cdep[b]) swap(a, b);
		for (int i = 0; i < (int)cpa.size(); ++i) if ((cdep[b] - cdep[a]) & (1 << i)) {
			b = cpa[i][b];
		}
		if (a == b) return a;
		for (int i = (int)cpa.size() - 1; i >= 0; --i) if (cpa[i][a] != cpa[i][b]) {
			a = cpa[i][a];
			b = cpa[i][b];
		}
		return cpa[0][a];
	};

	auto ModifyChain = [&] (int u, int now, int k) {
		while (cid[u] != cid[now]) {
			segs1[cid[now]].ModifyRange(0, cpos[now], k);
			segs2[cid[now]].ModifyRange(0, cpos[now], k);
			segs3[cid[now]].ModifyRange(0, cpos[now], k);
			now = cpa[0][chead[cid[now]]];
		}
		if (u != now)
			segs1[cid[now]].ModifyRange(cpos[u] + 1, cpos[now], k);
		segs2[cid[now]].ModifyRange(cpos[u], cpos[now], k);
		segs3[cid[now]].ModifyRange(cpos[u], cpos[now], k);
	};

	// auto QueryChain = [&] (int u, int now) {
	// 	debug("QueryChain u = " << u << " now = " << now << endl);
	// 	assert(u != now);
	// 	int x = INT_MIN;
	// 	x = max(x, segs1[cid[now]].Query(cpos[now], cpos[now]));
	// 	now = cpa[0][now];
	// 	while (cid[u] != cid[now]) {
	// 		x = max(x, segs1[cid[now]].Query(0, cpos[now]));
	// 		x = max(x, segs2[cid[now]].Query(0, cpos[now]));
	// 		x = max(x, MSTQuery(u_c_to_down[chead[cid[now]]], u_to_up[chead[cid[now]]]));
	// 		now = cpa[0][chead[cid[now]]];
	// 	}
	// 	if (u != now) {
	// 		x = max(x, segs1[cid[now]].Query(cpos[u] + 1, cpos[now]));
	// 		x = max(x, segs2[cid[now]].Query(cpos[u] + 1, cpos[now]));
	// 	}
	// 	debug("QueryChain x = " << x << endl);
	// 	return x;
	// };

	auto QueryPath = [&] (int u, int now) {
		debug("QueryPath from now = " << now << " to u " << u << endl);
		int x = -inf;
		while (cid[bel[u]] != cid[bel[now]]) {
			x = max(x, MSTQuery(now, u_to_up[bel[now]]) + segs3[cid[bel[now]]].Query(cpos[bel[now]], cpos[bel[now]]));
			now = u_to_up[bel[now]];
			x = max(x, segs1[cid[bel[now]]].Query(0, cpos[bel[now]]));
			if (cpos[bel[now]])
				x = max(x, segs2[cid[bel[now]]].Query(0, cpos[bel[now]] - 1));
			now = u_up_to[chead[cid[bel[now]]]];
		}
		debug("now = " << now << " u = " << u << " bel = " << bel[now] << ' ' << bel[u] << endl);
		if (bel[u] != bel[now]) {
			x = max(x, MSTQuery(now, u_to_up[bel[now]]) + segs3[cid[bel[now]]].Query(cpos[bel[now]], cpos[bel[now]]));
			now = u_to_up[bel[now]];
			x = max(x, segs1[cid[bel[now]]].Query(cpos[bel[u]] + 1, cpos[bel[now]]));
			if (cpos[bel[u]] + 1 < cpos[bel[now]])
				x = max(x, segs2[cid[bel[now]]].Query(cpos[bel[u]] + 1, cpos[bel[now]] - 1));
			now = u_c_to_down[bel[u]];
		}
		x = max(x, MSTQuery(now, u) + segs3[cid[bel[now]]].Query(cpos[bel[now]], cpos[bel[now]]));
		debug("QueryPath get " << x << endl);
		return x;
	};

	auto QueryOffset = [&] (int x) {
		// cerr << "QueryOffset x = " << x << endl;
		int z = segs3[cid[x]].Query(cpos[x], cpos[x]);
		// cerr << "QueryOffset ret = " << z << endl;
		return z;
	};

	auto OneStepToChild = [&] (int u, int v) {
		for (int i = (int)cpa.size() - 1; i >= 0; --i) if (cpa[i][v] != -1 && cdep[cpa[i][v]] > cdep[u])
			v = cpa[i][v];
		assert(cpa[0][v] == u);
		return v;
	};

	while (q--) {
		int c; cin >> c;
		if (c == 0) {
			int a, b, k; cin >> a >> b >> k;
			if (bel[a] == bel[b]) {
				ModifyChain(bel[a], bel[a], k);
			} else {
				if (cdep[bel[a]] > cdep[bel[b]]) swap(a, b);
				int l = GetCLCA(bel[a], bel[b]);
				if (l == bel[a]) {
					ModifyChain(l, bel[b], k);
				} else {
					ModifyChain(l, bel[a], k);
					ModifyChain(l, bel[b], k);
					ModifyChain(l, l, -k);
				}
			}
		} else {
			int a, b; cin >> a >> b;
			if (bel[a] == bel[b]) {
				debug("a b " << a << ' ' << b << endl);
				cout << MSTQuery(a, b) + QueryOffset(bel[a]) << '\n';
			} else {
				if (cdep[bel[a]] > cdep[bel[b]]) swap(a, b);
				debug("a b bel " << a << ' ' << b << ' ' << bel[a] << ' ' << bel[b] << endl);
				int l = GetCLCA(bel[a], bel[b]);
				debug("l = " << l << endl);
				if (l == bel[a]) {
					// int x = QueryChain(l, bel[b]);
					// x = max(x, MSTQuery(b, u_to_up[bel[b]]) + QueryOffset(bel[b]));
					// x = max(x, MSTQuery(a, u_up_to[OneStepToChild(l, bel[b])]) + QueryOffset(l));
					int x = QueryPath(a, b);
					cout << x << '\n';
				} else {
					// int x = QueryChain(l, bel[a]);
					// x = max(x, QueryChain(l, bel[b]));
					// x = max(x, MSTQuery(a, u_to_up[bel[a]]) + QueryOffset(bel[a]));
					// x = max(x, MSTQuery(b, u_to_up[bel[b]]) + QueryOffset(bel[b]));
					// x = max(x, MSTQuery(u_up_to[OneStepToChild(l, bel[a])], u_up_to[OneStepToChild(l, bel[b])]) + QueryOffset(l));
					int x = QueryPath(u_up_to[OneStepToChild(l, bel[b])], b);
					x = max(x, QueryPath(u_up_to[OneStepToChild(l, bel[a])], a));
					x = max(x, MSTQuery(u_up_to[OneStepToChild(l, bel[b])], u_up_to[OneStepToChild(l, bel[a])]) + QueryOffset(l));
					cout << x << '\n';
				}
			}
		}
	}
}
