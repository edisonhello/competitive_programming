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
// ostream& operator<<(ostream &ostm,const __int128 &val){__int128 cpy=val; stack<int> st; while(cpy)st.push(cpy%10),cpy/=10; while(st.size())ostm<<st.top(),st.pop();return ostm;}

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

inline ll gcd(ll x,ll y){
    if(!x)return y; if(!y)return x;
    return __gcd(x,y);
}

struct meow{
    meow *l,*r;
    int sz,px,py,yl,yr;
    ll val,gcd;
    meow(int x=0,int y=0,ll k=0):l(0),r(0),sz(1),px(x),py(y),yl(y),yr(y),val(k),gcd(k){}
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    int gl(){return l?l->yl:py;}
    int gr(){return r?r->yr:py;}
    ll lv(){return l?l->gcd:0;}
    ll rv(){return r?r->gcd:0;}
};
struct node{
    node *l,*r;
    meow *root;
    node():l(0),r(0),root(0){}
} *root;
void pull(meow *now){
    now->sz=now->lz()+now->rz()+1;
    now->yl=now->gl();
    now->yr=now->gr();
    now->gcd=gcd(now->val,gcd(now->lv(),now->rv()));
}
void rotate(meow *&now){
    if(now->lz()-2>now->rz()){
        meow *tmp=now->l;
        now->l=tmp->r;
        tmp->r=now;
        now=tmp;
        pull(now->r);
        pull(now);
    }
    else if(now->rz()-2>now->lz()){
        meow *tmp=now->r;
        now->r=tmp->l;
        tmp->l=now;
        now=tmp;
        pull(now->l);
        pull(now);
    }
}

#define mid ((l+r)>>1)
void modify(meow *&now,int x,int y,ll k){
    if(!now){now=new meow(x,y,k); return;}
    if(now->px==x && now->py==y){now->val=k; pull(now); rotate(now);}
    if(pii(y,x)<pii(now->py,now->px)){modify(now->l,x,y,k); pull(now); rotate(now);}
    else{modify(now->r,x,y,k); pull(now); rotate(now);}
}
void modify(node *&now,int l,int r,int x,int y,ll k){
    if(x>r || x<l)return;
    if(!now)now=new node();
    modify(now->root,x,y,k);
    if(l==r)return;
    modify(now->l,l,mid,x,y,k);
    modify(now->r,mid+1,r,x,y,k);
}
ll query(meow *now,int l,int r){
    if(!now)return 0;
    if(l<=now->yl && now->yr<=r)return now->gcd;
    if(r<now->yl  ||  now->yr<l)return 0;
    ll rt=0;
    if(l<=now->py && now->py<=r)rt=now->val;
    if(l<now->py)rt=gcd(rt,query(now->l,l,r));
    if(r>now->py)rt=gcd(rt,query(now->r,l,r));
    return rt;
}
ll query(node *now,int l,int r,int ql,int qr,int yl,int yr){
    if(!now)return 0;
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr)return query(now->root,yl,yr);
    return gcd(query(now->l,l,mid,ql,qr,yl,yr),query(now->r,mid+1,r,ql,qr,yl,yr));
}
#undef mid
int main(){
    int r,c,n; cin>>r>>c>>n;
    while(n--){
        int cmd; cin>>cmd;
        if(cmd==1){
            int p,q; ll k; cin>>p>>q>>k;
            modify(root,0,r-1,p,q,k);
        }
        else{
            int p,q,u,v; cin>>p>>q>>u>>v;
            cout<<query(root,0,r-1,p,u,q,v)<<endl;
        }
    }
}
