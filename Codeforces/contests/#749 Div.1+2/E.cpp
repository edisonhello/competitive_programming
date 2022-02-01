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

int djs[300005];
vector<int> g[300005];
int pa[20][300005];
int tag[300005];
int dep[300005];

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
void U(int x, int y) { djs[F(x)] = F(y); }

void dfs1(int now, int _pa) {
  if (_pa) dep[now] = dep[_pa] + 1;
  pa[0][now] = _pa;
  for (int z = 1; z < 20; ++z) pa[z][now] = pa[z - 1][pa[z - 1][now]];

  for (int i : g[now]) if (i != _pa) dfs1(i, now);
}

int lca(int u, int v) {
  if (u == v) return u;
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 19; i >= 0; --i) if ((1 << i) & (dep[v] - dep[u])) v = pa[i][v];
  if (u == v) return u;
  for (int i = 19; i >= 0; --i) if (pa[i][u] != pa[i][v]) {
    u = pa[i][u];
    v = pa[i][v];
  }
  return pa[0][u];
}

int deg[300005];
int dfs2(int now, int pa) {
  int val = 0;
  for (int i : g[now]) if (i != pa) {
    val += dfs2(i, now);
  }
  val += tag[now];
  if (val & 1) {
    ++deg[now];
    ++deg[pa];
  }
  return val;
}

void solve() {
  int n, m; 
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) djs[i] = i;

  while (m--) {
    int u, v;
    cin >> u >> v;
    if (F(u) == F(v)) continue;
    U(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
    PDE(u, v);
  }

  dfs1(1, 0);

  vector<vector<int>> goes;
  int q; cin >> q; while (q--) {
    int u, v; cin >> u >> v;
    tag[u] += 1;
    tag[v] += 1;
    int l = lca(u, v);
    tag[l] -= 2;
    PDE(u, v, l);

    vector<int> ul;
    vector<int> vl;
    while (u != l) ul.push_back(u), u = pa[0][u];
    ul.push_back(l);
    while (v != l) vl.push_back(v), v = pa[0][v];
    reverse(vl.begin(), vl.end());
    for (int i : vl) ul.push_back(i);
    goes.push_back(ul);
  }

  for (int i = 1; i <= n; ++i) PDE(i, tag[i]);

  assert(!dfs2(1, 0));

  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += (deg[i] & 1);

  if (ans == 0) {
    cout << "YES" << endl;
    for (auto &v : goes) {
      cout << v.size() << '\n';
      for (int i : v) cout << i << ' ';
      cout << '\n';
    }
  } else {
    cout << "NO" << endl << ans / 2 << endl;
  }
}

int32_t main() {
  CPPinput;
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
