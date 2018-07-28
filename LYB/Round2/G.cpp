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

#define ge make_pair

struct node{
    node *l,*r;
    vector<pii> ops;
    node():l(0),r(0){}
} *root;

int ans[300006],nans=1;
int djs[600006],sz[600006];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}

void ins(node *now,int l,int r,int ml,int mr,pii op){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->ops.pb(op);
        return;
    }
    ins(now->l,l,mid,ml,mr,op);
    ins(now->r,mid+1,r,ml,mr,op);
}

int F(int x){ return x==djs[x]?x:F(djs[x]); }
int C(int x,int y){ return F(x)==F(y); }

void dfs(node *now,int l,int r){
    PDE(l,r,nans);
    stack<pair<int*,int>> his;
    auto change=[&](int &a,int x){ his.emplace(&a,a); a=x; };
    auto U=[&](int fi,int se){
        fi=F(fi),se=F(se);
        if(sz[fi]<sz[se])swap(fi,se);
        change(djs[se],fi);
        change(sz[fi],sz[fi]+sz[se]);
    };
    for(auto &op:now->ops){
        if(!nans)continue;
        if(C(op.first,op.second) || C(op.first+300000,op.second+300000)){ change(nans,0); continue; }
        PDE(l,r,op);
        U(op.first,op.second+300000);
        U(op.first+300000,op.second);
    }
    PDE(l,r,nans);
    if(l==r)ans[l]=nans;
    else{
        dfs(now->l,l,mid);
        dfs(now->r,mid+1,r);
    }
    while(his.size()){
        *his.top().first=his.top().second;
        his.pop();
    }
}

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    vector<pair<pii,pii>> v;
    map<pii,int> mp;
    for(int i=1;i<=m;++i){
        int c,x,y; cin>>c>>x>>y;
        if(c==1)mp[ge(x,y)]=i;
        else v.eb(ge(x,y),ge(mp[ge(x,y)],i-1)),mp.erase(mp.find(ge(x,y)));
    }
    for(auto pp:mp)v.eb(pp.first,ge(pp.second,m+1));
    build(root=new node(),1,m+1);
    for(auto pp:v)ins(root,1,m+1,pp.second.first,pp.second.second,pp.first);

    PDE(v);
    
    for(int i=1;i<=600000;++i)djs[i]=i,sz[i]=1;

    dfs(root,1,m+1);
    for(int i=1;i<=m;++i)cout<<(ans[i]?"Yes":"No")<<endl;
}
