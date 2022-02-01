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

#define int int64_t

void solve() {
  int n; cin >> n;
  vector<tuple<int, int, int, int>> rec;
  while (n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a += 1e9;
    b += 1e9;
    c += 1e9;
    d += 1e9;
    rec.emplace_back(a, b, c, d);
  }

  auto getx = [&](int x) -> pair<int, int> {
    auto gety = [&](int y) -> int {
      int tot = 0;
      for (auto [x1, y1, x2, y2] : rec) {
        if (x <= x1) {
          tot += x1 - x;
        } else if (x1 <= x && x <= x2) {
          tot += 0;
        } else {
          tot += x - x2;
        }
        if (y <= y1) {
          tot += y1 - y;
        } else if (y1 <= y && y <= y2) {
          tot += 0;
        } else {
          tot += y - y2;
        }
      }
      return tot;
    };

    int yl = 0, yr = 2e9;
    while (yr - yl > 5) {
      int ym = (yl + yr) / 2;
      int ym1 = ym + 1;
      auto ans = gety(ym);
      auto ans1 = gety(ym1);
      if (ans <= ans1) yr = ym1;
      else yl = ym;
    }

    int mny = -1, mnval = LLONG_MAX;
    for (int i = yl; i <= yr; ++i) {
      auto ans = gety(i);
      if (ans < mnval) {
        mnval = ans;
        mny = i;
      }
    }
    return make_pair(mnval, mny);
  };

  int xl = 0, xr = 2e9;
  while (xr - xl > 5) {
    int xm = (xl + xr) / 2;
    int xm1 = xm + 1;
    auto [ans, _aty] = getx(xm);
    auto [ans1, _aty1] = getx(xm1);
    if (ans <= ans1) xr = xm1;
    else xl = xm;
  }

  int mnx = -1, mny = -1, mnval = LLONG_MAX;
  for (int i = xl - 10; i <= xr; ++i) {
    auto [ans, yy] = getx(i);
    PDE(i, ans, yy);
    if (ans < mnval) {
      mnval = ans;
      mnx = i;
      mny = yy;
    }
  }

  cout << mnx - 1000000000 << ' ' << mny - 1000000000 << endl;
}

int32_t main() {
  CPPinput;
  int t;
  cin >> t;
  // t = 1;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
