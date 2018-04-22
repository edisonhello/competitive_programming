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

struct edge{
    int u,v,f;
};
vector<edge> edg;
vector<int> G[10003];

void ae(int u,int v,int w){
    G[u].pb(edg.size());
    edg.pb({u,v,w});
    G[v].pb(edg.size());
    edg.pb({v,u,w});
}

bitset<10005> inq;
int cf[10005],bn[10005];
bool flow(int s,int t,int &nf){
    queue<int> q; q.push(s);
    inq.reset(); inq[s]=1;
    MS(bn,0); bn[s]=0x3f3f3f3f;
    while(q.size() && !bn[t]){
        int now=q.front(); q.pop(); inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(bn[e.v]<min(e.f,bn[now])){
                bn[e.v]=min(e.f,bn[now]);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(!bn[t])return 0;
    for(int u=t;u!=s;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[t];
        edg[cf[u]^1].f+=bn[t];
    }
    nf+=bn[t];
    return bn[t];
}

int flow(int s,int t){
    int f=0;
    while(flow(s,t,f));
    return f;
}

int main(){
    CPPinput;
    int n,ks=0; while(cin>>n,n){
        int s,t,m; cin>>s>>t>>m;
        edg.clear();
        for(int i=1;i<=n;++i)G[i].clear();
        while(m--){
            int u,v,c; cin>>u>>v>>c;
            ae(u,v,c);
        }
        int f=flow(s,t);
        cout<<"Network "<<(++ks)<<'\n';
        cout<<"The bandwidth is "<<f<<".\n";
    }
}
