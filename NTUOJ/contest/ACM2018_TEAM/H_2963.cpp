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

struct node{
    set<int> ch;
    int pa;
    void init(){ pa=0; ch.clear(); }
} tree[105];
vector<int> G[102];
vector<int> dep[102];
int sonmxd[102],d[102];

void dfs(int now,int pa){
    tree[now].pa=pa;
    for(int i:G[now]){
        if(i==pa)continue;
        tree[now].ch.insert(i);
        dfs(i,now);
    }
}

void getmaxh(int now,int ndep){
    dep[ndep].pb(now);
    d[now]=sonmxd[now]=ndep;
    for(int i:tree[now].ch){
        getmaxh(i,ndep+1);
        sonmxd[now]=max(sonmxd[now],sonmxd[i]);
    }
}

void sol(){
    int n,h; cin>>n>>h;
    for(int i=0;i<n;++i)G[i].clear();
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=0;i<n;++i)tree[i].init();
    dfs(0,0);
    int cost=0;
    while([&](){for(int i=0;i<n;++i)dep[i].clear();}(),MS(sonmxd,0),getmaxh(0,0),dep[h+1].size()){
        for(int now:dep[h+1]){
            int upcnt=sonmxd[now]-h;
            if(upcnt>=d[now]){
                int opa=tree[now].pa;
                cost+=d[now];
                tree[opa].ch.erase(now);
                tree[0].ch.insert(now);
                tree[now].pa=0;
                continue;
            }
            else{
                int opa=tree[now].pa;
                int npa=opa;
                cost+=upcnt;
                while(upcnt--){
                    npa=tree[npa].pa;
                }
                tree[npa].ch.insert(now);
                tree[opa].ch.erase(now);
                tree[now].pa=npa;
                continue;
            }
        }
    }
    cout<<cost<<endl;
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--){ sol(); }
}
