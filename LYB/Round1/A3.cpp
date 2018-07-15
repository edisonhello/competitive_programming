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
    int u,v,f;
};

vector<edge> edg;
vector<int> G[FLOW_POINTS];

void ae(int u,int v,int f){
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
            if(e.f>0 && vv[e.v]!=c){
                vv[e.v]=c;
                q.push(e.v);
                dep[e.v]=dep[now]+1;
            }
        }
    }
    return vv[t]==c;
}

int cur[FLOW_POINTS];
int dfs(int now,int t,int fl){
    if(fl==0)return 0;
    if(t==now)return fl;
    int f=0,df;
    for(int &i=cur[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        while(e.f && dep[e.v]==dep[now]+1 && (df=dfs(e.v,t,min(fl,e.f)))){
            f+=df;
            fl-=df;
            e.f-=df;
            edg[G[now][i]^1].f+=df;
            if(!fl)break;
        }
    }
    return f;
}

int la;
int flow(int s,int t){
    static int c=0;
    int f=0;
    while(bfs(s,t,++c)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,1e18);
    }
    PDE(f,la);
    f+=la; la=f;
    return f;
}

queue<int> td;
void de(int s,int t,int f){
    td.push(s); td.push(t); td.push(f);
    if(s!=0)ae(0,s,f);
    if(t!=4099)ae(t,4099,f);
}
void rebuild(){
    while(td.size()){
        int s=td.front(); td.pop();
        int t=td.front(); td.pop();
        int f=td.front(); td.pop();
        ae(s,t,f);
    }
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

    PDE(maxans);
    int fos=0;
    vector<int> must;
    for(int x:bye){
        de(x,4099,c[x]); fos+=c[x];
        int osos=0;
        for(int i=1;i<=m;++i){
            bool inc=0;
            for(int z:gp[i])if(x==z){ inc=1; break; }
            if(inc){
                de(0,n+i,er[i]); fos+=er[i]; osos+=er[i];
                for(int z:gp[i])de(n+i,z,3e13),fos+=3e13;
            }
        }
        int f=flow(0,4099)-fos;
        int nowans=os-osos-f;
        if(nowans!=maxans)must.pb(x);
        rebuild();
    }
    cout<<maxans<<endl;
    cout<<must.size()<<endl;
    for(int i:must)cout<<i<<" "; cout<<endl;
}
