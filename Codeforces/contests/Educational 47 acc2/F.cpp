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

vint G[1000006];
int dep[1000006],in[1000006],out[1000006],dt,ans[1000006];

void dfs(int now,int pa,int d){
    dep[now]=d;
    in[now]=++dt;
    for(int i:G[now]){
        if(i!=pa)dfs(i,now,d+1);
    }
    out[now]=dt;
}

struct node{
    node *l,*r;
    int sz;
    node():l(0),r(0),sz(0){}
} *root[1000006],pool[8000000];
int ptr=0;

node *gnode(node *ref){
    pool[ptr].l=ref->l;
    pool[ptr].r=ref->r;
    pool[ptr].sz=ref->sz;
    return &pool[ptr++];
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=&pool[ptr++],l,mid);
    build(now->r=&pool[ptr++],mid+1,r);
}
void modify(node *now,int l,int r,int x){
    if(l==r){ ++now->sz; return; }
    if(x<=mid)modify(now->l=gnode(now->l),l,mid,x);
    else modify(now->r=gnode(now->r,mid+1,r,x);
    now->sz=max(now->l->sz,now->r->sz);
}

int query(node *nowl,node *nowr,int l,int r){
    
}

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1,1,1);
    build(root[0]=&pool[ptr++],1,n);
    for(int i=1;i<=n;++i){
        modify(root[i]=gnode(root[i-1]),1,n,dep[i]);
    }
    for(int i=1;i<=n;++i)cout<<query(root[in[i]-1],root[out[i]],1,n)-dep[i]<<'\n';
}
