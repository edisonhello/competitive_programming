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

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;
struct disjointSet{
    std::vector<int> djs;
    void init(int size){
        djs.resize(size);
        for(int i=0;i<size;++i)djs[i]=i;
    }
    int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
    void U(int x,int y){djs[F(x)]=F(y);}
    bool C(int x,int y){return F(x)==F(y);}
} djs;

vector<pii> G[1006];
vector<pair<ll,pii>> E;
PQ<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> pq;
int p[12][1006],d[1006];
ll mx[12][1006];

void dfs(int now,int pa,int dep){
    d[now]=dep;
    p[0][now]=pa;
    for(int i=1;(1<<i)<dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
        mx[i][now]=max(mx[i-1][now],mx[i-1][p[i-1][now]]);
    }
    for(auto i:G[now]){
        if(i.X==pa)continue;
        mx[0][i.X]=i.Y;
        dfs(i.X,now,dep+1);
    }
}
ll lca(int pa,int pb){
    ll rt=0;
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<12;++i)if((d[pb]-d[pa])&(1<<i)){
        rt=max(rt,mx[i][pb]);
        pb=p[i][pb];
    }
    if(pa==pb)return rt;
    for(int i=11;i>=0;--i)if(p[i][pa]!=p[i][pb]){
        rt=max(rt,max(mx[i][pa],mx[i][pb]));
        pa=p[i][pa];
        pb=p[i][pb];
    } return max(rt,max(mx[0][pa],mx[0][pb]));
}
int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; ll c; cin>>u>>v>>c;
        pq.push({c,pii(u,v)});
        E.eb(c,pii(u,v));
    }
    djs.init(1006);
    int pointsssss=1;
    ll firstttttt=0;
    while(pq.size()){
        if(!djs.C(pq.top().Y.X,pq.top().Y.Y)){
            G[pq.top().Y.X].eb(pq.top().Y.Y,pq.top().X);
            G[pq.top().Y.Y].eb(pq.top().Y.X,pq.top().X);
            ++pointsssss;
            firstttttt+=pq.top().X;
            djs.U(pq.top().Y.X,pq.top().Y.Y);
        } pq.pop();
    } if(pointsssss<n)return cout<<"-1 -1"<<endl,0;
    if(E.size()==n-1)return cout<<firstttttt<<" -1"<<endl,0;
    dfs(1,1,1);
    PDE1(firstttttt);
    ll diffffffff=1000000000000000000ll;
    for(auto i:E){
        if(p[0][i.Y.X]==i.Y.Y || p[0][i.Y.Y]==i.Y.X)continue;
        PDE1(i);
        diffffffff=min(diffffffff,i.X-lca(i.Y.X,i.Y.Y));
    } cout<<firstttttt<<" "<<firstttttt+diffffffff<<endl;
}
