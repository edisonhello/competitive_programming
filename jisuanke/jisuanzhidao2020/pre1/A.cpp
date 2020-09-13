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

string mp[30];
int cnt[666];

int main() {
    CPPinput;
	int n = 25, m = 25;
	for (int i = 0; i < 25; ++i) cin >> mp[i];
	for (int i = 0; i < 25; ++i) for (char j : mp[i]) ++cnt[j];
	char to = cnt['x'] == cnt['o'] ? 'x' : 'o';
	vector<pair<int, int>> p;
	for (int i = 0; i < 25; ++i) for (int j = 0; j < 25; ++j) if (mp[i][j] == '.') {
		mp[i][j] = to;
		bool win = 0;
		auto update = [&] (int v) {
			win |= v == 5;
		};
		auto get = [&] (int x, int y) {
			return mp[x][y] == '.' ? 0 : mp[x][y] == to ? 1 : -1;
		};
		auto check = [&] (int q, int w, int e, int r, int t, int y, int u, int i, int o, int p) {
			update(get(q, w) + get(e, r) + get(t, y) + get(u, i) + get(o, p));
		};
		for (int i = 0; i < 25; ++i) for (int j = 0; j < 25; ++j) {
			if (i + 4 < 25) check(i, j, i + 1, j, i + 2, j, i + 3, j, i + 4, j);
			if (j + 4 < 25) check(i, j, i, j + 1, i, j + 2, i, j + 3, i, j + 4);
			if (i + 4 < 25 && j + 4 < 25) check(i, j, i + 1, j + 1, i + 2, j + 2, i + 3, j + 3, i + 4, j + 4);
			if (i + 4 < 25 && j - 4 >= 0) check(i, j, i + 1, j - 1, i + 2, j - 2, i + 3, j - 3, i + 4, j - 4);
		}
		if (win) p.emplace_back(i, j);
		mp[i][j] = '.';
	}

	sort(p.begin(), p.end());
	for (auto &o : p) cout << o.first << ' ' << o.second << endl;
	if (p.empty()) cout << "tie" << endl;
}
