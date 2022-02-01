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
const long long mod = 998244353;

int bf(vector<int> v) {
  int n = v.size();
  int cnt = 0;
  for (int z = 0; z < (1 << n); ++z) {
    bool ok = 1;
    for (int i = 0; i < n; ++i) if (z & (1 << i)) {
      for (int j = i + 1; j < n; ++j) if (z & (1 << j)) {
        if (v[i] >= v[j]) ok = 0;
      }
    }

    if (ok) ++cnt;
  }
  return cnt;
}

struct node {
  node *l, *r;
  ll sum;
  node ():l(0), r(0), sum (0) {}
  void pull() {
    sum = l->sum + r->sum;
    sum %= mod;
  }
  void add(ll v) {
    sum = (sum + v) % mod;
  }
};

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
  if (l == r) {
    return;
  }
  build(now->l = new node(), l, mid);
  build(now->r = new node(), mid + 1, r);
}

void add(node *now, int l, int r, int x, int v) {
  if (l == r) {
    now->add(v);
    return;
  }
  if (x <= mid) add(now->l, l, mid, x, v);
  else add(now->r, mid + 1, r, x, v);
  now->pull();
}

ll query(node *now, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) {
    return now->sum;
  }
  return query(now->l, l, mid, ql, qr) + query(now->r, mid + 1, r, ql, qr);
}

ll dp[200005][2];

int32_t main() {
  CPPinput;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  node *dp0 = new node();
  node *dp1 = new node();
  build(dp0 = new node(), 1, 200000); 
  build(dp1 = new node(), 1, 200000); 



  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int vi = v[i - 1];
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i][0] - query(dp0, 1, 200000, vi, 200000);

    add(dp0, 1, 200000, vi, dp[i][0]);
    add(dp1, 1, 200000, vi, dp[i][1]);

    PDE(i, dp[i][0], dp[i][1]);
  }

  cout << (dp[n][0] + dp[n][1]) % mod << endl;

}
