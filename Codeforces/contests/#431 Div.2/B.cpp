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
const ld eps=1e-8;
const ll mod=1e9+7;
int n;
int pos[1111];/*
pair<ld,ld> build(int x1,int y1,int x2,int y2){
    if(x2==x1)return pair<ld,ld>(7122,7122);
    return pair<ld,ld>((x2-x1)/(y2-y1),y1-(x2-x1)/(y2-y1));
}*/
vector<int> l1,l2;

ld getm(vector<int> &cur){
    if(cur.size()<2u)return 7122;
    return ((ld)pos[cur[1]]-(ld)pos[cur[0]])/((ld)cur[1]-(ld)cur[0]);
}
ld getof(vector<int> &cur){
    
    return (ld)pos[cur[1]]-getm(cur)*(ld)cur[1];
}
bool canins(int id,vector<int> &cur){
    if(cur.size()<2u)return 1;
    ld m=((ld)pos[cur[1]]-(ld)pos[cur[0]])/((ld)cur[1]-(ld)cur[0]);
    ld of=(ld)pos[cur[1]]-m*(ld)cur[1];
    PDE4(id,cur,m,of);
    PDE1((ld)pos[id]-(ld)id*m-of);
    if(abs((ld)pos[id]-(ld)id*m-of)<eps)return 1;
    return 0;
}
void dfs(int now){
    if(now==n+1){
        if(abs(getm(l1)-getm(l2))>eps && l1.size()>1u && l2.size()>1u)return ;
        if(l1.size()==0 || l2.size()==0)return;
        if(l1.size()>1u && l2.size()>1u && abs(getof(l1)-getof(l2))<eps)return;
        PDE2(l1,l2);
        cout<<"Yes"<<endl;
        exit(0);
    }
    PDE3(now,l1,l2);
    if(canins(now,l1))l1.push_back(now),dfs(now+1),l1.pop_back();
    if(canins(now,l2))l2.push_back(now),dfs(now+1),l2.pop_back();
}
void getin1(int now){
    if(now==n+1){
        cout<<"No"<<endl;
        exit(0);
    }PDE1(now);
    if(canins(now,l1))l1.push_back(now),getin1(now+1);

}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>pos[i];
    getin1(1);
    l1.clear();
    dfs(1);
cout<<"No"<<endl;
    /*for(int i=1;i<=n;++i){
        pair<ld,ld> l1=build(1,pos[1],i,pos[i]);
        vector<int> l2s;
        for(int j=2;j<=min(4,n);++j){
            if(l2s.size()>1u)break;
            if(j!=i)l2s.push_back(j);
        }
        pair<ld,ld> l2=build(
    }*/
}
