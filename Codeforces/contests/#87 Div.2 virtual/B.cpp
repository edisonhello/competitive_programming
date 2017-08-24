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

int n,m;
string mp[11];
vector<pii> G[11][11];
pii mat[11][11];
bool v[11][11];

bool dfs(pii now){
    PDE2(now,v[now.X][now.Y]);
    for(pii p:G[now.X][now.Y]){
        PDE3(p,v[p.X][p.Y],mat[p.X][p.Y]);
        if(v[p.X][p.Y])continue;
        v[p.X][p.Y]=1;
        if(mat[p.X][p.Y]==pii{-1,-1} || dfs(mat[p.X][p.Y])){
            mat[p.X][p.Y]=now;
            mat[now.X][now.Y]=p;
            return 1;
        }
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)mat[i][j]=pii{-1,-1};
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='P'){
                if(i<n-1 && mp[i+1][j]=='W'){
                    G[i][j].push_back({i+1,j});
                    G[i+1][j].push_back({i,j});
                }
                if(j<m-1 && mp[i][j+1]=='W'){
                    G[i][j].push_back({i,j+1});
                    G[i][j+1].push_back({i,j});
                }
            }
            if(mp[i][j]=='W'){
                if(i<n-1 && mp[i+1][j]=='P'){
                    G[i][j].push_back({i+1,j});
                    G[i+1][j].push_back({i,j});
                }
                if(j<m-1 && mp[i][j+1]=='P'){
                    G[i][j].push_back({i,j+1});
                    G[i][j+1].push_back({i,j});
                }
            }
        }
    }
    int meow=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            PDE3(i,j,mat[i][j]);FLH;
            if(mat[i][j]==pii{-1,-1}){
                MS(v,0);
                if(dfs({i,j}))++meow;
            }
        }
    }
    cout<<meow<<endl;
}
// 25887828 35:39 AC

// int dfs(int x,int y,int dep){
//     int rt=0;
//     for(int i=x;i<n;++i){
//         for(int j=(i==x?y:0);j<m;++j){
//             if(mp[i][j]=='P'){
//                 mp[i][j]='.';
//                 if(i>0 && mp[i-1][j]=='W'){
//                     mp[i-1][j]='.';
//                     rt=max(rt,dfs(i,j,dep+1));
//                     mp[i-1][j]='.'
//                 }
//                 if(j>0 && mp[i][j-1]=='W'){
//                     mp[i][j-1]='.';
//                     rt=max(rt,dfs(i,j,dep+1));
//                     mp[i][j-1]='.'
//                 }
//                 if(i<n-1 && mp[i+1][j]=='W'){
//                     mp[i+1][j]='.';
//                     rt=max(rt,dfs(i,j,dep+1));
//                     mp[i+1][j]='.'
//                 }
//                 if(j<m-1 && mp[i][j+1]=='W'){
//                     mp[i][j+1]='.';
//                     rt=max(rt,dfs(i,j,dep+1));
//                     mp[i][j+1]='.'
//                 }
//                 mp[i][j]='P';
//             }
//         }
//     }
//     return dep+rt;
// }
//
// int main(){
//     cin>>n>>m;
//     for(int i=0;i<n;++i)cin>>mp[i];
//     cout<<dfs(0,0,0)<<endl;
// }
