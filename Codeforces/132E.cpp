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
    int u,v,f,c,top,cor;
};
vector<edge> edg;
vector<int> G[1000];

void ae(int u,int v,int f,int c){
    G[u].pb(edg.size());
    edg.push_back({u,v,f,c,f,1});
    G[v].pb(edg.size());
    edg.push_back({v,u,0,-c,0,-1});
}

int d[1000],bn[1000],inq[1000],cf[1000];
bool flow(int s,int t,int &nco,int &nf){
    MS(d,0x3f);
    MS(bn,0);
    MS(inq,0);
    queue<int> q; q.push(s); d[s]=0; bn[s]=0x3f3f3f3f; inq[s]=1;
    while(q.size()){
        int now=q.front(); q.pop(); inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f>0 && d[e.v]>d[e.u]+e.c){
                d[e.v]=d[e.u]+e.c;
                bn[e.v]=min(bn[e.u],e.f);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(bn[t]==0)return 0;
    nco+=bn[t]*d[t];
    nf+=bn[t];
    for(int u=t;u!=s;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[t];
        edg[cf[u]^1].f+=bn[t];
    }
    return 1;
}

int flow(int s,int t){
    int co=0,fl=0;
    while(flow(s,t,co,fl));
    return co;
}

int a[1000],co[1000];
struct command{
    int type;
    char var;
    int ass;
    int position;
};
vector<command> commands;

void dfs(int now,char var){
    // cout<<"dfs: "<<now<<" "<<var<<endl;
    if(now==899)return;
    for(int ei:G[now]){
        edge &e=edg[ei];
        if(e.cor!=1)continue;
        if(e.f<e.top){
            ++e.f;
            if(e.v!=899 && !((e.u&1)&&e.c==0))commands.push_back({
                (e.u&1)?1:2,
                var,
                (e.v%2==0)?a[e.v/2]:0,
                e.v
            });
            dfs(e.v,var);
            return;
        }
    }
}

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    auto cb=[&](int x)->int{ int c=0; while(x)c+=x&1,x>>=1; return c; };
    for(int i=1;i<=n;++i)co[i]=cb(a[i]);
    ae(0,1,m,0);
    ae(1,899,m,0);
    for(int i=1;i<=n;++i){
        ae(1,i*2,m,co[i]);
        ae(i*2+1,899,m,0);
        ae(i*2,i*2+1,1,-50);
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ae(i*2+1,j*2,m,(a[i]==a[j]?0:co[j]));
        }
    }
    int co=flow(0,899);
    int penalty=co+50*n;
    for(int i=0;i<m;++i){
        dfs(1,i+'a');
    }
    sort(commands.begin(),commands.end(),[&](const auto &a,const auto &b){ return a.position<b.position; });
    cout<<commands.size()<<" "<<penalty<<endl;
    for(auto i:commands){
        if(i.type==1)cout<<i.var<<"="<<i.ass<<'\n';
        else cout<<"print("<<i.var<<")\n";
    }
}
