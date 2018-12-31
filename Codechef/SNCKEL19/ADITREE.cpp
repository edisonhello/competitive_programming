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
const ll mod=1e9+7;

const int maxn = 250005;

struct segtree{
#define mid ((l+r)>>1)
    struct node{
        node *l,*r;
        int tag,sz,val;
        node():l(0),r(0),tag(0),sz(0),val(0){}
        void addtag(){ tag^=1; val=sz-val; }
        void push(){ if(!l || !tag) return; l->addtag(); r->addtag(); tag=0; }
        void pull(){ sz=l->sz+r->sz; val=l->val+r->val; }
    } *root;
    int L,R;
    void setLR(int LL,int RR){ L=LL; R=RR; }
    void build(){ build(root=new node(),L,R); }
    void build(node *now,int l,int r){
        if(l==r){
            now->sz=1; return;
        }
        build(now->l=new node(),l,mid);
        build(now->r=new node(),mid+1,r);
        now->pull();
    }
    void modify(int l,int r){ modify(root,L,R,l,r); }
    void modify(node *now,int l,int r,int ml,int mr){
        if(r<ml || mr<l)return;
        if(ml<=l&&r<=mr){
            now->addtag();
            return;
        }
        now->push();
        modify(now->l,l,mid,ml,mr);
        modify(now->r,mid+1,r,ml,mr);
        now->pull();
    }
    int query(){ return root->val; }
    segtree():root(0),L(0),R(0){}
#undef mid
};

vint G[maxn];
int p[maxn],d[maxn],sz[maxn],mxsz[maxn],mxszi[maxn];
int cid[maxn],icp[maxn],cpa[maxn],csz[maxn],cc;
segtree seg[maxn];

void dfs1(int now,int pa){
    p[now]=pa;
    sz[now]=1;
    for(int i:G[now])if(i!=pa){
        dfs1(i,now);
        sz[now]+=sz[i];
        if(sz[i]>mxsz[now]){
            mxsz[now]=sz[i];
            mxszi[now]=i;
        }
    }
}

void dfs2(int now,int pa,int icid,int icpos){
    cid[now]=icid;
    ++csz[icid];
    icp[now]=icpos;
    if(mxszi[now])dfs2(mxszi[now],now,icid,icpos+1);
    for(int i:G[now])if(i!=pa && i!=mxszi[now]){
        ++cc;
        cpa[cc]=now;
        dfs2(i,now,cc,1);
    }
}

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs1(1,0);
    dfs2(1,0,++cc,1);
    for(int i=1;i<=cc;++i)seg[i].setLR(1,csz[i]),seg[i].build();
    int ans=0;
    int q; cin>>q; while(q--){
        int u,v; cin>>u>>v;
        auto modify=[&](int x){
            while(x){
                ans-=seg[cid[x]].query();
                seg[cid[x]].modify(1,icp[x]);
                ans+=seg[cid[x]].query();
                x=cpa[cid[x]];
            }
        };
        modify(u);
        modify(v);
        cout<<ans<<'\n';
    }
}
