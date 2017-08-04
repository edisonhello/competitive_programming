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
const ll mod=123456789;
const ll p=47017;
ll nor(ll x){return (x%mod+mod)%mod;}

unsigned ll __buffer__[7122],hsh[2][5555],pp[5555];
int cnt[5555];
string s;

int meow=0;
bool isp(int l,int r,int k){
    PDE3(l,r,k);
    // if(++meow>30)exit(0);
    if(k==1 && r<=l+1){
        PDE1(s[l]==s[r]);
        return s[l]==s[r];
    }
    PDE4(hsh[0][r]-hsh[0][l-1],pp[s.length()-l],hsh[1][l]-hsh[1][r+1],pp[r+1]);
    PDE4((hsh[0][r]-hsh[0][l-1])*pp[s.length()-l],(hsh[0][r]-hsh[0][l-1])*pp[s.length()-l],(hsh[1][l]-hsh[1][r+1])*pp[r+1],(hsh[1][l]-hsh[1][r+1])*pp[r+1]);
    if((hsh[0][r]-hsh[0][l-1])*pp[s.length()-l] != (hsh[1][l]-hsh[1][r+1])*pp[r+1])return 0;
    if(k==1)return 1;
    if(!isp(l,(l+r-1)>>1,k-1))return 0;
    if(!isp(((l+r)>>1)+1,r,k-1))return 0;
    PDE4(l,r,k,"ok");
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s; 
    clock_t t=clock();
    pp[0]=1; for(int i=0;i<5554;++i)pp[i+1]=pp[i]*p;
    for(int i=0;i<s.length();++i)hsh[0][i]=hsh[0][i-1]+s[i]*pp[i];
    for(int i=s.length()-1;i>=0;--i)hsh[1][i]=hsh[1][i+1]+s[i]*pp[s.length()-1-i];
    
    if(DEBUG){
        cout<<"pp : "; for(int i=0;i<=s.length();++i)cout<<setw(12)<<pp[i]; cout<<endl;
        cout<<"hsh: "; for(int i=0;i<=s.length();++i)cout<<setw(12)<<hsh[0][i]; cout<<endl;
        cout<<"hs1: "; for(int i=0;i<=s.length();++i)cout<<setw(12)<<hsh[1][i]; cout<<endl;
    }
    int len=s.length();
    for(int i=0,j,k;i<len;++i){
        for(j=i;j<len;++j){
            k=20; while((1<<k)>j-i+1)--k;
            while(1){
                if(isp(i,j,k+1)){
                    ++cnt[k+1];
                    break;
                }
                --k; if(k<=0)break;
            }
        }
    }
    for(int i=55;i>=1;--i)cnt[i]+=cnt[i+1];
    for(int i=1;i<=s.length();++i)cout<<cnt[i]<<" ";cout<<endl;
    cout<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl;
}
