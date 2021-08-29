// #pragma GCC optimize("no-stack-protector")
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

bool re(string ans) {
  int n = ans.size();
  for (int i = 1; i < n - 1; ++i) {
    if (ans[0] == ans[i] && ans[1] == ans[i + 1]) return 1;
  }
  return 0;
}

void check(string ans) {
  if (re(ans)) {
    cout << "Bad answer" << endl;
    exit(1);
  }

  string oans = ans;
  sort(ans.begin(), ans.end());

  do {
    if (!re(ans)) {
      if (ans < oans) {
        cout << "better: " << ans << endl;
        exit(1);
      }
    }
  } while (next_permutation(ans.begin(), ans.end()));

  cerr << "pass" << endl;
}

void solve() {
  string s; cin >> s;
  vector<int> cnt(256, 0);
  for (char c : s) ++cnt[c];
  int n = s.size();

  string ans;

  int fi = -1, se = -1, th = -1;
  for (int i = 0; i < 256; ++i) {
    if (cnt[i] == n) {
      cout << s << '\n';
      return;
    }
    if (cnt[i] > 0) {
      if (fi == -1) fi = i;
      else if (se == -1) se = i;
      else if (th == -1) th = i;
    }
  }

  int other = n - cnt[fi] - cnt[se];

  ans += (char)fi;
  cnt[fi]--;

  auto put = [&] (int x) { ans += char(x); --cnt[x]; };

  if (cnt[fi] <= (n - 1) - cnt[fi] + 1) {
    for (int i = se; i < 256; ++i) {
      while (cnt[i] > 0) {
        if (cnt[fi] > 0) {
          put(fi);
        }
        put(i);
      }
    }
    if (cnt[fi]) put(fi);

    cout << ans << '\n';
    check(ans);
    assert(ans.size() == n);
    return;
  }

  if (th == -1) {
    while (cnt[se] > 0) put(se);
    while (cnt[fi] > 0) put(fi);
    cout << ans << '\n';
    check(ans);
    assert(ans.size() == n);
    return;
  }

  put(se);

  while (cnt[fi] > 0) put(fi);
  put(th);

  for (int i = se; i < 256; ++i) {
    while (cnt[i] > 0) {
      put(i);
    }
  }
  cout << ans << '\n';
  check(ans);
    assert(ans.size() == n);
}

int main() {
    CPPinput;
    int t; cin >> t; while (t--) solve();
}
