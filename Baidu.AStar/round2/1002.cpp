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

ll pw(ll b,ll n,ll m,ll a){
    if(!n)return a;
    if(n&1)return pw(b*b%m,n>>1,m,a*b%m);
    else return pw(b*b%m,n>>1,m,a);
}
ll inv(ll x){ return pw(x,mod-2,mod,1); }

ll l[123],r[123],bases[123];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
    for(int i=1;i<=n;++i)bases[i]=inv(r[i]-l[i]+1);
    ll mxv=0,mnv=0;
    for(int i=1;i<=n;++i)mxv=max(mxv,r[i]),mnv=max(mnv,l[i]);
    ll sum=0;
    for(ll h=mnv;h<=mxv;++h){
        ll pro=1;
        for(int i=1;i<=n;++i){
            ll base=bases[i];
            // ll base=1;
            ll RR=min(r[i],h);
            ll sec=h*(RR-l[i]+1)%mod-(l[i]-2+RR)*(RR-l[i]+1)/2%mod;
            PDE(i,RR,base,sec);
            (pro*=base*sec%mod+mod)%=mod;
        }
        ll mina=1;
        for(int i=1;i<=n;++i){
            // if(r[i]<h)continue;
            ll base=bases[i];
            ll RR=min(r[i],h-1);
            ll sec=h*(RR-l[i]+1)%mod-(l[i]-2+RR)*(RR-l[i]+1)/2%mod;
            PDE(i,RR,base,sec);
            (mina*=base*sec%mod+mod)%=mod;
        }
        sum+=pro-mina+mod;
        // sum%=mod;
        PDE(h,pro,mina);
    }
    // ll tot=1;
    // for(int i=1;i<=n;++i)(tot*=(r[i]-l[i]+1))%=mod;
    cout<<sum%mod<<endl;
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--)sol();
}
