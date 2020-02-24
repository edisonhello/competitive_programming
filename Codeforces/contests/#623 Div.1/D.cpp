#pragma GCC optimize("O3")
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

int n, k;
int d[88][88];
int can[81][81][81][81];
int cho[8], used[8];

int dfs(int num, int mx) {
	if (num == mx) {
		cho[num] = 1;
		memcpy(used, cho, mx << 2);
		sort(used, used + mx);
		used[mx] = n + 1;
		int rt = 0;
		for (int i = 1; i <= mx; ++i) {
			int mn = INT_MAX;
			for (int j = 1; j <= mx; ++j) {
				if (used[j - 1] + 1 < used[j]) mn = min(mn, can[cho[i - 1]][cho[i]][used[j - 1] + 1][used[j] - 1]);
			}
			rt += mn;
		}
		return rt;
	}
	int mn = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		cho[num] = i;
		mn = min(mn, dfs(num + 1, mx));
	}
	return mn;
}

int main() {
    CPPinput;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> d[i][j];

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) for (int k = 1; k <= n; ++k) if (k != i || k != j) {
		can[i][j][k][k] = d[i][k] + d[k][j];
	} else can[i][j][k][k] = 1e9;

	for (int x = 1; x <= n; ++x) for (int y = 1; y <= n; ++y) 
		for (int l = 2; l <= n; ++l) for (int i = 1; i + l - 1 <= n; ++i) {
			int j = i + l - 1;
			can[x][y][i][j] = min(can[x][y][i][j - 1], can[x][y][i + 1][j]);
		}

	cho[0] = 1;
	int ans = dfs(1, k / 2);

	cout << ans << endl;
}
