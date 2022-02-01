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
  int n;
  cin >> n;
  vector<int> a(n + 4), b(n + 4);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];

  vector<vector<pair<int, int>>> g(n + 5);

#define mid ((l + r) >> 1)

  auto add_edge = [&](int so, int l, int r) {
    PDE(so, l, r);
    for (int i = r; i >= l; --i) g[so].emplace_back(i, 1);
  };

  add_edge(n, n - a[n], n);
  for (int i = n - 1; i >= 1; --i) {
    int start = min(n, i + b[i]);
    int hi = max(0, start - a[start]);
    add_edge(i, hi, start);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> d(n + 5, 1000000000);
  vector<int> vis(n + 5, 0);
  vector<int> cf(n + 5, 0);
  pq.emplace(0, n);
  d[n] = 0;

  while (pq.size()) {
    while (pq.size() && vis[pq.top().second]) pq.pop();
    if (pq.empty()) break;
    int now = pq.top().second;
    vis[now] = 1;
    for (auto [u, co] : g[now]) {
      if (d[now] + co < d[u]) {
        d[u] = d[now] + co;
        pq.emplace(d[u], u);
        cf[u] = now;
      }
    }
  }

  if (d[0] >= 1000000000) {
    cout << -1 << endl;
    return;
  }

  vector<int> path;
  for (int i = 0; ; i = cf[i]) {
    path.push_back(i);
    if (i == n) break;
  }

  cout << path.size() - 1 << endl;
  for (int i = path.size() - 2; i >= 0; --i) {
    cout << path[i] << ' ';
  }
  cout << endl;

}

int32_t main() {
  CPPinput;
  int t;
  // cin >> t;
  t = 1;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
