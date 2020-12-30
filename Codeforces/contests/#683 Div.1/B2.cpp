#pragma GCC optimize("O3")
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

int dp[5005][5005], vis[5005][5005];
int snxt[5005][128], tnxt[5005][128];

int main() {
    CPPinput;
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	s = " " + s, t = " " + t;
	for (int i = 'a'; i <= 'z'; ++i) snxt[n][i] = n + 1, tnxt[m][i] = m + 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 'a'; j <= 'z'; ++j) snxt[i][j] = snxt[i + 1][j];
		snxt[i][s[i + 1]] = i + 1;
	}
	for (int i = m - 1; i >= 0; --i) {
		for (int j = 'a'; j <= 'z'; ++j) tnxt[i][j] = tnxt[i + 1][j];
		tnxt[i][t[i + 1]] = i + 1;
	}

	int ans = 0;
	for (int i = n; i >= 1; --i) for (int j = m; j >= 1; --j) if (s[i] == t[j]) {
		int mx = 2;
		for (int z = 'a'; z <= 'z'; ++z) {
			int r = dp[snxt[i][z]][tnxt[j][z]];
			mx = max(mx, r - (snxt[i][z] - i - 1) - (tnxt[j][z] - j - 1) + 2);
		}

		PDE(i, j, mx);
		int r = dp[snxt[i][s[i]]][j];
		mx = max(mx, r - (snxt[i][s[i]] - i));

		PDE(i, j, mx);
		r = dp[i][tnxt[j][t[j]]];
		mx = max(mx, r - (tnxt[j][t[j]] - j));

		PDE(i, j, mx);
		ans = max(mx, ans);
		dp[i][j] = mx;
	};

	cout << ans << endl;
}
