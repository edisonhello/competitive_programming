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

pair<ll, vector<ll>> find_nm(vector<ll> v) {
	while (true) {
		vector<int> lef;
		for (int i = 0; i < 3; ++i) if (v[i] % 12) lef.push_back(i);
		if (lef.size() == 1u) {
			vector<ll> o;
			for (int i = 0; i < 3; ++i) if (i != lef[0]) o.push_back(v[i]);
			return make_pair(v[lef[0]], o);
		} else if (lef.size() == 2u) {
			vector<ll> o{v[lef[0]], v[lef[1]]};
			for (int i = 0; i < 3; ++i) if (i != lef[0] && i != lef[1]) return make_pair(v[i], o);
		}
		for (auto &i : v) i /= 12;
	}
}

pair<ll, ll> find_mn(vector<ll> v) {
	ll a = v / 12, b = v / 12;
}

void solve() {
	vector<ll> v(3);
	for (int i = 0; i < 3; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	// v[2] -= v[0], v[1] -= v[0], v[0] = 0;

	auto [nm, other] = find_nm(v);
	auto [mn, hr] = find_mn(v);
	PDE(nm, mn, hr);

	// cerr << hr << ' ' << mn << ' ' << nm << endl;

}

void test() {
	ll H = rand() % 12;
	ll M = rand() % 60;
	ll S = rand() % 60;
	ll N = rand() % 10000;
	ll tn = N + S * 1000000000 + M * 1000000000 * 60 + H * 60 * 60 * 1000000000;
	ll a = tn % Z;
	ll b = tn * 12 % Z;
	ll c = tn * 720 % Z;
	cout << a << ' ' << b << ' ' << c << endl;
}

int main() {
	srand(time(0) * clock());
	test();

    CPPinput;
	int t; cin >> t; 
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
