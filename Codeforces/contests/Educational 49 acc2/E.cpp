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
const ll mod=998244353;

ll dp[505][505],okcnt[505];

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    ll ans=0;

    for(int mx=1;mx<=n;++mx){
        MS(dp,0);
        dp[1][1]=1;
        for(int i=1;i<n;++i){
            for(int j=1;j<=mx;++j){
                dp[i][j]%=mod;
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][1]+=dp[i][j];
            }
        }
        for(int j=1;j<=mx;++j)okcnt[mx]+=dp[n][j];
        okcnt[mx]%=mod;
        PDE(mx,okcnt[mx]);
    }

    for(int i=1;i<=n;++i){
        MS(dp,0);
        int mx=(k-1)/i;
        mx=min(mx,n);
        for(int j=1;j<=mx;++j){
            ans+=(okcnt[i]*okcnt[j]%mod-okcnt[i]*okcnt[j-1]%mod-okcnt[i-1]*okcnt[j]%mod+okcnt[i-1]*okcnt[j-1]%mod+3*mod)%mod;
            ans%=mod;
            PDE(i,j,(okcnt[i]*okcnt[j]-okcnt[i]*okcnt[j-1]-okcnt[i-1]*okcnt[j]+okcnt[i-1]*okcnt[j-1]));
            PDE(okcnt[i]*okcnt[j],okcnt[i]*okcnt[j-1],okcnt[i-1]*okcnt[j],okcnt[i-1]*okcnt[j-1]);
        }
    }
    cout<<ans*2%mod<<endl;
}
