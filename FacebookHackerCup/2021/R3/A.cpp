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
  int n, m;
  cin >> n >> m;
  vector<int> djs(n);
  vector<int> sz(n, 1);
  iota(djs.begin(), djs.end(), 0);

  int64_t prod = 1;
  int64_t ans = 1ll * n * (n - 1) / 2 % mod;

  set<int> heads;
  for (int i = 0; i < n; ++i) heads.insert(i);

  function<int(int)> F = [&](int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); };

  auto U = [&](int x, int y) {
    x = F(x);
    y = F(y);
    if (x == y) return;
    ans = (ans + 1ll * sz[x] * sz[y]) % mod;
    djs[x] = y;
    sz[y] += sz[x];
    heads.erase(x);
  };

  auto connect = [&](int u, int v) {
    if (F(u) == F(v)) return;
    if (v < u) swap(u, v);
    set<int> all;
    all.insert(F(u));
    all.insert(F(v));
    for (auto it = heads.upper_bound(F(u)); it != heads.end() && *it < F(v); ++it) {
      all.insert(*it);
    }

    vector<int> vall(all.begin(), all.end());
    for (int i = 1; i < (int)vall.size(); ++i)
      U(vall[i - 1], vall[i]);
    // for (int i = u + 1; i <= v; ++i) U(i - 1, i);
  };

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    connect(u, v);
    prod = prod * ans % mod;
  }

  cout << prod << endl;
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
