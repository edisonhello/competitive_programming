// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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


vint G[200005];
bitset<200005> trash;
ll djs[200005],dp[200005][5];

int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }

void dfs(int now,int pa){
    PDE("dfs",now);
    if(G[now].size()==1u){
        dp[now][0]=1;
        dp[now][1]=1e7;
        dp[now][2]=0;
        return;
    }
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
    }
    ll add=1;
    for(int i:G[now]){
        if(i==pa)continue;
        add+=min(dp[i][0],min(dp[i][1],dp[i][2]));
    }
    dp[now][0]=add;
    add=0;
    ll take=0;
    ll delta=1e9;
    for(int i:G[now]){
        if(i==pa)continue;
        if(dp[i][0]<=dp[i][1])add+=dp[i][0],++take;
        else add+=dp[i][1],delta=min(delta,dp[i][0]-dp[i][1]);
    }
    if(!take)add+=delta;
    dp[now][1]=add;
    add=0;
    for(int i:G[now]){
        if(i==pa)continue;
        add+=min(dp[i][0],dp[i][1]);
    }
    dp[now][2]=add;
    PDE(now,dp[now][0],dp[now][1],dp[now][2]);
}

int main(){
    CPPinput;
    MS(dp,0x3f);
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        if(v<u)swap(u,v);
        /* if(u==1){
            trash[1]=1;
            trash[v]=1;
            continue;
        } */
        G[u].pb(v);
        G[v].pb(u);
        U(u,v);
    }

    ll ans=0;
    for(int i:G[1]){
        if(G[i].size()==1u){ continue; }
        dfs(i,1);
        ans+=min(dp[i][0]-1,dp[i][1]);
    }
    PDE(ans);
    cout<<ans<<endl;
}
