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

void Solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n + 2);
	for (int i = 2; i <= n; ++i) cin >> a[i];
	vector<vector<pair<int, int>>> g(n + 1);
	vector<int> ans(m, -1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}

	deque<pair<int, int>> known, order;
	for (int i = 2; i <= n; ++i) 
		if (a[i] > 0) known.emplace_back(a[i], i);
		else order.emplace_back(-a[i], i);

	sort(known.begin(), known.end());
	sort(order.begin(), order.end());
	int updated = 1;
	int nt = 0;

	while (updated < n) {
		int new_updated = 0;
		while (order.size() && order.front().first <= updated) {
			a[order.front().second] = nt + 1;
			order.pop_front();
			++new_updated;
		}

		while (known.size() && known.front().first == nt + 1) {
			known.pop_front();
			++new_updated;
		}

		++nt;
		updated += new_updated;

		PDE(order, known, nt, updated);
	}

	vector<bool> vis(n + 3, false);
	int it = 0;
	for (; it < n; ++it) {
		int mni = -1;
		for (int i = 1; i <= n; ++i) if (!vis[i]) {
			if (mni == -1) mni = i;
			else if (a[i] < a[mni]) mni = i;
		}

		PDE(mni);
		vis[mni] = 1;
		for (auto &e : g[mni]) if (a[e.first] <= a[mni]) {
			if (ans[e.second] == -1) ans[e.second] = 1000000;
		} else {
			ans[e.second] = a[e.first] - a[mni];
		}
	}


	// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// pq.emplace(0, 1);

	// while (pq.size()) {
	// 	int now = pq.top().second; pq.pop();
	// 	PDE(now);
	// 	for (auto &e : g[now]) {
	// 		PDE(e, vis);
	// 		if (vis[e.first]) {
	// 			if (ans[e.second] == -1) ans[e.second] = 1000000;
	// 		} else {
	// 			assert(ans[e.second] == -1);
	// 			ans[e.second] = a[e.first] - a[now];
	// 			pq.emplace(ans[e.second], e.first);
	// 			vis[e.first] = 1;
	// 		}
	// 	}
	// }

	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i];
		if (i != (int)ans.size() - 1) cout << ' ';
		else cout << '\n';
	}
}

int main() {
    CPPinput;
	int t; cin >> t; for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		Solve();
	}
}
