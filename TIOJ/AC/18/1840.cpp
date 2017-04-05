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
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define FLH fflush(stdout)

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<'\n'
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<'\n'
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<" , "<<#d<<" = "<<(d)<<'\n'
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
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
template<typename T>
inline T _pow(T b,int n){
    T a=1; while(n){
        if(n&1)a*=b; b*=b,n>>=1;
    } return a;
}
template<typename T>
inline T _pow(T b,int n,T mod){
    T a=1%mod; while(n){
        if(n&1)a=a*b%mod; b=b*b%mod,n>>=1;
    } return a;
}

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

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;
int a[50005];

struct treap{
    treap *l,*r;
    int val,sz;
    inline int lz(){return l?l->sz:0;}
    inline int rz(){return r?r->sz:0;}
    treap():l(NULL),r(NULL),val(0),sz(1){};
    treap(int v):l(NULL),r(NULL),val(v),sz(1){};
};
struct seg{
    seg *l,*r;
    treap *root;
    seg():l(NULL),r(NULL),root(NULL){};
} *root;
inline void psz(treap *now){now->sz=now->lz()+now->rz()+1;}
inline void rot(treap *&now,int dir){
    if(!~dir){
        treap *tmp=now->l;
        now->l=tmp->r;
        tmp->r=now;
        now=tmp;
    }
    else if(dir){
        treap *tmp=now->r;
        now->r=tmp->l;
        tmp->l=now;
        now=tmp;
    }
}
inline treap *pull(treap *&now){
    if(!now)return now;
    rot(now, now->lz()!=now->rz()?now->lz()>now->rz()?-1:1:0);
    if(now->l)psz(now->l);
    if(now->r)psz(now->r);
    return psz(now),now;
}

void insert(treap *&base,int val){
    if(!base){base=new treap(val);return;}
    if(base->val > val)insert(base->l,val);
    else insert(base->r,val);
    pull(base);
}
void insert(treap *&base,treap *qu){
    if(!qu)return;
    if(qu->l)insert(base,qu->l);
    if(qu->r)insert(base,qu->r);
    insert(base,qu->val);
    pull(base);
}
void remove(treap *&now,int val){
    if(!now)return;
    if(now->val > val)remove(now->l,val);
    else if(now->val < val)remove(now->r,val);
    else{
        if(!now->l){
            treap *bd=now;
            now=now->r;
            delete bd;
        }
        else if(!now->r){
            treap *bd=now;
            now=now->l;
            delete bd;
        }
        else{
            bool dir=now->lz()>now->rz();
            rot(now,dir?-1:1);
            remove(dir?now->r:now->l,val);
        }
    }
    pull(now);
}
// void print(treap *now){
// #ifdef WEAK
//     if(!now)return;
//     if(now->l)printf("("),print(now->l),printf(")");
//     pit(now->val);
//     if(now->r)printf("("),print(now->r),printf(")");
// #endif
// }
#define mid ((l+r)>>1)
void build(seg *&now,int l,int r){
    if(l==r){
        now->root=new treap(a[l]);
        return;
    }
    now->l=new seg(), now->r=new seg();
    build(now->l,l,mid), build(now->r,mid+1,r);
    insert(now->root,now->l->root), insert(now->root,now->r->root);
    pull(now->root);
    // LOG("Treap in range %d~%d: ",l,r);print(now->root);el;
}
void update(seg *&now,int l,int r,int c,int v){
    PDE4(l,r,c,v);
    if(c<l || c>r)return;
    int ori=a[c];
    if(l==r){
        a[c]=v;
        remove(now->root,ori);
        insert(now->root,a[c]);
        return;
    }
    update(now->l,l,mid,c,v), update(now->r,mid+1,r,c,v);
    remove(now->root,ori);
    insert(now->root,a[c]);
    pull(now->root);
    // LOG("Treap in range %d~%d: ",l,r);print(now->root);el;
}
int small(treap *&now,int v){
    // LOG("in now %x, search for %d\n",now,v);
    if(!now)return 0;
    // if(now->val==v)return now->lz();
    if(now->val>=v)return small(now->l,v);
    return small(now->r,v)+1+now->lz();
}
int small(seg *&now,int l,int r,int ql,int qr,int v){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return small(now->root,v);
    return small(now->l,l,mid,ql,qr,v)+small(now->r,mid+1,r,ql,qr,v);
}
vector<int> value;
struct command{int tp,x,y,z;};
vector<command> cmds;
inline void solve(const int &n,const int &q){
    cmds.resize(q);
    for(int i=0;i<q;++i){
        rit(cmds[i].tp);
        if(cmds[i].tp==1)rit(cmds[i].x,cmds[i].y,cmds[i].z),--cmds[i].x,--cmds[i].y;
        if(cmds[i].tp==2)rit(cmds[i].x,cmds[i].y),value.pb(cmds[i].y),--cmds[i].x;
        if(cmds[i].tp==3)rit(cmds[i].x,cmds[i].y);
    }
    sort(value.begin(),value.end());
    value.resize(unique(value.begin(),value.end())-value.begin());
    build(root=new seg(),0,n-1);
    int L,R;
    for(auto &cmd:cmds){
        if(cmd.tp==1){
            L=0,R=value.size();
            while(R>L){
                if(small(root,0,n-1,cmd.x,cmd.y,value[(L+R)>>1])>=cmd.z)R=((L+R)>>1);
                else L=((L+R)>>1)+1;
            }
            pit(value[L-1]),el;
        }
        else if(cmd.tp==2)update(root,0,n-1,cmd.x,cmd.y);
        else pit(7122),el;
    }
}
void clear(treap *now){
    if(!now)return;
    clear(now->l), clear(now->r);
    delete now;
}
void clear(seg *now){
    if(!now)return;
    clear(now->l), clear(now->r), clear(now->root);
    delete now;
}
inline void clear(){
    memset(a,0,sizeof(a));
    clear(root);root=NULL;
    value.clear();
    cmds.clear();
}
int main(){
    // FIN;
    int ts,n,q,i;rit(ts);while(ts--){
        rit(n,q);
        for(i=0;i<n;++i)rit(a[i]),value.pb(a[i]);
        solve(n,q);
        if(ts)clear();
    }
}
