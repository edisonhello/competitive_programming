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

struct data {
  int mn[3][3];
  data() { memset(mn, 0x3f, sizeof(mn)); }
  void add(int v) {
    mn[v][v] = 1;
    if (mn[0][0] < 1e9 && mn[1][1] < 1e9) mn[0][1] = mn[1][0] = 2;
    if (mn[1][1] < 1e9 && mn[2][2] < 1e9) mn[1][2] = mn[2][1] = 2;
    if (mn[0][0] < 1e9 && mn[1][1] < 1e9 && mn[2][2] < 1e9) mn[0][2] = mn[2][0] = 3;
  }
  int get(int x, int y) { return mn[x][y]; }
};

data merge (data l, data r) {
  data d;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        d.mn[i][k] = min(d.mn[i][k], l.mn[i][j] + r.mn[j][k]);
      }
    }
  }
  return d;
}

void solve() {
  int n, q;
  cin >> n >> q;
  int m = 3;

  vector<vector<int>> a(n, vector<int>(m));
  vector<int> alla;
  vector<tuple<int, int, int, int, int>> req(q);

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    cin >> a[i][j];
    alla.push_back(a[i][j]);
  }

  for (int i = 0; i < q; ++i) {
    int a, x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> a;
    req[i] = make_tuple(a, x1, y1, x2, y2);
    alla.push_back(a);
  }

  sort(alla.begin(), alla.end());
  alla.resize(unique(alla.begin(), alla.end()) - alla.begin());

  PDE(alla);

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    a[i][j] = lower_bound(alla.begin(), alla.end(), a[i][j]) - alla.begin();
  }

  PDE(a);

  for (int i = 0; i < q; ++i) {
    get<0>(req[i]) = lower_bound(alla.begin(), alla.end(), get<0>(req[i])) - alla.begin();
  }

  sort(req.begin(), req.end());
  // reverse(req.begin(), req.end());

  int ans = 1;

  vector<vector<pair<int, int>>> gopos(alla.size());
  PDE(gopos);

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    PDE(i, j, a[i][j]);
    gopos[a[i][j]].emplace_back(i, j);
  }

  vector<int> rowcango(n, 0);
  set<int> goodrow;


  struct node {
    node *l, *r;
    data d;
    node() : l(0), r(0) {}
    void pull() {
      d = merge(l->d, r->d);
    }
  } *root = 0;

#define mid ((l + r) >> 1)
  auto build = [&](auto build, node *now, int l, int r) -> void {
    if (l == r) return;
    build(build, now->l = new node(), l, mid);
    build(build, now->r = new node(), mid + 1, r);
    now->pull();
  };

  auto modify = [&](auto modify, node *now, int l, int r, int x, int y) -> void {
    if (l == r) {
      now->d.add(y);
      return;
    }
    if (x <= mid) modify(modify, now->l, l, mid, x, y);
    else modify(modify, now->r, mid + 1, r, x, y);
    now->pull();
  };

  auto query = [&](auto query, node *now, int l, int r, int ql, int qr) -> data {
    if (ql <= l && r <= qr) return now->d;
    if (qr <= mid) return query(query, now->l, l, mid, ql, qr);
    if (mid < ql) return query(query, now->r, mid + 1, r, ql, qr);
    return merge(query(query, now->l, l, mid, ql, qr), query(query, now->r, mid + 1, r, ql, qr));
  };
#undef mid

  build(build, root = new node(), 0, n - 1);

  auto cango = [&](int x, int y) {
    PDE("cango", x, y);
    ++rowcango[x];
    if (rowcango[x] == 3) {
      goodrow.insert(x);
    }

    modify(modify, root, 0, n - 1, x, y);
  };

  auto my_query = [&](int x1, int y1, int x2, int y2) -> int {
    if (x2 < x1) swap(x1, x2), swap(y1, y2);
    --x1, --x2, --y1, --y2;
    PDE("query", x1, y1, x2, y2);

    auto gores = query(query, root, 0, n - 1, x1, x2);

    int mn = 1e9;

    mn = min(mn, gores.get(y1, y2) - 1);

    int lextra = -1, rextra = -1;

    PDE(goodrow);
    if (y1 == 0 || y1 == 2) {
      auto it = goodrow.lower_bound(x1);
      if (it != goodrow.begin()) {
        --it;
        auto res = query(query, root, 0, n - 1, *it, x1);
        if (res.get(0, 0) < 1e9 && res.get(2, 2) < 1e9) {
          lextra = res.get(0, 0) + res.get(2, 2);
        }
      }
    }
    if (y2 == 0 || y2 == 2) {
      auto it = goodrow.upper_bound(x2);
      if (it != goodrow.end()) {
        PDE("ri", *it);
        auto res = query(query, root, 0, n - 1, x2, *it);
        PDE(res.get(0, 0), res.get(2, 2));
        if (res.get(0, 0) < 1e9 && res.get(2, 2) < 1e9) {
          rextra = res.get(0, 0) + res.get(2, 2);
        }
      }
    }

    PDE(lextra, rextra, goodrow);

    if (lextra != -1) {
      mn = min(mn, gores.get(2 - y1, y2) + lextra - 1);
    } 
    if (rextra != -1) {
      mn = min(mn, gores.get(y1, 2 - y2) + rextra - 1);
    } 
    if (lextra != -1 && rextra != -1) {
      mn = min(mn, gores.get(2 - y1, 2 - y2) + lextra + rextra - 1);
    }

    if (mn >= 1e9) return 1;
    return mn;
  };

  int ingo = -1;
  for (auto [l, x1, y1, x2, y2] : req) {
    PDE(l, x1, y1, x2, y2);
    while (ingo < l) {
      ++ingo;
      for (auto [x, y] : gopos[ingo]) {
        cango(x, y);
      }
    }

    int tmpans = my_query(x1, y1, x2, y2);
    PDE(tmpans);
    ans = 1ll * ans * tmpans % mod;
  }

  cout << ans << endl;

  auto del = [&](auto del, node *now) -> void {
    if (now->l) del(del, now->l);
    if (now->r) del(del, now->r);
    delete now;
  };

  del(del, root);
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
