// #pragma GCC optimize("no-stack-protector")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <utility>
#include <vector>

#if __cplusplus >= 201103L
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
#define RZUNI(x)              \
    sort(x.begin(), x.end()), \
	x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) \
    freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
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
#include "/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() \
    printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...)                                           \
    printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), \
	printf(__VA_ARGS__), puts(""), fflush(stdout)
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

void JIZZ(string output = "") {
  cout << output;
  exit(0);
}

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9 + 7;

int ca[12], cb[12];

tuple<int, string, string> go() {
	vector<int> ca(::ca, ::ca + 12);
	vector<int> cb(::cb, ::cb + 12);
	PDE(ca, cb);
	string a, b;
	for (int i = 8; i >= 1; --i) {
		for (int j = 1; j <= 8; ++j) {
			if (i + j < 9) continue;
			while (true) {
				if (ca[i] <= 0) break;;
				if (cb[j] <= 0) break;;
				--ca[i];
				--cb[j];
				a += char('0' + i);
				b += char('0' + j);
			}
		}
	}
	{
		for (int j = 1; j <= 8; ++j) {
			while (ca[9] > 0 && cb[j] > 0) {
				--ca[9];
				--cb[j];
				a += '9';
				b += char('0' + j);
			}
		}

		for (int j = 1; j <= 8; ++j) {
			while (cb[9] > 0 && ca[j] > 0) {
				--cb[9];
				--ca[j];
				b += '9';
				a += char('0' + j);
			}
		}
	}
	PDE(a, b);
	while (ca[9] > 0) {
		a += '9';
		--ca[9];
	}
	PDE(a, b);
	while (cb[9] > 0) {
		b += '9';
		--cb[9];
	}
	PDE(a, b);
	for (int i = 0; i <= 9; ++i) while (ca[i] > 0) {
		--ca[i];
		a += char('0' + i);
	}
	PDE(a, b);
	for (int i = 0; i <= 9; ++i) while (cb[i] > 0) {
		--cb[i];
		b += char('0' + i);
	}
	PDE(a, b);
	int sum = 0;
	int add = 1;
	for (int i = 0; i < (int)max(a.size(), b.size()); ++i) {
		int ds = add;
		add = 0;
		if (i < (int)a.size()) ds += a[i] - '0';
		if (i < (int)b.size()) ds += b[i] - '0';
		sum += ds % 10;
		add = ds / 10;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	PDE(a, b, sum, add);
	return tuple{sum + add, a, b};
}

void solve() {
	string a, b;
	cin >> a >> b;

	for (char c : a) ++ca[c & 15];
	for (char c : b) ++cb[c & 15];

	tuple<int, string, string> ans(1000000000, a, b);

	for (int i = 0; i <= 9; ++i) {
		if (ca[i]) { 
			--ca[i];
			for (int j = 0; j <= 9; ++j) {
				if (cb[j] && (i + j) >= 10) {
					PDE(i, j);
					--cb[j];
					auto [v, ta, tb] = go();
					ta += char('0' + i);
					tb += char('0' + j);
					ans = min(ans, make_tuple(v, ta, tb));
					// get<0>(ans) = min(get<0>(ans), v + (i + j) % 10);
					++cb[j];
				}
			}
			++ca[i];
		}
	}

	// cout << get<0>(ans) << endl;
	cout << get<1>(ans) << endl;
	cout << get<2>(ans) << endl;

}

int32_t main() {
  CPPinput;
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }

}
