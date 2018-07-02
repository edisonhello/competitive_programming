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

ll a[200005],pre[200005];
ll pmx[200005],pmn[200005],smx[200005],smn[200005];

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    ll ans=LLONG_MAX;
    for(int i=2,j=1;i<=n-2;++i){
        pmx[i]=LLONG_MAX/3;
        pmn[i]=LLONG_MIN/3;
        while(1){
            ll sum1=pre[i]-pre[j];
            ll sum2=pre[j];
            if(abs(sum1-sum2)<abs(pmx[i]-pmn[i])){
                pmx[i]=max(sum1,sum2);
                pmn[i]=min(sum1,sum2);
            }
            bool move=0;
            if(j<i-1){
                ll tsum1=pre[i]-pre[j+1];
                ll tsum2=pre[j+1];
                if(abs(tsum1-tsum2)<=abs(sum1-sum2))++j,move=1;
            }
            if(!move)break;
        }
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    for(int i=2,j=1;i<=n-2;++i){
        smx[i]=LLONG_MAX/3;
        smn[i]=LLONG_MIN/3;
        while(1){
            ll sum1=pre[i]-pre[j];
            ll sum2=pre[j];
            if(abs(sum1-sum2)<abs(smx[i]-smn[i])){
                smx[i]=max(sum1,sum2);
                smn[i]=min(sum1,sum2);
            }
            bool move=0;
            if(j<i-1){
                ll tsum1=pre[i]-pre[j+1];
                ll tsum2=pre[j+1];
                if(abs(tsum1-tsum2)<=abs(sum1-sum2))++j,move=1;
            }
            if(!move)break;
        }
    }
    reverse(smx+1,smx+1+n);
    reverse(smn+1,smn+1+n);
    for(int i=1;i<=n;++i)PDE(i,pmx[i],pmn[i],smx[i],smn[i]);
    for(int i=2;i<n-1;++i){
        ans=min(ans,max(pmx[i],smx[i+1])-min(pmn[i],smn[i+1]));
    }
    cout<<ans<<endl;
}
