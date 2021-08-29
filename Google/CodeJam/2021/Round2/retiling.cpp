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
#define WHR() printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), puts(""), fflush(stdout)
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

struct E {
	int u, v, f, c;
};

void solve() {
	int n, m, fli, swa; cin >> n >> m >> fli >> swa;

	vector<pair<int, int>> on, off;
	vector<string> mp(n), to_mp(n);
	for (int i = 0; i < n; ++i) { cin >> mp[i]; }
	for (int i = 0; i < n; ++i) { cin >> to_mp[i]; }
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (mp[i][j] != to_mp[i][j]) {
			if (mp[i][j] == 'M') on.emplace_back(i, j);
			else off.emplace_back(i, j);
		}
	}

	vector<E> edges;
	vector<vector<int>> g(155);

	auto add_edge = [&] (int u, int v, int f, int c) {
		g[u].push_back(edges.size());
		edges.emplace_back(E{u, v, f, c});
		g[v].push_back(edges.size());
		edges.emplace_back(E{v, u, 0, -c});
	};

	auto flow = [&] (int s, int t) {
		int nf = 0, nc = 0;
		while (true) {
			queue<int> q; q.push(s);
			vector<int> inq(155, 0); inq[s] = 1;
			vector<int> f(155, 0); f[s] = 1000000;
			vector<int> d(155, 1000000); d[s] = 0;
			vector<int> cf(155);

			while (q.size()) {
				int now = q.front(); q.pop();
				inq[now] = 0;

				for (int eid : g[now]) {
					E &e = edges[eid];
					if (e.f > 0 && d[e.v] > d[e.u] + e.c) {
						d[e.v] = d[e.u] + e.c;
						f[e.v] = min(f[e.u], e.f);
						cf[e.v] = eid;
						if (!inq[e.v]) {
							inq[e.v] = 1;
							q.push(e.v);
						}
					}
				}
			}

			if (f[t] == 0) break;

			nf += f[t];
			nc += f[t] * d[t];

			for (int u = t; u != s; u = edges[cf[u]].u) {
				edges[cf[u]].f -= f[t];
				edges[cf[u] ^ 1].f += f[t];
			}
		}
		return make_pair(nf, nc);
	};

	int n1 = on.size(), n2 = off.size();
	for (int i = 0; i < n1; ++i) for (int j = 0; j < n2; ++j) {
		auto [a, b] = on[i];
		auto [c, d] = off[j];
		int dist = abs(a - c) + abs(b - d);
		add_edge(i, j + n1, 1, dist);
		PDE(i, j, 1, dist);
	}
	int s = n1 + n2, t = s + 1;
	int S = t + 1, T = S + 1;
	for (int i = 0; i < n1; ++i) add_edge(s, i, 1, 0);
	for (int i = 0; i < n2; ++i) add_edge(i + n1, t, 1, 0);

	long long ans = 1e15;
	int nowf = 0, nowc = 0;
	for (int sw = 0; sw <= n * m; ++sw) {
		auto [f, c] = flow(S, T);
		nowf += f, nowc += c;
		ans = min(ans, 1ll * nowc * swa + 1ll * (n1 + n2 - nowf * 2) * fli);
		PDE(sw, nowf, nowc, ans);
		add_edge(S, s, 1, 0);
		add_edge(t, T, 1, 0);
	}

	cout << ans << endl;
}

int main() {
    CPPinput;
	int t; cin >> t; 
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
