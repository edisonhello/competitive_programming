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

int solve(vector<int> v) {
  for (int &i : v) i = abs(i);
  sort(v.begin(), v.end());
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    for (int z = 0; z < (1 << n); ++z) {
      if (z & (1 << i)) continue;
      int sum = 0;
      for (int y = 0; y < n; ++y)
        if (z & (1 << y)) sum += v[y];
      if (sum == v[i]) {
        return 1;
      }
    }
  }

  for (int z = 1; z < (1 << n); ++z) {
    for (int y = 1; y < (1 << n); ++y) {
      if (z & y) continue;
      int sum = 0;
      for (int x = 0; x < n; ++x) {
        if (z & (1 << x)) sum += v[x];
        if (y & (1 << x)) sum -= v[x];
      }
      // PDE(y, z, sum);
      if (sum == 0) {
        return 1;
      }
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int z = 1; z < (1 << n); ++z) {
  //     for (int y = 1; y < (1 << n); ++y) {
  //       if (z | y) continue;
  //       if ((z | y) & (1 << i)) continue;
  //       int sum = 0;
  //       for (int x = 0; x < n; ++x) {
  //         if (z & (1 << x)) sum += v[x];
  //         if (y & (1 << x)) sum -= v[x];
  //       }
  //       if (sum == v[i]) {
  //         return 1;
  //       }
  //     }
  //   }
  // }

  PDE(v);
  // for (int i = 0; i < n; ++i)
  //   for (int j = i + 1; j < n; ++j)
  //     for (int k = j + 1; k < n; ++k)
  //       for (int l = k + 1; l < n; ++l) {
  //         if (v[j] - v[i] == v[l] - v[k]) return 1;
  //       }

  // do {
  //   bool yes = 0;
  //   auto dfs = [&] (auto dfs, vector<int> vv, int idx, set<int> &st) {
  //     if (st.count(vv[idx])) yes = 1;
  //     if (yes) return;
  //     for (int i = 0; i < vv.size(); ++i) {
  //       v

  //     }
  //   };

  //   vector<int> vv{0, v[0]};
  //   set<int> st;
  //   st.insert(v[0]);
  //   dfs(dfs, vv, 1, st);
  // } while (next_permutation(v.begin(), v.end()));

  return 0;
}

int main() {
  CPPinput;
  srand(time(0) * clock());
  vector<int> v(10);
  // while (true) {
  //   for (int i = 0; i < v.size(); ++i) v[i] = rand() % 100;
  //   vector<int> vv;
  //   for (int i = 0; i < v.size(); ++i) {
  //     int l = rand() % v.size(), r = rand() % v.size();
  //     vv.push_back(v[l] - v[r]);
  //   }
  //   if (solve(vv) == 0) {
  //     PDE(v, vv);
  //     exit(0);
  //   }
  // }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i], v[i] = abs(v[i]);
    int res = solve(v);

    if (res == 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
