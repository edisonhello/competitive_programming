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

int djs[4004];

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }
void U(int x, int y) { djs[F(x)] = F(y); }

int cnt[4004];
int dp[4004][2004], uu[4004][2004];
int gans[4004];

int main(){
    CPPinput;
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        cout << "Case #" << T << ": ";
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; ++i) djs[i] = i, cnt[i] = 0, gans[i] = 0;
        while (m--) {
            int l, r; cin >> l >> r;
            while (l < r) U(l, r), ++l, --r;
        }
        for (int i = 1; i <= n; ++i) ++cnt[F(i)];
        vector<pair<int, int>> ws;
        for (int i = 1; i <= n; ++i) if (cnt[i]) ws.emplace_back(cnt[i], i);
        // PDE(ws);
        for (int i = 0; i <= n; ++i) for (int j = 0; j <= n / 2 + 1; ++j) dp[i][j] = -100000000, uu[i][j] = 0;
        dp[0][0] = 0;
        for (int i = 1; i <= (int)ws.size(); ++i) {
            for (int j = 0; j < ws[i - 1].first; ++j) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = ws[i - 1].first; j <= n / 2; ++j) {
                if (dp[i - 1][j - ws[i - 1].first] + ws[i - 1].first >= dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - ws[i - 1].first] + ws[i - 1].first;
                    uu[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int ii = ws.size(), jj = n / 2;
        while (uu[ii][jj] < 0) --jj;
        while (ii) {
            if (uu[ii][jj]) {
                gans[ws[ii - 1].second] = 1;
                jj -= ws[ii - 1].first;
            }
            --ii;
        }
        for (int i = 1; i <= n; ++i) cout << gans[F(i)]; cout << '\n';
    }
}
