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

struct node {
	node *l, *r;
	long long mn;
	void pull() { mn = min(l->mn, r->mn); }
	node() : l(0), r(0), mn(1000000000000000000) {}
};

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
	if (l == r) return;
	build(now->l = new node(), l, mid);
	build(now->r = new node(), mid + 1, r);
}

void modify(node *now, int l, int r, int x, long long v) {
	if (l == r) {
		now->mn = min(now->mn, v);
		return;
	}
	if (x <= mid) modify(now->l, l, mid, x, v);
	else modify(now->r, mid + 1, r, x, v);
	now->pull();
}

long long query(node *now, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) return 1000000000000000000;
	if (ql <= l && r <= qr) return now->mn;
	return min(query(now->l, l, mid, ql, qr), query(now->r, mid + 1, r, ql, qr));
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> c(n + 1);
	for (int i = 1; i <= n; ++i) cin >> c[i];

	node *root;
	build(root = new node(), 0, n);

	modify(root, 0, n, 1, 0);
	for (int i = 2; i <= n; ++i) if (c[i]) {
		modify(root, 0, n, i, query(root, 0, n, max(0, i - m), i - 1) + c[i]);
	}

	long long z = query(root, 0, n, n - m, n);
	if (z >= 1000000000000000000) cout << -1 << '\n';
	else cout << z << '\n';
}

int main() {
    CPPinput;
	int t, T = 0; cin >> t; while (t--) {
		cout << "Case #" << (++T) << ": ";
		solve();
	}
}
