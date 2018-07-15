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
const ld eps=1e-3;
const ll mod=1e9+7;

#define int long long

#define FLOW_POINTS 4100
struct edge{
    int u,v;
    double f;
};

vector<edge> edg;
vector<int> G[FLOW_POINTS];

void ae(int u,int v,double f){
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0});
}


int dep[FLOW_POINTS],vv[FLOW_POINTS];
bool bfs(int s,int t,int c){
    queue<int> q; q.push(s);
    dep[s]=0; vv[s]=c;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f>eps && vv[e.v]!=c){
                vv[e.v]=c;
                q.push(e.v);
                dep[e.v]=dep[now]+1;
            }
        }
    }
    return vv[t]==c;
}

int cur[FLOW_POINTS];
double dfs(int now,int t,double fl){
    if(fl<eps)return 0;
    if(t==now)return fl;
    double f=0,df;
    for(int &i=cur[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        while(e.f>eps && dep[e.v]==dep[now]+1 && (df=dfs(e.v,t,min(fl,e.f)))){
            f+=df;
            fl-=df;
            e.f-=df;
            edg[G[now][i]^1].f+=df;
            if(fl<eps)break;
        }
    }
    return f;
}

double last_flow;
double flow(int s,int t){
    static int c=0;
    double f=0;
    while(bfs(s,t,++c)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,1e25);
    }
    f+=last_flow; 
    return last_flow=f;
}

int c[2222],er[2222];
vint gp[2222];

int32_t main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i],ae(i,4099,c[i]);
    int os=0;
    for(int i=1,z;i<=m;++i){
        cin>>z>>er[i]; os+=er[i];
        gp[i].resize(z);
        for(int &x:gp[i])cin>>x;
        ae(0,n+i,er[i]);
        for(int &x:gp[i])ae(n+i,x,3e13);
    }
    int f=flow(0,4099);
    int maxans=os-f;

    vector<int> bye;
    for(auto &e:edg){
        if(e.v==4099)bye.pb(e.u);
    }

    double flow_offset=0;
    vector<int> must;
    for(int x:bye){
        /* edg.clear();
        for(int i=0;i<FLOW_POINTS;++i)G[i].clear(); */
        ae(0,x,c[x]); flow_offset+=c[x];
        int os_minus=0;
        for(int i=1;i<=m;++i){
            bool inc=0;
            for(int z:gp[i])if(z==x){ inc=1; break; }
            if(!inc)continue;
            os_minus+=er[i];
            ae(n+i,4099,er[i]); flow_offset+=er[i];
            for(int z:gp[i])ae(0,n+i,3e13),ae(z,4099,3e13),flow_offset+=3e13;
        }

        int f=flow(0,4099)-flow_offset;
        if(os-os_minus-f!=maxans)must.pb(x);

        ae(x,4099,c[x]);
        for(int i=1;i<=m;++i){
            bool inc=0;
            for(int z:gp[i])if(z==x){ inc=1; break; }
            if(!inc)continue;
            ae(0,n+i,er[i]);
            for(int z:gp[i])ae(n+i,z,3e13);
        }
    }
    cout<<maxans<<endl;
    cout<<must.size()<<endl;
    for(int i:must)cout<<i<<" "; cout<<endl;
}
