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

long long tsum, osum[22];
vector<int> bx[22];
int ans[22][2];

void dfs(int now, int n, vector<int> &hand) {
    // PDE(now, n, hand);
    if (now == n) {
        vector<bool> take(n, 0);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int need = tsum / n - osum[i];
            bool got = false;
            for (int j = 0; j < n; ++j) if (hand[j] == need && !take[j]) {
                take[j] = 1;
                ans[j][1] = i;
                got = true;
                break;
            }
            // PDE(i, need, got);
            if (!got) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            for (int i = 0; i < n; ++i) cout << ans[i][0] << ' ' << ans[i][1] + 1 << '\n';
            exit(0);
        }
        return;
    }

    for (int i : bx[now]) {
        hand.push_back(i);
        osum[now] -= i;
        ans[now][0] = i;
        dfs(now + 1, n, hand);
        osum[now] += i;
        hand.pop_back();
    }
}

int main() {
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int t; cin >> t; while (t--) {
            int z; cin >> z;
            bx[i].push_back(z);
            osum[i] += z;
            tsum += z;
        }
        sort(bx[i].begin(), bx[i].end());
    }

    if (tsum % n) {
        cout << "No" << endl;
        exit(0);
    }

    vector<int> hand;
    dfs(0, n, hand);

    cout << "No" << endl;
}
