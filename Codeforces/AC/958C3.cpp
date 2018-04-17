#pragma GCC optimize("no-stack-protector")
// #pragma GCC diagnostic ignored "-W"

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

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

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
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

#define getchar gtx
// #define fread fread_unlocked
inline char gtx(){
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
inline void pit(int x,Args ...args){printf("%d ",x); pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x); pit(args...);}

int a[500005],pre[500005],dp[102][500005];
int bit[105],ibit[105];

void add(int *bit,int x,int v){
    ++x;
    for(;x<105;x+=lowbit(x))bit[x]=min(bit[x],v);
}
int query(int *bit,int x,int v=1<<30){
    ++x;
    for(;x;x-=lowbit(x))v=min(bit[x],v);
    return v;
}

int main(){
    int n,k,p; rit(n,k,p);
    for(int i=1;i<=n;++i)rit(a[i]),a[i]%=p;
    for(int i=1;i<=n;++i)pre[i]=(pre[i-1]+a[i]),(pre[i]>=p?pre[i]-=p:0);
    // for(int i=1;i<=n;++i)dp[0][i]=1<<30;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=k;++i){
        // build(root=nnode(),0,p-1);
        memset(bit,0x3f,sizeof(bit));
        memset(ibit,0x3f,sizeof(ibit));
        add(bit,0,dp[i-1][0]);
        add(ibit,p-0,dp[i-1][0]);
        // modify(root,0,p-1,0,dp[i-1][0]);
        for(int j=1;j<=n;++j){
            // dp[i][j]=pre[j]+query(root,0,p-1,0,pre[j]);
            dp[i][j]=pre[j]+query(bit,pre[j]);
            // if(pre[j]!=p-1)dp[i][j]=min(dp[i][j],pre[j]+query(root,0,p-1,pre[j]+1,p-1)+p);
            if(pre[j]!=p-1)dp[i][j]=min(dp[i][j],pre[j]+query(ibit,p-(pre[j]+1))+p);
            // modify(root,0,p-1,pre[j],-pre[j]+dp[i-1][j]);
            add(bit,pre[j],-pre[j]+dp[i-1][j]);
            add(ibit,p-pre[j],-pre[j]+dp[i-1][j]);
            PDE(i,j,dp[i][j]);
        }
    }
    printf("%d\n",dp[k][n]);
}
