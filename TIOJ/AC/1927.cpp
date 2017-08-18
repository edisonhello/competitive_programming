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
#define reset(x,n) (x).clear(),(x).resize(n)
#define pb(x) push_back(x)
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

struct stu{ll x;int y,r,i;
stu(ll x=0,int y=0,int r=1,int i=0):x(x),y(y),r(r),i(i){}} sa[100005];
int a[100005];
int at[100005],lcpl,st[20][100005];

ll meow(ll b,int p=500000003,ll a=1){
    while(p){
        if(p&1)a=a*b%mod;
        b=b*b%mod; p>>=1;
    } return a;
}

int main(){
    int n=0,q=0; scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)scanf("%d",&a[i]),a[i]=sa[i].x=meow(a[i]),sa[i].i=i;
    if(DEBUG){printf("sa[i].x: ");for(int i=0;i<n;++i)printf("%d ",sa[i].x);puts("");}
    sort(sa,sa+n,[](const stu &a,const stu &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    sa[0].r=1; for(int i=1;i<n;++i)sa[i].r=(sa[i-1].x==sa[i].x&&sa[i-1].y==sa[i].y?sa[i-1].r:sa[i-1].r+1);
    for(int i=0;i<n;++i)sa[i].x=sa[i].r,at[sa[i].i]=i;
    for(int D=1;D<n;D<<=1){
        // sort(sa,sa+n,[](const stu &a,const stu &b){return a.i<b.i;});
        // for(int i=0;i<n;++i)sa[i].y=(i+D<n?sa[i+D].x:0);
        if(DEBUG){printf("sa[i]: ");for(int i=0;i<n;++i)printf("[%d,%d] ",sa[i].x,sa[i].y);puts("");}
        for(int i=0;i<n;++i)sa[i].y=(sa[i].i+D>=n?0:sa[at[sa[i].i+D]].x);
        sort(sa,sa+n,[](const stu &a,const stu &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
        if(DEBUG){printf("sa[i]: ");for(int i=0;i<n;++i)printf("[%d,%d] ",sa[i].x,sa[i].y);puts("");}
        sa[0].r=1; for(int i=1;i<n;++i)sa[i].r=(sa[i-1].x==sa[i].x&&sa[i-1].y==sa[i].y?sa[i-1].r:sa[i-1].r+1);
        for(int i=0;i<n;++i)at[sa[i].i]=i,sa[i].x=sa[i].r;
        if(sa[n-1].r==n)break;
    }
    if(DEBUG){printf("sa[i].i: ");for(int i=0;i<n;++i)printf("%d ",sa[i].i);puts("");}
    for(int i=0;i<n;++i){
        --lcpl; lcpl=lcpl<0?0:lcpl;
        if(at[i]>=n-1)continue;
        lcpl=min(lcpl,min(n-i,n-sa[at[i]+1].i));
        while(lcpl>=n-i || lcpl>=n-sa[at[i]+1].i || a[lcpl+i]!=a[lcpl+sa[at[i]+1].i] && lcpl>0)--lcpl;
        while(lcpl+i<n && lcpl+sa[at[i]+1].i<n && a[lcpl+i]==a[lcpl+sa[at[i]+1].i])++lcpl;
        st[0][at[i]]=lcpl;
        PDE4(i,at[i],sa[at[i]+1].i,lcpl);
    }
    if(DEBUG){printf("st[0][i]: ");for(int i=0;i<n;++i)printf("%d ",st[0][i]);puts("");}
    for(int d=1,j=1;d<n;d<<=1,++j)for(int i=0;i<n-d;++i)st[j][i]=min(st[j-1][i],st[j-1][i+d]);
    if(DEBUG){
        printf("sparse table\n");
        for(int d=1,j=0;d<(n<<1);d<<=1,++j){
            for(int i=0;i<n-(d>>1);++i){
                printf("%d ",st[j][i]);
            } puts("");
        }
    }
    while(q--){
        int s=0,t=0,d,j=-1; rit(s,t); if(at[s]>at[t])swap(s,t); d=at[t]-at[s]; while(d)d>>=1,++j;
        if(s==t)printf("%d\n",n-s);
        else printf("%d\n",min(st[j][at[s]],st[j][at[t]-(1<<j)]));
        PDE4(s,t,at[s],at[t]);
        PDE2(at[t]-at[s],j);
        PDE2(st[j][at[s]],st[j][at[t]-(1<<j)]);
    }
}
