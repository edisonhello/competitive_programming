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
	int n, m; cin >> n >> m;
	string s; cin >> s; s = " " + s;

	vector<int> pre(n + 1, 0);
	for (int i = 1; i <= n; ++i) s[i] = s[i] == 'W' ? 1 : 2;
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + s[i];
	vector<pair<int, int>> ans(2000010, pair<int, int>(-1, -1));

	bool all2 = true;
	for (int i = 1; i <= n; ++i) if (s[i] == 1) all2 = false;

	if (all2) {
		for (int i = 1; i <= n; ++i) ans[i * 2] = make_pair(1, i);
	} else {
		int l2 = 0, r2 = 0;
		while (s[l2 + 1] == 2) ++l2;
		while (s[n - r2] == 2) ++r2;

		auto Add = [&] (int l, int r) {
			if (l > r) return;
			assert(l >= 1 && r <= n);
			PDE(l, r, pre[r] - pre[l - 1]);
			ans[pre[r] - pre[l - 1]] = make_pair(l, r);
		};

		PDE(l2, r2);
		
		if (l2 > r2) {
			for (int l = 1; l <= n - r2; ++l) Add(l, n - r2), Add(l, n - r2 - 1);
			for (int r = n - r2; r <= n; ++r) Add(1, r);
		} else {
			for (int r = l2; r <= n; ++r) Add(l2 + 1, r), Add(l2 + 2, r);
			for (int l = 1; l <= l2; ++l) Add(l, n);
		}
	}

	while (m--) {
		int x; cin >> x;
		if (ans[x].first == -1) cout << "NIE" << '\n';
		else cout << ans[x].first << ' ' << ans[x].second << '\n';
	}
}
