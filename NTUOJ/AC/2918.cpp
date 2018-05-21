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

struct node{
    node *l,*r;
    vector<pair<int,int>> edgs;
    node():l(0),r(0){}
} *root;

map<pair<int,int>,pair<int,int>> alive;
vector<pair<pair<int,int>,pair<int,int>>> rip;

vector<int> qn[300005];
int ans[300005],djs[300005],nans,sz[300005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void insert(node *now,int l,int r,int ml,int mr,pair<int,int> e){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->edgs.pb(e);
        return;
    }
    insert(now->l,l,mid,ml,mr,e);
    insert(now->r,mid+1,r,ml,mr,e);
}
void go(node *now,int l,int r){
    stack<pair<int*,int>> history;
    for(auto e:now->edgs){
        while(djs[e.first]!=e.first)e.first=djs[e.first];
        while(djs[e.second]!=e.second)e.second=djs[e.second];
        if(e.first==e.second)continue;
        if(sz[e.second]>sz[e.first])swap(e.first,e.second);
        history.emplace(&djs[e.second],djs[e.second]);
        history.emplace(&sz[e.first],djs[e.first]);
        history.emplace(&nans,nans);
        --nans;
        djs[e.second]=e.first;
        sz[e.first]+=sz[e.second];
    }
    if(l==r){
        for(int id:qn[l])ans[id]=nans;
    }
    else{
        go(now->l,l,mid);
        go(now->r,mid+1,r);
    }
    while(history.size()){
        auto p=history.top(); history.pop();
        *p.first=p.second;
    }
}

int main(){
    CPPinput;
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=n;++i)sz[i]=1;
    nans=n;
    for(int i=1;i<=q;++i){
        char c; cin>>c;
        if(c=='?'){
            qn[i].push_back(i);
        }
        else if(c=='+'){
            int u,v; cin>>u>>v;
            if(u>v)swap(v,u);
            alive[make_pair(u,v)].first=i;
        }
        else{
            int u,v; cin>>u>>v;
            if(u>v)swap(v,u);
            auto &rem=alive[make_pair(u,v)];
            rem.second=i;
            rip.emplace_back(pair<int,int>(u,v),pair<int,int>(rem));
            rem=pair<int,int>(-1,-1);
        }
    }
    for(auto &p:alive){
        if(p.second.first!=-1){
            rip.emplace_back(p.first,pair<int,int>(p.second.first,q+1));
        }
    }
    build(root=new node(),1,q+1);
    for(auto &pp:rip){
        insert(root,1,q+1,pp.second.first,pp.second.second,pp.first);
    }
    go(root,1,q+1);
    for(int i=1;i<=q;++i)if(ans[i])cout<<ans[i]<<'\n';
}
