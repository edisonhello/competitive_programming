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
const ll mod=865948511;
const ll p=557;
ll invp;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

ll pp[2002],rhh[2502],rphh[2002];
string a[2002],b[202];

int main(){
    CPPinput;
    auto c=clock();
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    pp[0]=1;
    for(int i=1;i<2002;++i)pp[i]=pp[i-1]*p%mod;
    invp=pw(p,mod-2,mod);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            rhh[i]+=a[i][j]*pp[j]%mod;
        }
        rhh[i]%=mod;
        PDE(i,rhh[i]);
    }
    for(int i=0;i<m;++i)rphh[0]+=rhh[i]*pp[i]%mod;
    rphh[0]%=mod;
    for(int i=1;i+m-1<n;++i)rphh[i]=((rphh[i-1]-rhh[i-1]+mod)%mod*invp%mod+rhh[i+m-1]*pp[m-1]%mod)%mod;
    memset(rhh,0,sizeof(rhh));
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            rhh[i]+=b[i][j]*pp[j]%mod;
            PDE(i,j,rhh[i]);
        }
        rhh[i]%=mod;
    }
    for(int i=0;i+m-1<n;++i){
        ll nhh=0;
        for(int j=0;j<m;++j){
            PDE(i,j,rhh[j]);
            nhh+=rhh[j]*pp[j]%mod;
        }
        nhh%=mod;
        for(int j=0;j+m-1<n;++j){
            PDE(i,j,rphh[j],nhh);
            if(nhh==rphh[j]){
                bool ok=1;
                for(int ii=0;ii<m;++ii){
                    for(int jj=0;jj<m;++jj){
                        if(a[j+ii][jj]!=b[ii][jj+i])ok=0;
                    }
                }
                if(!ok)continue;
                cout<<j+1<<" "<<i+1<<endl;
                exit(0);
            }
        }
        if(i+m<n){
            for(int j=0;j<m;++j){
                rhh[j]=((rhh[j]-b[j][i]+mod)%mod*invp%mod+b[j][i+m]*pp[m-1]%mod)%mod;
            }
        }
    }
    while((double)(c-clock())/CLOCKS_PER_SEC<2.35);
    exit(123123);
}
