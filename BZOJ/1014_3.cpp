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

unsigned ll ppp[123456];
struct node{
    node *l,*r;
    unsigned ll hh;
    int val,sz,pri;
    node(char ch=0):l(0),r(0),hh(ch),val(ch),sz(1){pri=rand();}
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    unsigned ll lh(){return l?l->hh:0;}
    unsigned ll rh(){return r?r->hh:0;}
} *root;
void pull(node *now){
    if(!now)return;
    now->sz=now->lz()+now->rz()+1;
    now->hh=now->lh()+ppp[now->lz()]*now->val+ppp[now->lz()+1]*now->rh();
}
node *merge(node *a,node *b){
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
void split(node *s,int sz,node *&a,node *&b){
    if(!s){a=b=0; return;}
    if(s->lz()>=sz){
        b=s; split(s->l,sz,a,b->l);
        pull(b);
    }
    else{
        a=s; split(s->r,sz-1-s->lz(),a->r,b);
        pull(a);
    }
}
void modify(int pos,char nc){
    node *a,*b,*c,*d; 
    split(root,pos-1,a,d);
    split(d,1,b,c);
    delete b;
    root=merge(a,merge(new node(nc),c));
}
void insert(int pos,char nc){
    node *a,*b;
    split(root,pos,a,b);
    root=merge(a,merge(new node(nc),b));
}
unsigned ll hhh(int pos,int len){
    node *a,*b,*c,*d;
    split(root,pos-1,a,d);
    split(d,len,b,c);
    unsigned ll rt=b?b->hh:0;
    root=merge(a,merge(b,c));
    return rt;
}
int query(int px,int py){
    if(px>py)swap(px,py);
    int L=0,R=root->sz-py+1;
    while(R>L){
        int M=(R+L+1)>>1;
        if(hhh(px,M)==hhh(py,M))L=M;
        else R=M-1;
    } return L;
}

int main(){
    srand(time(0));
    char str[123456]; scanf("%s",str);
    ppp[0]=1; for(int i=1;i<123456;++i)ppp[i]=ppp[i-1]*47017;
    for(int i=0;str[i]!='\0';++i)root=merge(root,new node(str[i]));
    int q; scanf("%d\n",&q); while(q--){
        char cmd; int x,y; scanf("%c %d ",&cmd,&x);
        if(cmd=='Q'){
            scanf("%d\n",&y);
            printf("%d\n",query(x,y));
        }
        else if(cmd=='R'){
            scanf("%c\n",&cmd);
            modify(x,cmd);
        }
        else{
            scanf("%c\n",&cmd);
            insert(x,cmd);
        }
    }
}
