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

string mp[1005];
int pre[1005][1005];
int s_r[1005], s_c[1005];
int id[1005][1005];
int djs[1000005];

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }
void U(int x, int y) { 
	djs[F(x)] = F(y); }

int Q(int x1, int x2, int y1, int y2) {
	return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

int main() {
    CPPinput;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> mp[i];
	int nn = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i - 1][j - 1] == '#') {
				pre[i][j] = 1;
			}
			pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			djs[nn] = nn;
			id[i][j] = nn++;
		}
	}

	if (Q(1, n, 1, m) == 0) {
		cout << 0 << endl;
		exit(0);
	}

	vector<int> er, ec;
	for (int i = 1; i <= n; ++i) {
		bool e = 1;
		for (int j = 1; j <= m; ++j) if (Q(i, i, j, j) == 1) e = 0;
		if (e == 1) er.push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		bool e = 1;
		for (int j = 1; j <= n; ++j) if (Q(j, j, i, i) == 1) e = 0;
		if (e == 1) ec.push_back(i);
	}

	if (er.size() && ec.size()) {
		for (int i : er) s_r[i]++;
		for (int i : ec) s_c[i]++;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (Q(i, i, j, j)) {
				int l = j, r = j, u = i, d = i;

				for (int it = 10; it >= 0; --it) {
					int z = 1 << it;
					if (u - z < 1) continue;
					if (Q(u - z, i, j, j) == i - (u - z) + 1) u -= z;
				}
				for (int it = 10; it >= 0; --it) {
					int z = 1 << it;
					if (d + z > n) continue;
					if (Q(i, d + z, j, j) == d + z - i + 1) d += z;
				}
				for (int it = 10; it >= 0; --it) {
					int z = 1 << it;
					if (l - z < 1) continue;
					if (Q(i, i, l - z, j) == j - (l - z) + 1) l -= z;
				}
				for (int it = 10; it >= 0; --it) {
					int z = 1 << it;
					if (r + z > m) continue;
					if (Q(i, i, j, r + z) == r + z - j + 1) r += z;
				}

				if (Q(1, u - 1, j, j) || Q(d + 1, n, j, j) || 
					Q(i, i, 1, l - 1) || Q(i, i, r + 1, m)) {
				} else {
					s_r[i]++;
					s_c[j]++;
				}

				if (i > 1 && Q(i - 1, i - 1, j, j)) U(id[i][j], id[i - 1][j]);
				if (i < n && Q(i + 1, i + 1, j, j)) U(id[i][j], id[i + 1][j]);
				if (j > 1 && Q(i, i, j - 1, j - 1)) U(id[i][j], id[i][j - 1]);
				if (j < m && Q(i, i, j + 1, j + 1)) U(id[i][j], id[i][j + 1]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) if (s_r[i] == 0) {
		cout << -1 << endl;
		exit(0);
	}
	for (int i = 1; i <= m; ++i) if (s_c[i] == 0) {
		cout << -1 << endl;
		exit(0);
	}

	vector<int> cnt;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (Q(i, i, j, j)) {
		cnt.push_back(F(id[i][j]));
	}

	sort(cnt.begin(), cnt.end());
	cout << unique(cnt.begin(), cnt.end()) - cnt.begin() << endl;
}
