
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
#define RZUNI(x)                                                               \
  sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname)                                                             \
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
#define WHR()                                                                  \
  printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...)                                                               \
  printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__),  \
      puts(""), fflush(stdout)
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

pair<int, vector<int>> solve_one(vector<int> a) {
  int n = a.size();
  vector<vector<int>> poss(n + 5);
  set<int> left;
  for (int i = 0; i < n; i++) {
    poss[a[i]].push_back(i);
    left.insert(a[i]);
  }

  vector<int> ans(n);
  int cnt = 0;
  while (left.size() > 0) {
    vector<int> pos;
    vector<int> remv;
    for (int i : left) {
      pos.push_back(poss[i].back());
      poss[i].pop_back();
      if (poss[i].empty()) {
        remv.push_back(i);
      }
    }

    cnt += pos.size() - 1;

    for (int i : remv)
      left.erase(i);

    for (int i = 0; i < (int)pos.size(); ++i) {
      int j = (i + 1) % pos.size();
      ans[pos[i]] = a[pos[j]];
    }
  }

  return pair{cnt, ans};
}

void solve() {
  int n;
  // cin >> n;
  n = rand() % 1000 + 1;
  vector<int> a(n);
  vector<int> b(n);
  // for (int i = 0; i < n; i++)
  //   cin >> a[i];
  // for (int i = 0; i < n; i++)
  //   cin >> b[i];
  for (int i = 0; i < n; ++i)
    a[i] = rand() % n + 1;

  auto [ans, solution] = solve_one(a);

  b = solution;

  vector<vector<int>> g(n + 5);
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i])
      g[a[i]].push_back(b[i]);
  }

  vector<int> rec;
  vector<int> inrec(n + 5);
  int swaps = 0;
  int backing = 0;

  auto dfs = [&](auto dfs, int now) {
    // cout << "dfs " << now << endl;
    if (inrec[now]) {
      // cout << "find loop" << endl;
      backing = now;
      --swaps;
      return;
    }

    inrec[now] = 1;
    rec.push_back(now);

    while (g[now].size()) {
      int to = g[now].back();
      g[now].pop_back();

      ++swaps;

      // cout << now << " dfs to " << to << endl;
      dfs(dfs, to);

      if (backing != now) {
        // cout << "find loop backing " << now << endl;
        rec.pop_back();
        inrec[now] = 0;
        return;
      } else {
        // cout << "backing finish " << now << endl;
        backing = 0;
      }
    }

    inrec[now] = 0;
    rec.pop_back();
  };

  for (int i = 1; i <= n; ++i)
    dfs(dfs, i);

  if (swaps == ans) {
    cout << "AC\n";
  } else {
    cout << "WA\n";
    assert(0);
  }
}

int32_t main() {
  srand(time(0) * clock());
  CPPinput;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
