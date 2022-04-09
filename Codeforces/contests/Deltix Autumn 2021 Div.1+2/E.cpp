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

// now 42 min start 
struct node {
  node *l, *r;
  int tag, mn;
  node(): tag(0), mn(0) {}
  void addtag(int v) { tag += v; mn += v; }
  void pull() { mn = min(l->mn, r->mn); }
  void push() { if (tag) {
    l->addtag(tag);
    r->addtag(tag);
    tag = 0;
  } }
} *root;

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

int query(node *now, int l, int r, int ml, int mr) {
  if (r < ml || mr < l) return INT_MAX;
  if (ml <= l && r <= mr) {
    return now->mn;
  }
  now->push();
  return min(
    query(now->l, l, mid, ml, mr),
    query(now->r, mid + 1, r, ml, mr));
}


void solve() {
  int n, q; 
  cin >> n >> q;
  string s;
  cin >> s;

  build(root = new node(), 0, n);

  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'a') {
      modify(root, 0, n, i, n, 1);
    } else if (s[i - 1] == 'b') {

    }
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