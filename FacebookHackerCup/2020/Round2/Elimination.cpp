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

void solve() {
	int n; double p; cin >> n >> p;
	vector<vector<double>> dp(n + 1, vector<double>(n + 1, (double)-1));

	auto Dfs = [&] (auto self, int u, int d) -> double {
		if (u < 0 || d < 0) return 0;
		if (u == 0 && d == 0) return 0;
		if (u + d == 1) return 1;
		if (dp[u][d] >= 0) return dp[u][d];

		PDE(u, d);

		double uu = u, dd = d, nn = u + d + 1;

		dp[u][d] = 
			2 / nn * ((d ? dd / (nn - 1) * (p * self(self, u, d - 1) + (1 - p) * 0) : 0) + 
					  (u ? uu / (nn - 1) * ((1 - p) * self(self, u - 1, d) + p * 0) : 0) + 
					  1) +
			(nn - 2) / nn * (uu * (uu - 1) / ((nn - 1) * (nn - 2)) * self(self, u - 1, d) + 
						     dd * (dd - 1) / ((nn - 1) * (nn - 2)) * self(self, u, d - 1) +
							 uu * dd * 2 / ((nn - 1) * (nn - 2)) * (p * self(self, u, d - 1) + (1 - p) * self(self, u - 1, d)) +
							 1);

		PDE(u, d, dp[u][d]);
		return dp[u][d];
	};

	for (int i = 1; i <= n; ++i) {
		cout << fixed << setprecision(12) << Dfs(Dfs, n - i, i - 1) << '\n';
	}
}

int main() {
    CPPinput;
	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": " << '\n';
		solve();
	}
}
