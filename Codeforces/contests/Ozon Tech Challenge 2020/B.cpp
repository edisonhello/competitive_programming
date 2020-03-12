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

bool must_del[1005];
bool choosed[1005];

int main() {
    CPPinput;
	string s; cin >> s;
	int n = s.size();
	int sp_at = -1;
	int ansk = 10000000;
	for (int i = 0; i < n + 1; ++i) {
		memset(must_del, 0, sizeof(must_del));
		memset(choosed, 0, sizeof(choosed));
		int cl = 0, cr = 0;
		for (int j = 0; j < i; ++j) if (s[j] == '(') must_del[j] = 1, ++cl;
		for (int j = i; j < n; ++j) if (s[j] == ')') must_del[j] = 1, ++cr;
		if (cl == 0 && cr == 0) {
			cout << 0 << endl;
			exit(0);
		}
		if (cl > cr) {
			for (int j = i - 1; j >= 0; --j) {
				if (s[j] == ')') ++cl;
				else break;
				if (cl == cr) break;
			}
			if (cl != cr) continue;
		} else if (cl < cr) {
			for (int j = i; j < n; ++j) {
				if (s[j] == '(') ++cr;
				else break;
				if (cl == cr) break;
			}
			if (cl != cr) continue;
		}
		sp_at = i;
	}

	assert(sp_at != -1);
	for (int i = sp_at; i < sp_at + 1; ++i) {
		memset(must_del, 0, sizeof(must_del));
		memset(choosed, 0, sizeof(choosed));
		int cl = 0, cr = 0;
		for (int j = 0; j < i; ++j) if (s[j] == '(') must_del[j] = 1, ++cl;
		for (int j = i; j < n; ++j) if (s[j] == ')') must_del[j] = 1, ++cr;
		if (cl == 0 && cr == 0) {
			cout << 0 << endl;
			exit(0);
		}
		if (cl > cr) {
			for (int j = i - 1; j >= 0; --j) {
				if (s[j] == ')') ++cl, must_del[j] = 1;
				else break;
				if (cl == cr) break;
			}
			if (cl != cr) continue;
		} else if (cl < cr) {
			for (int j = i; j < n; ++j) {
				if (s[j] == '(') ++cr, must_del[j] = 1;
				else break;
				if (cl == cr) break;
			}
			if (cl != cr) continue;
		}

		cout << 1 << endl;
		cout << cl + cr << endl;
		for (int i = 0; i < n; ++i) if (must_del[i]) cout << i + 1 << ' ';
		cout << endl;
	}
}
