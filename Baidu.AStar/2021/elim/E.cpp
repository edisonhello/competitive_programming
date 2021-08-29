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

int main() { 
  CPPinput; 
  srand(time(0) * clock());

  vector<pair<int, vector<pair<int, int>>>> qs;
  int t; cin >> t; while (t--) {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> op;
    for (int i = 0; i < n; ++i) {
      char c; cin >> c;
      int y; cin >> y;
      if (c == '+') op.emplace_back(1, y);
      else if (c == '*') op.emplace_back(2, y);
    }
    qs.emplace_back(x, op);
  }

  auto get_ans = [&] (int i) -> int {
    auto &q = qs[i];
    int x = q.first;
    auto &op = q.second;
    int n = op.size();
    swap(op[rand() % n], op[rand() % n]);
    for (int j = 0; j < n; ++j) {
      if (op[j].first == 1) {
        x = (x + op[j].second);
        if (x >= mod) x -= mod;
      } else {
        x = 1ll * x * op[j].second % mod;
      }
    }
    return x;
  };

  vector<pair<int, int>> answers;

  int n = qs.size();
  for (int i = 0; i < n; ++i) {
    int x = get_ans(i);
    answers.emplace_back(i, x);
  }

  while (clock() < 1.95 * CLOCKS_PER_SEC) {
    for (int i = 0; i < n; ++i) {
      int mx = INT_MAX;
      for (int _ = 0; _ < 100; ++_) {
        mx = min(mx, get_ans(answers[i].first));
      }
      if (mx < answers[i].second) answers[i].second = mx;
    }

    sort(answers.begin(), answers.end(), [&] (const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; });

    for (int i = 0; i < min(100, n); ++i) {
      int mx = INT_MAX;
      for (int _ = 0; _ < 1000; ++_) {
        mx = min(mx, get_ans(answers[i].first));
      }
      if (mx < answers[i].second) answers[i].second = mx;
    }
  }

  sort(answers.begin(), answers.end(), [&] (const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
  
  for (int i = 0; i < n; ++i) cout << answers[i].second << '\n';

}
