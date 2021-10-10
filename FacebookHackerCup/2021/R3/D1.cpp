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
#define RZUNI(x)              \
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
#define LOG(...)                                           \
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

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> h(n, vector<int>(m));
  vector<vector<int>> s(n, vector<int>(m));

  vector<int> allhs;

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> h[i][j];
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> s[i][j];

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    allhs.push_back(h[i][j]);
    allhs.push_back(s[i][j]);
  }

  sort(allhs.begin(), allhs.end());
  allhs.resize(unique(allhs.begin(), allhs.end()) - allhs.begin());

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    h[i][j] = lower_bound(allhs.begin(), allhs.end(), h[i][j]) - allhs.begin();
    s[i][j] = lower_bound(allhs.begin(), allhs.end(), s[i][j]) - allhs.begin();
  }

  vector<vector<pair<int, int>>> harpos(allhs.size());
  vector<vector<pair<int, int>>> appearpos(allhs.size());

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    if (s[i][j] < h[i][j]) {
      harpos[s[i][j]].emplace_back(i, j);
    } 
    appearpos[h[i][j]].emplace_back(i, j);
  }

  int blks = 0;
  vector<int> djs(n * m);
  iota(djs.begin(), djs.end(), 0);
  vector<int> bot(n * m, 0);
  vector<int> inuse(n * m, 0);

  auto id = [&](int i, int j) { return i * m + j; };
  static int dx[] = {-1, 0, 1, 0};
  static int dy[] = {0, -1, 0, 1};
  function<int(int)> F = [&](int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); };
  auto U = [&](int u, int v) { 
    u = F(u);
    v = F(v);
    if (u == v) return;
    djs[u] = v;
    bot[v] |= bot[u];
    inuse[v] |= inuse[u];
    --blks;
  };

  int cnt = 0;
  int ans = 0;
  for (int t = allhs.size() - 1; t >= 0; --t) {
    for (auto [x, y] : harpos[t]) {
      int z = F(id(x, y));
      ++cnt;
      if (!bot[z]) {
        bot[z] = 1;
        ++ans;
      }
    }

    for (auto [x, y] : appearpos[t]) {
      inuse[F(id(x, y))] = 1;
      for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (inuse[F(id(nx, ny))]) U(id(x, y), id(nx, ny));
      }
    }
  }

  cout << cnt << ' ' << ans << endl;
}

int main() {
  CPPinput;
  int t;
  cin >> t;
  // t = 1;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
