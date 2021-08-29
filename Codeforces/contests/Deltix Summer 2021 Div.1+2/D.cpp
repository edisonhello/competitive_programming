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


int main() {
    CPPinput;
    srand(time(0) * clock());
    int n, k; cin >> n >> k;

#ifdef LOCAL
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = rand() % 123123;
#endif

    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
#ifdef LOCAL
      a[i] = ans[i] & ans[(i + 1) % n];
      b[i] = ans[i] | ans[(i + 1) % n];
#else
      cout << "and " << i + 1 << ' ' << i + 2 << endl;
      cin >> a[i];
      cout << "or " << i + 1 << ' ' << (i + 2) << endl;
      cin >> b[i];
#endif
    }
#ifdef LOCAL
    int extra = ans[0] & ans[2];
#else
    cout << "and " << 1 << ' ' << 3 << endl;
    int extra; cin >> extra;
#endif

    vector<int> v(n, 0);
    for (int z = 30; z >= 0; --z) {
      vector<int> tmp;
      for (int i = 0; i < n - 1; ++i) 
        tmp.push_back((a[i] & (1 << z)) ? 2 : (b[i] & (1 << z)) ? 1 : 0);
      int allb = 1;
      for (int i : tmp) if (i != 1) allb = 0;
      if (allb) {
        if (extra & (1 << z)) {
          for (int i = 0; i < n; i += 2) v[i] |= 1 << z;
        } else {
          for (int i = 1; i < n; i += 2) v[i] |= 1 << z;
        }
      } else {
        int start = 0;
        for (int i = 0; i < n - 1; ++i) {
          if (tmp[i] == 0) {
            start = 1;
          } else if (tmp[i] == 1) {
            if (start) {
              if (!(v[i] & (1 << z))) v[i + 1] |= 1 << z;
            }
          } else {
            start = 1;
            v[i] |= 1 << z;
            v[i + 1] |= 1 << z;
          }
        }

        start = 0;
        for (int i = n - 2; i >= 0; --i) {
          if (tmp[i] == 0) {
            start = 1;
          } else if (tmp[i] == 1) {
            if (start) {
              if (!(v[i + 1] & (1 << z))) v[i] |= 1 << z;
            }
          } else {
            start = 1;
            v[i] |= 1 << z;
            v[i + 1] |= 1 << z;
          }
        }
      }
    }

#ifdef LOCAL
    if (v != ans) {
      cout << "a   = ";
      for (int i : a) cout << i << ' ';
      cout << endl;
      cout << "b   = ";
      for (int i : b) cout << i << ' ';
      cout << endl;
      
      cout << "get = ";
      for (int i : v) cout << i << ' ';
      cout << endl;
      cout << "ans = ";
      for (int i : ans) cout << i << ' ';
      cout << endl;
    }
#else
    sort(v.begin(), v.end());
    cout << "finish " << v[k - 1] << endl;
#endif
}
