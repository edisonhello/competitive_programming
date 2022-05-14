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
#include "/Users/edison/Coding/competitive_programming/template/debug.cpp"
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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool same(double x, double y) { return abs(x - y) < eps; }

struct P {
  int x, y;

  P operator-(const P &b) const { return P{x - b.x, y - b.y}; }

  double abs() const { return hypot(x, y); }
};

void solve() {
  int n;
  cin >> n;
  vector<P> ps(n);
  vector<P> cand(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> ps[i].x >> ps[i].y;
  }
  for (int i = 0; i <= n; ++i) {
    cin >> cand[i].x >> cand[i].y;
  }

  vector<int> called(n, 0);
  vector<int> took(n + 1, 0);
  vector<pair<int, int>> ans;

  auto dfs = [&](auto dfs, int now) -> int {
    if (now == n)
      return 1;

    for (int i = 0; i < n; ++i)
      if (!called[i]) {
        vector<pair<double, int>> dist;
        for (int j = 0; j <= n; ++j)
          if (!took[j]) {
            dist.emplace_back((ps[i] - cand[j]).abs(), j);
          }

        sort(dist.begin(), dist.end());

        if (dist[0].second == 0 && !same(dist[0].first, dist[1].first))
          return 0;

        int jj = dist[0].second == 0 ? dist[1].second : dist[0].second;

        ans.emplace_back(i, jj);
        called[i] = 1;
        took[jj] = 1;

        int r = dfs(dfs, now + 1);
        if (r)
          return 1;

        ans.pop_back();
        called[i] = 0;
        took[jj] = 0;
      }

    return 0;
  };

  auto res = dfs(dfs, 0);

  if (res) {
    cout << "POSSIBLE" << '\n';
    for (auto [a, b] : ans) {
      cout << a + 1 << ' ' << b + 1 << '\n';
    }
  } else {
    cout << "IMPOSSIBLE" << '\n';
  }
}

int main() {
  // for (int i = 1; i <= 100; ++i) {
  //   cout << i << ": " << solve(i) / 4 << endl;
  // }
  CPPinput;
  int t;
  cin >> t;
  for (int T = 1; T <= t; ++T) {
    cout << "Case #" << T << ": ";
    solve();
  }
}
