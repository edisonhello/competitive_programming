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

#define int ll

ll val[100005];
ll pre[100005];

struct node {
  node *l, *r;
  ll mn, mx;
  void pull() {
    mn = min(l->mn, r->mn);
    mx = max(l->mx, r->mx);
  }
} * root;

#define mid ((l + r) >> 1)

void build(node *now, int l, int r) {
  if (l == r) {
    now->mn = now->mx = pre[l];
    return;
  }
  build(now->l = new node(), l, mid);
  build(now->r = new node(), mid + 1, r);
  now->pull();
}

ll qmin(node *now, ll l, ll r, ll ql, ll qr) {
  if (!now) return LLONG_MAX;
  if (r < ql || qr < l) return LLONG_MAX;
  if (ql <= l && r <= qr) return now->mn;
  return min(qmin(now->l, l, mid, ql, qr),
             qmin(now->r, mid + 1, r, ql, qr));
}
ll qmax(node *now, ll l, ll r, ll ql, ll qr) {
  if (!now) return LLONG_MIN;
  if (r < ql || qr < l) return LLONG_MIN;
  if (ql <= l && r <= qr) return now->mx;
  return max(qmax(now->l, l, mid, ql, qr),
             qmax(now->r, mid + 1, r, ql, qr));
}

int32_t main() {
  CPPinput;
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2), b(n + 2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];

  for (int i = 1; i <= n; ++i) val[i] = b[i] - a[i];
  for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1] + val[i];

  build(root = new node(), 1, n);

  while (m--) {
    int l, r;
    cin >> l >> r;
    PDE(l, r, pre[l - 1], pre[r]);
    if (pre[r] != pre[l - 1]) {
      cout << -1 << '\n';
      continue;
    }

    ll mn = qmin(root, 1, n, l, r);
    ll mx = qmax(root, 1, n, l, r);
    if (mn < pre[l - 1]) {
      cout << -1 << '\n';
      continue;
    }

    cout << mx - mn << '\n';
  }
}
