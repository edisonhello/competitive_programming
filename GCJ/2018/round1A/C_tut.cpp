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
const ld eps=1e-8;
const ll mod=1e9+7;

int w[111],h[111];
double dp[111][200005];

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
    // int ts=100,ks=0; while(ts--){
        cout<<"Case #"<<(++ks)<<": ";
        int n; double p; cin>>n>>p;
        // int n=100; double p=1e8;
        for(int i=1;i<=n;++i)cin>>w[i]>>h[i];
        // for(int i=1;i<=n;++i)w[i]=rand()%249+1,h[i]=rand()%249+1;
        if([&](){for(int i=1;i<n;++i)if(w[i]!=w[i+1]||h[i]!=h[i+1])return 0;return 1;}()){
            double W=w[1],H=h[1];
            double ans=(W+H)*2*n;
            for(int i=1;i<=n;++i){
                double tmp=(W+H)*2*(n-i);
                double L=(W+H+min(W,H))*2*i,R=(W+H+sqrt(W*W+H*H))*2*i;
                if(L+tmp-eps>p)break;
                PDE(tmp,L,R);
                ans=max(ans,tmp+R);
                ans=min(ans,p);
            }
            cout<<fixed<<setprecision(12)<<ans<<endl;
        }
        else{
            int offset=0;
            for(int i=1;i<=n;++i)offset+=(w[i]+h[i])*2;
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;++i){
                for(int j=min(w[i],h[i]);j<=200000;++j){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-min(w[i],h[i])]+sqrt(w[i]*w[i]+h[i]*h[i]));
                }
            }
            double ans=offset;
            for(int j=0;j<=200000;++j){
                if(j+offset>p)break;
                ans=max(ans,offset+dp[n][j]);
            }
            ans=min(ans,p);
            cout<<fixed<<setprecision(12)<<ans<<endl;
        }
    }
}
