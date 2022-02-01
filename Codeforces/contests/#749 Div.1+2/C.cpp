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
  vector<string> mp(n);
  for (int i = 0; i < n; ++i) cin >> mp[i];

  // vector<vector<int>> mostleft(n, vector<int>(m, 1000000000));
  // for (int i = 0; i < m; ++i) if (mp[0][i] == '.') mostleft[0][i] = -1;
  // for (int i = 0; i < m; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if (mp[j][i] == '.') {
  //       mostleft[j][i] = min(mostleft[j][i], i);
  //       if (j && mp[j - 1][i] == '.') mostleft[j][i] = min(mostleft[j][i], mostleft[j - 1][i]);
  //       if (i && mp[j][i - 1] == '.') mostleft[j][i] = min(mostleft[j][i], mostleft[j][i - 1]);
  //     } else {
  //       mostleft[j][i] = -1;
  //     }
  //   }
  // }
  // PDE(mostleft);

  // vector<int> cmx(m, -1);
  // for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
  //   cmx[j] = max(cmx[j], mostleft[i][j]);
  // }

  int q; cin >> q;
  vector<tuple<int, int, int>> qs;
  for (int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b;
    --a, --b;
    qs.emplace_back(i, a, b);
  }

  sort(qs.begin(), qs.end(), [&](auto &t1, auto &t2) -> bool {
      return get<2>(t1) < get<2>(t2);
      });

  vector<int> ans(q);
  int lemx = 0;
  int nowr = 0;
  for (auto [i, l, r] : qs) {
    while (nowr < r) {
      ++nowr;
      for (int j = 0; j < n - 1; ++j) {
        if (mp[j][nowr] == 'X' && mp[j + 1][nowr - 1] == 'X') {
          lemx = nowr;
        }
      }
    }

    if (l >= lemx) ans[i] = 1;
    else ans[i] = 0;
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << '\n';
  }
}

int32_t main() {
  CPPinput;
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
