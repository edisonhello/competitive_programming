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
#define rz(x) resize(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define ln puts("");
#define mid ((l+r)>>1)
#define xm ((x1+x2)/2)
#define ym ((y1+y2)/2)
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define FASTCPP ios_base::sync_with_stdio(0); cin.tie(0)

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<'\n'
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<'\n'
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<" , "<<#d<<" = "<<(d)<<'\n'
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define LOG(...) ;
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto it:mp)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto it:s)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

inline int lowbit(int &x){return x&-x;}
inline ll lowbit(ll &x){return x&-x;}
template<typename T>
inline T mp(T b,int n){
    T a=1; while(n){
        if(n&1)a*=b; b*=b,n>>=1;
    } return a;
}
template<typename T>
inline T mp(T b,int n,T mod){
    T a=1%mod; while(n){
        if(n&1)a=a*b%mod; b=b*b%mod,n>>=1;
    } return a;
}

#define getchar gtx
inline int gtx(){
    const int N=1048576;
    static char buffer[N],*p,*end; p=end=buffer;
    if(p==end) {
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    }
    return *p++;
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

inline void pit(int &x){printf("%d",x);}
inline void pll(ll &x){printf("%lld",x);}
template<typename ...Args>
inline void pit(int &x,Args& ...args){printf("%d ",x);pit(args...);}
template<typename ...Args>
inline void pll(ll &x,Args& ...args){printf("%lld ",x);pit(args...);}s

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int main(){

}
