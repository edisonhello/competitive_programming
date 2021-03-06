#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
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
#include<iostream>

using namespace std;

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

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int n,k;
double p[5555][10],dp[5555][5555],pp[5555],ev[5555];

int main(){
    while(scanf("%d%d",&n,&k)==2){
        double base=0;
        for(int i=1;i<=n;++i){
            scanf("%lf%lf%lf%lf",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
            base+=1.0/(p[i][2]+p[i][3]);
            pp[i]=p[i][3]/(p[i][2]+p[i][3]); ev[i]=1.0/p[i][3];
        }
        k-=n*2; if(k<0)k=0;
        while(k>n);
        double more=0;
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n;++j){
                dp[i][j]=dp[i-1][j]*(1-pp[i]);
                if(j)dp[i][j]+=dp[i-1][j-1]*pp[i];
            }
        }
        sort(ev+1,ev+1+n);
        for(int i=2;i<=n;++i)ev[i]+=ev[i-1];
        for(int i=k,j=0;i>=0;--i,++j)more+=ev[j]*dp[n][i];

        printf("%.12lf\n",base+more);
        PDE(base,more);
    }
}
