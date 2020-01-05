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

vector<bitset<26>> q1[105], q2[105];
vector<pair<int, int>> pos1[105], pos2[105];
bool checked[105][105];
bitset<26> posset[105][105];

int diff(bitset<26> &a, bitset<26> &b) {
	int pos = -1;
	for (int i = 0; i < 26; ++i) if (a[i] != b[i]) {
		if (pos != -1) return -2; // multiple diff
		pos = i;
	}
	return pos; // -1 if no diff
}

int ans[105];

int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << "? 1 1" << endl;
		string s; cin >> s;
		cout << "! " << s << endl;
		exit(0);
	}
	for (int i = 1; i <= n; ++i) ans[i] = -1;

	cout << "? 1 " << n << endl;
	int tot = n * (n + 1) / 2;
	for (int i = 0; i < tot; ++i) {
		string s; cin >> s;
		bitset<26> bs;
		for (char c : s) {
			bs.flip(c - 'a');
		}
		q1[s.size()].push_back(bs);
		pos1[s.size()].emplace_back(-1, -1);
	}

	pos1[n][0] = make_pair(1, n);
	checked[1][n] = 1;
	posset[1][n] = q1[n][0];

	cout << "? 2 " << n << endl;
	tot = n * (n - 1) / 2;
	for (int i = 0; i < tot; ++i) {
		string s; cin >> s;
		bitset<26> bs;
		for (char c : s) {
			bs.flip(c - 'a');
		}
		q2[s.size()].push_back(bs);
		pos2[s.size()].emplace_back(-1, -1);
	}

	pos2[n - 1][0] = make_pair(2, n);
	checked[2][n] = 1;
	posset[2][n] = q2[n - 1][0];

	int l = 1, r = n;
	int step = 1;
	while (l <= r) {
		PDE(l, r);
		int ddd = diff(posset[l][r], posset[l + 1][r]);
		ans[l] = ddd;
		PDE("assign", l, ddd, ans[l]);
		bitset<26> zz = posset[l][r];
		zz.flip(ans[l]);
		posset[l + 1][r] = zz;
		PDE("maintain", l + 1, r, zz);
		int process_length = n - step;
		int exist_in_1 = n - process_length + 1;
		int exist_in_2 = n - process_length;
		vector<int> match_count(exist_in_2, -1);
		PDE(process_length, exist_in_1, exist_in_2);
		int find_index = -1;
		for (int i = 0; i < exist_in_1; ++i) {
			bool matched = 0;
			for (int j = 0; j < exist_in_2; ++j) if (match_count[j] == -1) {
				int d = diff(q1[process_length][i], q2[process_length][j]);
				PDE(i, j, q1[process_length][i], q2[process_length][j]);
				if (d == -1) {
					match_count[j] = i;
					matched = 1;
					break;
				}
			}
			PDE(i, matched);
			if (!matched) find_index = i;
		}

		bitset<26> y = q1[process_length][find_index];
		PDE(find_index, y);
		for (int i = 1; i <= step; ++i) y.flip(ans[i]);

		bitset<26> z = posset[l + 1][r];
		PDE(y, z);
		int d = diff(y, z);
		assert(d >= 0);
		ans[r] = d;
		PDE("assign", r, d, ans[r]);

		z.flip(ans[r]);
		posset[l + 1][r - 1] = z;
		PDE("maintain", l + 1, r - 1, z);

		++l; --r;
	}

	cout << "! ";
	for (int i = 1; i <= n; ++i) cout << char(ans[i] + 'a');
	cout << endl;
}
