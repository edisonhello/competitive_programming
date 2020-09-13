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
	return vector<int>(l.begin() + 1, l.end());
}

bool check(int n, int m, long long s, vector<int> p, vector<int> q, long long limit) {
	PDE(limit);
	deque<int> dq(q.begin(), q.end());

	for (int i : p) {
		if (dq.empty()) break;
		long long broke = 0;
		long long wl = i, wr = i;
		while (true) {
			if (dq.empty()) break;

			if (dq.front() < i) { 
				if (wl >= dq.front()) {
					wl = dq.front();
				}
				if (wr - wl + (wl == i || wr == i ? 0 : min(i - wl, wr - i)) + s * (broke + 1) > limit) break;
				dq.pop_front();
				++broke;
			} else {
				wr = dq.front();
				if (wr - wl + (wl == i || wr == i ? 0 : min(i - wl, wr - i)) + s * (broke + 1) > limit) break;
				dq.pop_front();
				++broke;
			}
			PDE(i, broke, wl, wr, dq);
		}
		PDE(i, dq);
	}

	return dq.empty();
}

void solve() {
	int n, m, k, s; cin >> n >> m >> k >> s;
	vector<int> p = input(n, k);
	vector<int> q = input(m, k);

	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	PDE(n, m, k, s, p, q);

	// PDE(check(n, m, s, p, q, 8));
	// PDE(check(n, m, s, p, q, 9));
	// return;

	long long L = s, R = 1e18;
	while (L < R) {
		long long M = (L + R) >> 1;
		if (check(n, m, s, p, q, M)) R = M;
		else L = M + 1;
	}
	cout << L << '\n';
}

int main() {
    CPPinput;
	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
