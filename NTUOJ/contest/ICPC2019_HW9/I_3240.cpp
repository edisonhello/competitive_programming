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

#include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
using namespace __gnu_pbds;

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

cc_hash_table<int, vector<pair<int, int>>> mp;

int main() {
    CPPinput;
    int curmaxsize = 0;
    for (long long i = 330000000; ; ++i) {
        vector<pair<long long, long long>> ans;
        for (long long x = 0; 2 * x * x <= i; ++x) {
            long long yy = sqrt(i - x * x);
            for (long long y = yy - 2; y <= yy + 2; ++y) {
                if (x * x + y * y == i) {
                    set<pair<long long, long long>> st;
                    st.insert(make_pair(x, y));
                    st.insert(make_pair(y, x));
                    st.insert(make_pair(-x, y));
                    st.insert(make_pair(y, -x));
                    st.insert(make_pair(x, -y));
                    st.insert(make_pair(-y, x));
                    st.insert(make_pair(-x, -y));
                    st.insert(make_pair(-y, -x));
                    for (auto p : st) ans.push_back(p);
                }
            }
        }
        if ((int)ans.size() >= 1000) {
            for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
            exit(0);
        }
        curmaxsize = max(curmaxsize, (int)ans.size());
        if ((i & 65535) == 0) cerr << "r = " << i << ", curmax = " << curmaxsize << endl;
    }
    // for (int i = 0; i <= 10000; ++i) {
    //     for (int j = 0; j <= 10000; ++j) {
    //         int x = i * i + j * j;
    //         set<pair<int, int>> st;
    //         st.insert(make_pair(i, j));
    //         st.insert(make_pair(j, i));
    //         st.insert(make_pair(-i, j));
    //         st.insert(make_pair(j, -i));
    //         st.insert(make_pair(i, -j));
    //         st.insert(make_pair(-j, i));
    //         st.insert(make_pair(-i, -j));
    //         st.insert(make_pair(-j, -i));
    //         for (auto p : st) mp[x].push_back(p);
    //     }
    // }
    // int n; cin >> n;
    // for (auto &p : mp) {
    //     if ((int)p.second.size() >= n) {
    //         for (int i = 0; i < n; ++i) cout << p.second[i].first << ' ' << p.second[i].second << '\n';
    //         break;
    //     }
    // }
}
