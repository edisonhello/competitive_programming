// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <utility>
#include <functional>
#include <complex>
#include <climits>
#include <random>
#include <thread>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <tuple>
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
#define RZUNI(x) sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
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
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), puts(""), fflush(stdout)
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

void JIZZ(string output = ""){ cout << output; exit(0); }

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

#define _L 0
#define _R 4'000'000'000'000'000
#define _Z 2'000'000'000'000'000
#define mid ((l + r) >> 1)

struct node {
  node *l, *r;
  ll tot, tag, len; 
  void addtag(ll v) {
    tot += len * v;
    tag += v;
  }
  void push() {
    if (!l) {
      l = new node();
      r = new node();
      l->len = (len + 1) / 2;
      r->len = (len / 2);
    }
    if (tag) {
      l->addtag(tag);
      r->addtag(tag);
      tag = 0;
    }
  }
  void pull() {
    tot = l->tot + r->tot;
  }
} *root;

void add(node *now, ll l, ll r, ll ml, ll mr) {
  if (r < ml || mr < l) return;
  if (ml <= l && r <= mr) {
    now->addtag(1);
    return;
  }
  now->push();
  add(now->l, l, mid, ml, mr);
  add(now->r, mid + 1, r, ml, mr);
  now->pull();
}

ll query(node *now, ll l, ll r, ll ql, ll qr) {
  if (!now) return 0;
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return now->tot;
  now->push();
  return query(now->l, l, mid, ql, qr) + query(now->r, mid + 1, r, ql, qr);
}


int main() {
    CPPinput;
    int n; cin >> n;
    ll now = 0;
    ll ans = 0;
    root = new node();
    root->len = _R - _L + 1;
    for (int i = 0; i < n; ++i) {
      ll a; cin >> a;
      if (i & 1) {
        ans += query(root, _L, _R, now - a + 1 + _Z, now + _Z);
        now -= a;
      } else {
        add(root, _L, _R, now + 1 + _Z, now + a + _Z);
        now += a;
      }

      if (now < 0) {
        root = new node();
        root->len = _R - _L + 1;
        now = 0;
      }
    }

    cout << ans << endl;
}

