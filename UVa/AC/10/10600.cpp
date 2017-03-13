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
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define Ugbemugbem Osas

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
#define getchar gtx
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto it:mp)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto it:s)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

inline int lowbit(int &x){return x&-x;}
inline ll lowbit(ll &x){return x&-x;}

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
inline bool rit(T& x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c-'0');
    while(c=getchar(), c>='0' && c<='9')x=x*10+c-'0';
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
void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int n,m;
struct edge{int u,v,w,i;};
bool operator<(const edge &a,const edge &b){return a.w<b.w;}
vector<edge> eg;
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
struct node{int u,w,i;};
vector<node> G[105];
int d[105],p[9][105],mxw[9][105];
vector<bool> u;

void dfs(int now,int pa,int dep,int w){
    d[now]=dep;
    p[0][now]=pa;
    mxw[0][now]=max(mxw[0][now],w);
    for(int i=1;;++i){
        if((1<<i)>dep)break;
        p[i][now]=p[i-1][p[i-1][now]];
        mxw[i][now]=max(mxw[i-1][now],mxw[i-1][p[i-1][now]]);
    }
    for(auto i:G[now]){
        if(i.u==pa)continue;
        dfs(i.u,now,dep+1,i.w);
    }
}

int bgw(int pa,int pb){
    // PDE4(pa,pb,d[pa],d[pb]);
    int mx=0;
    if(d[pb]<d[pa])swap(pa,pb);
    for(int i=0;i<7;++i){
        if((1<<i)&(d[pb]-d[pa])){
            mx=max(mx,mxw[i][pb]);
            pb=p[i][pb];
        }
    }
    // PDE2(pa,pb);
    if(pa==pb)return mx;
    for(int i=6;i>=0;--i){
        if(p[i][pa]==p[i][pb])continue;
        mx=max({mx,mxw[i][pa],mxw[i][pb]});
        pa=p[i][pa], pb=p[i][pb];
    }
    // PDE2(pa,pb);
    return max({mx,mxw[0][pa],mxw[0][pb]});
}

int main(){
    int ts;cin>>ts;while(ts--){
        cin>>n>>m;

        eg.clear(); u.clear();
        int _num=0;
        while(m--){
            int u,v,w;cin>>u>>v>>w;
            eg.push_back({u,v,w,_num++});
        }
        sort(eg.begin(),eg.end()); u.resize(eg.size());
        // sort(eg.begin(),eg.end(),[](const edge &a,const edge &b)->bool{return a.w<b.w;});
        // for(auto i:eg)cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;

        djs.init(n+9);
        int MST=0;
        for(int i=0;i<=104;++i)G[i].clear();
        for(auto i:eg){
            if(djs.C(i.u,i.v))continue;
            djs.U(i.u,i.v); MST+=i.w; u[i.i]=1;
            PDE2(i.u,i.v);FLH;
            G[i.u].push_back({i.v,i.w,i.i});
            G[i.v].push_back({i.u,i.w,i.i});
        }

         MS0(d), MS0(p), MS0(mxw), dfs(1,0,0,0);

         int MMST=987654321;
         for(auto i:eg){
             if(u[i.i])continue;
             PDE5(i.u,i.v,i.w,bgw(i.u,i.v),MST+i.w-bgw(i.u,i.v));
             MMST=min(MMST,MST+i.w-bgw(i.u,i.v));
         }
         cout<<MST<<" "<<MMST<<endl;
    }
}
