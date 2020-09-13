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

int main() {
    CPPinput;
	ll n, r1, r2, r3, d; cin >> n >> r1 >> r2 >> r3 >> d;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector<ll> dp(n + 1, LLONG_MIN);
	dp[0] = -d;

	for (int i = 1; i <= n; ++i) {
		PDE(i);
		dp[i] = dp[i - 1] + r1 * a[i] + r3 + d;

		PDE(i, dp[i]);

		for (int j = 1; j < i; ++j) {
			ll sum = 0;
			for (int k = j; k <= i; ++k) {
				sum += min(min(r1 * (a[k] + 2), r1 * a[k] + r3), r1 + r2);
			}
			ll upd = (dp[j - 1] - 3 * j * d) + (sum) + 3 * i * d + d;
			//  (dp[j - 1] - 3 * j * d - pmin3[j - 1]) + 3 * d * i + pmin3[i] + d;
			dp[i] = min(dp[i], upd);
			PDE(j, upd, dp[j - 1], -3 * j * d, sum, 3 * i * d + d);

			if (i == n) {
				sum -= min(min(r1 * (a[n] + 2), r1 * a[n] + r3), r1 + r2);
				sum += r1 * a[n] + r3;
				upd = dp[j - 1] + sum + 2 * i * d - 2 * j * d + d;
				dp[i] = min(dp[i], upd);
				PDE(j, sum, upd);
			}

		}

		PDE(i, dp[i]);
	}

	cout << dp[n] << endl;
}

// dp[i] = dp[i - 1] + 
//						r1 * a[i] + r3 + d
//			dp[i - j - 1] + rangesum(min(r1 * (a[k] + 2), r1 * a[k] + r3, r2 + r1), k in [j, i]) + 3id - 3jd + d
