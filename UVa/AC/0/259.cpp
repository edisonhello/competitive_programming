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

struct edge{
    int u,v,f;
    edge(int u,int v,int f):u(u),v(v),f(f){};
};
vector<int> G[111],needchk;
vector<edge> edg;
vector<char> work;

void ae(int u,int v,int f){
    PDE3(u,v,f);
    G[u].push_back(edg.size());
    G[v].push_back(edg.size()+1);
    edg.push_back(edge(u,v,f));
    edg.push_back(edge(v,u,0));
}

vector<int> cf,bn,v,wid;
bool floww(){
    cf.clear(); cf.resize(111);
    bn.clear(); bn.resize(111); bn[0]=878787;
    v.clear() ; v.resize(111);
    queue<int> q; q.push(0);
    while(q.size()){
        for(int i:G[q.front()]){
            edge e=edg[i];
            if(e.f>0 && !v[e.v]){
                bn[e.v]=min(bn[e.u],e.f);
                cf[e.v]=i;
                q.push(e.v);
                v[e.v]=1;
            }
        }
        q.pop();
    }
    PDE1(bn[87]);
    if(!bn[87])return 0;
    for(int u=87,pw=0;u;u=edg[cf[u]].u){
        PDE1(u);
        if(u>0 && u<=26 && pw)wid[pw]=u,pw=0;
        else if(u>=30 && u<40)pw=u;
        edg[cf[u]].f-=bn[87];
        edg[cf[u]^1].f+=bn[87];
    } return 1;
}

int main(){
    string s; while(getline(cin,s)){
        for(int i=0;i<111;++i)G[i].clear(); edg.clear(); work.clear(); needchk.clear();
        work.resize(22,'_'); int totneed=0;
        do{
            char job=s[0]; int req=s[1]-'0'; SS ss(s); ss>>s>>s; s=s.substr(0,s.length()-1);
            PDE1(s);
            needchk.push_back(edg.size()); ae(0,job-'A'+1,req); totneed+=req; 
            for(char c:s)ae(job-'A'+1,c-'0'+30,1);
        }while(getline(cin,s) && s!="");
        for(int i=30;i<40;++i)ae(i,87,1);
        wid.clear(); wid.resize(111); while(floww())if(DEBUG){
            for(int i=30;i<40;++i)cout<<(char)(wid[i]?wid[i]-1+'A':'_');
            cout<<endl;
        }
        for(int i:needchk)if(edg[i].f>0){
            cout<<"!\n"; goto ww;
        }
        for(int i=30;i<40;++i)cout<<(char)(wid[i]?wid[i]-1+'A':'_'); cout<<endl;
        ww:;
    }
}
