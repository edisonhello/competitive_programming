#pragma GCC optimize("O3")
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

auto cmp = [] (double x, double y) {
	return abs(x - y) > 1e-9 ? x < y : 0;
};

int p[1005][2];
map<double, vector<pair<int, int>>, decltype(cmp)> dd(cmp);
set<pair<int, int>> same;

double dist(int i, int j) {
	return hypot(p[i][0] - p[j][0], p[i][1] - p[j][1]);
}

set<int> gg[1005];
set<int> ggg[1005];

//
int djs[1005];
int a[1005];
int grp[1005];
double ddddd[1005][1005];

void dfs(int now, int cc) {
	grp[now] = cc;
	for (int i : ggg[now]) if (!grp[i]) dfs(i, -cc);
}

int F(int x) {
	return x == djs[x] ? x : djs[x] = F(djs[x]);
}

inline void U(int x, int y) {
	djs[F(x)] = F(y);
}

int main() {
    CPPinput;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i][0] >> p[i][1];	
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) ddddd[i][j] = dist(i, j);
	for (int i = 1; i <= n; ++i) djs[i] = i;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) a[j] = j;
		sort(a + 1, a + 1 + n, [&] (const int x, const int y) { return ddddd[i][x] < ddddd[i][y]; });

		for (int j = 3; j <= n; ++j) {
			PDE(i, j, ddddd[a[j]][i], ddddd[a[j - 1]][i]);
			if (abs(ddddd[a[j]][i] - ddddd[a[j - 1]][i]) < 1e-9) {
				U(a[j], a[j - 1]);
				PDE("u", a[j], a[j - 1]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dd[ddddd[i][j]].emplace_back(i, j);
		}
	}
	PDE(dd);
	for (auto &p : dd) {
		bool _same = 0;
		for (int j = 1; j < (int)p.second.size(); ++j) {
			if (F(p.second[j - 1].first) == F(p.second[j - 1].second)) 
				U(p.second[j].first, p.second[j].second), _same = 1;
		}
		reverse(p.second.begin(), p.second.end());
		for (int j = 1; j < (int)p.second.size(); ++j) {
			if (F(p.second[j - 1].first) == F(p.second[j - 1].second)) 
				U(p.second[j].first, p.second[j].second), _same = 1;
		}
		if (!_same) {
			for (int j = 1; j < (int)p.second.size(); ++j) {
				same.insert(minmax(F(p.second[j].first), F(p.second[j].second)));
				same.insert(minmax(F(p.second[j - 1].first), F(p.second[j - 1].second)));
			}
		}
	}


	for (auto &pp : same) {
		ggg[pp.first].insert(pp.second);
		ggg[pp.second].insert(pp.first);
	}


	int st = 1;
	for (int i = 1; i <= n; ++i) if (i == F(i) && !grp[i]) {
		dfs(i, st);
		st *= -1;
	}

	vector<int> ans;
	for (int i = 1; i <= n; ++i) if (grp[F(i)] == 1)
		ans.insert(i);


	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
	cout << endl;

}
