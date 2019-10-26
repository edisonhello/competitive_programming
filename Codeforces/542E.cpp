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
#define WHR() printf("%s: Line %d", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), fflush(stdout)
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

vector<int> g[1005];
int c[1005];

void dfs(int x, int nc) {
    c[x] = nc;
    for (int i : g[x]) {
        if (c[i]) {
            if (c[i] == nc) {
                JIZZ("-1");
            }
        } else {
            dfs(i, -nc);
        }
    }
}

int djs[1005];
int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
int mx[1005];
int d[1005];

void go(int s) {
    memset(d, -1, sizeof(d));
    queue<int> q; q.push(s); d[s] = 0;
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i : g[x]) {
            if (d[i] == -1) {
                d[i] = d[x] + 1;
                q.push(i);
                mx[F(s)] = max(mx[F(s)], d[i]);
            }
        }
    }
}

int main() {
    CPPinput;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) djs[i] = i;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        djs[F(u)] = F(v);
    }
    for (int i = 1; i <= n; ++i) if (!c[i]) dfs(i, 1);
    for (int i = 1; i <= n; ++i) go(i);
    cout << accumulate(mx, mx + 1005, 0) << endl;
}
