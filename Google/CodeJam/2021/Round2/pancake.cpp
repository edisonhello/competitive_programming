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

int pw(int b, int n) {
	int a = 1;
	while (n) {
		if (n & 1) a = 1ll * a * b % mod;
		b = 1ll * b * b % mod; n >>= 1;
	}
	return a;
}

int fac[100005], ifac[100005];
void init() {
	fac[0] = 1;
	for (int i = 1; i <= 100000; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[100000] = pw(fac[100000], mod - 2);
	for (int i = 99999; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
	return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

vector<int> poss[100005];
vector<int> v;

int dfs(int l, int r, int x) {
	if (l > r) return 1;
	if (l == r) return v[l] == x;
	auto it2 = upper_bound(poss[x].begin(), poss[x].end(), r);
	if (it2 == poss[x].begin()) return 0;
	auto it = prev(it2);
	int pos = *it;
	if (pos < l) return 0;
	PDE(l, r, x, pos);

	int le = dfs(l, pos - 1, x);
	int ri = dfs(pos + 1, r, x + 1);
	int llen = pos - 1 - l + 1;
	int rlen = r - (pos + 1) + 1;
	return 1ll * le * ri % mod * C(llen + rlen, llen) % mod;
}

void solve() {
	int n; cin >> n;
	v.resize(n + 3);
	for (int i = 1; i <= n; ++i) poss[i].clear();
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		poss[v[i]].push_back(i);
	}

	int ans = dfs(1, n, 1);
	cout << ans << endl;
}

int main() {
	init();
    CPPinput;
	int t; cin >> t; 
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
