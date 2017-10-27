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

void JIZZ(){cout<<"No\n";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

vector<vint> wd;
vint G[100009];
bitset<100009> mrk,in,out;
int rec[100009];
void dfs(int now,int bring){
    PDE2("dfs",now);
    if(out[now])return;
    if(in[now] && !out[now] && bring)JIZZ();
    else if(in[now])return;
    PDE2("in",now);
    in[now]=1;
    bring+=mrk[now];
    rec[now]=bring;
    if(bring>1)JIZZ();
    for(int i:G[now]){
        dfs(i,bring);
    }
    PDE2("out",now);
    out[now]=1;
}
vint tp;
void pdfs(int now){
    if(in[now])return;
    in[now]=1;
    for(int i:G[now])pdfs(i);
    tp.pb(now);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0,len;i<n;++i){
        cin>>len; wd.push_back(vint(len));
        for(int j=0;j<len;++j)cin>>wd.back()[j];
    }
    for(int i=1;i<n;++i){
        vint &fnt=wd[n-i]; //wbg
        vint &bak=wd[n-i-1];
        PDE2(fnt,bak);
        if(fnt.size()<bak.size()){ //extdf
            int i=0;
            for(;i<fnt.size();++i){
                if(fnt[i]==bak[i])continue;
                else break;
            }
            if(i==fnt.size())JIZZ();
            G[fnt[i]].pb(bak[i]);
            if(fnt[i]>=bak[i])continue;
            mrk[bak[i]]=1;
        }
        else{
            int i=0;
            for(;i<bak.size();++i){
                if(fnt[i]==bak[i])continue;
                else break;
            }
            if(i==bak.size())continue;
            G[fnt[i]].pb(bak[i]);
            if(fnt[i]>=bak[i])continue;
            mrk[bak[i]]=1;
        }
    }
    if(DEBUG)for(int i=1;i<=m;++i){
        PDE3(i,G[i],mrk[i]);
    }
    for(int i=1;i<=m;++i){
        if(!in[i])pdfs(i);
    }
    in.reset();
    for(int i=m-1;i>=0;--i){
        if(!in[tp[i]])dfs(tp[i],0);
    }
    int cnt=0;
    for(int i=1;i<=m;++i){
        if(rec[i])++cnt;
    }
    cout<<"Yes"<<endl;
    cout<<cnt<<endl;
    for(int i=1;i<=m;++i){
        if(rec[i])cout<<i<<" ";
    }
}
