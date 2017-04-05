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

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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

struct node{
    int v;
    bool vis;
};
vector<node> D[111];
int in[maxv],out[maxv];

struct edge{int v,cap;};
vector<edge> eg;
vint G[111];
int s,t,vcnt,lv[111],q[111];

void addEdge(int u,int v,int c){
    G[u].pb(eg.size());
    eg.pb({v,c});
    G[v].pb(eg.size());
    eg.pb({u,0});
}

bool bfs(){
    MS(lv,0);
    int l=0,r=0;
    q[r++]=S; lv[S]=1;
    while(r>l){
        int u=q[l++];
        for(int i=0;i<G[u].size();++i){
            auto &e=eg[G[u][i]];
            if(!lv[e.v] && e.cap){
                lv[e.v]=lv[u]+1;
                q[r++]=e.v;
            }
        }
    } return lv[T];
}

int cur[111];
int dfs(int u,int a)
{
    if(u==T || !a)return a;
    int flow=0,f;
    for(int &i=cur[u];i<G[u].size();i++){
        auto &e=eg[G[u][i]];
        if(lv[e.v]==lv[u]+1 && (f=dfs(e.v,min(e.cap,a)))){
            flow+=f;
            a-=f;
            e.cap-=f;
            edges[G[u][i]^1].cap+=f;
            if(!a)break;
        }
    } return flow;
}

int maxFlow(){
    int flow=0;
    while(bfs()){
        MS(cur,0);
        flow+=dfs(S,999999999);
    } return flow;
}

int build(){
    int del=0;
    for(int i=1,d;i<=V;i++){
        if((in[i]+out[i])&1)return -1;
        if(out[i]<in[i]){
            d=(in[i]-out[i])>>1; del+=d;
            addEdge(i,T,d);
        }
        else if(in[i]<out[i]){
            d=(out[i]-in[i])>>1;
            addEdge(S,i,d);
        }
    } return del;
}

int djs[111],cnt;
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
bool v[111];

void init(){
    S=0; T=V+1; vcnt=T+1;
    for(int i=1; i<=V;i++)D[i].clear(),in[i]=out[i]=0;
    for(int i=0;i<=T;i++)G[i].clear();
    for(int i=1;i<=V;i++)djs[i]=i;
    eg.clear(); MS(v,0);
    cnt=0;
}

bool read(){
    cin>>V>>E;
    init();
    for(int i=0,u,v;i<E;i++){
        char ch; cin>>u>>v>>ch;
        if(ch=='U')addEdge(u,v,1);
        else D[u].pb({v,false});
        if(!v[u])cnt++,vis[u] = true;
        if(!v[v])cnt++,vis[v] = true;
        int s1 = Find(u),s2 = Find(v);
        if(s1 != s2) {
            cnt--;
            djs[s1] = s2;
        }
        out[u]++; in[v]++;
    }
    return cnt == 1;
}

void reBuild()
{
    for(int u = 1; u <= V; u++){
        for(int i = 0; i < G[u].size(); i++){
            Edge &e = edges[G[u][i]];
            if(e.cap) {
                int v0 = edges[G[u][i]^1].v, v1 = e.v;
                if(v0&&v0<=V&&v1&&v1<=V) D[v0].PB({v1,false});
            }
        }
    }
}

stack<int> ans;
void Euler(int u)
{
    for(int i = 0; i < D[u].size(); i++){
        if(D[u][i].vis) continue;
        D[u][i].vis = true;
        int v = D[u][i].v;
        Euler(v);
        ans.push(v);
    }
}

void solve()
{
    if(read()) {
        int totFlow = build();
        if(~totFlow  && totFlow <= MaxFlow()) {
            reBuild();
            memset(cur,0,sizeof(int)*(vcnt));
            Euler(1);
            printf("1");
            while(ans.size()){
                printf(" %d",ans.top());
                ans.pop();
            }
            putchar(‘\n‘);
            return;
        }
    }
    puts("No euler circuit exist");
}

int main()
{
    //freopen("in.txt","r",stdin);
    int Test; scanf("%d",&Test);

    while(Test--){
        solve();
        if(Test) putchar(‘\n‘);
    }
    return 0;
}
