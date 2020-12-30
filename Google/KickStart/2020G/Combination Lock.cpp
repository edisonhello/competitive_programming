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

template<typename T, typename Q> void Add(vector<T> &bit, int x, Q v) {
	for (++x; x < (int)bit.size(); x += x & -x) bit[x] += v;
}
template<typename T> T Query(vector<T> &bit, int x) {
	T v = 0;
	for (++x; x; x -= x & -x) v += bit[x];
	return v;
}
template<typename T> T Query(vector<T> &bit, int x, int y) {
	if (x > y) return (T)0;
	return Query(bit, y) - Query(bit, x - 1);
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) v.push_back(v[i] + k);
	vector<int64_t> pre(v.size());
	pre[0] = v[0];
	for (int i = 1; i < 2 * n; ++i) pre[i] = pre[i - 1] + v[i];
	int64_t ans = 1e18;
	PDE(v, pre);
	for (int l = 0, r = n - 1, i = 0; l < n; ++l, ++r) {
		auto Get = [&] (int l, int r, int i) {
			return int64_t(pre[r] - pre[i] - v[i] * 1ll * (r - i) +
				v[i] * 1ll * (i - l) - (i ? pre[i - 1] : (int64_t)0) + (l ? pre[l - 1] : (int64_t)0));
		};
		if (i < l) i = l;
		int64_t tmp;
		ans = min(ans, tmp = Get(l, r, i));
		PDE(l, i, r, tmp);
		while (i < r && Get(l, r, i + 1) <= tmp) {
			tmp = Get(l, r, i + 1);
			ans = min(ans, tmp);
			PDE(l, i, r, tmp);
			++i;
		}
		PDE(l, i, r);
	}
	cout << ans << endl;
}

int main() {
    CPPinput;
	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
