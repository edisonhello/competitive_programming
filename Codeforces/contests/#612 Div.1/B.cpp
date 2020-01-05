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

vector<int> g[2005];
int val[2005];
int c[2005];
int sz[2005];
// int mx[2005];
// 
// void dfs2(int now, int mx, int off) {
// 	if (c[now] >= mx) c[now] += off;
// 	for (int i : g[now]) {
// 		dfs2(i, mx, off);
// 	}
// }
// 
// void dfs1(int now) {
// 	int chs = 0;
// 	for (int i : g[now]) {
// 		dfs1(i);
// 		chs += mx[i];
// 	}
// 	if (chs < c[now]) {
// 		cout << "NO" << endl;
// 		exit(0);
// 	}
// 	int cur = 0;
// 	for (int i : g[now]) {
// 		if (mx[i] + cur > c[now]) {
// 			
// 		} else {
// 			cur += mx[i];
// 		}
// 	}
// 	val[now] = c[now];
// 	mx[now] = chs + 1;
// }

void dfs1(int now) {
	sz[now] = 1;
	for (int i : g[now]) {
		dfs1(i);
		sz[now] += sz[i];
	}
}

void dfs2(int now, vector<int> &set) {
	if (c[now] >= (int)set.size()) {
		cout << "NO" << endl;
		exit(0);
	}
	val[now] = set[c[now]];
	set.erase(set.begin() + c[now]);
	for (int i : g[now]) {
		vector<int> give(set.begin(), set.begin() + sz[i]);
		set.erase(set.begin(), set.begin() + sz[i]);
		dfs2(i, give);
	}
}

int main() {
    CPPinput;
	int n; cin >> n;
	int root;
	for (int i = 1; i <= n; ++i) {
		int p; cin >> p >> c[i];
		if (p == 0) root = i;
		else g[p].push_back(i);
	}

	dfs1(root);
	vector<int> ok(n);
	iota(ok.begin(), ok.end(), 1);
	dfs2(root, ok);

	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) cout << val[i] << ' ';
	cout << endl;
}
