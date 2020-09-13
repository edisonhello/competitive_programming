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

vector<int> Input(int n, int k, int mod) {
	vector<int> v;
	for (int i = 0; i < k; ++i) {
		int t; cin >> t; 
		v.push_back(t);
	}
	int a, b, c; cin >> a >> b >> c;
	for (int i = k; i < n; ++i) {
		v.push_back((1ll * a * v[i - 2] + 1ll * b * v[i - 1] + c) % mod);
	}
	return v;
}

struct Edge {
	int u, v, w, oi, ow;
};
struct Event {
	int eid, nw;
};

bool operator< (const Edge &a, const Edge &b) { return a.w < b.w; }
ostream& operator<< (ostream &o, const Edge &e) { o << "(" << e.u << ", " << e.v << ", " << e.w << ", " << e.oi << ", " << e.ow << ")"; return o; }

void solve() {
	int n, m, e, k; cin >> n >> m >> e >> k;
	vector<int> X = Input(n, k, m);
	vector<int> Y = Input(n, k, m);
	vector<int> I = Input(e, k, n * m + n);
	vector<int> W = Input(e, k, 1000000000);

	vector<Edge> G;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			G.emplace_back(Edge{i * m + j, i * m + (j + 1) % m, 1, i * m + j, 1});
		}
	}
	for (int i = 0; i < n; ++i) {
		G.emplace_back(Edge{m * i + Y[i], m * ((i + 1) % n) + X[(i + 1) % n], 1, n * m + i, 1});
	}

	// vector<Event> evn;
	// for (int i = 0; i < e; ++i) {
	// 	env.emplace_back(Event{I[i], W[i]});
	// }

	long long ans = 1;
	vector<Edge> active;
	vector<int> djs(n * m + 1, 0);
	vector<int> e_at_pos(n * m + n, 0);

	auto initdjs = [&] (vector<Edge> &edgs) {
		for (auto &e : edgs) {
			djs[e.u] = e.u;
			djs[e.v] = e.v;
		}
	};
	function<int(int)> F = [&] (int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); };
	auto U = [&] (int x, int y) { djs[F(x)] = F(y); };
	auto C = [&] (int x, int y) { return F(x) == F(y); };

	auto contraction = [&] (long long &curans) {
		sort(active.begin(), active.end());
		PDE(active);
		initdjs(active);
		vector<Edge> tmp;
		for (auto &e : active) {
			if (C(e.u, e.v)) continue;
			U(e.u, e.v);
			tmp.push_back(e);
		}
		initdjs(tmp);
		for (auto &e : tmp) {
			if (e.w == -mod) continue;
			U(e.u, e.v);
			curans += e.w;
		}
		tmp.clear();
		for (auto &e : active) {
			if (C(e.u, e.v)) continue;
			tmp.emplace_back(Edge{F(e.u), F(e.v), e.w, e.oi, e.ow});
			e_at_pos[e.oi] = tmp.size() - 1;
		}
		active.swap(tmp);
	};

	auto reduction = [&] () {
		sort(active.begin(), active.end());
		initdjs(active);
		vector<Edge> tmp;
		for (auto &e : active) {
			if (C(e.u, e.v) && e.w != mod) continue;
			U(e.u, e.v);
			tmp.push_back(e);
			e_at_pos[e.oi] = tmp.size() - 1;
		}
		active.swap(tmp);
	};

	auto cdq = [&] (auto self, int l, int r, long long curans) -> void {
		// PDE(l, r, curans);
		if (l == r) {
			G[I[l]].w = W[l];
			// PDE("edge ", I[l], "change w", W[l]);
		}

		for (int i = 0; i < (int)active.size(); ++i) {
			e_at_pos[active[i].oi] = i;
			active[i].w = G[active[i].oi].w;
		}

		// PDE("1");

		if (l == r) {
			initdjs(active);
			sort(active.begin(), active.end());
			for (auto &e : active) {
				if (C(e.u, e.v)) continue;
				U(e.u, e.v);
				curans += e.w;
			}
			ans = 1ll * ans * (curans % mod) % mod;
			PDE(l, r, curans);
			return;
		}

		// PDE("2");

		// PDE(active);
		// PDE(e_at_pos);

		int mid = (l + r) >> 1;
		for (int i = l; i <= r; ++i) { if ((int)active.size() > e_at_pos[I[i]]) active[e_at_pos[I[i]]].w = -mod; }
		contraction(curans);
		PDE("contraction", active);
		for (int i = l; i <= r; ++i) { if ((int)active.size() > e_at_pos[I[i]]) active[e_at_pos[I[i]]].w = mod; }
		reduction();
		PDE("reduction", active);

		auto backup = active;
		self(self, l, mid, curans);
		active = backup;
		self(self, mid + 1, r, curans);
	};

	PDE(X, Y, I, W);

	active = G;
	cdq(cdq, 0, e - 1, 0);

	PDE(G);

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
