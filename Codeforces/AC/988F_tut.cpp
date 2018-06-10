// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
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

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

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
#define exp expexpexpexp
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

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int dp[2005][2005];
vector<int> umi[2005];
int uw[2005];
int rai[2005];

int main(){
    CPPinput;
    int x,n,m; cin>>x>>n>>m;
    while(n--){
        int l,r; cin>>l>>r; --r;
        for(int i=l;i<=r;++i)rai[i]=1;
    }
    for(int i=1;i<=m;++i){
        int x,p; cin>>x>>p;
        umi[x].pb(i);
        uw[i]=p;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i:umi[0])dp[0][i]=0;
    for(int i=1;i<=x;++i){
        int mn=INT_MAX;
        for(int z=(rai[i-1]?1:0);z<=m;++z)mn=min(mn,dp[i-1][z]+uw[z]);
        // cout<<"rai "<<rai[i-1]<<" , mn : "<<mn<<endl;
        dp[i][0]=mn;
        for(int j:umi[i])dp[i][j]=mn;
        for(int j=1;j<=m;++j)if(dp[i-1][j]!=0x3f3f3f3f)dp[i][j]=dp[i-1][j]+uw[j];
    }
    int ans=INT_MAX;
    for(int i=0;i<=m;++i)ans=min(ans,dp[x][i]);
    cout<<(ans>1e9+3?-1:ans)<<endl;
}
