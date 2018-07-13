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

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexp
#define expl explexplexpl

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
double p[5555][10],dp[5555][5555]; /* ,pp[5555],ev[5555],nv; */

int main(){
    while(scanf("%d%d",&n,&k)==2){
        k-=n*2; if(k<0)k=0;
        double base=0;
        vector<pair<double,double>> stg;
        for(int i=1;i<=n;++i){
            scanf("%lf%lf%lf%lf",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
            base+=1.0/(p[i][2]+p[i][3]);
            stg.eb(p[i][3]/(p[i][2]+p[i][3]),1.0/p[i][3]);
            // pp[i]=p[i][3]/(p[i][2]+p[i][3]); ev[i]=1.0/p[i][3];
        }
        sort(stg.begin(),stg.end(),[](const pair<double,double> &a,const pair<double,double> &b){ return a.second<b.second; });
        vector<pair<double,double>> to3,ot;
        for(int i=0;i<k;++i)to3.pb(stg[i]);
        for(int i=k;i<n;++i)ot.pb(stg[i]);
        double more=0;
        dp[0][0]=1;
        // pp = chance to get 3*
        // dp[i][j] = until i, get j 3*
        for(int i=1;i<=n-k;++i){
            for(int j=0;j<=n-k;++j){
                dp[i][j]=dp[i-1][j]*(1-ot[i-1].first);
                if(j)dp[i][j]+=dp[i-1][j-1]*(ot[i-1].first);
            }
        }
        double allno=1;
        double vpre=0;
        for(int i=0;i<k;++i)allno*=(1-to3[i].first);
        for(int i=0;i<k;++i)vpre+=to3[i].second;
        /* sort(ev+1,ev+1+n);
        for(int i=2;i<=n;++i)ev[i]+=ev[i-1];
        for(int i=k,j=0;i>=0;--i,++j)more+=ev[j]*dp[n][i]; */

        printf("%.12lf\n",base+more);
    }
}
