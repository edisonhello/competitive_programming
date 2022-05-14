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
#define RZUNI(x)                                                               \
  sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname)                                                             \
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
#define WHR()                                                                  \
  printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...)                                                               \
  printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__),  \
      puts(""), fflush(stdout)
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

void Update(auto &x, auto y) { x = min(x, y); }

auto calc(int64_t start, int64_t to, int64_t end) {
  return abs(start - to) + abs(to - end);
}

void solve() {
  int n, p;
  cin >> n >> p;
  vector v(n + 2, pair(0ll, 0ll));

  for (int i = 1; i <= n; i++) {
    vector<int> t(p);
    for (int j = 0; j < p; ++j)
      cin >> t[j];

    v[i] = pair(*min_element(t.begin(), t.end()),
                *max_element(t.begin(), t.end()));

    // cout << v[i].first << " " << v[i].second << endl;
  }

  vector dp(n + 2, vector(2, LLONG_MAX / 2));
  dp[0][0] = 0;
  dp[0][1] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      int prev = j ? v[i - 1].second : v[i - 1].first;
      Update(dp[i][0], dp[i - 1][j] + calc(prev, v[i].second, v[i].first));
      Update(dp[i][1], dp[i - 1][j] + calc(prev, v[i].first, v[i].second));
    }
    // cout << "i dp0 dp1 " << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
  }

  cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main() {
  CPPinput;
  int t;
  cin >> t;
  for (int T = 1; T <= t; ++T) {
    cout << "Case #" << T << ": ";
    solve();
  }
}
