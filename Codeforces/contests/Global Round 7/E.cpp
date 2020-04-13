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


int main() {
    CPPinput;
	int n; cin >> n;
	vector<int> p(n + 1), q(n + 1);
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) cin >> q[i];

	vector<int> seg(4 * n + 87), at(4 * n + 87);

	auto Pull = [&] (int o) {
		if (seg[o * 2 + 1] < seg[o * 2 + 2]) seg[o] = seg[o * 2 + 1], at[o] = at[o * 2 + 1];
		else seg[o] = seg[o * 2 + 2], at[o] = at[o * 2 + 2];
	};
	
#define mid ((l + r) >> 1)
	function<void(int, int, int)> Build = [&] (int o, int l, int r) {
		if (l == r) {
			seg[o] = p[l];
			at[o] = l;
			return;
		}
		Build(o * 2 + 1, l, mid);
		Build(o * 2 + 2, mid + 1, r);
		Pull(o);
	};

	function<void(int, int, int, int, int)> Modify = [&] (int o, int l, int r, int x, int v) {
		if (l == r) {
			seg[o] = v;
			return;
		}
		if (x <= mid) Modify(o * 2 + 1, l, mid, x, v);
		else Modify(o * 2 + 2, mid + 1, r, x, v);
		Pull(o);
	};

	function<pair<int, int>(int, int, int, int, int)> Query = [&] (int o, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return make_pair(INT_MAX, 0);
		if (ql <= l && r <= qr) return make_pair(seg[o], at[o]);
		return min(Query(o * 2 + 1, l, mid, ql, qr), Query(o * 2 + 2, mid + 1, r, ql, qr));
	};
#undef mid

	vector<int> anss;
	set<int> st;
	for (int i = n; i >= 1; --i) {
		
	}
}
