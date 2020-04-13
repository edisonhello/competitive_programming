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

vector<int> g[100005];
int dp[100005][2]; // [root, touch]
int sons[100005];

void dfs(int now, int pa) {
	dp[now][0] = 1;
	for (int i : g[now]) if (i != pa) {
		dfs(i, now);
		dp[now][0] = max(dp[now][0], 1 + dp[i][1]);
		++sons[now];
	}

	int mx = sons[now];
	for (int i : g[now]) if (i != pa) {
		mx = max(mx, sons[now] - 1 + max(dp[i][1], dp[i][0]));
	}

	dp[now][1] = mx;

	PDE(now, dp[now][0], dp[now][1]);
}

int ans;

void dfs2(int now, int pa, int up0, int up1) {
	PDE(now, pa, up0, up1);

	ans = max(max(dp[now][0], dp[now][1]), ans);
	if (pa) {
		ans = max(ans, 1 + up1); // be 0
		ans = max(ans, sons[now] + max(up0, up1)); // be 1
	}

	vector<int> gg;
	for (int i : g[now]) if (i != pa) gg.push_back(i);

	vector<int> pre1mx(gg.size(), 0), suf1mx(gg.size(), 0);
	for (int i = 0; i < (int)gg.size(); ++i) {
		pre1mx[i] = 1 + dp[gg[i]][1];
		suf1mx[i] = pre1mx[i];
		if (i) pre1mx[i] = max(pre1mx[i], pre1mx[i - 1]);
	}
	for (int i = (int)gg.size() - 2; i >= 0; --i) 
		suf1mx[i] = max(suf1mx[i], suf1mx[i + 1]);

	vector<int> pre01mx(gg.size(), 0), suf01mx(gg.size(), 0);
	for (int i = 0; i < (int)gg.size(); ++i) {
		pre01mx[i] = max(dp[gg[i]][0], dp[gg[i]][1]);
		suf01mx[i] = pre01mx[i];
		if (i) pre01mx[i] = max(pre01mx[i], pre01mx[i - 1]);
	}
	for (int i = (int)gg.size() - 2; i >= 0; --i) 
		suf01mx[i] = max(suf01mx[i], suf01mx[i + 1]);

	int sons_ = (int)g[now].size() - 1;

	for (int i = 0; i < (int)gg.size(); ++i) {
		PDE(gg[i], sons_ - 1 + max(up0, up1));
		dfs2(gg[i], now, max(1 + up1, max(i ? pre1mx[i - 1] : -10000000, i == (int)gg.size() - 1 ? -10000000 : suf1mx[i + 1])),
					     max(sons_ - 1 + max(up0, up1), sons_ - 1 + max(i ? pre01mx[i - 1] : -10000000, i == (int)gg.size() - 1 ? -10000000 : suf01mx[i + 1])));
	}


}

int main() {
    CPPinput;
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);

	dfs2(1, 0, 0, 0);
	cout << ans << endl;
}
