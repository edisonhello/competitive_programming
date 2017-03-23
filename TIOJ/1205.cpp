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
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define Ugbemugbem Osas

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

inline int lowbit(int &x){return x&-x;}
inline ll lowbit(ll &x){return x&-x;}

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

struct pnt{
    int x,y;
    pnt(){x=y=0;}
    pnt(int x){this->x=this->y=x;}
    pnt(int x,int y){this->x=x;this->y=y;}
    pnt& operator=(const pnt &a){this->x=a.x;this->y=a.y;return *this;}
    friend std::istream& operator>>(std::istream &istm,pnt &a){istm>>a.x>>a.y;return istm;}
    friend std::ostream& operator<<(std::ostream &ostm,pnt &a){ostm<<"("<<a.x<<","<<a.y<<")";return ostm;}
    operator bool()const{return this->x||this->y;}
    operator long double()const{return sqrt((long double)this->x*(long double)this->x+(long double)this->y*(long double)this->y);}
    long double abs(){return (long double)(*this);}
    pnt operator+(const pnt &a)const{pnt t=*this;t.x+=a.x;t.y+=a.y;return t;}
    pnt operator-(const pnt &a)const{pnt t=*this;t.x-=a.x;t.y-=a.y;return t;}
    pnt operator*(const int &a)const{pnt t=*this;t.x*=a;t.y*=a;return t;}
    pnt operator/(const int &a)const{pnt t=*this;t.x/=a;t.y/=a;return t;}
    pnt& operator+=(const pnt &a){this->x+=a.x;this->y+=a.y;return *this;}
    pnt& operator-=(const pnt &a){this->x-=a.x;this->y-=a.y;return *this;}
    pnt& operator*=(const int &a){this->x*=a;this->y*=a;return *this;}
    pnt& operator/=(const int &a){this->x/=a;this->y/=a;return *this;}
    bool operator<(const pnt &a)const{return this->x==a.x?this->y<a.y:this->x<a.x;}
    // bool operator>(const pnt &a)const{pnt l=*this,r=a;return l.abs()>r.abs();}
    bool operator==(const pnt &a)const{return this->x==a.x && this->y==a.y;}
    pnt turn(int deg){
        if(deg==0)return *this;
        if(deg==90)return pnt(-this->y,this->x);
        if(deg==180)return pnt(-this->x,-this->y);
        if(deg==270)return pnt(this->y,-this->x);
    }
} p[1555];
set<pnt> s;

int main(){
    int n;while(cin>>n,n){
        s.clear();
        for(int i=0;i<n;++i){
            cin>>p[i]; p[i]*=2;
            s.insert(p[i]);
        }
        for(auto i:s)cout<<i<<" ";cout<<endl;
        // PDE1(s);
        ll ans=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                pnt pp1=p[i]+(p[j]-p[i]).turn(90),
                    pp2=p[i]+(p[j]-p[i]).turn(270),
                    pp3=p[j]+(p[i]-p[j]).turn(90),
                    pp4=p[j]+(p[i]-p[j]).turn(270);
                PDE4(pp1,pp2,pp3,pp4);
                if(s.count(pp1))++ans;
                if(s.count(pp2))++ans;
                if(s.count(pp3))++ans;
                if(s.count(pp4))++ans;
            }
        }
        cout<<ans<<endl;
    }
}