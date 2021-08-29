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

struct node {
  node *l, *r;
  int mx, tag;
  node() : l(0), r(0), mx(0), tag(0) {}
  void pull() { mx = max(l->mx, r->mx); }
  void push() {
    if (tag) l->addtag(tag), r->addtag(tag), tag = 0;
  }
  void addtag(int t) { mx += t, tag += t; }
} * root;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
  if (l == r) {
    return;
  }
  build(now->l = new node(), l, mid);
  build(now->r = new node(), mid + 1, r);
}

void modify(node *now, int l, int r, int ml, int mr, int v) {
  if (r < ml || mr < l) return;
  if (ml <= l && r <= mr) {
    now->addtag(v);
    return;
  }
  now->push();
  modify(now->l, l, mid, ml, mr, v);
  modify(now->r, mid + 1, r, ml, mr, v);
  now->pull();
}

int query(node *now, int l, int r, int ql, int qr) {
  if (r < ql || qr < l) return -1;
  if (ql <= l && r <= qr) return now->mx;
  now->push();
  return max(query(now->l, l, mid, ql, qr),
             query(now->r, mid + 1, r, ql, qr));
}

int main() {
  CPPinput;
  int n, k;
  cin >> n >> k;
  int most = n / (k - 1) + !!(n % (k - 1));
  int nn = n * k;
  vector<int> c(nn);
  for (int i = 0; i < nn; ++i) cin >> c[i], --c[i];
  vector<int> cpre(n, -1);
  vector<int> pre(nn);
  for (int i = 0; i < nn; ++i) {
    pre[i] = cpre[c[i]];
    cpre[c[i]] = i;
  }

  build(root = new node(), 0, nn - 1);

  vector<pair<int, int>> pos(n, make_pair(-1, -1));
  for (int i = 1; i < nn; ++i) {
    if (pos[c[i]] == make_pair(-1, -1)) {
      if (pre[i] != -1) {
        if (query(root, 0, nn - 1, pre[i], i) < most) {
          modify(root, 0, nn - 1, pre[i], i, 1);
          pos[c[i]] = make_pair(pre[i], i);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    assert(pos[i] != make_pair(-1, -1));
    cout << pos[i].first + 1 << ' ' << pos[i].second + 1 << '\n';
  }
}
