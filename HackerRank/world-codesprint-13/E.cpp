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
#define fread fread_unlocked
#define fwrite fwrite_unlocked
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
int djs[100005],sz[100005];
int cntbit[100005];

void padd(int x,int v){
    for(;x<100005;x+=x&-x)cntbit[x]+=v;
}
int query(int x,int v=0){
    for(;x;x-=x&-x)v+=cntbit[x];
    return v;
}

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}

long long preans[355];

int main(){
    int n,q; rit(n,q);
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=n;++i)sz[i]=1;
    padd(1,n);
    int c,a,b,grps=n;
    map<int,int> all_size;
    all_size[1]=n;
    preans[0]=1ll*n*(n-1)/2;
    auto del=[&](int x){
        PDE("del",x);
        auto it=all_size.find(x);
        if(it==all_size.end())while(1); // add this line to get AC, otherwise RE (?)
        --it->second;
        if(it->second==0)all_size.erase(it);
        padd(x,-1);
        --grps;
        for(int i=1;i<=350;++i){
            int r=x+i-1,l=x-i;
            r=min(r,100000); l=max(0,l);
            preans[i]-=grps-(query(r)-query(l));
            // PDE("preans",i,grps-(query(r)-query(l)));
        }
    };
    auto add=[&](int x){
        PDE("add",x);
        ++all_size[x];
        for(int i=1;i<=350;++i){
            int r=x+i-1,l=x-i;
            r=min(r,100000); l=max(0,l);
            preans[i]+=grps-(query(r)-query(l));
        }
        ++grps;
        padd(x,1);
    };
    do{
        rit(c);
        if(c==1){
            rit(a,b);
            // PDE(c,a,b);
            a=F(a); b=F(b);
            if(a==b)continue;
            del(sz[a]);
            // PDE(preans[2]);
            del(sz[b]);
            // PDE(preans[2]);
            djs[a]=b;
            sz[b]+=sz[a];
            add(sz[b]);
        }
        else{
            rit(a);
            PDE(c,a);
            if(!a)pit(1ll*grps*(grps-1)/2);
            else if(a<=350)pit(preans[a]);
            else{
                PDE(all_size);
                long long ans=0;
                auto R=all_size.lower_bound(a);
                auto L=all_size.begin();
                int precnt=0;
                while(R!=all_size.end()){
                    while(R->first-L->first>=a){
                        precnt+=L->second;
                        ++L;
                    }
                    ans+=1ll*precnt*R->second;
                    ++R;
                }
                PDE(ans);
                pit(ans);
            }
        }
    }while(--q);
}
