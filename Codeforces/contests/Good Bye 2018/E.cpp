// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

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
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define vpii vector<pair<int,int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

int n;

struct node{
    node *l,*r;
    int idx,val,tag,sz,pri;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; }
    void push(){
        if(!tag)return;
        if(l)l->addtag(tag);
        if(r)r->addtag(tag);
        tag=0;
    }
    void addtag(int x){
        val+=x;
        tag+=x;
    }
    node(int i=0,int val=0):l(0),r(0),idx(i),val(val),tag(0),sz(1),pri(rand()){}
} *croot,*root,pool[1000005];
int itr,itr2;
node *gnode(int i,int v){
    pool[itr].l=0;
    pool[itr].r=0;
    pool[itr].idx=i;
    pool[itr].val=v;
    pool[itr].tag=0;
    pool[itr].sz=1;
    return &pool[itr++];
}

void split_val(node *now,int v,node *&a,node *&b){ // >= put in L
    if(!now){ a=b=0; return; }
    now->push();
    if(now->val>=v){
        a=now;
        split_val(now->r,v,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split_val(now->l,v,a,b->l);
        b->pull();
    }
}
void split_sz(node *now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    now->push();
    if(now->lz()>=sz){
        b=now;
        split_sz(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        split_sz(now->r,sz-1-now->lz(),a->r,b);
        a->pull();
    }
}
node *merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;
    a->push(); b->push();
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}

int deg[500005];


void pureinsert(int i,int v){
    node *a,*b;
    split_val(croot,v,a,b);
    croot=merge(a,merge(gnode(i,v),b));
}
void insert(int i,int v){
    node *a,*b;
    split_val(root,v,a,b);
    root=merge(a,merge(gnode(i,v),b));
}

inline void del(){
    // itr=0;
}

/* void build(){
    del();
    for(int i=0;i<=n;++i)insert(i,deg[i]);
} */
void purebuild(){
    for(int i=1;i<=n;++i)pureinsert(i,deg[i]);
}

node *getleft(node *now){
    if(!now)return 0;
    now->push();
    if(now->l)return getleft(now->l);
    return now;
}
node *getright(node *now){
    if(!now)return 0;
    now->push();
    if(now->r)return getright(now->r);
    return now;
}

void printtree(node *now){
    if(!now)return;
    now->push();
    if(now->l)cout<<"(",printtree(now->l),cout<<")";
    cout<<now->val;
    if(now->r)cout<<"(",printtree(now->r),cout<<")";
}

void print(node *now){
    // printtree(now); cout<<endl;
}

void copy(node *mas,node *&di){
    di=&pool[itr2++];
    memcpy(di,mas,sizeof(node));
    if(mas->l)copy(mas->l,di->l=&pool[itr2++]);
    if(mas->r)copy(mas->r,di->r=&pool[itr2++]);
}

int go(int MM){
    deg[0]=MM;
    // build();
    itr2=500001;
    copy(croot,root);
    insert(0,deg[0]);
    print(root);
    // print(root);
    while(root){
        // print(root);
        node *a,*b;
        split_sz(root,1,a,b);
        int cut=a->val;
        PDE(cut,b,b?b->sz:0);
        if(cut==0){ root=0; del(); return -1; }
        if(!b || cut>b->sz){ int r=a->idx; root=0; del(); return r; }
        node *c,*d;
        split_sz(b,cut,c,d);
        c->addtag(-1);
        node *crr=getright(c);
        if(crr->val<0){ int r=a->idx; root=0; del(); return r; }
        if(c && d){
            node *dll=getleft(d);
            if(crr->val<dll->val){
                node *cl,*cr,*dl,*dr;
                split_val(c,crr->val+1,cl,cr);
                split_val(d,dll->val,dl,dr);
                c=merge(cl,dl);
                d=merge(cr,dr);
            }
        }
        root=merge(c,d);
    }
    return -1;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112], *ptr=buffer, *end=buffer+4096;
    template <typename T> inline void writeint(T x, char endc='\n'){
        if(x<0)*ptr = '-', ++ptr, x=-x; if(!x)*ptr='0', ++ptr;
        char *s=ptr, c; T t;
        while(x){ t=x/10; c=x-10*t+'0'; *ptr=c, ++ptr, x=t; }
        char *f=ptr-1; while(s<f)swap(*s,*f), ++s, --f;
        if(ptr>end)fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
        *ptr=endc, ++ptr;
    }

    template<typename T>
    inline void output(T x){ writeint(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ writeint(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop
int main(){
    srand(time(0)+clock());
    rit(n);
    for(int i=1;i<=n;++i)rit(deg[i]);
    long long degsum=0;
    for(int i=1;i<=n;++i)degsum+=deg[i];
    int la=degsum&1;
    purebuild();
    print(croot);

    int L=0,R=n;
    while(L<R){
        int M=(L+R)>>1;
        int MM=((M<<1)|la);
        int deadwhen=go(MM);
        PDE(L,R,M,MM,deadwhen);
        if(deadwhen==-1 || deg[deadwhen]<=deg[0])R=M;
        else L=M+1;
    }
    int ansl=(L<<1)|la;
    R=n;
    while(L<R){
        int M=(L+R+1)>>1;
        int MM=((M<<1)|la);
        int deadwhen=go(MM);
        PDE(L,R,M,MM,deadwhen);
        if(deadwhen==-1)L=M;
        else R=M-1;
    }
    int ansr=(L<<1)|la;
    PDE(ansl,ansr);
    if(go(ansl)!=-1)exit((cout<<-1<<endl,0));
    for(int i=ansl;i<=ansr;i+=2)pit.writeint(i,' ');
}
