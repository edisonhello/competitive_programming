// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

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
        char *s=ptr,c; T t;
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

struct info{
    int a,b,i;
    bool operator<(const info &r)const{ return tie(a,b)<tie(r.a,r.b); }
};

int n;
pair<int,int> ex[1000006];
bitset<2000006> avail;
bitset<1000006> took;
vector<int> occu[2000006];

bool ok(int mx){
    for(int i=1;i<=mx;++i)occu[i].clear();
    avail.reset(); took.reset();
    set<info> st;
    for(int i=1;i<=mx;++i)avail[i].set();
    bool ternimate=0;

    for(int i=1;i<=n;++i){
        if(ex[i].first>mx && ex[i].second>mx)return 0;
        else if(ex[i].second>mx || !avail[ex[i].second]){
            if(avail[ex[i].first])taketime(ex[i].first);
            else return 0;
        }
        else if(!avail[ex[i].first]){
            if(avail[ex[i].second])taketime(ex[i].second);
            else return 0;
        }
        else{
            auto it=st.find(info{ex[i].first,ex[i].second,-1});
            if(it!=st.end()){
                auto r=*it; st.erase(it);
                taketime(r.a);
                taketime(r.b);
            }
            else{
                st.insert(info{ex[i].first,ex[i].second,i});
                occu[ex[i].first].pb(i);
                occu[ex[i].second].pb(i);
            }
        }
        if(ternimate)return 0;
    }
    return 1;
}

int main(){
    rit(n);
    vector<int> num;
    for(int i=1;i<=n;++i)rit(ex[i].first,ex[i].second);
    for(int i=1;i<=n;++i)num.pb(ex[i].first),num.pb(ex[i].second);
    sort(num.begin(),num.end());
    num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=1;i<=n;++i)ex[i].first=upper_bound(num.begin(),num.end(),ex[i].first),ex[i].second=upper_bound(num.begin(),num.end(),ex[i].second);
    int L=n,R=num.size()+1;
    while(R>L){
        int M=(L+R)>>1;
        if(ok(M))R=M;
        else L=M+1;
    }
    if(L==num.size()+1)L=-1;
    else L=num[L-1];
    cout<<L<<endl;
}
