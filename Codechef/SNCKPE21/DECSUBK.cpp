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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i], --v[i];
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) ++cnt[v[i]];

  for (int i = 0; i < n; ++i) if (cnt[i] > k) {
    cout << -1 << '\n';
    return;
  }

  int mxcnt = 0;
  int mxi = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (cnt[i]) {
      mxcnt = cnt[i];
      mxi = i;
      break;
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    while (cnt[i] > 0) {
      --cnt[i];
      --k;
      bool bad = 0;

      for (int j = i; j < n; ++j) {
        if (cnt[j] > k) bad = 1;
      }
      PDE(i, k, bad);

      if (bad) {
        ++cnt[i];
        ++k;
        break;
      }

      ans.push_back(i);
    }

    if (cnt[i]) break;
  }

  while (k) {
    int blk = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (cnt[i] == k) {
        ++blk;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (cnt[i] == k) {
        ans.push_back(i);
        --cnt[i];
        --blk;
        if (blk == 0) {
          for (int j = 0; j < i; ++j) {
            if (cnt[j]) {
              --cnt[j];
              ans.push_back(j);
              break;
            }
          }
          break;
        }
      }
    }
    --k;
  }

  for (int i : ans) cout << i + 1 << ' ';
  cout << endl;
}

int32_t main() {
  CPPinput;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
