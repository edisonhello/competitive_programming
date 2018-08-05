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

int djs[1000006],mx[1000006],le[1000006];

int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }

void sol(){
    int n,s,m,k; cin>>n>>s>>m>>k; m<<=1;
    vector<int> p(1,0),d(1,0);
    vector<ll> dp(n+1,0);
    for(int i=0;i<k;++i){
        int l,a,x,y,z; cin>>l>>a>>x>>y>>z;
        p.push_back(a); --l;
        while(l--){ a=(1ll*a*x+y)%z+1; p.push_back(a); }
    }
    for(int i=0;i<k;++i){
        int l,a,x,y,z; cin>>l>>a>>x>>y>>z;
        d.push_back(a); --l;
        while(l--){ a=(1ll*a*x+y)%z+1; d.push_back(a); }
    }
    PDE(p,d);
    vector<pair<int,int>> foss;
    for(int i=0;i<=n;++i)foss.emplace_back(p[i],d[i]+s);
    sort(foss.begin(),foss.end());
    PDE(foss);
    for(int i=1;i<=n;++i)djs[i]=i,mx[i]=foss[i].second,le[i]=i;
    deque<int> dq;
    multiset<ll> dpv;
    for(int i=1;i<=n;++i){
        PDE(i,F(i),mx[F(i)]);
        while(dq.size()){
            int fi=dq.front();
            if(foss[i].first-foss[fi].first<=m)break;
            dq.pop_front();
            dpv.erase(dpv.find(dp[fi-1]+mx[F(fi)]));
            if(F(fi+1)==F(fi)){
                dpv.insert(dp[fi]+mx[F(fi)]);
                le[F(fi+1)]=fi+1;
            }
        }
        PDE(dq,dpv);
        for(int u=i-1;dq.size() && u>=dq.front();){
            if(mx[F(u)]>mx[F(i)])break;
            u=le[F(u)];
            dpv.erase(dpv.find(dp[u-1]+mx[F(u)]));
            mx[F(u)]=max(mx[F(i)],mx[F(u)]);
            djs[F(i)]=F(u);
            PDE(F(i),mx[F(i)]);
            --u;
        }
        dq.push_back(i);
        dpv.insert(dp[le[F(i)]-1]+mx[F(le[F(i)])]);
        PDE(dq,dpv);
        dp[i]=*dpv.begin();
        PDE(i,dp[i]);
    }
    cout<<dp[n]<<endl;
}

int main(){
    CPPinput;
    int t,k=0; cin>>t; while(t--){
        cout<<"Case #"<<(++k)<<": ";
        sol();
    }
}
