// #pragma GCC optimize("no-stack-protector")
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

vint G[300005];

bool dfs1(int now,int pa,int dis){
    if(dis==now)return 1;
    for(int i:G[now]){
        if(i==pa)continue;
        if(dfs1(i,now,dis))return 1;
    }
    return 0;
}
int dfs2(int now,int pa){
PDE(now,pa);
    int rt=1;
    for(int i:G[now]){
        if(i!=pa)rt+=dfs2(i,now);
    }
    return rt;
}

int main(){
    CPPinput;
    int n,x,y; cin>>n>>x>>y;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    int toflr=-1;
    for(int i:G[y]){
        if(dfs1(i,y,x))toflr=i;
    }
    int cnt=1;
    for(int i:G[y]){
        if(i!=toflr)cnt+=dfs2(i,y);
    }
    int tobee=-1;
    for(int i:G[x]){
        if(dfs1(i,x,y))tobee=i;
    }
    int cnt2=1;
    for(int i:G[x]){
        if(i!=tobee){
            PDE(i);
            cnt2+=dfs2(i,x);
        }
    }
    PDE(cnt,cnt2);
    cout<<1ll*n*(n-1)-1ll*cnt*cnt2;
}
