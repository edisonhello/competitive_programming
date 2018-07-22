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

int h[200005];
int tnu[200005],tnd[200005];

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
        cout<<"Case #"<<(++ks)<<": "<<fixed<<setprecision(10);
        int n,m; cin>>n>>m;
        if(DEBUG){ cout<<endl; }
        { int w,x,y,z; cin>>h[1]>>h[2]>>w>>x>>y>>z;
        for(int i=3;i<=n;++i)h[i]=(1ll*w*h[i-2]+1ll*x*h[i-1]+y)%z; }
        if(DEBUG && n<=10){ cout<<"h: "; for(int i=1;i<=n;++i)cout<<h[i]<<" "; cout<<endl; }
        for(int i=1;i<n;++i)tnu[i]=tnd[i]=1000000;
        for(int i=1;i<=m;++i){
            int a,b,u,d; cin>>a>>b>>u>>d;
            if(a<b){
                for(int i=a;i<b;++i){
                    tnu[i]=min(tnu[i],u);
                    tnd[i]=min(tnd[i],d);
                }
            }
            else{
                for(int i=a-1;i>=b;--i){
                    tnu[i]=min(tnu[i],d);
                    tnd[i]=min(tnd[i],u);
                }
            }
        }
        if(DEBUG && n<=10){ cout<<"tnu: "; for(int i=1;i<n;++i)cout<<tnu[i]<<" "; cout<<endl; }
        if(DEBUG && n<=10){ cout<<"tnd: "; for(int i=1;i<n;++i)cout<<tnd[i]<<" "; cout<<endl; }
        double L=0,R=1000000;
        while(R-L>1e-8){
            if([&](double t)->bool{
                double ub=h[1]+t,lb=h[1]-t;
                for(int i=1;i<n;++i){
                    ub=min(ub+tnu[i],h[i+1]+t);
                    lb=max(lb-tnd[i],h[i+1]-t);
                    if(ub<lb)return 0;
                }
                for(int i=n-1;i>=1;--i){
                    ub=min(ub+tnd[i],h[i]+t);
                    lb=max(lb-tnu[i],h[i]-t);
                    if(ub<lb)return 0;
                }
                return 1;
            }((L+R)/2))R=(L+R)/2;
            else L=(L+R)/2;
        }
        cout<<L<<endl;
    }
}
