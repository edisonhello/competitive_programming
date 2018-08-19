// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#include<random>
#include<thread>

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

int c[200005],to[200005],cc,bel[200005],ans;
vector<int> G[200005],iG[200005],tp(1,0),mem[200005];
bitset<200005> v,notend;

void dfs1(int now){
    if(v[now])return;
    v[now]=1;
    for(int i:G[now])dfs1(i);
    tp.pb(now);
}
void dfs2(int now,int ccn){
    if(v[now])return;
    v[now]=1;
    bel[now]=ccn;
    mem[ccn].pb(now);
    for(int i:iG[now])dfs2(i,ccn);
}

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<=n;++i)cin>>to[i];
    for(int i=1;i<=n;++i)G[i].pb(to[i]);
    for(int i=1;i<=n;++i)iG[to[i]].pb(i);
    for(int i=1;i<=n;++i)if(!v[i])dfs1(i); v.reset();
    for(int i=n;i>=1;--i)if(!v[tp[i]])dfs2(tp[i],++cc); v.reset();
    for(int i=1;i<=n;++i)if(bel[i]!=bel[to[i]])notend[bel[i]]=1;
    for(int i=1;i<=n;++i)PDE(i,bel[i],mem[i],notend[i]);
    for(int i=1,mn=1e5;i<=n;++i,ans+=mn==1e5?0:mn,mn=1e5)if(!notend[i] && mem[i].size())for(int j:mem[i])mn=min(mn,c[j]);
    cout<<ans<<endl;
}
