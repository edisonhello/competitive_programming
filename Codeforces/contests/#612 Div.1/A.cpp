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

int a[105];
int dp[105][105][105][3];

void update(int &a, int b) {
	a = min(a, b);
}

int main() {
    CPPinput;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int od = (n + 1) / 2, ev = n / 2;
	for (int i = 1; i <= n; ++i) if (a[i]) {
		if (a[i] & 1) --od;
		else --ev;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][od][ev][0] = 0;
	PDE(od, ev);
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			for (int j = 0; j <= od; ++j) for (int k = 0; k <= ev; ++k) {
				if (j) update(dp[i][j - 1][k][1], dp[i - 1][j][k][0]);
				if (k) update(dp[i][j][k - 1][2], dp[i - 1][j][k][0]);
				if (j) update(dp[i][j - 1][k][1], dp[i - 1][j][k][1]);
				if (k) update(dp[i][j][k - 1][2], dp[i - 1][j][k][1] + 1);
				if (j) update(dp[i][j - 1][k][1], dp[i - 1][j][k][2] + 1);
				if (k) update(dp[i][j][k - 1][2], dp[i - 1][j][k][2]);
			}
		} else {
			for (int j = 0; j <= od; ++j) for (int k = 0; k <= ev; ++k) {
				if (a[i] & 1) {
					update(dp[i][j][k][1], dp[i - 1][j][k][0]);
					update(dp[i][j][k][1], dp[i - 1][j][k][1]);
					update(dp[i][j][k][1], dp[i - 1][j][k][2] + 1);
				} else {
					update(dp[i][j][k][2], dp[i - 1][j][k][0]);
					update(dp[i][j][k][2], dp[i - 1][j][k][1] + 1);
					update(dp[i][j][k][2], dp[i - 1][j][k][2]);
				}
			}
		}
	}
	cout << min(dp[n][0][0][1], dp[n][0][0][2]) << endl;
}
