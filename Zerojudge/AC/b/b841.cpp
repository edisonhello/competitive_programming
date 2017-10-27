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
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define reset(x,n) (x).clear(), (x).resize(n)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define endl '\n'
#define getchar gtx
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

#define lowbit(x) ((x)&(-(x)))

inline int gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}


const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int mp[10][10];
int dp[10][10][1<<10];

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<n;++i){
        if(i)for(int meow=0;meow<(1<<m+1);++meow)dp[i][0][meow<<1]=dp[i-1][m][meow];
        for(int j=0;j<m;++j){
            for(int meow=0;meow<(1<<m+1);++meow){
                int l=meow&(1<<j),u=meow&(1<<j+1);
                if(!l && !u){
                    if(i<n-1){
                        if(mp[i][j]==mp[i+1][j])dp[i][j+1][meow|(1<<j)]=dp[i][j][meow]+1;
                    }
                    if(j<m-1){
                        if(mp[i][j]==mp[i][j+1])dp[i][j+1][meow|(1<<j+1)]=dp[i][j][meow]+1;
                    }
                    PDE1(dp[i][j+1][meow]);
                    dp[i][j+1][meow]=max(dp[i][j+1][meow],dp[i][j][meow]);
                }
                if(l && !u){
                    dp[i][j+1][meow-l]=max(dp[i][j+1][meow-l],dp[i][j][meow]);
                }
                if(!l && u){
                    dp[i][j+1][meow-u]=max(dp[i][j+1][meow-u],dp[i][j][meow]);
                }
                if(l && u){
                    // meow
                }
                PDE4(i,j,meow,dp[i][j][meow]);
            }
        }
    }
    cout<<dp[n-1][m][0]<<endl;
}
