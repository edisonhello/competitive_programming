#pragma GCC optimize("O3")
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

int a[1000006];
int dp[1006][7][7][7];

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        ++a[t];
    }
    // for(int i=1;i<=m;++i)PDE(i,a[i]);
    int ans=0;
    for(int i=1;i<=m;++i){
        while(a[i]>6 && a[i+1]>6 && a[i+2]>6){
            a[i]-=3; a[i+1]-=3; a[i+2]-=3;
            ans+=3;
        }
        while(a[i]>6){
            a[i]-=3;
            ans+=1;
        }
    }
    // at most left 6
#define upd(a,b) a=max(a,b)
    memset(dp,0xc0,sizeof(dp));
    dp[0][0][0][0]=0;
    for(int i=0;i<=m+4;++i){
        int cur=i%1000;
        int nxt=(i+1)%1000;
        memset(dp[nxt],0xc0,7*7*7*4);
        for(int j=6;j>=0;--j){
            for(int k=6;k>=0;--k){
                for(int l=6;l>=0;--l){
                    upd(dp[nxt][k][l][a[i+1]],dp[cur][j][k][l]);
                    if(j>=3)upd(dp[cur][j-3][k][l],dp[cur][j][k][l]+1);
                    if(j&&k&&l)upd(dp[cur][j-1][k-1][l-1],dp[cur][j][k][l]+1);
                }
            }
        }
    }
    int mx=0;
    int tak=(m+3)%1000;
    for(int j=0;j<7;++j){
        for(int k=0;k<7;++k){
            for(int l=0;l<7;++l){
                mx=max(mx,dp[tak][j][k][l]);
            }
        }
    }
    cout<<ans+mx<<endl;
}
