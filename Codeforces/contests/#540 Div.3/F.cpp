// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const ll mod=998244353;

int pa[20][300005],dep[300005],it[300005],ot[300005],nt;
int c[300005];
set<int> G[300005];

void dfs(int now,int p,int d){
    pa[0][now]=p;
    dep[now]=d;
    for(int i=1;i<20;++i)pa[i][now]=pa[i-1][pa[i-1][now]];
    it[now]=++nt;
    for(int i:G[now]){
        if(i!=p)dfs(i,now,d+1);
    }
    ot[now]=++nt;
}

int lca(int u,int v){
    if(u==v)return u;
    if(dep[u]>dep[v])swap(u,v);
    for(int i=19;i>=0;--i)if((dep[v]-dep[u])&(1<<i))v=pa[i][v];
    if(u==v)return u;
    for(int i=19;i>=0;--i)if(pa[i][v]!=pa[i][u])u=pa[i][u],v=pa[i][v];
    return pa[0][u];
}

vector<int> mem[300005];
int clca[300005];

// int fa[300005],bsz

int mids;
long long ans=1;
bool dfs1(int now,int pa,int paclr){
    PDE(now,pa,paclr);
    if(c[now]){
        if(c[now]==paclr){
            for(int i:G[now])if(i!=pa)dfs1(i,now,c[now]);
            return 1;
        }
        else{
            for(int i:G[now])if(i!=pa)dfs1(i,now,c[now]);
            return 0;
        }
    }
    else{
        bool same=0;
        for(int i:G[now])if(i!=pa)same|=dfs1(i,now,paclr);
        if(same)c[now]=paclr;
        return same;
    }
}

void dfs2(int now,int pa,int paclr,int len){
    PDE(now,pa,paclr,len);
    int chs=0,echs=0;
    for(int i:G[now])if(i!=pa)++chs;
    for(int i:G[now])if(i!=pa && !c[i])++echs;
    if(echs>1){
        if(c[now] && c[now]!=paclr){
            mids++;
            ans*=len;
            ans%=mod;
        }
        
        if(c[now]){
            if(c[now]!=paclr){
            }
            for(int i:G[now])if(i!=pa){
                dfs2(i,now,c[now],1);
            }
        }
        else{
            /* for(int i:G[now])if(i!=pa){
                if(c[i])
            } */
            bool downme=0;
            
        }
    }
    else{
        if(c[now]){
            if(c[now]!=paclr){
                mids++;
                ans*=len;
                ans%=mod;
            }
            for(int i:G[now])if(i!=pa)dfs2(i,now,c[now],1);
        }
        else{
            for(int i:G[now])if(i!=pa)dfs2(i,now,paclr,len+1);
        }
    }
}

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    // int n,k=2; cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        PDE(u,v);
        G[u].insert(v);
        G[v].insert(u);
    }
    PDE("INPUT");

    queue<int> lev;
    for(int i=1;i<=n;++i)if(G[i].size()==1u && !c[i])lev.push(i);
    while(lev.size()){
        int now=lev.front(); lev.pop();
        int to=*G[now].begin();
        G[to].erase(now);
        if(G[to].size()==1u && !c[to])lev.push(to);
    }

    int root=-1;
    for(int i=1;i<=n;++i)if(c[i])root=i;
    PDE(root);

    dfs(1,0,0);
    for(int i=1;i<=n;++i){
        mem[c[i]].push_back(i);
        clca[c[i]]=i;
    }
    for(int i=1;i<=k;++i)for(int j:mem[i])clca[i]=lca(clca[i],j);
    for(int i=1;i<=k;++i)if(c[clca[i]] && c[clca[i]]!=i){
        cout<<0<<endl;
        exit(0);
    }
    for(int i=1;i<=k;++i)c[clca[i]]=i;

    dfs1(root,0,c[root]);
    if(DEBUG){ cout<<"new color: "; for(int i=1;i<=n;++i)cout<<c[i]<<" "; cout<<endl; }
    dfs2(root,0,c[root],0);

    PDE(mids,ans);
    if(mids!=k-1)ans=0;
    cout<<ans<<endl;
}
