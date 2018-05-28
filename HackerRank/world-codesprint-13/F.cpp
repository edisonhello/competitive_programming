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

struct segtree{
    struct node{
        node *l,*r;
        int val;
        node():l(0),r(0),val(0){}
    } *root;
    int L,R;
#define mid ((l+r)>>1)
    void build(node *now,int l,int r){
        if(l==r){
            return;
        }
        build(now->l=new node(),l,mid);
        build(now->r=new node(),mid+1,r);
    }
    void modify(node *now,int l,int r,int x,int d){
        if(l==r){
            now->val=d;
            return;
        }
        if(x<=mid)modify(now->l,l,mid,x,d);
        else modify(now->r,mid+1,r,x,d);
        now->val=now->l->val+now->r->val;
    }
    int query(node *now,int l,int r,int ql,int qr){
        if(qr<l || r<ql)return 0;
        if(ql<=l&&r<=qr)return now->val;
        return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
    }
#undef mid
    void init(int l,int r){
        L=l, R=r;
        build(root=new node(),L,R);
    }
    void modify(int x,int d){
        modify(root,L,R,x,d);
    }
    int query(int l,int r){
        return query(root,L,R,l,r);
    }
    segtree():L(0),R(0),root(0){}
} tree[200005];

vector<int> G[200005];
vector<pii> edg;

int d[200005],p[20][200005],sz[200005];
int mxsz[200005],mxszi[200005];
int bel[200005],icpos[200005],ctop[200005],ccnt,clen[200005];
int conval[200005];

void dfs1(int now,int pa,int dep){
    p[0][now]=pa;
    d[now]=dep;
    for(int i=1;(1<<i)<=dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now,dep+1);
        sz[now]+=sz[i];
        if(mxsz[now]<sz[i]){
            mxsz[now]=sz[i];
            mxszi[now]=i;
        }
    }
    ++sz[now];
}

void dfs2(int now,int pa,int cnum,int cpos){
    bel[now]=cnum;
    icpos[now]=cpos;
    clen[cnum]=cpos;
    for(int i:G[now]){
        if(i==pa)continue;
        if(i==mxszi[now]){
            dfs2(i,now,cnum,cpos+1);
        }
        else{
            ++ccnt;
            ctop[ccnt]=now;
            dfs2(i,now,ccnt,1);
        }
    }
}

int glca(int pa,int pb){
    if(pa==pb)return pa;
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<20;++i){
        if((1<<i)&(d[pb]-d[pa])){
            pb=p[i][pb];
        }
    }
    if(pa==pb)return pa;
    for(int i=19;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    return p[0][pa];
}

int cnt(int u,int v){
    int rt=0;
    while(bel[u]!=bel[v]){
        rt+=tree[bel[v]].query(1,icpos[v]-1);
        rt+=conval[bel[v]];
        v=ctop[bel[v]];
    }
    if(u!=v)rt+=tree[bel[v]].query(icpos[u],icpos[v]-1);
    return rt;
}

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        if(v<u)swap(u,v);
        edg.eb(u,v);
        G[u].pb(v);
        G[v].pb(u);
    }
    sort(edg.begin(),edg.end());
    dfs1(1,1,0);
    dfs2(1,1,++ccnt,1);
    for(int i=1;i<=ccnt;++i){
        tree[i].init(1,clen[i]);
    }
    int q; cin>>q; while(q--){
        char c; cin>>c;
        int u,v; cin>>u>>v;
        if(c=='q'){
            if(d[v]<d[u])swap(u,v);
            int lca=glca(u,v);
            int dis=d[u]+d[v]-2*d[lca];
            int val;
            if(lca==u){
                val=cnt(u,v);
            }
            else{
                val=cnt(lca,u)+cnt(lca,v);
            }
            if(val)cout<<"Impossible"<<'\n';
            else cout<<dis<<endl;
        }
        else if(c=='c'){
            if(v<u)swap(u,v);
            auto it=lower_bound(edg.begin(),edg.end(),make_pair(u,v));
            if(it==edg.end() || *it!=make_pair(u,v))continue;
            if(d[v]<d[u])swap(u,v);
            if(icpos[v]==1){
                conval[bel[v]]=0;
            }
            else{
                tree[bel[v]].modify(icpos[v]-1,0);
            }
        }
        else if(c=='d'){
            if(v<u)swap(u,v);
            auto it=lower_bound(edg.begin(),edg.end(),make_pair(u,v));
            if(it==edg.end() || *it!=make_pair(u,v))continue;
            if(d[v]<d[u])swap(u,v);
            if(icpos[v]==1){
                conval[bel[v]]=1;
            }
            else{
                tree[bel[v]].modify(icpos[v]-1,1);
            }
        }
    }
}
