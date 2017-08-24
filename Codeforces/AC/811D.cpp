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
#define CIO ios_base::sync_with_stdio(0),cin.tie(0);
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

int n,m,cx,cy,ex,ey;
char L,R,U,D;
string mp[111];
int cf[111][111];

void go(char dir){
    cout<<dir<<endl;
    cin>>cx>>cy;
    if(mp[cx][cy]=='F')exit(0);
}
bool u[111][111];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>mp[i],mp[i]="$"+mp[i];
    cx=1,cy=1; if(mp[cx][cy]=='F')exit(0);
    L='L',R='R',U='U',D='D';
    if(mp[1][2]=='.'){
        go(R); if(cy==1)swap(L,R);
        else go(L);
        while(mp[2][cy]=='*')go(R);
        go(D); if(cx==1)swap(U,D);
    }
    else{
        go(D); if(cx==1)swap(U,D);
        else go(U);
        while(mp[cx][2]=='*')go(D);
        go(R); if(cy==1)swap(L,R);
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(mp[i][j]=='F')ex=i, ey=j;
    PDE4(L,R,U,D);
    PDE4(cx,cy,ex,ey);
    queue<pair<int,int>> q; q.push(pair<int,int>(cx,cy)); u[cx][cy]=1;
    while(q.size()){
        int x=q.front().first, y=q.front().second; if(x==ex && y==ey)break;
        // PDE2(x,y);
        if(y<m && mp[x][y+1]!='*' && !u[x][y+1])cf[x][y+1]=1,q.push(pair<int,int>(x,y+1)),u[x][y+1]=1;
        if(y>1 && mp[x][y-1]!='*' && !u[x][y-1])cf[x][y-1]=2,q.push(pair<int,int>(x,y-1)),u[x][y-1]=1;
        if(x<n && mp[x+1][y]!='*' && !u[x+1][y])cf[x+1][y]=3,q.push(pair<int,int>(x+1,y)),u[x+1][y]=1;
        if(x>1 && mp[x-1][y]!='*' && !u[x-1][y])cf[x-1][y]=4,q.push(pair<int,int>(x-1,y)),u[x-1][y]=1;
        q.pop();
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j) cout<<cf[i][j];
    //     cout<<endl;
    // }
    stack<char> ans;
    while(ex!=cx || ey!=cy){
        PDE2(ex,ey);
        if(cf[ex][ey]==1)ans.push(R),--ey;
        else if(cf[ex][ey]==2)ans.push(L),++ey;
        else if(cf[ex][ey]==3)ans.push(D),--ex;
        else if(cf[ex][ey]==4)ans.push(U),++ex;
        else assert(1==0);
    }
    while(ans.size()){
        go(ans.top());
        ans.pop();
    }
}
