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

#define FLOW_POINTS 4020
struct edge{
    int u,v,f;
};

vector<edge> edg;
vector<int> G[FLOW_POINTS];

void ae(int u,int v,int f){
    if(!f)return;
    PDE(u,v,f);
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
    PDE(now,t,fl);
    if(fl==0)return 0;
    if(t==now)return fl;
    int f=0,df;
    for(int &i=cur[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        if(e.f && dep[e.v]==dep[now]+1 && (df=dfs(e.v,t,min(fl,e.f)))){
            f+=df;
            fl-=df;
            e.f-=df;
            edg[G[now][i]^1].f+=df;
        }
    }
    return f;
}


int flow(int s,int t){
    MS(vv,0);
    int f=0,c=0;
    while(bfs(s,t,++c)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,0x3f3f3f3f);
    }
    PDE(s,t,f);
    return f;
}

vector<pii> gg;
int dega[2005],degb[2005];
stack<vint> ans;

int main(){
    CPPinput;
    int n1,n2,m; cin>>n1>>n2>>m;
    gg.resize(m);
    for(auto &i:gg)cin>>i.first>>i.second;
    for(auto &i:gg)++dega[i.first],++degb[i.second];
    for(int i=1;i<=n1;++i)PDE(i,dega[i]);
    for(int i=1;i<=n2;++i)PDE(i,degb[i]);
    for(auto &i:gg)ae(i.first,i.second+n1,1);
    int mindeg=m;
    for(int i=1;i<=n1;++i)mindeg=min(mindeg,dega[i]);
    for(int i=1;i<=n2;++i)mindeg=min(mindeg,degb[i]);
    for(int i=1;i<=n1;++i)ae(0,i,dega[i]-mindeg);
    for(int i=1;i<=n2;++i)ae(i+n1,n1+n2+1,degb[i]-mindeg);
    int totf=0;
    for(int i=mindeg;i>=0;--i){
        if(DEBUG)for(auto &e:edg)cout<<e.u<<" "<<e.v<<" "<<e.f<<endl;
        totf+=flow(0,n1+n2+1);
        PDE(i,totf);
        vint tmp;
        tmp.pb(m-totf);
        for(int i=0;i<m*2;i+=2){
            if(edg[i].f)tmp.pb((i>>1)+1);
        }
        ans.push(tmp);
        for(int i=1;i<=n1;++i)ae(0,i,1);
        for(int i=1;i<=n2;++i)ae(i+n1,n1+n2+1,1);
    }
    PDE(ans);
    while(ans.size()){
        for(int i:ans.top())cout<<i<<" ";
        ans.pop();
        cout<<'\n';
    }
}
