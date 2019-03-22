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

vector<pair<int,int>> pts[300005*4];

#define mid ((l+r)>>1)
#define lc ((o<<1))
#define rc ((o<<1)|1)

void modify(int o,int l,int r,int ml,int mr,int x,int y){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        pts[o].emplace_back(x,y);
        return;
    }
    modify(lc,l,mid,ml,mr,x,y);
    modify(rc,mid+1,r,ml,mr,x,y);
}

long long now;
long long djs[300005*2],gx[300005*2],gy[300005*2],sz[300005*2],ans[300005];

int Find(int x){
    return x==djs[x]?x:Find(djs[x]);
}

void op(stack<pair<long long*,long long>> &hi,pair<int,int> p){
    int x=p.first,y=p.second;
    const int o=300000;
    x=Find(x); y=Find(o+y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    hi.emplace(&now,now);
    hi.emplace(&djs[y],djs[y]);
    hi.emplace(&sz[x],sz[x]);
    hi.emplace(&gx[x],gx[x]);
    hi.emplace(&gy[x],gy[x]);
    now-=gx[x]*gy[x];
    now-=gx[y]*gy[y];
    djs[y]=djs[x];
    sz[x]+=sz[y];
    gx[x]+=gx[y];
    gy[x]+=gy[y];
    now+=gx[x]*gy[x];
}

void dfs(int o,int l,int r){
    stack<pair<long long*,long long>> hi;
    for(auto &p:pts[o]){ op(hi,p); }
    if(l==r){
        ans[l]=now;
    }
    else{
        dfs(lc,l,mid);
        dfs(rc,mid+1,r);
    }
    while(hi.size()){
        auto &p=hi.top();
        *p.first=p.second;
        hi.pop();
    }
}

int main(){
    CPPinput;
    int n; cin>>n;
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;++i){
        int x,y; cin>>x>>y;
        auto it=mp.find(make_pair(x,y));
        if(it==mp.end()){
            mp[make_pair(x,y)]=i;
        }
        else{
            modify(1,1,n,it->second,i-1,x,y);
            mp.erase(it);
        }
    }
    for(auto &p:mp){
        modify(1,1,n,p.second,n,p.first.first,p.first.second);
    }
    for(int i=1;i<=300000;++i){
        djs[i]=i;
        gx[i]=1;
        sz[i]=1;
    }
    for(int i=300001;i<=600000;++i){
        djs[i]=i;
        gy[i]=1;
        sz[i]=1;
    }
    dfs(1,1,n);
    for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
}
