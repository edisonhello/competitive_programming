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

pair<int, int> GetDir(pair<int, int> a, pair<int, int> b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	int g = __gcd(dx, dy);
	dx /= g, dy /= g;
	if (dx < 0 || (dx == 0 && dy < 0)) dx *= -1, dy *= -1;
	return make_pair(dx, dy);
}

void Solve() {
	int n; cin >> n;
	vector<pair<int, int>> ps(n);
	for (int i = 0; i < n; ++i) cin >> ps[i].first >> ps[i].second;
	vector<pair<int, int>> dir;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			dir.emplace_back(GetDir(ps[i], ps[j]));
		}
	}
	sort(dir.begin(), dir.end());
	dir.resize(unique(dir.begin(), dir.end()) - dir.begin());

	int mx = 1;
	for (auto &d : dir) {
		vector<int> djs(n);
		iota(djs.begin(), djs.end(), 0);
		
		function<int(int)> F = [&] (int x) { return djs[x] == x ? djs[x] : djs[x] = F(djs[x]); };
		auto U = [&] (int x, int y) { djs[F(x)] = F(y); };

		for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
			if (GetDir(ps[i], ps[j]) == d) U(i, j);
		}

		vector<int> cnt(n, 0);
		for (int i = 0; i < n; ++i) ++cnt[F(i)];

		vector<int> lanes;
		for (int i = 0; i < n; ++i) if (F(i) == i) lanes.push_back(cnt[F(i)]);

		// int one = 0, many = 0;
		// for (int i : lanes) {
		// 	if (i > 1) many += i;
		// 	else ++one;
		// }
		// mx = max(mx, many + min(2, one));

		// auto QAQ = [&] (vector<int> v) {
		// 	vector<vector<int>> vv;
		// 	int nn = 0;
		// 	for (auto i : v) {
		// 		vv.emplace_back(vector<int>());
		// 		while (i--) vv.back().push_back(nn++);
		// 	}
		// 	vector<int> nxt(nn, -1);
		// 	vector<int> hole(nn, -1);
		// 	for (auto &v : vv) {
		// 		for (int i = 0; i < (int)v.size() - 1; ++i) nxt[v[i]] = v[i + 1];
		// 	}

		// 	int mx = 0;
		// 	auto Dfs = [&] (auto self, vector<bool> &used) -> void {
		// 		int fre = 0;
		// 		for (bool i : used) fre += !i;
		// 		for (int st = 0; st < (int)used.size(); ++st) {
		// 			{
		// 				int now = st;
		// 				vector<bool> touched(used.size(), false);
		// 				touched[now] = true;
		// 				int it = used.size() * 10;
		// 				while (it--) {
		// 					if (nxt[now] == -1) break;
		// 					now = nxt[now];
		// 					touched[now] = 1;
		// 					if (hole[now] == -1) break;
		// 					now = hole[now];
		// 					touched[now] = 1;
		// 				}
		// 				int c = 0;
		// 				for (bool i : touched) c += i;
		// 				mx = max(mx, c);
		// 			}
		// 			{
		// 				int now = st;
		// 				vector<bool> touched(used.size(), false);
		// 				touched[now] = true;
		// 				int it = used.size() * 10;
		// 				while (it--) {
		// 					if (hole[now] == -1) break;
		// 					now = hole[now];
		// 					touched[now] = 1;
		// 					if (nxt[now] == -1) break;
		// 					now = nxt[now];
		// 					touched[now] = 1;
		// 				}
		// 				int c = 0;
		// 				for (bool i : touched) c += i;
		// 				mx = max(mx, c);
		// 			}
		// 		}

		// 		for (int i = 0; i < (int)used.size(); ++i) if (used[i] == 0) {
		// 			for (int j = i + 1; j < (int)used.size(); ++j) if (used[j] == 0) {
		// 				used[i] = used[j] = 1;
		// 				hole[i] = j, hole[j] = i;
		// 				self(self, used);
		// 				used[i] = used[j] = 0;
		// 				hole[i] = -1, hole[j] = -1;
		// 			}
		// 		}
		// 	};
		// 	vector<bool> used(nn, false);
		// 	Dfs(Dfs, used);

		// 	return mx;
		// };

		auto QAQ = [&] (vector<int> v) {
			int ans = 0;
			for (int i : v) if (i == 1) {
				++ans;
				break;
			}
			vector<int> vv;
			for (int i : v) if (i != 1) vv.push_back(i);
			v = vv;
		};

		mx = max(mx, QAQ(lanes));
	}
	cout << mx << '\n';
}

int main() {
    CPPinput;
	int t; cin >> t; for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		Solve();
	}

}
