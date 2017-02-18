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
#define mid ((l+r)>>1)
#define xm ((x1+x2)/2)
#define ym ((y1+y2)/2)
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

struct node{
    node *l,*r;
    int sz,val,pri;
    node():l(NULL),r(NULL),sz(1),val(0){pri=rand();};
    node(int v):l(NULL),r(NULL),sz(1),val(v){pri=rand();};
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
} *root[20009];
inline node *pull(node *now){return now->sz=now->lz()+now->rz()+1,now;}
inline int sz(node *now){return now?now->sz:0;}

int people[20009],djs[20009],jizz,jizzed,Sekai=0;
struct eg{int u,v;bool willCrash=0;} edge[60009];
struct cm{char t;int x,y;} history[310009];

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri > b->pri){
        a->r=merge(a->r,b);
        return pull(a);
    }
    else{
        b->l=merge(a,b->l);
        return pull(b);
    }
}
void split(node *now,int v,node *&a,node *&b){
    if(!now){a=b=NULL;return;}
    if(now->val < v)a=now, split(now->r,v,a->r,b), pull(a);
    else b=now, split(now->l,v,a,b->l), pull(b);
}
int query(node *now,int k){
    LOG("in query for %d , at %x\n",k,now);
    if(!now)return 0;
    if(k>now->sz)return 0;
    if(k==now->rz()+1)return now->val;
    if(k<=now->rz())return query(now->r,k);
    return query(now->l,k-1-now->rz());
}
void insert(node *&root,int v){
    node *t,*a,*b,*c;
    LOG("before split\n");
    split(root,v,a,t), split(t,v+1,b,c);
    LOG("finish split\n");
    t=merge(a,b); a=merge(t,new node(v)); root=merge(a,c);
    LOG("finish merge\n");
}
void change(int whr,int hmn){
    LOG("in change %d %d\n",whr,hmn);
    int oripp=people[whr];
    node *t,*a,*b,*c;
    split(root[F(whr)],oripp,a,t), split(t,oripp+1,b,c);
    t=merge(b->l,b->r); b=merge(a,t); root[F(whr)]=merge(b,c);
    insert(root[F(whr)],people[whr]=hmn);
    LOG("out change\n");
}
void mergeNode(node *&base,node *&ano){
    if(!ano)return;
    if(ano->l)mergeNode(base,ano->l);
    if(ano->r)mergeNode(base,ano->r);
    LOG("merge in %d\n",ano->val);
    insert(base,ano->val);
    delete ano;
}
void mergeTreap(int edgnm){
    LOG("merge treap %d and %d\n",edge[edgnm].u,edge[edgnm].v);
    int u=F(edge[edgnm].u),v=F(edge[edgnm].v);
    if(u==v)return; if(sz(root[u])<sz(root[v]))swap(u,v);
    mergeNode(root[u],root[v]); root[v]=0; djs[v]=u;
    // if(C(edge[edgnm].u,edge[edgnm].v))return;
    // if(root[F(edge[edgnm].v)]->sz > root[F(edge[edgnm].u)]->sz){
    //     LOG("merge %d to %d\n",F(edge[edgnm].u),F(edge[edgnm].v));
    //     mergeNode(root[F(edge[edgnm].v)],root[F(edge[edgnm].u)]);
    //     root[F(edge[edgnm].u)]=NULL;
    //     djs[F(edge[edgnm].u)]=F(edge[edgnm].v);
    // }
    // else{
    //     LOG("merge %d to %d\n",F(edge[edgnm].v),F(edge[edgnm].u));
    //     mergeNode(root[F(edge[edgnm].u)],root[F(edge[edgnm].v)]);
    //     root[F(edge[edgnm].v)]=NULL;
    //     djs[F(edge[edgnm].v)]=F(edge[edgnm].u);
    // }
}
void printTreap(node *now){
    if(!now)return;
    if(now->l)printf("("),printTreap(now->l),printf(")");
    printf("%d",now->val);
    if(now->r)printf("("),printTreap(now->r),printf(")");
}
void solve(int &n,int &m,int &q){
    for(int i=0;i<q;++i){
        auto &cmd=history[i];
        LOG("processing command %d(inv) %c:%d %d\n",i,cmd.t,cmd.x,cmd.y);
        // for(int j=0;j<n;++j)if(root[j])printf("Treap num %d: ",j),printTreap(root[j]),el;else printf("Treap num %d: ()\n",j);
        if(cmd.t=='Q')jizzed+=query(root[F(cmd.x)],cmd.y),++jizz;
        else if(cmd.t=='C')change(cmd.x,cmd.y);
        else if(cmd.t=='D')mergeTreap(cmd.x);
        LOG("now jizzed is %d\n",jizzed);
    }
    // cout<<(ld)jizzed/jizz<<endl;fflush(stdout);
    printf("Sekai %d: %.6lf\n",++Sekai,(double)jizzed/jizz),fflush(stdout);
}
void init(int &n,int &m){
    LOG("in init\n");
    for(int i=0;i<n;++i)djs[i]=i;
    // for(int i=0;i<m;++i)if(!edge[i].willCrash)U(edge[i].u,edge[i].v);
    LOG("before insert\n");
    // for(int i=0;i<n;++i)insert(root[F(i)],people[i]);
    for(int i=0;i<n;++i)root[i]=new node(people[i]);
    for(int i=0;i<m;++i)if(!edge[i].willCrash)mergeTreap(i);
    LOG("finish insert\n");
}
void read(int &n,int &m,int &q){
    for(int i=0;i<n;++i)cin>>people[i];
    for(int i=0;i<m;++i)cin>>edge[i].u>>edge[i].v;
    LOG("reading...\n");
    for(;;++q){ cin>>history[q].t;
        if(history[q].t=='Q')cin>>history[q].x>>history[q].y;
        else if(history[q].t=='C'){ cin>>history[q].x>>history[q].y;
            swap(people[history[q].x],history[q].y);
        }
        else if(history[q].t=='D'){ cin>>history[q].x;
            edge[history[q].x].willCrash=1;
        }
        else break;
    }
    LOG("finish read in\n");
}
void clearTreap(node *now){
    if(!now)return;
    clearTreap(now->l), clearTreap(now->r);
    delete now;
}
void clear(){
    for(int i=0;i<20006;++i)clearTreap(root[i]),root[i]=NULL;
    memset(people,0,sizeof(people));
    memset(djs,0,sizeof(djs));
    memset(edge,0,sizeof(edge));
    memset(history,0,sizeof(history));
    jizz=jizzed=0;
}
int main(){ CIO;
    // FIN, FOUT;
    srand(1234);
    int n,m,q;while(cin>>n>>m,n){
        clear();
        read(n,m,q=0);
        init(n,m);
        reverse(history,history+q);
        solve(n,m,q);
    }
}
