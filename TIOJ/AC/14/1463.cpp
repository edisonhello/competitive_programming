#include<cstdio>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define rz(x) resize(x)
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
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
#define FLH fflush(stdout)

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
#define DEBUG 1
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>

inline int gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x);pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x);pit(args...);}
#endif

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int dp[10005];
char s[10005];
int main(){
    while(scanf("%s",s)){
        if(s[0]=='0' && s[1]=='\0')break;
        dp[0]=1; int i=0;
        for(;s[i]!='\0';++i){
            dp[i+1]=0;
            if(i && (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')))dp[i+1]+=dp[i-1];
            if(s[i]!='0')dp[i+1]+=dp[i];
        }
        printf("%d\n",dp[i]);
    }
}
