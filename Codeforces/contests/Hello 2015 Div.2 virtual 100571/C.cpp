// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>

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

// void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

ll pw(ll b,ll n,ll m=mod,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int a[20004];
int inv[66];
int primecount[66][10];
int primeptr[66];
map<int,int> rprime[20004];
double reclog[66];
double mnlog[20004];
ll mnval[20004];

int main(){
    srand(clock());
    int n,m; rit(n,m);
    // int n=20000,m=1000000;
    for(int i=1;i<=n;++i)rit(a[i]);
    // for(int i=1;i<=n;++i)a[i]=rand()%60+1;
    for(int i=1;i<=n;++i)mnlog[i]=1e9;
    for(int i=1;i<=60;++i){
        inv[i]=pw(i,mod-2);
        reclog[i]=log(i);
    }
    for(int i=2;i<=60;++i){
        int x=i;
        for(int j=2;j*j<=x;++j){
            while(x%j==0){
                ++rprime[i][j];
                x/=j;
            }
        }
        if(x!=1)++rprime[i][x];
    }
    mnval[1]=61;
    for(int i=1;i<=n;++i)mnval[1]=min(mnval[1],(ll)a[i]);
    for(int i=1;i<=n;++i)mnlog[1]=min(mnlog[1],reclog[a[i]]);
    for(int len=2;len<=n;++len){
        if(len<=max(80,n/13));
        else if(len>=n-max(80,n/13));
        else continue;
        double nlog=0;
        ll nval=1;
        int i,j;
        auto add=[&](int x)->void{
            for(auto &p:rprime[x]){
                ++primecount[p.first][p.second];
                while(primeptr[p.first]<p.second){
                    ++primeptr[p.first];
                    nlog+=reclog[p.first];
                    nval=(nval*p.first)%mod;
                }
            }
        };
        auto sub=[&](int x)->void{
            for(auto &p:rprime[x]){
                --primecount[p.first][p.second];
                while(primeptr[p.first]>0 && primecount[p.first][primeptr[p.first]]==0){
                    --primeptr[p.first];
                    nlog-=reclog[p.first];
                    nval=(nval*inv[p.first])%mod;
                }
            }
        };
        for(i=1;i<len;++i)add(a[i]);
        for(j=1;i<=n;++i,++j){
            add(a[i]);
            PDE(i,nlog,nval);
            if(nlog<mnlog[len]){
                mnlog[len]=nlog;
                mnval[len]=nval;
            }
            sub(a[j]);
            PDE(i,nlog,nval);
        }
        for(;j<=n;++j)sub(a[j]);
    }
    vector<int> rpoints;
    for(int i=1;i<=max(80,n/13);++i)rpoints.pb(i);
    for(int i=1;i<=8000;++i)rpoints.pb(rand()%n+1);
    for(int st:rpoints){
        double nlog=0;
        ll nval=1;
        auto add=[&](int x)->void{
            for(auto &p:rprime[x]){
                ++primecount[p.first][p.second];
                while(primeptr[p.first]<p.second){
                    ++primeptr[p.first];
                    nlog+=reclog[p.first];
                    nval=(nval*p.first)%mod;
                }
            }
        };
        memset(primeptr,0,sizeof(primeptr));
        memset(primecount,0,sizeof(primecount));
        for(int i=st;i<=n;++i){
            add(a[i]);
            if(nlog<mnlog[i-st+1]){
                mnlog[i-st+1]=nlog;
                mnval[i-st+1]=nval;
            }
        }
    }
    for(int i=2;i<=n;++i){
        if(mnlog[i]<mnlog[i-1]){
            mnlog[i]=mnlog[i-1];
            mnval[i]=mnval[i-1];
        }
    }
    int t;
    while(m--){
        rit(t);
        // t=rand()%n+1;
        pit(mnval[t]);
    }
}
