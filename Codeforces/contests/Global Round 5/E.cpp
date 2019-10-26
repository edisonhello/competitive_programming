#pragma GCC optimize("O3")
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
const long long mod = 998244353;

long long dp[1000006][2];
bitset<2> vis[1000006];

void solve(int n, int prt) {
    if (n <= 3) return;
    if (vis[n][prt]) return;
    if ((n ^ prt) & 1) return;
    if (7 <= n && n <= 8) return;
    if (15 <= n && n <= 19) return;
    if (31 <= n && n <= 40) return;
    if (63 <= n && n <= 83) return;
    if (127 <= n && n <= 168) return;
    if (255 <= n && n <= 339) return;
    if (511 <= n && n <= 680) return;
    if (1023 <= n && n <= 1363) return;
    if (2047 <= n && n <= 2728) return;
    if (4095 <= n && n <= 5459) return;
    if (8191 <= n && n <= 10920) return;
    if (16383 <= n && n <= 21843) return;
    if (32767 <= n && n <= 43688) return;
    if (65535 <= n && n <= 87379) return;
    if (131071 <= n && n <= 174760) return;


    vis[n][prt] = 1;

    int FULL = (1 << 20) - 1;
    while (FULL > n) FULL >>= 1;
    int LRBASE = FULL / 2;
    int FREE = n - 1 - LRBASE * 2;
    // long long __SUM = 0;
    for (int FREEFORL = 0; FREEFORL <= FREE; ++FREEFORL) {
        int LSIZE = LRBASE + FREEFORL;
        int RSIZE = LRBASE + (FREE - FREEFORL);
        int ROOT = LSIZE + 1;
        if ((ROOT & 1) != prt) continue;
        solve(LSIZE, (ROOT & 1) ^ 1), solve(RSIZE, 0);
        long long &ans = dp[n][ROOT & 1];
        ans += 1ll * dp[LSIZE][(ROOT & 1) ^ 1] * dp[RSIZE][0];
        ans %= mod;
        if (1ll * dp[LSIZE][(ROOT & 1) ^ 1] * dp[RSIZE][0]) PDE(n, prt, ROOT, LSIZE, RSIZE, ans);
        // for (auto LP : dp[LSIZE][(ROOT & 1) ^ 1]) {
        //     for (auto RP : dp[RSIZE][0]) {
        //         if (((ROOT ^ LP.first) & 1) && !(RP.first & 1)) {
        //             long long &ans = dp[i][ROOT & 1];
        //             ans += 1ll * LP.second * RP.second;
        //             ans %= mod;
        //             __SUM += 1ll * LP.second * RP.second;
        //             __SUM %= mod;
        //         }
        //     }
        // }
    }
}

int main() {
    CPPinput;
    dp[1][1] = 1;
    dp[2][0] = 1;


    auto sum = [&] (int x) {
        solve(x, 0);
        solve(x, 1);
        return dp[x][0] + dp[x][1];
    };

    sum(1000);

    // for (int i = 4; i < 200; i += 2) {
    //     cout << "i = " << setw(6) << i << setw(20) << sum(i) << setw(20) << sum(i + 1) << endl;
    // }
    // for (int i = 4; i <= 1000000; ++i) {
    //     if (!sum(i) && sum(i - 1)) cout << "if (" << i << " <= n &";
    //     if (!sum(i) && sum(i + 1)) cout << "& n <= " << i << ") return;" << endl;
    // }

    int n; cin >> n; 
    if (n <= 2) cout << 1 << endl;
    cout << sum(n) << endl;

    // for (int i = 5; i < 2000; ++i) {
    //     solve(i, 0), solve(i, 1);
    //     PDE(i, dp[i][0], dp[i][1]);
    // }

    //     solve(n, 0);
    //     solve(n, 1);
    //     cout << (dp[n][0] + dp[n][1]) % mod << endl;
    //     // int FULL = (1 << 20) - 1;
    //     // while (FULL > n) FULL >>= 1;
    //     // int LRBASE = FULL / 2;
    //     // int FREE = n - 1 - LRBASE * 2;
    //     // long long __SUM = 0;
    //     // for (int FREEFORL = 0; FREEFORL <= FREE; ++FREEFORL) {
    //     //     int LSIZE = LRBASE + FREEFORL;
    //     //     int RSIZE = LRBASE + (FREE - FREEFORL);
    //     //     int ROOT = LSIZE + 1;
    //     //     solve(LSIZE, (ROOT & 1) ^ 1), solve(RSIZE, 0);
    //     //     for (auto LP : dp[LSIZE][(ROOT & 1) ^ 1]) {
    //     //         for (auto RP : dp[RSIZE][0]) {
    //     //             if (((ROOT ^ LP.first) & 1) && !(RP.first & 1)) {
    //     //                 long long &ans = dp[n][ROOT & 1];
    //     //                 ans += 1ll * LP.second * RP.second;
    //     //                 ans %= mod;
    //     //                 __SUM += 1ll * LP.second * RP.second;
    //     //                 __SUM %= mod;
    //     //             }
    //     //         }
    //     //     }
    //     // }
    //     // cout << __SUM << endl;
    // }
    // bool _P_WARP = true;
    // for (int i = 4; i <= 300; ++i) {
    //     int FULL = (1 << 20) - 1;
    //     while (FULL > i) FULL >>= 1;
    //     int LRBASE = FULL / 2;
    //     int FREE = i - 1 - LRBASE * 2;
    //     long long __SUM = 0;
    //     for (int FREEFORL = 0; FREEFORL <= FREE; ++FREEFORL) {
    //         int LSIZE = LRBASE + FREEFORL;
    //         int RSIZE = LRBASE + (FREE - FREEFORL);
    //         int ROOT = LSIZE + 1;
    //         for (auto LP : dp[LSIZE]) {
    //             for (auto RP : dp[RSIZE]) {
    //                 if (((ROOT ^ LP.first) & 1) && !(RP.first & 1)) {
    //                     long long &ans = dp[i][ROOT];
    //                     ans += 1ll * LP.second * RP.second;
    //                     ans %= mod;
    //                     __SUM += 1ll * LP.second * RP.second;
    //                     __SUM %= mod;
    //                 }
    //             }
    //         }
    //     }
    //     // if (__SUM) PDE(i, __SUM);
    //     if (__SUM == 0) { if (!_P_WARP) cout << endl; _P_WARP = true; }
    //     else { cout << __SUM << ' '; _P_WARP = false; }
    // }
}
