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

const ll mod=1e9+7;

struct node{
    node *l,*r;
    ll val;
    node():l(0),r(0),val(0){};
    node(ll v):l(0),r(0),val(v){};
    node(node *ref):l(ref->l),r(ref->r),val(ref->val){};
} *root[200009];
int n,pos[200009];

#define mid ((l+r)>>1)
void build_empty(node *now,int l,int r){
    if(l==r)return;
    build_empty(now->l=new node(),l,mid);
    build_empty(now->r=new node(),mid+1,r);
}
void build(node *now,int l,int r,int x){
    ++now->val;
    if(l==r){return;}
    if(pos[x]<=mid)build(now->l=new node(now->l),l,mid,x);
    else build(now->r=new node(now->r),mid+1,r,x);
}
ll query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return now->val;
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

ll Q(int x1,int x2,int y1,int y2){
    if(x2<x1 || y2<y1)return 0;
    x1=max(1,x1), x2=min(x2,n);
    y1=max(1,y1), y2=min(y2,n);
    return query(root[x2],1,n,y1,y2)-query(root[x1-1],1,n,y1,y2);
}
#undef mid
void printTree(node *now){
    if(DEBUG);else return;
    if(!now)return;
    if(now->l)cout<<"(",printTree(now->l),cout<<")";
    cout<<now->val;
    if(now->r)cout<<"(",printTree(now->r),cout<<")";
}

int main(){
    int q,x1,y1,x2,y2; rit(n,q);
    for(int i=1;i<=n;++i)rit(pos[i]);
    build_empty(root[0]=new node(),1,n);
    for(int i=1;i<=n;++i)build(root[i]=new node(root[i-1]),1,n,i);
    LOG("treeeeeeee\n");
    if(DEBUG)for(int i=0;i<=n;++i)printTree(root[i]),cout<<endl;
    LOG("eeeeeeeert\n");
    while(q--){
        rit(x1,y1,x2,y2);
        ll ld=Q(1,x1-1,1,y1-1),md=Q(x1,x2,1,y1-1),rd=Q(x2+1,n,1,y1-1),
           lm=Q(1,x1-1,y1,y2),mm=Q(x1,x2,y1,y2),rm=Q(x2+1,n,y1,y2),
           lu=Q(1,x1-1,y2+1,n),mu=Q(x1,x2,y2+1,n),ru=Q(x2+1,n,y2+1,n);
        PDE3(lu,mu,ru);
        PDE3(lm,mm,rm);
        PDE3(ld,md,rd);
        printf("%lld\n",ld*(mm+mu+rm+ru)+lm*(md+mm+mu+rd+rm+ru)+lu*(md+mm+rd+rm)+md*(mm+mu+rm+ru)+mm*(mu+rd+rm+ru)+mu*(rd+rm)+mm*(mm-1)/2);
    }
}
