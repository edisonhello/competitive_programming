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

struct edge{int u,v,f;} E;
vector<edge> edg;
vint G[2222];
char mp[222][222];

int bn[2222],cf[2222];
bitset<2222> inq;
bool floww(int st,int ed,int &ans){
    inq.reset(); 
    MS(bn,0); bn[st]=0x3f3f3f3f;
    queue<int> q; q.push(st);
    while(q.size()){
        // printf("q front %d\n",q.front());
        for(int i=0;i<G[q.front()].size();++i){
            if(bn[edg[G[q.front()][i]].v]<min(bn[q.front()],edg[G[q.front()][i]].f)){
                bn[edg[G[q.front()][i]].v]=min(bn[q.front()],edg[G[q.front()][i]].f);
                // printf("%d, %d\n",edg[G[q.front()][i]].v,bn[edg[G[q.front()][i]].v]);
                cf[edg[G[q.front()][i]].v]=G[q.front()][i];
                if(!inq[edg[G[q.front()][i]].v]){
                    inq[edg[G[q.front()][i]].v]=1;
                    q.push(edg[G[q.front()][i]].v);
                }
            }
        }
        inq[q.front()]=0; q.pop();
    }
    if(bn[ed]==0)return false;
    // printf("%d %d %d %d\n",st,ed,ans,bn[ed]);
    for(int u=ed;u!=st;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[ed];
        edg[cf[u]^1].f+=bn[ed];
        // printf("%d\n",u);
    }
    ans+=bn[ed];
    return true;
}
int flow(int st,int ed){
    int ans=0;
    while(floww(st,ed,ans));
    return ans;
}
void ae(int u,int v,int f){
    // printf("ae: %d %d %d\n",u,v,f);
    G[u].pb(edg.size());
    E.u=u, E.v=v, E.f=f;
    edg.pb(E);
    G[v].pb(edg.size());
    swap(E.u,E.v), E.f=0;
    edg.pb(E);
}
int main(){
    int r,c,d; scanf("%d %d %d\n",&r,&c,&d);
    for(int i=1;i<=r;++i){
        scanf("%s",mp[i]+1);
        for(int j=1;j<=c;++j){
            if(mp[i][j]!='0'){
                ae(i*25+j,i*25+j+888,mp[i][j]-'0');
            }
        }
    }
    for(int i=0;i<=r+1;++i){
        for(int j=0;j<=c+1;++j){
            if(mp[i][j]>'0'){
                for(int k=0;k<=r+1;++k){
                    for(int l=0;l<=c+1;++l){
                        if(i==k && j==l)continue;
                        if(mp[k][l]=='0')continue;
                        if((i-k)*(i-k)+(j-l)*(j-l)>d*d)continue;
                        ae(i*25+j+888,k*25+l,1000);
                    }
                }
            }
            else ae(i*25+j,2109,1000);
        }
    }
    int cnt=0;
    for(int i=1;i<=r;++i){
        char str[222]; scanf("%s",str+1);
        for(int j=1;j<=c;++j){
            if(str[j]=='L'){
                ae(2108,i*25+j,1);
                ++cnt;
            }
        }
    }
    printf("%d\n",cnt-flow(2108,2109));
}
