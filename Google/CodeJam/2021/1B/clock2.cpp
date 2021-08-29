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
const ll Z = 360 * 12 * 10000000000;

ll norm(ll x) { 
	return (x % Z + Z) % Z;
}


vector<ll> qq(vector<ll> v) {
	ll hr = 0, mn = norm(v[1] - v[0]), se = norm(v[2] - v[0]);
	for (int H = 0; H < 12; ++H) {
		for (int M = 0; M < 60; ++M) {
			for (int S = 0; S < 60; ++S) {
				// ll r_hr = H * 60 * 60 * 1000000000 + M * 60 * 1000000000 + S * 1000000000;
				// ll r_mn = H * Z + M * 60 * 1000000000 * 12 + S * 1000000000 * 12;
				// ll r_se = (H * 60 + M) * Z + S * 1000000000 * 720;
				ll r_hr = H * 60ll * 60 * 1000000000 + M * 60ll * 1000000000 + S * 1000000000ll;
				ll r_mn = M * 60ll * 1000000000 * 12 + S * 1000000000ll * 12;
				ll r_se = S * 1000000000ll * 720;
				r_mn = norm(r_mn - r_hr);
				r_se = norm(r_se - r_hr);

				if (H == 6 && M == 30 && S == 0) {
					PDE(H, M, S, hr, mn, se, r_mn, r_se);
				}

				if ((mn - r_mn) % 11 == 0) {
					ll x = (mn - r_mn) / 11;
				//	PDE(v, H, M, S, x);
					if (x >= 0 && x < 1000000000) {
						if ((r_se + 719 * x) % Z == se) return vector<ll>{H, M, S, x};
					}
				}
				if ((mn + Z - r_mn) % 11 == 0) {
					ll x = (mn + Z - r_mn) / 11;
				//	PDE(v, H, M, S, x);
					if (x >= 0 && x < 1000000000) {
						if ((r_se + 719 * x) % Z == se) return vector<ll>{H, M, S, x};
					}
				}
			}
		}
	}
	return vector<ll>{};
}

void solve() {
	vector<ll> v(3);
	for (int i = 0; i < 3; ++i) cin >> v[i];

	sort(v.begin(), v.end());
	do {
		auto ans = qq(v);
		if (ans.size()) {
			cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
			return;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << -1 << endl;
}

void test() {
	ll H = rand() % 12;
	ll M = rand() % 60;
	ll S = rand() % 60;
	ll N = rand() % 1000000000;
	ll tn = N + S * 1000000000 + M * 1000000000 * 60 + H * 60 * 60 * 1000000000;
	ll a = tn % Z;
	ll b = tn * 12 % Z;
	ll c = tn * 720 % Z;
	cout << a << ' ' << b << ' ' << c << endl;
}

int main() {
	srand(time(0) * clock());
	// test();

    CPPinput;
	int t; cin >> t; 
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
