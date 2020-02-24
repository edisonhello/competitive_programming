#pragma GCC optimize("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2")

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
int can[82][82][82][82];
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

	for (int x = 1; x <= n; ++x) for (int y = 1; y <= n; ++y) {
		for (int l = 0; l <= n + 1; ++l) for (int r = 0; r <= n + 1; ++r) can[x][y][l][r] = 4e8;
		for (int i = 1; i <= n; ++i) can[x][y][i][i] = d[x][i] + d[i][y];

		for (int l = 2; l <= n; ++l) for (int i = 1; i + l - 1 <= n; ++i) {
			int j = i + l - 1;
			can[x][y][i][j] = min(can[x][y][i][j - 1], can[x][y][i + 1][j]);
		}
	}

	if (k != 10) {
		cho[0] = 1;
		int ans = dfs(1, k / 2);

		cout << ans << endl;
	} else {
		int ans = INT_MAX;
		for (int x1 = 1; x1 <= n; ++x1) {
			for (int x2 = 1; x2 <= n; ++x2) {
				for (int x3 = 1; x3 <= n; ++x3) {
					for (int x4 = 1; x4 <= n; ++x4) {
						int x[] = {x1, x2, x3, x4};
						sort(x, x + 4);
						ans = min(ans,
								min(min(min(can[1][x1][2][x[0] - 1], can[1][x1][x[0] + 1][x[1] - 1]), min(can[1][x1][x[1] + 1][x[2] - 1], can[1][x1][x[2] + 1][x[3] - 1])), can[1][x1][x[3] + 1][n]) + 
								min(min(min(can[x1][x2][2][x[0] - 1], can[x1][x2][x[0] + 1][x[1] - 1]), min(can[x1][x2][x[1] + 1][x[2] - 1], can[x1][x2][x[2] + 1][x[3] - 1])), can[x1][x2][x[3] + 1][n]) + 
								min(min(min(can[x2][x3][2][x[0] - 1], can[x2][x3][x[0] + 1][x[1] - 1]), min(can[x2][x3][x[1] + 1][x[2] - 1], can[x2][x3][x[2] + 1][x[3] - 1])), can[x2][x3][x[3] + 1][n]) + 
								min(min(min(can[x3][x4][2][x[0] - 1], can[x3][x4][x[0] + 1][x[1] - 1]), min(can[x3][x4][x[1] + 1][x[2] - 1], can[x3][x4][x[2] + 1][x[3] - 1])), can[x3][x4][x[3] + 1][n]) + 
								min(min(min(can[x4][1][2][x[0] - 1], can[x4][1][x[0] + 1][x[1] - 1]), min(can[x4][1][x[1] + 1][x[2] - 1], can[x4][1][x[2] + 1][x[3] - 1])), can[x4][1][x[3] + 1][n]));
					}
				}
			}
		}
		cout << ans << endl;
	}
}
