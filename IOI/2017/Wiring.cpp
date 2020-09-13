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

#define int long long
int tp[200005];
int pdf[200005], ndf[200005];
long long pre[200005];

long long dp[200005];

int32_t main() {
    CPPinput;
	int n, m; cin >> n >> m;
	vector<pair<int, int>> p;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; 
		p.emplace_back(x, 0);
	}
	for (int i = 0; i < m; ++i) {
		int x; cin >> x; 
		p.emplace_back(x, 1);
	}
	n += m;

	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	p.emplace_back(-1, -1);
	reverse(p.begin(), p.end());

	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + p[i].first;
	for (int i = 1; i <= n; ++i) tp[i] = tp[i - 1] + p[i].second;
	for (int i = 2; i <= n; ++i) {
		if (p[i].second != p[i - 1].second) pdf[i] = i - 1;
		else pdf[i] = pdf[i - 1];
	}
	for (int i = n - 1; i >= 1; --i) {
		if (p[i].second != p[i + 1].second) ndf[i] = i + 1;
		else ndf[i] = ndf[i + 1];
	}

	PDE(p);

	memset(dp, 0x3f, sizeof(dp));

	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		PDE(i);
		auto update = [&] (int x) { dp[i] = min(dp[i], x); };
		if (pdf[i]) {
			PDE("con pre");
			update(dp[i - 1] + p[i].first - p[pdf[i]].first);
		} 
		if (ndf[i]) {
			PDE("con nx");
			update(dp[i - 1] + p[ndf[i]].first - p[i].first);
		}
		if (pdf[i] && pdf[i] - (i - pdf[i]) + 1 >= 1 && (tp[pdf[i]] - tp[pdf[i] - (i - pdf[i])] == i - pdf[i] || tp[pdf[i]] - tp[pdf[i] - (i - pdf[i])] == 0)) {
			PDE("pair");
			update(dp[pdf[i] - (i - pdf[i])] + pre[i] - pre[pdf[i]] - (pre[pdf[i]] - pre[pdf[i] - (i - pdf[i])]));
		}
		PDE(i, dp[i]);
	}

	cout << dp[n] << endl;
}
