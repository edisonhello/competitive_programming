// #pragma GCC optimize("no-stack-protector")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <utility>
#include <vector>

#if __cplusplus >= 201103L
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
#define RZUNI(x)            \
  sort(x.begin(), x.end()), \
      x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) \
  freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
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
#include "/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() \
  printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...)                                         \
  printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), \
      printf(__VA_ARGS__), puts(""), fflush(stdout)
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

void JIZZ(string output = "") {
  cout << output;
  exit(0);
}

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9 + 7;

int pw(int b, int n) {
  int a = 1;
  while (n) {
    if (n & 1) a = 1ll * a * b % mod;
    b = 1ll * b * b % mod;
    n >>= 1;
  }
  return a;
}

int inv(int x) { return pw(x, mod - 2); }

int fac[40005], ifac[40005];

int C(int n, int m) {
  return fac[n] * 1ll * ifac[m] % mod * ifac[n - m] % mod;
}

int dp[4005][4005];

int solve(int n, int m) {
  if (m == 0) return 1;
  int add = 0;
  for (int mg = 1; mg <= m; ++mg) {
    if (n < mg - 1) continue;
    int w = dp[m][mg] * 1ll * fac[mg] % mod;
    int ww = 0;
    if (n >= mg - 1 && mg > 1) {
      ww = (ww + dp[n][mg - 1] * 1ll * fac[mg - 1]) % mod;
      // PDE(1, ww);
    } if (n >= mg) {
      ww = (ww + dp[n][mg] * 2ll * fac[mg]) % mod;
      // PDE(2, ww);
    } if (n >= mg + 1) {
      ww = (ww + dp[n][mg + 1] * 1ll * fac[mg + 1]) % mod;
      // PDE(3, ww);
    }
    PDE(mg, w, ww);
    add = (add + 1ll * w * ww) % mod;
  }
  return add;
}

int main() {
  CPPinput;
  fac[0] = 1;
  for (int i = 1; i <= 20000; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[20000] = inv(fac[20000]);
  for (int i = 19999; i >= 0; --i)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

  dp[1][1] = 1;
  for (int i = 1; i <= 3000; ++i) {
    for (int j = 1; j <= i; ++j) {
      (dp[i + 1][j + 1] += dp[i][j]) %= mod;
      (dp[i + 1][j] += dp[i][j] * 1ll * j % mod) %= mod;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << '\n';
  }
}
