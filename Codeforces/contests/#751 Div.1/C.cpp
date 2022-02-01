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
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  sort(b.begin(), b.end());

  vector<int> putb4(m);

  auto dc = [&](auto dc, int ml, int mr, int nl, int nr) -> void {
    if (mr < ml) return;
    int mm = (ml + mr) / 2;
    int val = b[mm];
    PDE(mm, val, nl, nr);

    int add_large = 0, add_small = 0;
    for (int i = nl; i < nr; ++i) if (a[i] < val) ++add_small;

    int best = nl, best_large = add_large, best_small = add_small;
    for (int i = nl; i < nr; ++i) {
      if (a[i] < val) --add_small;
      if (a[i] > val) ++add_large;
      if (add_small + add_large < best_large + best_small) {
        best_large = add_large;
        best_small = add_small;
        best = i + 1;
      }
    }

    putb4[mm] = best;

    dc(dc, ml, mm - 1, nl, best);
    dc(dc, mm + 1, mr, best, nr);
  };

  dc(dc, 0, m - 1, 0, n);

  vector<int> na;
  int nowi = 0;
  for (int i = 0; i < m; ++i) {
    while (nowi < putb4[i]) na.push_back(a[nowi++]);
    na.push_back(b[i]);
  }
  while (nowi < n) na.push_back(a[nowi++]);
  a = na;

  auto num = a;
  sort(num.begin(), num.end());
  num.resize(unique(num.begin(), num.end()) - num.begin());
  for (int &i : a) i = upper_bound(num.begin(), num.end(), i) - num.begin();

  vector<int> bit(num.size() + 2);
  auto add = [&](int x) {
    for (; x < bit.size(); x += x & -x) ++bit[x];
  };
  auto query = [&](int x) {
    int a = 0;
    for (; x; x -= x & -x) a += bit[x];
    return a;
  };
  int64_t ans = 0;
  for (int i : a) {
    ans += query(num.size()) - query(i);
    add(i);
  }

  cout << ans << '\n';
}

int32_t main() {
  CPPinput;
  int t;
  cin >> t;
  // t = 1;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
