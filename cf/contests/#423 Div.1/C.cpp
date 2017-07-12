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
#define y1 Enyetuenwuevue
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
#define endl '\n'
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

struct ynode{
    ynode *u,*d;
    int v[5];
    ynode():u(NULL),d(NULL){MS0(v);};
    ynode(ynode *ref):u(ref->u),d(ref->d){for(int i=0;i<5;++i)v[i]=ref->v[i];}
};
struct xnode{
    xnode *l,*r;
    ynode *y;
    xnode():l(NULL),r(NULL),y(NULL){};
    xnode(xnode *ref):l(ref->l),r(ref->r),y(ref->y){};
} *root[100005];

int gid(char c){
    if(c=='A')return 0;
    else if(c=='T')return 1;
    else if(c=='C')return 2;
    else return 3;
}

void init(ynode *now,int yl,int yr,int yy,int tg,int v){
    if(yl==yr){
        now->v[tg]+=v;
    }
    else{
        if(yy<=((yl+yr)>>1))init(now->u=new ynode(now->u),yl,(yl+yr)>>1,yy,tg,v);
        else init(now->d=new ynode(now->d),((yl+yr)>>1)+1,yr,yy,tg,v);
    }
}
void init(xnode *now,int xl,int xr,int yl,int yr,int xx,int yy,int tg,int v){
    if(xl==xr){
        init(now->y=new ynode(now->y),yl,yr,yy,tg,v);
    }
    else{
        if(xx<=((xl+xr)>>1))init(now->l=new xnode(now->l),xl,(xl+xr)>>1,yl,yr,xx,yy,tg,v);
        else init(now->r=new xnode(now->r),((xl+xr)>>1)+1,xr,yl,yr,xx,yy,tg,v);
    }
}
void epdy(ynode *now,int l,int r){
    if(l==r)return;
    else{
        epdy(now->u=new ynode(),l,(l+r)>>1);
        epdy(now->d=new ynode(),((l+r)>>1)+1,r);
    }
}
void epdx(xnode *now,int l,int r){
    if(l==r){
        epdy(now->y=new ynode(),0,l-1);
    }
    else{
        epdx(now->l=new xnode(),l,((l+r)>>1));
        epdx(now->r=new xnode(),((l+r)>>1)+1,r);
    }
}
void mdf(ynode *now,int yl,int yr,int yy,int tg,int v){
    if(yl==yr){
        cout<<" "<<yl<<" v["<<tg<<"]+= "<<v<<endl;
        now->v[tg]+=v;
    }
    else{
        if(yy<=((yl+yr)>>1))init(now->u,yl,(yl+yr)>>1,yy,tg,v);
        else init(now->d,((yl+yr)>>1)+1,yr,yy,tg,v);
    }
}
void mdf(xnode *now,int xl,int xr,int yl,int yr,int xx,int yy,int tg,int v){
    if(xl==xr){
        cout<<"mdf "<<xl;
        mdf(now->y,yl,yr,yy,tg,v);
    }
    else{
        if(xx<=((xl+xr)>>1))mdf(now->l,xl,(xl+xr)>>1,yl,yr,xx,yy,tg,v);
        else mdf(now->r,((xl+xr)>>1)+1,xr,yl,yr,xx,yy,tg,v);
    }
}

int qry(ynode *now,int yl,int yr,int yy){
    if(yl==yr){
        int rt=0;
        for(int i=0;i<4;++i)rt+=now->v[i];
        return rt;
    }
    else{
        if(yy<=((yl+yr)>>1))return qry(now->u,yl,(yl+yr)>>1,yy);
        else return qry(now->d,((yl+yr)>>1)+1,yr,yy);
    }
}
int qry(xnode *now,int xl,int xr,int yl,int yr,int xx,int yy){
    if(xl==xr){
        return qry(now->y,yl,yr,yy);
    }
    else{
        if(xx<=((xl+xr)>>1))return qry(now->l,xl,(xl+xr)>>1,yl,yr,xx,yy);
        else return qry(now->r,((xl+xr)>>1)+1,xr,yl,yr,xx,yy);
    }
}

int main(){
    epdx(root[0]=new xnode(),1,10);
    string s; cin>>s;
    for(int i=0;i<s.length();++i){
        int id=gid(s[i]);
        for(int j=1;j<=10;++j)init(root[i+1]=new xnode(root[i]),1,10,0,j-1,j,i%j,id,1);
    }
    cout<<"inited\n";
    int com; cin>>com; while(com--){
        int t; cin>>t;
        if(t==1){
            int x; char c,o; cin>>x>>c; o=s[x];
            for(int j=1;j<=10;++j){
                mdf(root[x],1,10,0,j-1,j,x%j,gid(o),-1);
                mdf(root[x],1,10,0,j-1,j,x%j,gid(c),1);
            }
        }
        else{
            int l,r; string ss; cin>>l>>r>>ss;
            int ans=0;
            for(int i=0;i<ss.length();++i){
                ans+=qry(root[r],1,10,0,ss.length()-1,ss.length(),i)-qry(root[l-1],1,10,0,ss.length()-1,ss.length(),i);
            }
            cout<<ans<<endl;
        }
    }
}
