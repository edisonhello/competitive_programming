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

vector<int> input(int n, int k) {
	vector<int> l(n + 1, 0);
	for (int i = 1; i <= k; ++i) cin >> l[i];
	int al, bl, cl, dl; cin >> al >> bl >> cl >> dl;
	for (int i = k + 1; i <= n; ++i) l[i] = (1ll * al * l[i - 2] + 1ll * bl * l[i - 1] + cl) % dl + 1;
	return l;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> l = input(n, k);
	vector<int> w = input(n, k);
	vector<int> h = input(n, k);

	PDE(n, k, l, w, h);

	set<pair<int, int>> covered;

	auto intersect = [&] (pair<int, int> a, pair<int, int> b) {
		return max(0, min(a.second, b.second) - max(a.first, b.first));
	};

	auto iscovered = [&] (int x) {
		auto it = covered.lower_bound(make_pair(x, -1));
		if (it != covered.end() && it->first == x) return true;
		if (it != covered.begin() && prev(it)->second >= x) return true;
		return false;
	};

	auto add = [&] (int l, int r) {
		// WHR();
		int base = r - l;
		int kill = 0;

		while (true) {
			auto it = covered.lower_bound(make_pair(l, -1));
			if (it != covered.end() && it->first <= r) {
				base -= intersect(make_pair(l, r), *it);
				if (l != it->first) ++kill;
				if (it->second < r) ++kill;
				else r = it->second;
				covered.erase(it);
			} else break;
		}
		// WHR();

		auto it = covered.lower_bound(make_pair(l, -1));
		if (it != covered.begin() && prev(it)->second >= l) {
			base -= intersect(make_pair(l, r), *prev(it));
			if (prev(it)->second < r) ++kill;
			else r = prev(it)->second;
			l = min(l, prev(it)->first);
			covered.erase(prev(it));
		}
		// WHR();

		covered.insert(make_pair(l, r));
		return pair(base, kill);
	};

	vector<int> p = {0};

	for (int i = 1; i <= n; ++i) {
		PDE(i, covered);
		PDE(l[i], l[i] + w[i], h[i]);
		int lr = (iscovered(l[i]) ? 0 : 1) + (iscovered(l[i] + w[i]) ? 0 : 1);
		auto info = add(l[i], l[i] + w[i]);
		PDE(lr, info);
		p.push_back(((p.back() + (lr - info.second) * 1ll * h[i] + info.first * 2ll) % mod + mod) % mod);
	}

	PDE(p);

	int a = 1;
	for (int i = 1; i <= n; ++i) a = 1ll * a * p[i] % mod;
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
