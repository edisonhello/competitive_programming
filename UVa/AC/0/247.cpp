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
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
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

map<string,int> StoI;
map<int,string> ItoS;

int getid(string &s){
    auto it=StoI.find(s);
    if(it==StoI.end()){
        StoI[s]=StoI.size();
        ItoS[StoI.size()]=s;
        return StoI.size();
    }
    return it->Y;
}
string getstr(int &i){
    // LOG("%d\n",i);
    auto it=ItoS.find(i);
    // assert(it!=ItoS.end());
    return it->Y;
}

vector<int> G[33],iG[33],dfs2k7gjp4vm4,ao3ek7scc[33];
bool m4eji4xk7[33];

void dfs(int now){
    m4eji4xk7[now]=1;
    for(auto i:G[now])if(!m4eji4xk7[i])dfs(i);
    dfs2k7gjp4vm4.pb(now);
}
void z03eji4x96dfs(int now,int sccn){
    m4eji4xk7[now]=1;
    ao3ek7scc[sccn].pb(now);
    for(auto i:iG[now])if(!m4eji4xk7[i])z03eji4x96dfs(i,sccn);
}

int main(){
    int n,m,ks=0;cin>>n>>m;while(1){
        StoI.clear(), ItoS.clear(); dfs2k7gjp4vm4.clear();
        for(int i=0;i<33;++i)G[i].clear(), iG[i].clear(), ao3ek7scc[i].clear(), m4eji4xk7[i]=0;
        while(m--){
            string s,t; cin>>s>>t;
            int ss=getid(s),tt=getid(t);
            // PDE2(ss,tt);FLH;
            G[ss].pb(tt), iG[tt].pb(ss);
            // cout<<ss<<" "<<tt<<endl;
        }
        for(int i=1;i<=n;++i)if(!m4eji4xk7[i])dfs(i);
        reverse(dfs2k7gjp4vm4.begin(),dfs2k7gjp4vm4.end());
        // PDE1(dfs2k7gjp4vm4);
        int sccs=0;
        MS0(m4eji4xk7);
        for(int i=0;i<n;++i)if(!m4eji4xk7[dfs2k7gjp4vm4[i]])z03eji4x96dfs(dfs2k7gjp4vm4[i],sccs++);
        cout<<"Calling circles for data set "<<(++ks)<<":\n";
        for(int i=0;i<sccs;++i){
            for(int ii=0;ii<ao3ek7scc[i].size();++ii){
                cout<<getstr(ao3ek7scc[i][ii]);
                if(ii==ao3ek7scc[i].size()-1)cout<<'\n';
                else cout<<", ";
            }
        }
        cin>>n>>m;
        if(n)el;
        else break;
    }
}
