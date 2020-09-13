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

vector<pair<int, int>> g[200005];
vector<pair<int, int>> gg[12][12];
bitset<200005> in[22][22];
bool no[22][22][22][22];
bool no2[22][22];

int main() {
    CPPinput;
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
	}
	for (int i = 1; i <= n; ++i) {
		sort(g[i].begin(), g[i].end(), [&] (const auto &e, const auto &f) -> bool {
			return e.second < f.second;
		});
		for (int j = 0; j < (int)g[i].size(); ++j) {
			gg[g[i].size()][j + 1].push_back(g[i][j]);
			if (in[g[i].size()][j + 1][g[i][j].first]) {
				no2[g[i].size()][j + 1] = 1;
			} else {
				in[g[i].size()][j + 1][g[i][j].first] = 1;
			}
		}
	}

	for (int i = 1; i <= k; ++i) for (int j = 1; j <= i; ++j) {
		PDE(i, j, gg[i][j]);
		for (int x = i + 1; x <= k; ++x) for (int y = 1; y <= x; ++y) {
			// PDE(i, j, x, y, gg[i][j], gg[x][y]);
			if ((in[i][j] & in[x][y]).count()) {
				no[i][j][x][y] = no[x][y][i][j] = 1;
				PDE("no", i, j, x, y);
			}
		}
	}

	int ans = 0;
	auto dfs = [&] (auto self, int now, vector<int> &took) -> void {
		if (now > k) {
			++ans;
			PDE(now, took);
			return;
		}
		for (int i = 1; i <= now; ++i) {
			bool ok = !no2[now][i];
			for (int j = 1; j < now; ++j) if (no[j][took[j]][now][i]) ok = 0;
			if (ok) {
				took.push_back(i);
				self(self, now + 1, took);
				took.pop_back();
			}
		}
	};

	vector<int> took = {0};
	dfs(dfs, 1, took);

	cout << ans << endl;
}
