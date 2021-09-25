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

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> f(n);
  for (int i = 0; i < n; ++i) cin >> f[i], --f[i];

  int dfn = 0;
  vector<int> sz(n), mxszi(n, -1), pa(n), order(n), opos(n), dep(n);
  auto dfs_pre = [&](auto f, int now, int p) -> void {
    sz[now] = 1;
    pa[now] = p;
    order[dfn] = now;
    opos[now] = dfn;
    ++dfn;
    for (int i : g[now])
      if (i != p) {
        dep[i] = dep[now] + 1;
        f(f, i, now);
        sz[now] += sz[i];
        if (mxszi[now] == -1 || sz[i] > sz[mxszi[now]]) {
          mxszi[now] = i;
        }
      }
  };
  dfs_pre(dfs_pre, 0, -1);

  int cc = 0;
  vector<int> bel(n), icpos(n), clen(n), chead(n), cpa(n);
  vector<vector<int>> mem(n);
  auto dfs_decom = [&](auto f, int now, int p, int ccn,
                       int ccpos) -> void {
    PDE(now, p, ccn, ccpos);
    bel[now] = ccn;
    icpos[now] = ccpos;
    mem[ccn].push_back(now);
    clen[ccn] = ccpos + 1;
    for (int i : g[now])
      if (i != p) {
        if (i == mxszi[now])
          f(f, i, now, ccn, ccpos + 1);
        else {
          chead[cc] = i;
          cpa[cc] = now;
          f(f, i, now, cc++, 0);
        }
      }
  };
  dfs_decom(dfs_decom, 0, -1, cc++, 0);

  struct Seg {
    struct node {
      node *l, *r;
      int val, tag;
      node() : l(0), r(0), val(0), tag(0) {}
      void addtag(int v) {
        val += v;
        tag += v;
      }
      void push() {
        if (tag) l->addtag(tag), r->addtag(tag);
        tag = 0;
      }
    } * root;
    int len;
    Seg() : root(0), len(0) {}
#define mid ((l + r) >> 1)
    void build(node *now, int l, int r) {
      if (l == r) return;
      build(now->l = new node(), l, mid);
      build(now->r = new node(), mid + 1, r);
    }
    void init(int len) {
      this->len = len;
      build(root = new node(), 0, len - 1);
      PDE(len, root);
    }
    void _add(node *now, int l, int r, int ml, int mr) {
      if (mr < l || r < ml) return;
      if (ml <= l && r <= mr) {
        now->addtag(1);
        return;
      }
      _add(now->l, l, mid, ml, mr);
      _add(now->r, mid + 1, r, ml, mr);
    }
    void add(int l, int r) {
      PDE(root, len, l, r);
      _add(root, 0, len - 1, l, r);
    }
    int _query(node *now, int l, int r) {
      if (l == r) {
        return !now->val;
      }
      now->push();
      return _query(now->l, l, mid) + _query(now->r, mid + 1, r);
    }
    int get_empty() { return _query(root, 0, len - 1); }
#undef mid
  };

  PDE(cc);
  vector<Seg> segs(cc);
  for (int i = 0; i < cc; ++i) {
    PDE(i, clen[i]);
    segs[i].init(clen[i]);
  }

  vector<vector<int>> pas(20, vector<int>(n, -1));
  pas[0] = pa;
  for (int z = 1; z < 20; ++z) {
    for (int i = 0; i < n; ++i) {
      if (pas[z - 1][i] == -1)
        pas[z][i] = -1;
      else
        pas[z][i] = pas[z - 1][pas[z - 1][i]];
    }
  }

  vector<vector<int>> flist(n);
  for (int i = 0; i < n; ++i) {
    flist[f[i]].push_back(i);
  }

  auto get_lca = [&](int a, int b) {
    if (a == b) return a;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 19; i >= 0; --i) {
      if ((dep[b] - dep[a]) & (1 << i)) b = pas[i][b];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; --i) {
      if (pas[i][a] != pas[i][b]) {
        a = pas[i][a];
        b = pas[i][b];
      }
    }
    return pas[0][a];
  };

  auto _add_path = [&](int l, int p) {
    while (l != p) {
      if (bel[l] == bel[p]) {
        segs[bel[p]].add(icpos[l] + 1, icpos[p]);
        break;
      } else {
        segs[bel[p]].add(0, icpos[p]);
        p = cpa[bel[p]];
      }
    }
  };

  auto add_path = [&](int a, int b) {
    int l = get_lca(a, b);
    _add_path(l, a);
    _add_path(l, b);
  };

  for (auto &v : flist) {
    if (v.size() > 1u) {
      sort(v.begin(), v.end(),
           [&](const int &a, const int &b) { return opos[a] < opos[b]; });
      for (int i = 1; i < (int)v.size(); ++i) {
        add_path(v[i - 1], v[i]);
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < cc; ++i) {
    sum += segs[i].get_empty();
  }
  --sum;
  cout << sum << endl;
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
