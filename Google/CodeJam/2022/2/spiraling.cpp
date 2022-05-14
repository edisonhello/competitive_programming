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

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> sc;
  vector v(n, vector(n, 0));

  auto inside = [&](int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n;
  };
  auto filled = [&](int x, int y) { return inside(x, y) && v[x][y]; };

  auto dfs = [&](auto dfs, int x, int y, int now, int d) -> void {
    v[x][y] = now;
    if (now == n * n)
      return;

    if (!inside(x + dx[d], y + dy[d]) || filled(x + dx[d], y + dy[d])) {
      int nd = (d + 1) % 4;
      dfs(dfs, x + dx[nd], y + dy[nd], now + 1, nd);
    } else {
      dfs(dfs, x + dx[d], y + dy[d], now + 1, d);
    }
  };

  dfs(dfs, 0, 0, 1, 0);

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout << v[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  int nx = 0, ny = 0, d = 0;
  int exp_step = n * n - 1;

  while (v[nx][ny] != n * n) {
    PDE(nx, ny, v[nx][ny]);
    int nxx = nx + dx[d], nxy = ny + dy[d];
    if (!inside(nxx, nxy) || v[nxx][nxy] < v[nx][ny]) {
      d = (d + 1) % 4;
      nx += dx[d];
      ny += dy[d];
      continue;
    }

    int nd = (d + 1) % 4;
    int scx = nx + dx[nd], scy = ny + dy[nd];
    int to = v[scx][scy];
    int fast = to - v[nx][ny] - 1;
    if (to >= v[nx][ny] && exp_step - fast >= k) {
      sc.emplace_back(v[nx][ny], to);
      nx = scx;
      ny = scy;
      exp_step -= fast;
      continue;
    }

    nx = nxx;
    ny = nxy;
  }

  if (exp_step != k) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  cout << sc.size() << endl;
  for (auto [x, y] : sc) {
    cout << x << ' ' << y << '\n';
  }
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
