#include<algorithm>
#include<cstdio>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define rz(x) resize(x)
#define reset(x,n) (x).clear(),(x).resize(n)
#define pb(x) push_back(x)
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
const ld eps=1e-8;
const ll mod=1e9+7;
#define max(a,s) ((a)>(s)?(a):(s))

vector<pair<int,int>> G[30005];
vector<pair<int,pair<int,int>>> tg;
int dj[30005];
int F(int x){return x==dj[x]?x:(dj[x]=F(dj[x]));}
void U(int x,int y){dj[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}
int p[20][30005],dep[30005];
unsigned mx[20][30005];
bool u[30005];
void dfs(int now,int pa,int d){
PDE3(now,pa,d);
    p[0][now]=pa; dep[now]=d; u[now]=1;
    for(int i=1;(1<<i)<=d;++i){
        p[i][now]=p[i-1][p[i-1][now]];
        mx[i][now]=max(mx[i-1][now],mx[i-1][p[i-1][now]]);
    }
    for(pair<int,int> i:G[now]){
        if(i.first==pa)continue;
        mx[0][i.first]=i.second;
        dfs(i.first,now,d+1);
    }   
}
unsigned meow(int u,int v){
PDE2(u,v);
    unsigned rt=0;
    if(dep[u]>dep[v])swap(u,v);
    for(int i=0;i<20;++i)if((1<<i)&(dep[v]-dep[u])){
        rt=max(rt,mx[i][v]);
        v=p[i][v];
        if(dep[v]==dep[u])break;
    }
    if(u==v)return rt;
    for(int i=19;i>=0;--i)if(p[i][u]!=p[i][v]){
        rt=max(rt,max(mx[i][u],mx[i][v]));
        u=p[i][u], v=p[i][v];
    }
    return max(rt,max(mx[0][u],mx[0][v]));
}
int main(){
    int v,e; rit(v,e);
    for(int i=1;i<=v;++i)dj[i]=i;
    for(int i=0,u,v,d;i<e;++i){
        rit(u,v,d);
        tg.push_back(pair<int,pair<int,int>>(d,pair<int,int>(u,v)));
    }
    sort(tg.begin(),tg.end());
    for(pair<int,pair<int,int>> &i:tg){
        if(C(i.second.first,i.second.second))continue;
        G[i.second.first].push_back(pair<int,int>(i.second.second,i.first));
        G[i.second.second].push_back(pair<int,int>(i.second.first,i.first));
        U(i.second.first,i.second.second);
    }
    for(int i=1;i<=v;++i)if(!u[i])dfs(i,0,0);
    // if(DEBUG)for(int i=0;i<=2;++i){for(int j=1;j<=6;++j)cout<<p[i][j]<<" ";cout<<endl;}
    // if(DEBUG)for(int i=0;i<=2;++i){for(int j=1;j<=6;++j)cout<<mx[i][j]<<" ";cout<<endl;}
    int q,s,t; rit(q); while(q--){
        rit(s,t); if(s==t)puts("0");
        else if(C(s,t))printf("%u\n",meow(s,t));
        else puts("-1");
    }
}
