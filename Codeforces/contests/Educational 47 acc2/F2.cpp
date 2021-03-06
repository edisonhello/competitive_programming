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

struct Q{
    int l,r,i,lb;
} qs[1000006];

int cnt[1002006];
set<int> fre[1000006];
int ptr;

void add(int v){
    fre[cnt[v]].erase(v);
    ++cnt[v];
    fre[cnt[v]].insert(v);
    if(fre[ptr+1].size())++ptr;
}
void sub(int v){
    fre[cnt[v]].erase(v);
    --cnt[v];
    fre[cnt[v]].insert(v);
    if(fre[ptr].empty())--ptr;
}
int gans(){
    return *fre[ptr].begin();
}

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1,1,1);
    for(int i=1;i<=n;++i)qs[i]={in[i],out[i],i,in[i]/1000};
    sort(qs+1,qs+1+n,[](const Q &a,const Q &b){ return a.lb==b.lb?(a.lb&1?a.r<b.r:a.r>b.r):a.lb<b.lb; });
    int L=1,R=0;
    for(int i=1;i<=n;++i){
        Q &q=qs[i];
        while(R<q.r)add(dep[++R]);
        while(L>q.l)add(dep[--L]);
        while(R>q.r)sub(dep[R--]);
        while(L<q.l)sub(dep[L++]);
        PDE(q.l,q.r,q.i,gans(),L,R);
        ans[q.i]=gans();
    }
    for(int i=1;i<=n;++i)cout<<ans[i]-dep[i]<<'\n';
}
