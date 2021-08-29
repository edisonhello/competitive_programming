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

int min_fac[1000002];
void init() {
	for (int i = 2; i <= 1000000; ++i) {
		if (min_fac[i]) continue;
		min_fac[i] = i;
		for (int j = i * 2; j <= 1000000; j += i) {
			min_fac[j] = i;
		}
	}
}

vector<vector<int>> facs(1000002);
vector<int>& get_facs(int x) {
	if (facs[x].size()) return facs[x];

	vector<int> &fac = facs[x];
	int ox = x;

	map<int, int> cnt;
	while (x > 1) {
		cnt[min_fac[x]]++;
		x /= min_fac[x];
	}

	auto dfs = [&] (auto dfs, int now, auto it) {
		if (it == cnt.end()) {
			fac.push_back(now);
			return;
		}

		for (int i = 0; i <= it->second; ++i) {
			dfs(dfs, now, next(it));
			now *= it->first;
		}
	};

	dfs(dfs, 1, cnt.begin());

	sort(fac.begin(), fac.end());
	reverse(fac.begin(), fac.end());

	return fac;

}

map<pair<int, int>, int> rec;
int dfs(int e_left, int e_prev) {
	if (e_left == 0) return 0;
	if (e_left < 3) return -1000000;

	auto it = rec.find(make_pair(e_left, e_prev));
	if (it != rec.end()) return it->second;

	auto &facs = get_facs(e_prev);
	int ans = -1000000;
	for (int i : facs) {
		if (i <= e_left / 2) break;
		else if (i <= e_left && i != e_prev) ans = max(ans, dfs(e_left - i, i) + 1);
	}

	// cerr<< "get to dfs " << e_left << ' ' << e_prev << " = " << ans << endl;


	return rec[make_pair(e_left, e_prev)] = ans;
}

void solve() {
	init();

	int n; cin >> n;

	// int ans = 1;
	// for (int i = n - 1; i >= n / 2; --i) {
	// 	ans = max(ans, dfs(n - i, i) + 1);
	// }
	
	vector<int> rec(n + 2, 0);
	vector<int> vis(n + 2, false);
	auto dfs = [&] (auto dfs, int now) {
		if (now == 0) return 0;
		if (now == 1) return -1000000;
		if (now < 0) return -1000000;

		if (vis[now]) return rec[now];
		vis[now] = 1;

		auto &v = get_facs(now);
		int mx = 0;
		for (int i : v) if (i != 1) mx = max(mx, dfs(dfs, now / i - 1) + 1);
		return rec[now] = mx;
	};
	
	auto &v = get_facs(n);
	int mx = 0;
	for (int i : v) if (i >= 3) mx = max(mx, dfs(dfs, n / i - 1) + 1);

	cout << mx << endl;
}

int main() {
    CPPinput;
	int t; cin >> t; 
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
