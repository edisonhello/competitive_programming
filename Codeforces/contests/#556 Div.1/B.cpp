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

int nxt[100005][26];
int dp[255][255][255];

int main(){
    CPPinput;
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < 26; ++i) nxt[n][i] = nxt[n + 1][i] = n + 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i + 1;
    }
    string str[5]; str[1] = str[2] = str[3] = " ";
    int len[5] = {0};
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    while (q--) {
        char c; cin >> c;
        if (c == '+') {
            int i; cin >> i >> c;
            ++len[i]; str[i] += c;
            // dp[len[1]][len[2]][len[3]] = 0x3f3f3f3f;
            auto update = [&](int i, int j, int k) {
                if (i) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[dp[i - 1][j][k]][str[1][i] - 'a']);
                }
                if (j) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j - 1][k]][str[2][j] - 'a']);
                }
                if (k) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k - 1]][str[3][k] - 'a']);
                }
            };
            if (i == 1) {
                for (int i = 0; i <= len[2]; ++i) {
                    for (int j = 0; j <= len[3]; ++j) {
                        dp[len[1]][i][j] = 0x3f3f3f3f;
                        update(len[1], i, j);
                    }
                }
            } else if (i == 2) {
                for (int i = 0; i <= len[1]; ++i) {
                    for (int j = 0; j <= len[3]; ++j) {
                        dp[i][len[2]][j] = 0x3f3f3f3f;
                        update(i, len[2], j);
                    }
                }
            } else {
                for (int i = 0; i <= len[1]; ++i) {
                    for (int j = 0; j <= len[2]; ++j) {
                        dp[i][j][len[3]] = 0x3f3f3f3f;
                        update(i, j, len[3]);
                    }
                }
            }
        } else {
            int i; cin >> i;
            --len[i]; str[i].pop_back();
        }
        PDE(dp[len[1]][len[2]][len[3]]);
        if (dp[len[1]][len[2]][len[3]] <= n) cout << "YES\n";
        else cout << "NO\n";
    }
}

