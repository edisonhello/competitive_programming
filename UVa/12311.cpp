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

struct point{
    int x,y,i;
    point():x(0),y(0),i(0){};
    point(int xx,int yy):x(xx),y(yy),i(0){};
    point(int xx,int yy,int ii):x(xx),y(yy),i(ii){};
} vt[33333];
point operator-(const point &a,const point &b){return point(b.x-a.x,b.y-a.y,7122);}
int operator^(const point &a,const point &b){return a.x*b.y-a.y*b.x;}
ll operator*(const point &a,const point &b){return (ll)(b-a).x*(b-a).x+(ll)(b-a).y*(b-a).y;}
int tb[33333],tbz,far[33333],ans[33333];
int main(){
    int n;while(cin>>n,n){
        tbz=0; MS(far,-1);
        for(int i=0;i<33333;++i){
            vt[i]=point(0,0,0);
            tb[i]=far[i]=ans[i]=0;
        }
        for(int i=0;i<n;++i)cin>>vt[i].x>>vt[i].y,vt[i].i=i+1;
        sort(vt,vt+n,[](const point &a,const point &b){return a.x==b.x?a.y>b.y:a.x<b.x;});
        for(int i=0;i<n;++i){
            while(tbz>1 && ((vt[i]-vt[tb[tbz-1]])^(vt[tb[tbz-2]]-vt[tb[tbz-1]]))>0)--tbz;
            tb[tbz++]=i;
        }
        int rside=tbz-1;
        for(int i=n-2;i>=0;--i){
            while(tbz>rside+1 && ((vt[i]-vt[tb[tbz-1]])^(vt[tb[tbz-2]]-vt[tb[tbz-1]]))>0)--tbz;
            tb[tbz++]=i;
        }
        assert((--tbz)==n);
        int lptr=0,rptr=rside;
        // cout<<"tu bao: ";
        // for(int i=0;i<n;++i)cout<<vt[tb[i]].x<<","<<vt[tb[i]].y<<endl;
        // cout<<"ready go rotate"<<endl;
        while(lptr<n){
            // PDE2(lptr,rptr);
            if(far[lptr]==-1)far[lptr]=rptr;
            else{
                ll od=vt[tb[far[lptr]]]*vt[tb[lptr]],
                   nd=vt[tb[rptr]]*vt[tb[lptr]];
                // PDE2(od,nd);
                if(nd>od){
                    // cout<<"shorter!"<<endl;
                    far[lptr]=rptr;
                }
                else if(nd==od){
                    // cout<<"same distance, check number"<<endl;
                    if(vt[tb[far[lptr]]].i>vt[tb[rptr]].i)far[lptr]=rptr;
                }
            }
            // cout<<"now lptr:"<<lptr<<", match rptr is "<<far[lptr]<<endl;

            if(((vt[tb[(lptr+1)%n]]-vt[tb[lptr]])^(vt[tb[rptr]]-vt[tb[(rptr+1)%n]]))>0){
                rptr=(rptr+1)%n;
            }
            else ++lptr;
        }
        for(int i=0;i<n;++i){
            // cout<<"tu bou number "<<i<<" = original number "<<vt[tb[i]].i<<endl;
        }
        for(int i=0;i<n;++i){
            // cout<<"   lptr: "<<i<<" , rptr: "<<far[i]<<endl;
            // cout<<"-> lnum: "<<vt[tb[i]].i<<" , rnum: "<<vt[tb[far[i]]].i<<endl;
            ans[vt[tb[i]].i]=vt[tb[far[i]]].i;
        }
        for(int i=1;i<=n;++i){
            cout<<ans[i]<<endl;
        }
    }
}
