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

ll m[1111],s[1111],p[1111];
ll dp[1111][1111];

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
        cout<<"Case #"<<(++ks)<<": ";
        ll r,b,c; cin>>r>>b>>c;
        for(int i=1;i<=c;++i){
            cin>>m[i]>>s[i]>>p[i];
        }

        auto ok=[&](ll mxt){
            memset(dp,0x3f,sizeof(dp));
            dp[0][r]=b;
            for(int i=1;i<=c;++i){
                for(int j=0;j<=r;++j)dp[i][j]=dp[i-1][j];
                if(p[i]>mxt)continue;
                for(int j=0;j<r;++j){
                    ll tl=mxt-p[i];
                    ll csm=tl/s[i];
                    csm=min(csm,m[i]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j+1]-csm);
                }
            }
            for(int i=0;i<=r;++i)if(dp[c][i]<=0)return 1;
            return 0;
        };

        ll L=0,R=1ll<<60;
        while(R>L){
            ll mid=(L+R)>>1;
            if(ok(mid))R=mid;
            else L=mid+1;
        }
        cout<<L<<endl;
    }
}
