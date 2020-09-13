// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <utility>
#include <functional>
#include <complex>
#include <climits>
#include <random>
#include <thread>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define vint vector<int>
#define vpii vector<pair<int, int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x, v) memset((x), (v), sizeof(x))
#define RZUNI(x) sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
#define FIN(fname) freopen(fname, "r", stdin)
#define FOUT(fname) freopen(fname, "w", stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl
#define data datadetedoto

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() printf("%s: Line %d", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), fflush(stdout)
#define DEBUG 1
#define exit(x) cout << "exit code " << x << endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x) & (-(x)))

void JIZZ(string output = ""){ cout << output; exit(0); }

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

struct dinic {
    static const int inf = 1e9;
	static const int maxn = 2005;
    struct edge {
        int to, cap, rev;
        edge(int d, int c, int r): to(d), cap(c), rev(r) {}
    };
    vector<edge> g[maxn];
    int qu[maxn], ql, qr;
    int lev[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            g[i].clear();
    }
    int add_edge(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size() - 0);
        g[b].emplace_back(a, 0, g[a].size() - 1);
		return g[a].size() - 1;
    }
    bool bfs(int s, int t) {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        ql = qr = 0;
        qu[qr++] = s;
        while (ql < qr) {
            int x = qu[ql++];
            for (edge &e : g[x]) if (lev[e.to] == -1 && e.cap > 0) {
                lev[e.to] = lev[x] + 1;
                qu[qr++] = e.to;
            }
        }
        return lev[t] != -1;
    }
    int dfs(int x, int t, int flow) {
        if (x == t) return flow;
        int res = 0;
        for (edge &e : g[x]) if (e.cap > 0 && lev[e.to] == lev[x] + 1) {
            int f = dfs(e.to, t, min(e.cap, flow - res));
            res += f;
            e.cap -= f;
            g[e.to][e.rev].cap += f;
        }
        if (res == 0) lev[x] = -1;
        return res;
    }
    int operator()(int s, int t) {
        int flow = 0;
        for (; bfs(s, t); flow += dfs(s, t, inf));
        return flow;
    }
};

int main() {
    CPPinput;
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int, int>> g;
	int L = 0, R = 1001;
	for (int i = 0; i < m; ++i) {
		int u, v, a, b; cin >> u >> v >> a >> b;
		--u, --v;
		g.emplace_back(u, v, a, b);
		L = max(min(a, b), L);
	}

	vector<int> ans;
	auto ok = [&] (int x) {
		ans.clear();
		vector<int> in(n, 0), out(n, 0);
		dinic f;
		vector<pair<int, int>> chki;
		map<pair<int, int>, int> g2;
		for (int i = 0; i < m; ++i) {
			int u, v, a, b;
			tie(u, v, a, b) = g[i];
			assert(a <= x || b <= x);
			if (a <= x && b <= x) {
				++out[u], ++in[v];
				int z = f.add_edge(v, u, 1);
				chki.emplace_back(v, z);
				g2[make_pair(u, v)] = i;
			} else if (a <= x) {
				++out[u], ++in[v];
				g2[make_pair(u, v)] = i;
			} else if (b <= x) {
				++in[u], ++out[v];
				g2[make_pair(v, u)] = i;
			} else assert(0);
		}
		PDE(g2);
		for (int i = 0; i < n; ++i) if ((in[i] ^ out[i]) & 1) return false;
		int mxf = 0;
		for (int i = 0; i < n; ++i) {
			int z = in[i] - out[i];
			if (z < 0) f.add_edge(i, n + 1, -z / 2);
			else {
				f.add_edge(n, i, z / 2);
				mxf += z / 2;
			}
		}
		int resf = f(n, n + 1);
		PDE(mxf, resf);
		if (resf != mxf) return false;

		for (auto &p : chki) {
			auto &e = f.g[p.first][p.second];
			PDE(p, e.to, e.cap, e.rev);
			if (e.cap == 0) {
				auto it = g2.find(make_pair(e.to, p.first));
				g2[make_pair(p.first, e.to)] = it->second;
				g2.erase(it);
			}
		}
		PDE(g2);
		vector<vector<pair<int, int>>> g(n);
		for (auto &p : g2) {
			PDE(p);
			g[p.first.first].emplace_back(p.first.second, p.second);
		}
		set<pair<int, int>> vis;
		vector<int> vi(n, 0);

		auto Dfs = [&] (auto self, int now) -> void {
			vi[now]++;
			for (auto p : g[now]) {
				if (!vis.count(minmax(now, p.first))) {
					vis.insert(minmax(now, p.first));
					self(self, p.first);
					ans.push_back(p.second);
				}
			}
		};
		Dfs(Dfs, 0);
		reverse(ans.begin(), ans.end());
		for (int i : vi) if (!i) return false;
		return true;
	};

	while (L < R) {
		int m = (L + R) >> 1;
		PDE(L, m, R);
		if (ok(m)) R = m;
		else L = m + 1;
	}

	if (L == 1001) {
		cout << "NIE" << '\n';
		exit(0);
	}

	ok(L);
	cout << L << endl;
	for (int i : ans) cout << i + 1 << ' ';
	cout << endl;
}
