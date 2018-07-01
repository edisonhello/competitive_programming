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

struct edge{
    int u,v;
    ll f;
    edge(int u=0,int v=0,ll f=0):u(u),v(v),f(f){}
};
vector<edge> edg;
vector<int> G[105];

void ae(int u,int v,ll f){
    G[u].pb(edg.size());
    edg.eb(u,v,f);
    G[v].pb(edg.size());
    edg.eb(v,u,0);
}

int d[105],idx[105];

bool bfs(int s,int t){
    queue<int> q; q.push(s); d[s]=1;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(!d[e.v] && e.f>0){
                d[e.v]=d[now]+1;
                q.push(e.v);
            }
        }
    }
    return d[t];
}
ll dfs(int now,ll nf,int t){
    if(now==t)return nf;
    ll rt=0;
    for(int &i=idx[now];i<G[now].size();++i){
        int eid=G[now][i];
        edge &e=edg[eid];
        if(e.f && d[e.v]==d[now]+1){
            ll f=dfs(e.v,min(nf,e.f),t);
            rt+=f;
            nf-=f;
            e.f-=f;
            edg[G[now][i]^1].f+=f;
        }
    }
    return rt;
}

ll flow(int s,int t){
    ll f=0;
    while(1){
        memset(d,0,sizeof(d));
        if(!bfs(s,t))break;
        memset(idx,0,sizeof(idx));
        f+=dfs(s,1e18,t);
    }
    return f;
}

ll a[105];

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll allsum=0,possum=0;
    for(int i=1;i<=n;++i)allsum+=a[i];
    for(int i=1;i<=n;++i){
        if(a[i]>0){
            ae(i,n+1,a[i]);
        }
        else{
            ae(0,i,-a[i]);
            possum-=a[i];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+i;j<=n;j+=i){
            ae(i,j,1e18);
        }
    }
    ll f=flow(0,n+1);
    PDE(allsum,possum,f);
    cout<<allsum+(possum-f)<<endl;
}
