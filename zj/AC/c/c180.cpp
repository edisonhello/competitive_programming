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
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

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
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define endl '\n'
#define getchar gtx
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
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
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
inline bool rit(T& x){
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

struct node{
    node *l,*r;
    ll mx,tag;
    node():l(NULL),r(NULL),mx(0),tag(0){};
    node(int v):l(NULL),r(NULL),mx(0),tag(0){};
} *root;
ll a[300005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        // now->pre = now->mx = pre+a[l];
        return;
    }
    build(now->l = new node(),l,mid);
    build(now->r = new node(),mid+1,r);
    // now->mx = max({now->l->mx,now->r->mx});
}
void modify(node *now,int l,int r,int ml,int mr,ll v){
    if(now->tag){
        now->mx += now->tag;
        if(now->l){
            now->l->tag += now->tag;
            now->r->tag += now->tag;
        }
        now->tag = 0;
    }
    if(ml<=l && r<=mr){
        now->mx += v;
        if(now->l){
            now->l->tag += v;
            now->r->tag += v;
        }
        return;
    }
    if(r<ml || mr<l)return;
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    now->mx = max({now->l->mx,now->r->mx});
}
ll getMx(node *now,int l,int r,int ql,int qr){
    if(now->tag){
        now->mx += now->tag;
        if(now->l){
            now->l->tag += now->tag;
            now->r->tag += now->tag;
        }
        now->tag = 0;
    }
    if(ql<=l&&r<=qr)return now->mx;
    if(qr<l || r<ql)return -(1ll<<61);
    return max(getMx(now->l,l,mid,ql,qr),getMx(now->r,mid+1,r,ql,qr));
}
#undef mid

int n;
void allMinusCheck(){
    bool allMinus=1;
    for(int i=1;i<=n;++i)if(a[i]>=0){
        allMinus=0;
        break;
    }
    if(allMinus){
        ll mn=-(1ll<<61);
        for(int i=1;i<=n;++i)mn=max(mn,a[i]);
        cout<<mn<<endl;
        exit(0);
    }
    else return;
}
struct chg{int l,r;ll v;};
bool operator<(const chg &a,const chg &b){return a.l==b.l?a.r<b.r:a.l<b.l;}
vector<chg> l;
int main(){
    int m; rit(n,m);
    for(int i=1;i<=n;++i)rit(a[i]);
    allMinusCheck();
    build(root = new node(),1,n);
    for(int i=1;i<=n;++i)modify(root,1,n,i,n,a[i]);
    while(m--){
        int b,c,d; rit(b,c,d);
        l.push_back({b,c,d});
    }
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());
    for(auto &i:l){
        modify(root,1,n,i.r,n,i.v);
    }
    ll mx=root->mx;
    PDE1(mx);
    for(int i=1;i<=n;++i){
        modify(root,1,n,i+1,n,-a[i]);
        while(l.size() && l.back().l<=i){
            modify(root,1,n,l.back().r,n,-l.back().v);
            l.pop_back();
        }
        PDE1(getMx(root,1,n,i+1,n));
        mx=max(mx,getMx(root,1,n,i+1,n));
    }
    cout<<mx<<endl;
}
