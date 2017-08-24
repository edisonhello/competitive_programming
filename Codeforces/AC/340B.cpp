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
void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

struct pnt{int x,y;} p[333];
int tb[333];
bool itb[333];

int meow(int x1,int x2,int n1){
    return (p[n1].x-p[x2].x)*(p[x1].y-p[x2].y)-(p[n1].y-p[x2].y)*(p[x1].x-p[x2].x);
}
ld getArea(int p1,int p2,int p3,int p4){
    return (ld)abs(p[p1].x*p[p2].y+p[p2].x*p[p3].y+p[p3].x*p[p4].y+p[p4].x*p[p1].y
                 -(p[p1].y*p[p2].x+p[p2].y*p[p3].x+p[p3].y*p[p4].x+p[p4].y*p[p1].x));
}
ld trivago(int p1,int p2,int p3){
    return (ld)abs(p[p1].x*p[p2].y+p[p2].x*p[p3].y+p[p3].x*p[p1].y
             -(p[p1].y*p[p2].x+p[p2].y*p[p3].x+p[p3].y*p[p1].x));
}
ld jizz(int p1,int p2,int p3,int i1){
    return trivago(p1,p2,p3)-min({trivago(p1,p2,i1),trivago(p1,i1,p3),trivago(i1,p2,p3)});
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    sort(p,p+n,[](const pnt &a,const pnt &b)->bool{return a.x==b.x?a.y<b.y:a.x<b.x;});
    // for(int i=0;i<n;++i)cout<<p[i].x<<" "<<p[i].y<<endl;
    int up=0;
    for(int i=0;i<n;++i){
        while(up>1 && meow(tb[up-2],tb[up-1],i)>0)--up;
        tb[up++]=i;
    }
    for(int i=n-2,t=up;i>=0;--i){
        while(up>t+1 && meow(tb[up-2],tb[up-1],i)>0)--up;
        tb[up++]=i;
    }
    --up;
    for(int i=0;i<up;++i)itb[tb[i]];
    // for(int i=0;i<up;++i)cout<<p[tb[i]].x<<" "<<p[tb[i]].y<<endl;
    ld mx=0;
    if(up==3){
        for(int i=0;i<n;++i){
            if(itb[i])continue;
            mx=max(mx,jizz(tb[0],tb[1],tb[2],i));
        }
    }
    else{
        for(int i=0;i<up;++i){
            for(int j=i+1;j<up;++j){
                for(int k=j+1;k<up;++k){
                    for(int l=k+1;l<up;++l){
                        mx=max(mx,getArea(tb[i],tb[j],tb[k],tb[l]));
                    }
                }
            }
        }
    }
    cout<<fixed<<setprecision(10)<<mx/2<<endl;
}
