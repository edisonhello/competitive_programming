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
const long long mod = 998244353;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
inline char gtx() {
    const int N=4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    } return *p++;
}

template <typename T>
inline void rit(T &x) {
    char c; bool fg = 0;
    while (c = gtx(), (c < '0' && c != '-') || c > '9');
    c == '-' ? (fg = 1, x = 0) : (x = c & 15);
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    if (fg) x = -x;
}
template <typename T, typename ...Args>
inline void rit(T& x, Args& ...args) { rit(x), rit(args...); }

template <typename T>
inline void ruit(T &x) {
    char c;
    while (c = gtx(), c < '0' || c > '9');
    x = c & 15;
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
}
template <typename T, typename ...Args>
inline void ruit(T& x, Args& ...args) { ruit(x), ruit(args...); }

template <typename T>
inline bool rit_save(T &x) {
    char c; bool fg = 0;
    while (c = gtx(), (c < '0' && c != '-') || c > '9') if (c == EOF) return false;
    c == '-' ? (fg = 1, x = 0) : (x = c & 15);
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    if (fg) x = -x; return true;
}
template <typename T, typename ...Args>
inline bool rit_save(T& x, Args& ...args) { return rit_save(x) && rit_save(args...); }

template <typename T>
inline bool ruit_save(T &x) {
    char c;
    while (c = gtx(), c < '0' || c > '9') if (c == EOF) return false;
    x = c & 15;
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    return true;
}
template <typename T, typename ...Args>
inline bool ruit_save(T& x, Args& ...args) { return ruit_save(x) && ruit_save(args...); }

struct outputter {
    char buffer[4112], *ptr = buffer, *end = buffer + 4096;
    inline void writebyte(char c) {
        *ptr = c; ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr-buffer, stdout), ptr = buffer;
    }
    template <typename T> inline void writeint(T x, char endc = '\n') {
        if (x < 0) *ptr = '-', ++ptr, x = -x; if (!x) *ptr = '0', ++ptr;
        char *s = ptr, c; T t;
        while (x) { t = x / 10; c = x - 10 * t + '0'; *ptr = c, ++ptr, x = t; }
        char *f = ptr - 1; while (s < f) swap(*s, *f), ++s, --f;
        *ptr = endc, ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr - buffer, stdout), ptr = buffer;
    }

    template <typename T>
    inline void output(T x) { writeint(x, '\n'); }
    template <typename T,typename ...Args>
    inline void output(T x,Args ...args) { writeint(x, ' '); output(args...); }

    template <typename ...Args> inline void operator()(Args ...args) { output(args...); }
    outputter() {}
    ~outputter() { fwrite(buffer, sizeof(char), ptr - buffer, stdout); }
} pit;
#pragma GCC diagnostic pop

int pw(int b, int n) {
  int a = 1;
  while (n) {
    if (n & 1) a = 1ll * a * b % mod;
    b = 1ll * b * b % mod; n >>= 1;
  }
  return a;
}
int inv(int x) { return pw(x, mod - 2); }

vector<pair<int, int>> g[105];

#define mat vector<vector<int>>

int n;

void init(mat &m) {
  m.resize(n + n + 5);
  for (auto &v : m) {
    v.resize(n + n + 5);
    for (auto &i : v) i = 0;
  }
}

mat mprod(mat a, mat b) {
  mat r;
  init(r);
  for (int i = 1; i <= n + n; ++i) {
      for (int k = 1; k <= n + n; ++k) {
    for (int j = 1; j <= n + n; ++j) {
        r[i][j] = (r[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return r;
}

mat mpw(mat b, int n) {
  mat a;
  init(a);
  for (int i = 1; i <= ::n + ::n; ++i) a[i][i] = 1;
  while (n) {
    if (n & 1) a = mprod(a, b);
    b = mprod(b, b); n >>= 1;
  }
  return a;
}

void solve() {
      int m, k; rit(n,m,k);
      for (int i = 1; i <= n; ++i) g[i].clear();

      while (m--) {
        int u, v, w; rit(u, v, w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
      }

      mat tr;
      init(tr);

      for (int i = 1; i <= n; ++i) {
        auto op = [&] (int x) { return x <= n ? x + n : x - n; };

        int od = g[i].size();
        int fm = inv(od);
        for (auto e : g[i]) {
          int u = e.first;
          if (!e.second) {
            tr[i][u] = fm;
            tr[op(i)][op(u)] = fm;
          } else {
            tr[i][op(u)] = fm;
            tr[op(i)][u] = fm;
          }
        }
      }


      tr = mpw(tr, k);

      pit(tr[1][n + n]);

}

int32_t main() {
    int t; rit(t); while (t--) {
      solve();
    }
}
