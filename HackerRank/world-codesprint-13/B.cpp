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

map<string,int> mp;
string rname[100005];
int sz[5][100005],djs[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

int main(){
    CPPinput;
    int n,m,mn,mx,m1,m2,m3;
    cin>>n>>m>>mn>>mx>>m1>>m2>>m3;
    for(int i=1;i<=n;++i){
        string s; cin>>s;
        mp[s]=i;
        rname[i]=s;
        int gr; cin>>gr;
        djs[i]=i;
        sz[gr][i]=1;
        sz[0][i]=1;
    }
    while(m--){
        string s1,s2; cin>>s1>>s2;
        int u=mp[s1],v=mp[s2];
        u=F(u); v=F(v);
        if(u==v)continue;
        if(sz[0][u]+sz[0][v]>mx)continue;
        if(sz[1][u]+sz[1][v]>m1)continue;
        if(sz[2][u]+sz[2][v]>m2)continue;
        if(sz[3][u]+sz[3][v]>m3)continue;
        PDE(u,v);
        djs[v]=u;
        sz[0][u]+=sz[0][v];
        sz[1][u]+=sz[1][v];
        sz[2][u]+=sz[2][v];
        sz[3][u]+=sz[3][v];
    }
    int bigg=0;
    for(int i=1;i<=n;++i){
    }
    for(int i=1;i<=n;++i)bigg=max(bigg,sz[0][i]);
    if(bigg<mn)return cout<<"no groups"<<endl,0;
    set<string> ok;
    for(int i=1;i<=n;++i){
        if(sz[0][F(i)]==bigg)ok.insert(rname[i]);
    }
    for(auto &s:ok)cout<<s<<'\n';
}
