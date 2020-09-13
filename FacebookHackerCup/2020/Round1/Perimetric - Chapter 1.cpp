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

vector<int> input(int n, int k) {
	vector<int> l(n + 1, 0);
	for (int i = 1; i <= k; ++i) cin >> l[i];
	int al, bl, cl, dl; cin >> al >> bl >> cl >> dl;
	for (int i = k + 1; i <= n; ++i) l[i] = (1ll * al * l[i - 2] + 1ll * bl * l[i - 1] + cl) % dl + 1;
	return l;
}

void solve() {
	int n, k, w; cin >> n >> k >> w;
	vector<int> l = input(n, k);
	vector<int> h = input(n, k);

	l[0] = -w - 1;

	PDE(n, k, w, l, h);

	auto useless = [&] (int big, int small, int come) {
		if (l[small] <= l[big] + w && l[come] <= l[big] + w && h[come] >= h[small]) return true;
		return false;
	};

	auto calcmore = [&] (int prev, int come) {
		if (l[prev] + w < l[come]) return (w * 2ll + h[come] * 2ll) % mod;
		int morew = (l[come] - l[prev]) * 2ll % mod;
		if (h[come] > h[prev]) morew = (morew + 2ll * (h[come] - h[prev])) % mod;
		return 1ll * morew;
	};

	vector<int> eff = {0};
	vector<int> pre = {0};
	for (int i = 1; i <= n; ++i) {
		while (eff.size() > 1u && useless(eff[eff.size() - 2], eff[eff.size() - 1], i))
			eff.pop_back();
		pre.push_back((pre[eff.back()] + calcmore(eff.back(), i)) % mod);
		eff.push_back(i);
		PDE(i, eff, pre);
	}

	int a = 1;
	for (int i = 1; i <= n; ++i) a = 1ll * a * pre[i] % mod;
	cout << a << '\n';
}

int main() {
    CPPinput;
	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
