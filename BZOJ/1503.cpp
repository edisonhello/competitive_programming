#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
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

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

struct node{
    node *l,*r;
    int mx,tag,sz,pri,val;
    node(int val=0):l(0),r(0),mx(val),val(val),tag(0),sz(1){pri=rand();}
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    int lx(){return l?l->mx:-7122;}
    int rx(){return r?r->mx:-7122;}
} *root;
void pull(node *a){
    if(!a)return;
    a->sz=a->lz()+a->rz()+1;
    a->mx=max(max(a->lx(),a->rx()),a->val);
}
void push(node *a){
    if(!a)return;
    if(a->tag){
        if(a->l){
            a->l->tag+=a->tag;
            a->l->mx+=a->tag;
            a->l->val+=a->tag;
        }
        if(a->r){
            a->r->tag+=a->tag;
            a->r->mx+=a->tag;
            a->r->val+=a->tag;
        }
        a->tag=0;
    }
}
node *merge(node *a,node *b){
    push(a); push(b);
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        pull(a); return a;
    }
    else{
        b->l=merge(a,b->l);
        pull(b); return b;
    }
}
void split_sz(node *s,int sz,node *&a,node *&b){
    if(!s){a=b=0; return;}
    push(s);
    if(s->lz()>=sz){
        b=s; split_sz(s->l,sz,a,b->l);
        pull(b); return;
    }
    else{
        a=s; split_sz(s->r,sz-1-s->lz(),a->r,b);
        pull(a); return;
    }
}
void split_val(node *s,int val,node *&a,node *&b){
    if(!s){a=b=0; return;}
    push(s);
    if(s->val<=val){
        b=s; split_val(s->l,val,a,b->l);
        pull(b); return;
    }
    else{
        a=s; split_val(s->r,val,a->r,b);
        pull(a); return;
    }
}
int bye;
void delT(node *&now){
    if(!now)return;
    if(now->l)delT(now->l);
    if(now->r)delT(now->r);
    delete now;
    now=0;
    ++bye;
}
int lb;
void insert(int val){
    if(val<lb){
        ++bye;
        return;
    }
    node *a,*b;
    split_val(root,val,a,b);
    root=merge(a,merge(new node(val),b));
}
void modify(int val){
    if(root){
        root->tag+=val;
        root->mx+=val;
        root->val+=val;
        node *a,*b;
        split_val(root,lb-1,a,b);
        root=a;
        delT(b);
    }
}
void pT(node *now){
    if(!now)return;
    if(now->l)printf("("),pT(now->l),printf(")");
    printf("val: %d, tag: %d, mx: %d",now->val,now->tag,now->mx);
    if(now->r)printf("("),pT(now->r),printf(")");
}
int find(int x){
    int rtv=-2;
    node *a,*b,*c,*d;
    split_sz(root,x-1,a,d);
    split_sz(d,1,b,c);
    // printf("a: "); pT(a); puts("");
    // printf("b: "); pT(b); puts("");
    // printf("c: "); pT(c); puts("");
    if(!b)rtv=-1;
    else if(b->val<lb)rtv=-1;
    else rtv=b->val;
    if(c && c->mx<lb)delT(c);
    if(b && b->mx<lb)delT(b);
    root=merge(a,merge(b,c));
    return rtv;
}
int main(){
    int q; scanf("%d %d\n",&q,&lb); while(q--){
        char ch; int val; scanf("%c %d\n",&ch,&val);
        if(ch=='I')insert(val);
        else if(ch=='S')modify(-val);
        else if(ch=='A')modify(val);
        else printf("%d\n",find(val));
        // pT(root); puts("");
    }
    printf("%d\n",bye);
}
