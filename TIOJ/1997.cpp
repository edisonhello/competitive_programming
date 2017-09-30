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

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int spnt[10],recl[1000006],recr[1000006],rec[1000006];
ll a[1000006],pre[1000006],suf[1000006],tmp[1000006];
int main(){
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    if(k==1)return 0;
    if(k==2){
        pre[0]=a[0]; for(int i=1;i<n;++i)pre[i]=pre[i-1]+a[i];
        suf[n-1]=a[n-1]; for(int i=n-2;i>=0;--i)suf[i]=suf[i+1]+a[i];
        ll nowmax=pre[0]-suf[1]; spnt[0]=1;
        for(int i=2;i<n;++i){
            if(pre[i-1]-suf[i]>nowmax){
                nowmax=pre[i-1]-suf[i];
                spnt[0]=i;
            }
        }
    }
    if(k==3){
        ll nse=0,mn=a[1]; int l=1,r=2,nl=1; for(int i=2;i<n;++i){
            nse+=a[i-1];
            if(nse<mn){
                mn=nse;
                l=nl, r=i;
            }
            else if(nse>0){
                nse=0; nl=i;
            }
        } spnt[0]=l, spnt[1]=r;
    }
    if(k==4){
        suf[n-1]=a[n-1]; for(int i=n-2;i>=0;--i)suf[i]=suf[i+1]+a[i];
        ll nse=0,mn=a[1]; int l=1,r=2,nl=1; for(int i=2;i<n-1;++i){
            nse+=a[i-1];
            if(nse<mn){
                mn=nse;
                l=nl, r=i;
            }
            pre[i]=mn;
            recl[i]=l;
            recr[i]=r;
            if(nse>0){
                nse=0; nl=i;
            }
        } mn=1000000000000000000ll; for(int i=2;i<n-1;++i){
            if(pre[i]+suf[i+1]<mn){
                mn=pre[i]+suf[i+1];
                spnt[0]=recl[i];
                spnt[1]=recr[i];
                spnt[2]=i+1;
            }
        }
    }
    if(k==5){
        pre[0]=a[0]; for(int i=1;i<n;++i)pre[i]=pre[i-1]+a[i];
        suf[n-1]=a[n-1]; for(int i=n-2;i>=0;--i)suf[i]=suf[i+1]+a[i];
        {   ll nowmin=suf[]; int npnt=1;
        for(int i=2;i<n-3;++i){
            if(suf[i]<nowmin){
                nowmin=suf[i];
                npnt=i;
            }
            rec[i]=npnt;
            tmp[i]=nowmin;
        }}
        {   ll nse=0,mn=a[1]; int l=1,r=2,nl=1; for(int i=2;i<n-3;++i){
            nse+=a[i-1];
            if(nse<mn){
                mn=nse;
                l=nl, r=i;
            }
            pre[i]=mn;
            recl[i]=l;
            recr[i]=r;
            if(nse>0){
                nse=0; nl=i;
            }
        }} ll mn=1000000000000000000ll;
        for(int i=2;i<n-3;++i){
            if(tmp[i]+pre[i]<mn){
                mn=tmp[i]+pre[i];
                spnt[0]=rec[i];
            }
        }
    }
    if(k==6){
        
    }
    for(int i=0;i<k-1;++i)cout<<spnt[i]<<endl;
}
