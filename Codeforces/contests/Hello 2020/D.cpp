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

pair<int, int> ev[100005][2];
// int mx[200005 * 4], mn[200005 * 4];
int seg[200005 * 4], tag[200005 * 4];

#define mid ((l + r) >> 1)
void build(int o, int l, int r) {
	seg[o] = tag[o] = 0;
	if (l == r) return;
	build(o * 2 + 1, l, mid);
	build(o * 2 + 2, mid + 1, r);
}

void modify(int o, int l, int r, int ml, int mr) {
	if (r < ml || mr < l) return;
	if (ml <= l && r <= mr) {
		seg[o] = 1;
		tag[o] = 1;
		return;
	}
	if (tag[o]) tag[o * 2 + 1] = tag[o * 2 + 2] = seg[o * 2 + 1] = seg[o * 2 + 2] = 1;
	modify(o * 2 + 1, l, mid, ml, mr);
	modify(o * 2 + 2, mid + 1, r, ml, mr);
	seg[o] = max(seg[o * 2 + 1], seg[o * 2 + 2]);
}

int query(int o, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) return 0;
	if (ql <= l && r <= qr) return seg[o];
	if (tag[o]) tag[o * 2 + 1] = tag[o * 2 + 2] = seg[o * 2 + 1] = seg[o * 2 + 2] = 1;
	return max(query(o * 2 + 1, l, mid, ql, qr),
			   query(o * 2 + 2, mid + 1, r, ql, qr));
}
#undef mid

void meow(int n) {
	// for (int i = 0; i < n; ++i) {
	// 	cerr << ev[i][0].first << ' ' << ev[i][0].second << ' ' << ev[i][1].first << ' ' << ev[i][1].second << endl;
	// }
	build(0, 1, 200000);
	vector<int> u(n), d(n);
	iota(u.begin(), u.end(), 0);
	iota(d.begin(), d.end(), 0);
	sort(u.begin(), u.end(), [&] (const int a, const int b) { return ev[a][1].second < ev[b][1].second; });
	sort(d.begin(), d.end(), [&] (const int a, const int b) { return ev[a][1].first < ev[b][1].first; });
	for (int i = n - 1; i >= 0; --i) {
		int now = u[i];
		int hh = ev[u[i]][1].second;
		while (d.size() && ev[d.back()][1].first > hh) {
			modify(0, 1, 200000, ev[d.back()][0].first, ev[d.back()][0].second);
		// 	cerr << "add " << ev[d.back()][0].first << ' ' << ev[d.back()][0].second << endl;
			d.pop_back();
		}
		// cerr << "query " << ev[now][0].first << ' ' << ev[now][0].second << endl;
		if (query(0, 1, 200000, ev[now][0].first, ev[now][0].second)) {
			cout << "NO" << endl;
			exit(0);
		}
	}
}

int main() {
    CPPinput;
	int n; cin >> n;
	vector<int> v1, v2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) 
			cin >> ev[i][j].first >> ev[i][j].second;
		v1.push_back(ev[i][0].first);
		v1.push_back(ev[i][0].second);
		v2.push_back(ev[i][1].first);
		v2.push_back(ev[i][1].second);
	}

	RZUNI(v1); 
	RZUNI(v2);

	for (int i = 0; i < n; ++i) {
		ev[i][0].first = upper_bound(v1.begin(), v1.end(), ev[i][0].first) - v1.begin();
		ev[i][0].second = upper_bound(v1.begin(), v1.end(), ev[i][0].second) - v1.begin();
		ev[i][1].first = upper_bound(v2.begin(), v2.end(), ev[i][1].first) - v2.begin();
		ev[i][1].second = upper_bound(v2.begin(), v2.end(), ev[i][1].second) - v2.begin();
	}

	meow(n);
	for (int i = 0; i < n; ++i)
		swap(ev[i][0], ev[i][1]);
	meow(n);

// 	for (int i = 0; i < n; ++i) {
// 		ev[i][0].first = 200001 - ev[i][0].first;
// 		ev[i][0].second = 200001 - ev[i][0].second;
// 		ev[i][1].first = 200001 - ev[i][1].first;
// 		ev[i][1].second = 200001 - ev[i][1].second;
// 	}
// 	
// 	meow(n);
// 	for (int i = 0; i < n; ++i)
// 		swap(ev[i][0], ev[i][1]);
// 	meow(n);

	cout << "YES" << endl;
}
