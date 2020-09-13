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

int dp[15][15][15][15];

void Update(int &x, int y) { x = min(x, y); }
int Calc(string s, string t) {
	int n = s.size(), m = t.size();
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) 
		dp[i][i][j][j] = s[i] != t[j];

	for (int k = 1; k <= n; ++k) for (int l = 1; l <= m; ++l) {
		for (int i = 0; i + k - 1 < n; ++i) for (int j = 0; j + l - 1 < m; ++j) {
			int ii = i + k - 1, jj = j + l - 1;
			int now = dp[i][ii][j][jj];

			if (i > 0) Update(dp[i - 1][ii][j][jj], now + 1);
			if (ii < n - 1) Update(dp[i][ii + 1][j][jj], now + 1);
			if (j > 0) Update(dp[i][ii][j - 1][jj], now + 1);
			if (jj < m - 1) Update(dp[i][ii][j][jj + 1], now + 1);
			
			if (i > 0 && j > 0) 
				if (s[i - 1] == t[j - 1]) Update(dp[i - 1][ii][j - 1][jj], now);
				else Update(dp[i - 1][ii][j - 1][jj], now + 1);
			if (ii < n - 1 && jj < m - 1) 
				if (s[ii + 1] == t[jj + 1]) Update(dp[i][ii + 1][j][jj + 1], now);
				else Update(dp[i][ii + 1][j][jj + 1], now + 1);
		}
	}

	return dp[0][n - 1][0][m - 1];
}

void Solve() {
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	string ans;
	int tot = 1e9, diff = -1;

	auto Check = [&] (string r) {
		int a = Calc(s, r);
		int b = Calc(t, r);
		PDE(s, t, r, a, b);
		auto Update = [&] () {
			if (r.size() > 6u) {
				PDE(s, t, r, a, b, ans, tot, diff);
				assert(0);
			}
			tot = a + b;
			diff = abs(a - b);
			ans = r;
			PDE(tot, diff, ans);
		};
		if (a + b < tot) {
			Update();
		} else if (a + b == tot && abs(a - b) < diff) {
			Update();
		}
	};

	queue<string> q;
	q.push("");
	while (q.size()) {
		string s = q.front(); q.pop();
		if (s.size()) Check(s);
		if (s.size() == 6u) continue;
		q.push(s + "X");
		q.push(s + "Y");
		q.push(s + "Z");
	}

	cout << ans << '\n';
}

int main() {
    CPPinput;
	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		Solve();
	}
}
