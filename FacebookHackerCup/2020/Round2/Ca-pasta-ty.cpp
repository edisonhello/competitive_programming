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

vector<int> Input(int n, int k) {
	vector<int> v = {0};
	for (int i = 0; i < k; ++i) {
		int t; cin >> t; 
		v.push_back(t);
	}
	int a, b, c, d; cin >> a >> b >> c >> d;
	for (int i = k + 1; i <= n; ++i) {
		v.push_back((1ll * a * v[i - 2] + 1ll * b * v[i - 1] + c) % d);
	}
	return v;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> s = Input(n, k);
	vector<int> x = Input(n, k);
	vector<int> y = Input(n, k);
	PDE(n, k, s, x, y);
	for (int i = 1; i <= n; ++i) y[i] += x[i];
	long long ans = 0;
	long long mn = 0, mx = 0, sum = 0;
	for (int i : s) sum += i;
	for (int i : x) mn += i;
	for (int i : y) mx += i;
	if (sum < mn || mx < sum) {
		cout << -1 << endl;
		return;
	}
	mn = mx = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] < x[i]) mn += x[i] - s[i];
		else if (y[i] < s[i]) mx += s[i] - y[i];
	}
	cout << max(mx, mn) << endl;
	// {
	// 	vector<int> low;
	// 	vector<int> hi;
	// 	long long lc = 0, hc = 0;
	// 	for (int i = 1; i <= n; ++i) {
	// 		if (s[i] < x[i]) {
	// 			low.push_back(i);
	// 			lc += x[i] - s[i];
	// 		} else if (s[i] > y[i]) {
	// 			hi.push_back(i);
	// 			rc += s[i] - y[i];
	// 		}
	// 	}

	// 	if (lc > hc) {
	// 		for (int i : hi) {
	// 			s[i] = y[i];
	// 		}
	// 		lc -= hc;
	// 		for (int i : low) {
	// 			if (hc == 0) break;
	// 			int d = min(hc, 0ll + x[i] - s[i]);
	// 			hc -= d;
	// 			s[i] += d;
	// 			ans += d;
	// 		}
	// 	} else if (hc > lc) {
	// 		for (int i : low) {
	// 			s[i] = x[i];
	// 		}
	// 		hc -= lc;
	// 		for (int i : hi) {
	// 			if (lc == 0) break;
	// 			int d = min(lc, 0ll + s[i] - y[i]);
	// 			lc -= d;
	// 			s[i] -= d;
	// 			ans += d;
	// 		}
	// 	}

	// 	vector<int> can;
	// 	long long cc = 0;
	// 	if (lc > 0) {
	// 		for (int i = 1; i <= n; ++i) {
	// 			if (s[i] < y[i]) {
	// 				can.push_back(i);
	// 				cc += 
	// 			}
	// 		}
	// 	}
	// }
}

int main() {
    CPPinput;
	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
