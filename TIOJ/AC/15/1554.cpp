#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>

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

struct edge{
    int u,v,f;
    ld cst;
    edge(int u=0,int v=0,int f=0,ld cst=0):u(u),v(v),f(f),cst(cst){}
};
vector<edge> edg;
vint G[111];
void addedge(int u,int v,int f,ld cst){
    G[u].pb(edg.size());
    edg.eb(u,v,f,cst);
    G[v].pb(edg.size());
    edg.eb(v,u,0,-cst);
}
int cf[111],bn[111];
ld d[111];
bitset<111> inq;
bool floww(int st,int ed,ld &nans){
    inq.reset();
    MS(bn,0); bn[st]=0x3f3f3f3f;
    fill(d,d+111,1e10); d[st]=0;
    queue<int> q; q.push(st); inq[st]=1;
    while(q.size()){
        int np=q.front(); q.pop(); inq[np]=0;
        for(int eid:G[np]){
            if(edg[eid].f && d[edg[eid].v]>d[np]+edg[eid].cst){
                d[edg[eid].v]=d[np]+edg[eid].cst;
                cf[edg[eid].v]=eid;
                bn[edg[eid].v]=min(bn[np],edg[eid].f);
                if(!inq[edg[eid].v]){
                    inq[edg[eid].v]=1;
                    q.push(edg[eid].v);
                }
            }
        }
    }
    if(!bn[ed])return false;
    nans+=d[ed];
    PDE2(d[ed],bn[ed]);
    for(int u=ed;u!=st;u=edg[cf[u]].u){
        PDE1(u);
        edg[cf[u]].f-=bn[ed];
        edg[cf[u]^1].f+=bn[ed];
    }
    return true;
}
ld flow(int st,int ed){
    ld ans=0;
    while(floww(st,ed,ans));
    PDE1(ans);
    return ans;
}
int main(){
    int n; scanf("%d",&n);
    // srand(time(0));
    // int n=20;
    for(int i=1;i<=n;++i){
        addedge(0,i,1,0);
        addedge(i+25,87,1,0);
        for(int j=1;j<=n;++j){
            ld cst; scanf("%Lf",&cst); cst/=100;
            // ld cst=(ld)rand()/RAND_MAX;
            // ld cst=0;
            cst=-log10(cst+1e-8);
            PDE3(i,j,cst);
            addedge(i,j+25,1,cst);
        }
    }
    printf("%.2Lf\n",pow(10,-flow(0,87))*100);
    // cout<<fixed<<setprecision(2)<<pow(10,-flow(0,87))*100<<endl;
}
