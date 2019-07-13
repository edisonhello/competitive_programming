// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
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
#define pii pair<int,int>
#define vint vector<int>
#define vpii vector<pair<int,int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

void upd(int &x, int y) { x = min(x, y); }

int dp[305][3][305];
int go_dp(string &s, int mx, int first) { // mx = max times of context switching
    PDE("go_dp", s, mx, first);
    int n = (int)s.size() - 1; // s[0] == ' '
    for (int i = 0; i <= mx; ++i) for (int j = 0; j <= mx; ++j) dp[i][0][j] = dp[i][1][j] = dp[i][2][j] = 10000000;
    dp[0][first][1] = 0;

    for (int i = 1; i <= n; ++i) for (int j = 0; j <= i; ++j) {
        for (int cur = 0; cur <= 1; ++cur) for (int prv = 0; prv <= 1; ++prv) {
            if (s[i] - 'A' != cur && prv != cur) continue;
            if (prv == cur) {
                upd(dp[i][cur][j], dp[i - 1][prv][j] + 1);
            }
            if (s[i] - 'A' == cur) {
                if (cur == prv) upd(dp[i][cur][j], dp[i - 1][prv][j]);
                else upd(dp[i][cur][j + 1], dp[i - 1][prv][j]);
            }
        }
    }
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= i; ++j) PDE(i, j, dp[i][0][j], dp[i][1][j], dp[i][2][j]);
    int mn = INT_MAX;
    for (int j = 0; j <= mx; ++j) mn = min(mn, min(dp[n][0][j], min(dp[n][1][j], dp[n][2][j])));
    // PDE(mn);
    return mn;
}

int ans[100005];

void go(vector<string> &st, vector<pair<int, int>> &qs, int L, int R) {
    if (qs.empty()) return;
    // PDE("go", L, R);
    if (L == R) {
        for (auto &p : qs) ans[p.second] = L;
        return;
    }
    int mid = (L + R) >> 1; // expected context switching times
    int tot1 = 0, tot2 = 0;
    for (auto &s : st) tot1 += go_dp(s, mid, 0); // calc number of papers needs to be ignore
    for (auto &s : st) tot2 += go_dp(s, mid, 1);
    int tot = min(tot1, tot2);
    vector<pair<int, int>> ql, qr;
    for (auto &p : qs) {
        if (p.first < tot) qr.push_back(p);
        else ql.push_back(p);
    }
    // PDE(mid, tot, ql, qr);
    go(st, ql, L, mid);
    go(st, qr, mid + 1, R);
}

vector<string> fuck(vector<string> v) {
    vector<string> r(v[0].size(), " ");
    for (string s : v) {
        for (int i = 0; i < (int)s.size(); ++i) r[i].push_back(s[i]);
    }
    return r;
}

int main(){
    CPPinput;
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        int n, m, q; cin >> n >> m >> q;
        vector<string> st; st.reserve(n);
        string s;
        for (int i = 0; i < n; ++i) cin >> s, st.push_back(s);
        st = fuck(st);
        // for (auto &s : st) for (char &c : s) c -= 'A'; // 0 or 1
        // vector<pair<int, int>> qs(q);
        // for (int i = 0; i < q; ++i) cin >> qs[i].first, qs[i].second = i;
        // PDE(n, m, q, st, qs);
        vector<int> ans1(303, 0), ans2(303, 0);
        for (string s : st) {
            go_dp(s, 300, 0);
            int mn = INT_MAX;
            for (int j = 0; j <= 300; ++j) mn = min(mn, min(dp[s.size() - 1][0][j], dp[s.size() - 1][1][j])), ans1[j] += mn;
        }
        for (string s : st) {
            go_dp(s, 300, 1);
            int mn = INT_MAX;
            for (int j = 0; j <= 300; ++j) mn = min(mn, min(dp[s.size() - 1][0][j], dp[s.size() - 1][1][j])), ans2[j] += mn;
        }
        vector<int> ans(303);
        for (int i = 0; i <= 300; ++i) ans[i] = min(ans1[i], ans2[i]);
        PDE(ans1, ans2, ans);
        cout << "Case #" << T << ": ";
        while (q--) {
            int qq; cin >> qq;
            PDE(qq);
            for (int i = 0; i <= 300; ++i) if (ans[i] <= qq) {
                cout << i << "\n "[!!q];
                break;
            }
        }
        // go(st, qs, 1, 300);

        // for (int i = 0; i < q; ++i) cout << ans[i] << " \n"[i == q - 1];
    }
}
