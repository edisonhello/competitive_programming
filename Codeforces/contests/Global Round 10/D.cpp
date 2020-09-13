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

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	bool diff = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != s[i - 1]) {
			diff = 1;
		}
	}

	if (!diff) {
		cout << (n + 2) / 3 << '\n';
		return;
	}

	vector<bool> vis(n, false);

	int ans = 0;

	auto next = [&] (int x) { return x == n - 1 ? 0 : x + 1; };
	auto prev = [&] (int x) { return x == 0 ? n - 1 : x - 1; };
	auto calc = [&] (int l, int r) {
		if (l <= r) return r - l + 1;
		return n - 1 - l + 1 + r - 0 + 1;
	};

	for (int i = 0; i < n; ++i) if (!vis[i]) {
		int l = 0, r = 0;
		if (s[i] == 'L') {
			int rr;
			for (rr = i; s[rr] == 'L'; rr = rr == n - 1 ? 0 : rr + 1);
			rr = rr == 0 ? n - 1 : rr - 1;
			int ll;
			for (ll = i; s[ll] == 'L'; ll = ll == 0 ? n - 1 : ll - 1);
			ll = ll == n - 1 ? 0 : ll + 1;

			int rrr = prev(ll);
			int lll = rrr;
			for (; s[lll] == 'R'; lll = prev(lll));
			lll = next(lll);

			ans += (calc(ll, rr)) / 3 + (calc(lll, rrr)) / 3;

			if (lll <= rrr) for (int i = lll; i <= rrr; ++i) vis[i] = 1;
			else {
				for (int i = lll; i < n; ++i) vis[i] = 1;
				for (int i = 0; i <= rrr; ++i) vis[i] = 1;
			}
			if (ll <= rr) for (int i = ll; i <= rr; ++i) vis[i] = 1;
			else {
				for (int i = ll; i < n; ++i) vis[i] = 1;
				for (int i = 0; i <= rr; ++i) vis[i] = 1;
			}
			PDE("L", i, ll, rr, lll, rrr, ans);
		} else {
			int ll = i, rr = i;
			while (s[next(rr)] == 'R') rr = next(rr);
			while (s[prev(ll)] == 'R') ll = prev(ll);
			int lll = next(rr), rrr = lll;
			while (s[next(rrr)] == 'L') rrr = next(rrr);

			ans += (calc(ll, rr)) / 3 + (calc(lll, rrr)) / 3;

			if (lll <= rrr) for (int i = lll; i <= rrr; ++i) vis[i] = 1;
			else {
				for (int i = lll; i < n; ++i) vis[i] = 1;
				for (int i = 0; i <= rrr; ++i) vis[i] = 1;
			}
			if (ll <= rr) for (int i = ll; i <= rr; ++i) vis[i] = 1;
			else {
				for (int i = ll; i < n; ++i) vis[i] = 1;
				for (int i = 0; i <= rr; ++i) vis[i] = 1;
			}

			PDE("R", i, ll, rr, lll, rrr, ans);
		}
	}

	cout << ans << endl;
}

int main() {
    CPPinput;
	int t; cin >> t; while (t--) solve();
}
