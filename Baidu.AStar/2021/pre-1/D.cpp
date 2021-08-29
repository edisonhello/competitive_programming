#pragma GCC optimize("no-stack-protector", "O3")
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

bool np[40000];
vector<int> ps;

void init() {
  for (int i = 2; i < 40000; ++i) {
    if (!np[i]) {
      ps.push_back(i);
      for (auto j = 1ll * i * i; j < 40000; j += i) {
        np[j] = 1;
      }
    }
  }
}

vector<int> val;
map<int, int> cnt;
void factors(int x) {
  cnt.clear();
  for (int p : ps) {
    while (x % p == 0) {
      cnt[p]++;
      x /= p;
    }

    if (1ll * p * p > x) continue;
  }
  if (x != 1) {
    cnt[x]++;
  }

  val.clear();
  function<void(int, map<int, int>::iterator)> dfs = [&] (int now, map<int, int>::iterator it) {
    if (it == cnt.end()) {
      val.push_back(now);
      return;
    }
    for (int j = 0; j <= it->second; ++j) {
      dfs(now, next(it));
      now *= it->first;
    }
  };
  dfs(1, cnt.begin());
}

map<pair<int, int>, pair<int, int>> ans;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  // auto it = ans.find(minmax(a, b));
  // if (it != ans.end()) {
  //   cout << it->second.first << ' ' << it->second.second << '\n';
  //   return;
  // }

  int d = b - a;
  if (d == 0) {
    if (a == 1) {
      cout << "-1 -1" << '\n';
      return;
    }
    cout << 2 << " " << a << '\n';
    return;
  } else if (d == 1) {
    cout << "-1 -1" << '\n';
    return;
  } else {
    for (int i = 2; i * i <= d; ++i) {
      if (d % i == 0) {
        cout << i << ' ' << d << '\n';
        return;
      }
    }
    cout << d << ' ' << d << '\n';
  }
  // factors(d);
  // int mn = INT_MAX, mx = INT_MIN;
  // for (int ff : val) {
  //   if (ff == 1) continue;
  //   if (a % ff == b % ff) {
  //     mn = min(mn, ff);
  //     mx = max(mx, ff);
  //   }
  // }

  // if (mn == INT_MAX) {
  //   cout << "-1 -1" << '\n';
  //   ans[minmax(a, b)] = make_pair(-1, -1);
  // }
  // else {
  //   cout << mn << ' ' << mx << '\n';
  //   ans[minmax(a, b)] = make_pair(mn, mx);
  // }
}

int main() {
  init();
  CPPinput;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
