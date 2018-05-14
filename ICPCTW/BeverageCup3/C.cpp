// #pragma GCC optimize("no-stack-protector")
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

ll prime[10000000],cprime=-1;
bitset<31622800> nprime;
void init(){
    for(ll i=2;i<=31622800;++i){
        if(!nprime[i])prime[++cprime]=i;
        for(ll j=0;i*prime[j]<=31622800;++j){
            nprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

int main(){
    CPPinput;
    init();
    ll n; cin>>n;
    map<ll,int> mp;
    for(ll i=0;prime[i]*prime[i]<=n;++i){
        // if(prime[i]==0)cout<<i<<" "<<prime[i]<<endl;
        // if(i==18803525)cout<<i<<" "<<prime[i]<<" "<<prime[i]*prime[i]<<" "<<n<<endl;
        while(n%prime[i]==0){
            ++mp[prime[i]];
            n/=prime[i];
        }
    }
    if(n>1)++mp[n];
    // for(auto &p:mp){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    map<int,int> dp,prv;
    prv[1]=1;
    for(auto &p:mp){
        dp=prv;
        for(int i=1;i<=p.second;++i){
            for(auto &pp:prv){
                dp[pp.first*(i+1)]+=pp.second;
            }
        }
        dp.swap(prv);
    }
    ll ans=0;
    for(auto &p:prv){
        ans+=1ll*p.first*p.first*p.first*p.second;
    }
    cout<<ans<<endl;
}
