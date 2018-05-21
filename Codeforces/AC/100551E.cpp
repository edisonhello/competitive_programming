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

pair<int,int> edg[100005];
int per[100005];
int djs[100005];
bitset<100005> ismst;
vector<pair<int,int>> G[100005];
int p[20][100005],d[100005];
unsigned long long ev[100005],tag[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}

int glca(int pa,int pb){
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<20;++i){
        if((1<<i)&(d[pb]-d[pa])){
            pb=p[i][pb];
        }
    }
    if(pa==pb)return pb;
    for(int i=19;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    return p[0][pa];
}

void dfs(int now,int pa,int dep){
    d[now]=dep;
    p[0][now]=pa;
    for(int i=1;(1<<i)<=dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(auto p:G[now]){
        if(p.first!=pa){
            dfs(p.first,now,dep+1);
        }
    }
}
unsigned long long dfs2(int now,int pa){
    unsigned long long rt=0;
    for(auto p:G[now]){
        if(p.first==pa)continue;
        unsigned long long tmp=dfs2(p.first,now);
        ev[p.second]=tmp;
        rt^=tmp;
    }
    return rt^tag[now];
}

int main(){
    CPPinput;
    srand(clock());
    freopen("disconnected.in","r",stdin);
    freopen("disconnected.out","w",stdout);
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;++i)cin>>edg[i].first>>edg[i].second;
    for(int i=1;i<=m;++i)per[i]=i;
    random_shuffle(per+1,per+1+m);
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=m;++i){
        auto &e=edg[per[i]];
        PDE(i,F(e.first),F(e.second));
        if(F(e.first)==F(e.second))continue;
        U(e.first,e.second);
        ismst[per[i]]=1;
    }
    for(int i=1;i<=m;++i){
        if(ismst[i]){
            PDE("ismst", i);
            G[edg[i].first].eb(edg[i].second,i);
            G[edg[i].second].eb(edg[i].first,i);
        }
    }
    dfs(1,0,0);
    for(int i=1;i<=m;++i){
        if(ismst[i])continue;
        int u=edg[i].first,v=edg[i].second;
        if(d[u]<d[v])swap(u,v);
        int lca=glca(u,v);
        unsigned long long val=(rand()<<16)^(rand())^((long long)rand()<<32)^((long long)rand()<<48);
        ev[i]=val;
        PDE(i,val,lca);
        tag[u]^=val, tag[v]^=val;
    }
    dfs2(1,0);
    if(DEBUG)for(int i=1;i<=m;++i)PDE(ev[i]);
    int q; cin>>q; while(q--){
        int c; cin>>c; 
        vector<int> can;
        while(c--){
            int t; cin>>t;
            can.pb(t);
        }
        bool dis=0;
        for(int i=1;i<(1<<can.size());++i){
            unsigned long long v=0;
            for(int j=0;j<can.size();++j)if(i&(1<<j))v^=ev[can[j]];
            if(!v)dis=1;
        }
        if(dis)cout<<"Disconnected"<<'\n';
        else cout<<"Connected"<<'\n';
    }
}
