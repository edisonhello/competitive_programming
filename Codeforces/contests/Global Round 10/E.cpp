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

long long val[30][30];
long long dp[30][30];
int n;

void CHECK(long long v, stack<pair<int, int>> st) {
	assert(st.size() == n * 2 - 1);
	assert(st.top() == make_pair(1, 1));

	int x = 1, y = 1;
	st.pop();
	v -= val[x][y];
	while (st.size()) {
		int nx, ny; tie(nx, ny) = st.top();
		st.pop();
		assert(nx >= x && ny >= y && nx + ny - x - y == 1 && nx <= n && ny <= n);
		x = nx, y = ny;
		v -= val[x][y];
	}

	assert(v == 0);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			val[i][j] = 1 << (i - 1);
			dp[i][j] = min(i == 1 ? 1000000000 : dp[i - 1][j], j == 1 ? 1000000000 : dp[i][j - 1]) + val[i][j];
			if (i == 1 && j == 1) dp[i][j] = 1;
			cout << val[i][j] << ' ';
		}
		cout << endl;
	}

	// cerr << "dp: " << endl;
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 1; j <= n; ++j) {
	// 		cerr << dp[i][j] << ' ';
	// 	}
	// 	cerr << endl;
	// }

	int t; cin >> t; while (t--) {
		long long v; cin >> v;
		stack<pair<int, int>> st;
		long long ov = v;

		int i = n, j = n;
		while (i > 1 || j > 1) {
			st.emplace(i, j);
			v -= val[i][j];

			if (j > 1 && v >= dp[i][j - 1]) {
				--j;
			} else --i;
		}
		st.emplace(1, 1);

		CHECK(ov, st);

		// PDE(st, v);

		assert(v == 1);

		while (st.size()) {
			cout << st.top().first << ' ' << st.top().second << '\n';
			st.pop();
		}
		fflush(stdout);
	}
}
