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
#include<tuple>

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
#define el putchar('\n')
#define spc putchar(' ')
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
#define DEBUG "jizz"
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
#define DEBUG 0
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
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

#define lowbit(x) ((x)&(-(x)))

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
void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int Rand(){
    static int seed=7122;
    return seed=(seed*5487)^'meow';
}

struct node{
    node *l,*r;
    int val,sz,tag,pri;
    node(int val=0):l(NULL),r(NULL),val(val),sz(1),tag(0),pri(Rand()){};
    int lz(){return this->l?this->l->sz:0;}
    int rz(){return this->r?this->r->sz:0;}
    node *pull(){
        this->sz=this->lz()+this->rz()+1;
        return this;
    }
} *root;
int ws[1000006];

void push(node *now){
    now->val+=now->tag;
    if(now->l)now->l->tag+=now->tag;
    if(now->r)now->r->tag+=now->tag;
    now->tag=0;
}
void printTree(node *now){
    if(!DEBUG || !now)return;
    if(now->l)cout<<"(",printTree(now->l),cout<<")";
    cout<<"["<<now->val<<","<<now->tag<<"]";
    if(now->r)cout<<"(",printTree(now->r),cout<<")";
}
node *merge(node *a,node *b){
    // if(DEBUG)LOG("merging a: "),printTree(a),printf(", b: "),printTree(b),el;
    if(!a)return b; if(!b)return a;
    if(a->tag)push(a); if(b->tag)push(b);
    if(b->pri>a->pri)return a->r=merge(a->r,b),a->pull();
    else return b->l=merge(a,b->l),b->pull();
}
void splitSize(node *now,int sz,node *&a,node *&b){
    if(!now){
        a=0,b=0;
        return;
    }
    push(now);
    if(now->lz()>=sz){
        b=now; splitSize(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now; splitSize(now->r,sz-1-now->lz(),a->r,b);
        a->pull();
    }
}
void splitVal(node *now,int val,node *&a,node *&b){
    if(!now){
        a=0,b=0;
        return;
    }
    if(now)push(now);
    if(now->val>val){
        b=now; splitVal(now->l,val,a,b->l);
        b->pull();
    }
    else{
        a=now; splitVal(now->r,val,a->r,b);
        a->pull();
    }
}
void addNode(int val){
    LOG("adding node val=%d\n",val);
    node *a,*b;
    splitVal(root,val,a,b);
    LOG("splited\n");
    if(DEBUG)printf("a:"),printTree(a),spc,printf("b:"),printTree(b),el;
    root=merge(merge(a,new node(val)),b);
    LOG("merged\n");
}
int getRight(node *now){
    PDE2(now,now?now->r:0);
    assert(now);
    if(now->tag)push(now);
    return now->r?getRight(now->r):now->val;
}

int main(){
    int n; cin>>n;
    while(n--){
        int u,v; cin>>u>>v;
        ++ws[u], --ws[v+1];
    }
    for(int i=1;i<=1000000;++i)ws[i]+=ws[i-1];
    int m; cin>>m;
    vector<pair<int,int>> wks;
    while(m--){
        int u,v; cin>>u>>v;
        wks.push_back(pair<int,int>(v,u));
    }
    sort(wks.begin(),wks.end());
    int nt=0;
    for(pair<int,int> w:wks){
        while(nt<w.first)addNode(ws[++nt]);
        LOG("working for time: %d, need %d\n",nt,w.second);
        node *a,*b;
        splitSize(root,w.second,a,b);
        ++a->tag;
        int rLimit=getRight(a);
        node *aa,*ab,*ba,*bb;
        splitVal(a,rLimit-1,aa,ab);
        splitVal(b,rLimit-1,ba,bb);
        if(DEBUG)printf("aa: "),printTree(aa),printf(", ab: "),printTree(ab),printf(", ba: "),printTree(ba),printf(", bb: "),printTree(bb),el;
        root=merge(merge(aa,ba),merge(ab,bb));
        LOG("new t:%d tree: ",nt); if(DEBUG)printTree(root),el;
    }
    while(nt<(DEBUG?10:1000000))addNode(ws[++nt]),printTree(root),DEBUG?el:0;
    printTree(root);
    cout<<getRight(root)<<endl;
}
