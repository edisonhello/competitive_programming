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
#include<tuple>

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
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

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
#define DEBUG "jizz"
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
#define DEBUG 0
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
void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int n,m,k;
map<string,int> msi;
struct edge{
    int u,v,cap;
    edge(int u,int v,int cap):u(u),v(v),cap(cap){};
};
vector<edge> edg;
vector<int> G[1111];

void clear(){
    msi.clear();
    edg.clear();
    for(int i=0;i<1111;++i)G[i].clear();
}

vector<int> d,se;
vector<bool> inq,v;
int flowwww(int &mxf){
    LOG("flowwww\n");
    d.clear(), d.resize(1111);
    se.clear(), se.resize(1111);
    inq.clear(), inq.resize(1111);
    v.clear(), v.resize(1111);

    queue<int> q; q.push(0); d[0]=8787;
    while(q.size()){
        int x=q.front(); q.pop();
        PDE1(x);
        for(int edi:G[x]){
            if(edg[edi].cap<=0)continue;
            if(!inq[edg[edi].v]){
                d[edg[edi].v]=min(d[x],edg[edi].cap);
                se[edg[edi].v]=edi;
                q.push(edg[edi].v);
                inq[edg[edi].v]=1;
            }
        }
        if(d[777])break;
    }
    if(!d[777])return 0;
    for(int u=777;u;u=edg[se[u]].u){
        edg[se[u]].cap-=d[777];
        LOG("bw: %d, add %d, %d left\n",u,d[777],edg[se[u]].cap);
        edg[se[u]^1].cap+=d[777];
    }
    assert(d[777]>0);
    return mxf+=d[777];
}
int flowww(){
    int ans=0;
    while(flowwww(ans));
    return ans;
}

int gid(string &s){
    int &id=msi[s];
    if(id==0)id=msi.size()+1;
    return id;
}

int main(){
    int ts; cin>>ts; while(ts--){
        clear();
        cin>>n; for(int i=0;i<n;++i){
            string s; cin>>s; int sid=gid(s);
            G[sid].push_back(edg.size());
            G[777].push_back(edg.size()+1);
            edg.push_back(edge(sid,777,1));
            edg.push_back(edge(777,sid,0));
        }
        cin>>m; for(int i=0;i<m;++i){
            string s,ss; cin>>s>>ss;
            int ssid=gid(ss);
            PDE3(i,ss,ssid);
            G[0].push_back(edg.size());
            G[ssid].push_back(edg.size()+1);
            edg.push_back(edge(0,ssid,1));
            edg.push_back(edge(ssid,0,0));
        }
        cin>>k; for(int i=0;i<k;++i){
            string s,ss; cin>>s>>ss;
            int sid=gid(s),ssid=gid(ss);
            G[sid].push_back(edg.size());
            G[ssid].push_back(edg.size()+1);
            edg.push_back(edge(sid,ssid,8787));
            edg.push_back(edge(ssid,sid,0));
        }
        if(DEBUG && 0){
            for(int i=0;i<=4;++i){
                for(int j:G[i]){
                    cout<<j<<" : ";
                    PDE3(edg[j].u,edg[j].v,edg[j].cap);
                }
            }
        }
        cout<<m-flowww()<<endl;
        if(DEBUG && 0)for(edge &e:edg){
            PDE3(e.u,e.v,e.cap);
        }
        if(ts)cout<<endl;
    }
}
