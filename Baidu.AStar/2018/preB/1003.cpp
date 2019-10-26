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
    node *l,*r;
    int pri,sz;
    ll val,pro;
    double key;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; pro=(l?l->pro:1)*(r?r->pro:1)%mod*val%mod; }
    node(ll v,double k):l(0),r(0),pri(rand()),sz(1),val(v),pro(v),key(k){}
};

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void split_key(node *now,double key,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->key<=key){
        a=now;
        split_key(now->r,key,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split_key(now->l,key,a,b->l);
        b->pull();
    }
}
void split_sz(node *now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->lz()>=sz){
        b=now;
        split_sz(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        split_sz(now->r,sz-1-now->lz(),a->r,b);
        a->pull();
    }
}

void insert(node *&root,ll v,double k){
    PDE("insert ",v,k);
    node *a,*b;
    split_key(root,k,a,b);
    root=merge(merge(a,new node(v,k)),b);
}
void remove(node *&root,ll v,double k){
    PDE("remove ",v,k);
    node *a,*b,*c,*d;
    split_key(root,k-1e-8,a,d);
    split_sz(d,1,b,c);
    delete b;
    root=merge(a,c);
}

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x){ return pw(x,mod-2,mod); }

int k;
vector<pair<long long,long long>> G[100005];
ll ans[100005],inv200k;

void dfs(int now,node *&root,ll ch,int kleft){
    PDE("dfs",now,ch,kleft);
    if(ch==0){
        if(G[now].empty())ans[now]=0;
        else for(auto p:G[now])dfs(p.first,root,0,0);
        return;
    }
    if(G[now].empty()){
        PDE(ch,kleft);
        node *a,*b;
        int tsz=(root?root->sz:0);
        split_sz(root,tsz-kleft,a,b);
        if(b)(ch*=b->pro)%=mod;
        ans[now]=ch;
        root=merge(a,b);
        return;
    }
    ll mx_ch=-1;
    for(auto p:G[now])mx_ch=max(mx_ch,p.second);
    PDE(mx_ch);
    for(auto p:G[now]){
        if(p.second==0){
            if(kleft) dfs(p.first,root,ch*mx_ch%mod*inv200k%mod,kleft-1);
            else dfs(p.first,root,0,0);
        }
        else{
            insert(root,mx_ch*inv(p.second)%mod,(double)mx_ch/p.second);
            PDE(p,ch,p.second*inv200k%mod);
            dfs(p.first,root,ch*p.second%mod*inv200k%mod,kleft);
            remove(root,mx_ch*inv(p.second)%mod,(double)mx_ch/p.second);
        }
    }
}

void sol(){
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)G[i].clear();
    for(int i=1;i<n;++i){
        int a,b,v; cin>>a>>b>>v;
        G[a].eb(b,v);
    }
    node *root=0;
    dfs(0,root,1,k);
    for(int i=0;i<n;++i)if(G[i].empty())cout<<ans[i]<<'\n';
}

int main(){
    CPPinput;
    inv200k=inv(200000);
    // PDE(428500003ll*9%mod*inv(20)%mod);
    // PDE(142825001*inv(200)%mod*199700%mod);
    int ts; cin>>ts; while(ts--)sol();
}
