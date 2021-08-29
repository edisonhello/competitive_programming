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

struct Edge {
    int to, cap, rev;
    Edge(int t, int c, int r) : to(t), cap(c), rev(r) {}
};

int Flow(vector<vector<Edge>> &g, int s, int t) {
    int n = g.size(), res = 0;
    vector<int> lev(n, -1), iter(n);
    while (true) {
        vector<int> que(1, s);
        fill(lev.begin(), lev.end(), -1);
        fill(iter.begin(), iter.end(), 0);
        lev[s] = 0;
        for (int it = 0; it < que.size(); ++it) {
            int x = que[it];
            for (Edge &e : g[x]) {
                if (e.cap > 0 && lev[e.to] == -1) {
                    lev[e.to] = lev[x] + 1;
                    que.push_back(e.to);
                }
            }
        }
        if (lev[t] == -1) break;
        auto Dfs = [&](auto dfs, int x, int f = 1000000000) {
            if (x == t) return f;
            int res = 0;
            for (int &it = iter[x]; it < g[x].size(); ++it) {
                Edge &e = g[x][it];
                if (e.cap > 0 && lev[e.to] == lev[x] + 1) {
                    int p = dfs(dfs, e.to, min(f - res, e.cap));
                    res += p;
                    e.cap -= p;
                    g[e.to][e.rev].cap += p;
                }
            }
            if (res == 0) lev[x] = -1;
            return res;
        };
        res += Dfs(Dfs, s);
    }
    return res;
}

int main() {
    CPPinput;
    int n, k; cin >> n >> k;
    int most = n / (k - 1) + !!(n % (k - 1));

    vector<int> v(n * k + 10);
    for (int i = 1; i <= n * k; ++i) cin >> v[i];

    vector<vector<Edge>> g(n * k * 2 + n * 2 + 10);
    auto AddEdge = [&] (int u, int v, int f) {
      PDE(u, v, f);
      g[u].push_back(Edge(v, f, g[v].size() - 0u));
      g[v].push_back(Edge(u, 0, g[u].size() - 1u));
    };

    for (int i = 1; i <= n * k; ++i) {
      AddEdge(n * k * 2 + v[i], i, 1);
      AddEdge(i + n * k, n * k * 2 + n + v[i], 1);
      AddEdge(i + n * k, i, 100000);
    }

    for (int i = 2; i <= n * k; ++i) {
      AddEdge(i - 1, i + n * k, most);
    }

    for (int i = 1; i <= n; ++i) {
      AddEdge(0, n * k * 2 + i, 1);
      AddEdge(n * k * 2 + n + i, n * k * 2 + 2 * n + 1, 1);
    }

    // for (int i = 2; i <= n * k; ++i) AddEdge(i - 1, i, most);

    int res = Flow(g, 0, n * k * 2 + n * 2 + 1);
    PDE(res);
    assert(res == n);

    vector<int> in(n + 10, -1), out(n + 10, -1);
    for (int i = 1; i <= n * k; ++i) {
      for (auto e : g[i]) {
        if (e.to > n * k * 2 && e.to <= n * k * 2 + n && e.cap > 0) {
          in[v[i]] = i;
        } 
      }
      for (auto e : g[i + n * k]) {
        if (e.to > n * k * 2 + n && e.cap == 0) {
          out[v[i]] = i;
        }
      }
    }

    for (int i = 1; i <= n; ++i) cout << in[i] << ' ' << out[i] << '\n';

}
