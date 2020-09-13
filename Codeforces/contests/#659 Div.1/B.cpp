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

// pair<int, int> dfs(int c0, int c1) {
// 	if (!c0 && !c1) return make_pair(0, 0);
// 	if (!c0) {
// 		auto p = dfs(c0, c1 - 1);
// 		swap(p.first, p.second);
// 		p.first ^= 1;
// 		return p;
// 	}
// 	if (!c1) {
// 		auto p = dfs(c0 - 1, c1);
// 		swap(p.first, p.second);
// 		return p;
// 	}
// 
// 	static map<pair<int, int>, pair<int, int>> mp;
// 	auto it = mp.find(make_pair(c0, c1));
// 	if (it != mp.end()) return it->second;
// 
// 	auto p0 = dfs(c0 - 1, c1);
// 	swap(p0.first, p0.second);
// 	auto p1 = dfs(c0, c1 - 1);
// 	swap(p1.first, p1.second);
// 	p1.first ^= 1;
// 
// 	PDE(c0, c1, p0, p1);
// 
// 	return mp[make_pair(c0, c1)] = (p0.first - p0.second > p1.first - p1.second) ? p0 : p1;
// }

int dfs(int c0, int c1, int me, int op) {
	// PDE(c0, c1, me, op);
	if (!c0 && !c1) return me - op;
	int z = 2;
	if (c0) z = min(z, dfs(c0 - 1, c1, op, me));
	if (c1) z = min(z, dfs(c0, c1 - 1, op, me ^ 1));
	// PDE(c0, c1, me, op, z);
	return -z;
}

int bruh(int i, int j) {
	if (j % 2 == 0) return 0;
	if (j % 4 == 1) return 1;
	if (i % 2 == 0) return -1;
	return 1;
}

int dp[100][100];
void test() {
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= 20; ++j) {
			int z = dfs(i, j, 0, 0);
			if (z > 0) cout << "+ ";
			if (z == 0) cout << "0 ";
			if (z < 0) cout << "- ";
		}
		cout << endl;
	}
	// for (int i = 0; i <= 20; ++i) {
	// 	for (int j = 0; j <= 20; ++j) {
	// 		if (i) {
	// 			if ((j % 2 == 1) && !dp[i - 1][j]) dp[i][j] = 1;
	// 			if ((j % 2 == 0) && dp[i - 1][j]) dp[i][j] = 1;
	// 		} 
	// 		if (j) {
	// 			if (((j - 1) % 2 == 1) && dp[i][j - 1]) dp[i][j] = 1;
	// 			if (((j - 1) % 2 == 0) && !dp[i][j - 1]) dp[i][j] = 1;
	// 		}
	// 		PDE(i, j, dp[i][j]);
	// 	}
	// }

	// for (int i = 0; i <= 20; ++i) {
	// 	for (int j = 0; j <= 20; ++j) {
	// 		if ((j % 2 == 1) && dp[i][j]) cout << "+ ";
	// 		else if ((j % 2 == 1) && !dp[i][j]) cout << "- ";
	// 		else cout << "0 ";
	// 	}
	// 	cout << endl;
	// }
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int z = 30; z >= 0; --z) {
		int c[2] = {0, 0};
		for (int i = 0; i < n; ++i) {
			++c[!!(v[i] & (1 << z))];
		}

		int y = bruh(c[0], c[1]);
		if (y) {
			if (y > 0) cout << "WIN" << '\n';
			else cout << "LOSE" << '\n';
			return;
		}
	}
	cout << "DRAW" << '\n';
}

int main() {
    CPPinput;
	// test();
	 // dfs(2, 3);

	int t; cin >> t; while (t--) solve();
}
