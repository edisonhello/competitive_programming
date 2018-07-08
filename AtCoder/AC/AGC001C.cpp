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

vector<int> G[2005];
int del[2005][2],sz[2005];

void dsz(int now,int pa){
    for(int i:G[now]){
        if(i==pa)continue;
        dsz(i,now);
        sz[now]+=sz[i];
    }
    ++sz[now];
}
int dfs(int now,int pa,int dis){
    if(dis==-1)return sz[now];
    if(dis==0)return sz[now]-1;
    int rt=0;
    for(int i:G[now]){
        if(i==pa)continue;
        rt+=dfs(i,now,dis-1);
    }
    return rt;
}

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].pb(v); G[v].pb(u);
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;++i){
        memset(del,0,sizeof(del));
        memset(sz ,0,sizeof(sz ));
        dsz(i,i);
        for(int j:G[i]){
            del[j][0]=dfs(j,i,k/2-1);
            if(k&1)del[j][1]=dfs(j,i,k/2);
        }
        int sum=0;
        for(int j:G[i])sum+=del[j][0];
        ans=min(ans,sum);
        if(k&1)for(int j:G[i])ans=min(ans,sum-del[j][0]+del[j][1]);
        PDE(ans);
    }
    cout<<ans<<endl;
}
