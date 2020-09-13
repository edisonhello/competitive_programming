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

long long calc(vector<int> &v, int l, int k) {
	long long res = 0;
	multiset<int> u, d;

	auto add = [&] (int x) {
		PDE("add", x, u, d);
		if ((int)u.size() < k) u.insert(x);
		else {
			if (x < *u.begin()) {
				d.insert(x);
			} else {
				u.insert(x);
				x = *u.begin();
				u.erase(u.begin());
				d.insert(x);
			}
		}
		PDE("add", x, u, d);
	};

	auto get = [&] () {
		PDE("get");
		return *u.begin();
	};

	auto remove = [&] (int x) {
		PDE("remove", x, u, d);
		if (x < *u.begin()) {
			d.erase(d.find(x));
		} else {
			u.erase(u.find(x));
			if (d.size()) {
				x = *prev(d.end());
				d.erase(prev(d.end()));
				u.insert(x);
			}
		}
		PDE("remove", x, u, d);
	};

	int n = v.size();

	for (int i = 0; i < l - 1; ++i) {
		PDE(i);
		add(v[i]);
	}

	for (int i = l - 1; i < n; ++i) {
		PDE(i);
		add(v[i]);
		res += get();
		remove(v[i - l + 1]);
	}

	return res;
}

void solve() {
	int n, l, k; cin >> n >> l >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	vector<int> vv = v;

	vector<int> w(n, 0);
	for (int j = 1; j <= l; ++j) {
		for (int i = l; i < n; i += l) {
			if (i - j >= n) continue;
			w[i - j] = vv.back();
			vv.pop_back();
		}
	}

	PDE(w);

	cout << calc(w, l, k) << ' ';

	w = vector<int>(n, 0);
	vv = v;
	reverse(vv.begin(), vv.end());
	k = l + 1 - k;
	for (int j = 1; j <= l; ++j) {
		for (int i = l; i < n; i += l) {
			if (i - j >= n) continue;
			w[i - j] = vv.back();
			vv.pop_back();
		}
	}

	cout << calc(w, l, l + 1 - k) << '\n';
}

int main() {
    CPPinput;
	int t; cin >> t; while (t--) solve();
}
