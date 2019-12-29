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

void find(int sum, int xr) {
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (__lg(i) > __lg(j)) continue;
			if ((sum + j) == (xr ^ i) * 2) {
				cout << "xor " << bitset<10>(i) << ", add " << bitset<10>(j) << endl;
				return;
			}
		}
	}
	assert(0);
}

int main() {
    CPPinput;
	// for (int i = 0; i <= 10; ++i) {
	// 	for (int j = 0; j <= 10; ++j) {
	// 		cout << "sum = " << bitset<10>(i) << ", xor = " << bitset<10>(j) << ", ans = ";
	// 		find(i, j);
	// 	}
	// }
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		ll sum = 0;
		ll xr = 0;
		while (n--) {
			int t; cin >> t;
			sum += t;
			xr ^= t;
		}
		ll x = 0, y = 0, z = 0;
		ll os = sum, ox = xr;
		PDE(os, ox);
		auto add = [&] (ll w) { sum += w, xr ^= w; };
		if (sum & 1) {
			add(1);
			z = 1;
		}
		for (int i = 0; i < 54; ++i) {
			if ((xr & (1ll << i))) {
				if (sum & (1ll << (i + 1))) {
					PDE(1);
				} else {
					x ^= 1ll << i;
					y ^= 1ll << i;
					add(1ll << i);
					add(1ll << i);
					PDE(2);
				}
			} else {
				if (sum & (1ll << (i + 1))) {
					x ^= 1ll << i;
					y ^= 1ll << i;
					add(1ll << i);
					add(1ll << i);
					PDE(3);
				} else {
					PDE(4);
				}
			}
		}
		if ((os + x + y + z) != (ox ^ x ^ y ^ z) * 2) {
			z ^= 1ll << __lg(sum);
			add(1ll << __lg(sum));
		}
		cout << 3 << '\n' << x << ' ' << y << ' ' << z << endl;
		assert((os + x + y + z) == (ox ^ x ^ y ^ z) * 2);
	}
}
