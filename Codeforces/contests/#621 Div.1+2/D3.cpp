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

vector<int> g[200005];
bool spec[200005];
int d[2][200005];
bool vis[200005];

int bit[500005];

int main() {
    CPPinput;
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		int t; cin >> t;
		spec[t] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	queue<int> q;
	q.push(1); vis[1] = 1;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i : g[now]) if (!vis[i]) {
			d[0][i] = d[0][now] + 1;
			vis[i] = 1;
			q.push(i);
		}
	}

	memset(vis, 0, sizeof(vis));
	q.push(n); vis[n] = 1;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i : g[now]) if (!vis[i]) {
			d[1][i] = d[1][now] + 1;
			vis[i] = 1;
			q.push(i);
		}
	}

	memset(bit, 0xb0, sizeof(bit));

	for (int i = 1; i <= n; ++i) if (spec[i]) {
		PDE("add ", i, d[1][i], d[0][i], d[1][i] - d[0][i] + 200000);
		for (int x = d[1][i] - d[0][i] + 200000; x < 500000; x += x & -x)
			bit[x] = max(bit[x], d[1][i]);
	}

	int mx = 0;
	for (int i = 1; i <= n; ++i) if (spec[i]) {
		PDE("find ", i, d[1][i], d[0][i], d[1][i] - d[0][i] + 200000 - 1);
		for (int x = d[1][i] - d[0][i] + 200000; x; x -= x & -x) 
			mx = max(mx, bit[x] + 1 + d[0][i]);
		PDE(mx);
	}
	cout << min(d[0][n], mx) << endl;

	/*
	auto check = [&] (int mxd) -> bool {
		for (int i = 1; i <= n; ++i) {
			if (spec[i] && d[0][i] >=
		}
		return false;
	};

	int L = 1, R = d[n];
	while (L < R) {
		int M = (L + R + 1) >> 1;
		if (check(M)) L = M;
		else R = M - 1;
	}

	cout << L << endl; */
}
