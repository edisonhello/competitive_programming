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

#include<complex>

struct cplx{
    double r,i;
    cplx(double r=0,double i=0):r(r),i(i){}
    void exp(double ang){ r=cos(ang); i=sin(ang); }
};
cplx operator+(const cplx &a,const cplx &b){ return cplx(a.r+b.r,a.i+b.i); }
cplx operator-(const cplx &a,const cplx &b){ return cplx(a.r-b.r,a.i-b.i); }
cplx operator*(const cplx &a,const cplx &b){ return cplx(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r); }
cplx& operator*=(cplx &a,const double x){ a.r*=x; a.i*=x; return a; }
cplx& operator*=(cplx &a,const cplx &b){ double tmp=a.r*b.r-a.i*b.i; a.i=a.r*b.i+a.i*b.r; a.r=tmp; return a; }
cplx operator/(const cplx &a,const double x){ return cplx(a.r/x,a.i/x); }
cplx& operator/=(cplx &a,const double x){ a.r/=x; a.i/=x; return a; }


cplx a[262144],b[262144],res[262144],omg[262144];
int N=262144,base;

void init(){
    while(N!=lowbit(N))N+=lowbit(N);
    while((1<<base)<N)++base;
    for(int i=0;i<N;++i)omg[i].exp(i*2*PI/N);
}
void FFT(cplx *x){
    int size=0,mask=(N>>1)-1;
    for(int i=base-1;i>=0;--i,size=(size<<1)|1,mask>>=1){
        for(int j=0;j<N;++j){
            int front=j>>i,back=j&mask;
            int a=(front&size)<<1,b=a|1;
            res[j]=x[(a<<i)|back]+omg[front<<i]*x[(b<<i)|back];
        }
        for(int j=0;j<N;++j)x[j]=res[j];
    }
}
void IFFT(cplx *a){
    FFT(a);
    reverse(a+1,a+N);
    for(int i=0;i<N;++i)a[i]/=N;
}

void calc(){
    FFT(a), FFT(b);
    for(int i=0;i<N;++i)a[i]*=b[i];
    IFFT(a);
}

int ans[524288];

int main(){
    CPPinput;
    int n,m; string s,t; cin>>n>>m>>s>>t;
    N=n+m;
    init();
    reverse(t.begin(),t.end());
    for(int i=0;i<n;++i)a[i]=cplx(s[i]=='R'?1:0,0);
    for(int i=0;i<m;++i)b[i]=cplx(t[i]=='P'?1:0,0);
    calc();
    for(int i=0;i<n;++i)ans[i]+=int(a[i+m-1].r+0.5);
    // cout<<"ans: "; for(int i=0;i<n;++i)cout<<ans[i]<<" "; cout<<endl;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;++i)a[i]=cplx(s[i]=='P'?1:0,0);
    for(int i=0;i<m;++i)b[i]=cplx(t[i]=='S'?1:0,0);
    calc();
    for(int i=0;i<n;++i)ans[i]+=int(a[i+m-1].r+0.5);
    // cout<<"ans: "; for(int i=0;i<n;++i)cout<<ans[i]<<" "; cout<<endl;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;++i)a[i]=cplx(s[i]=='S'?1:0,0);
    for(int i=0;i<m;++i)b[i]=cplx(t[i]=='R'?1:0,0);
    calc();
    for(int i=0;i<n;++i)ans[i]+=int(a[i+m-1].r+0.5);
    // cout<<"ans: "; for(int i=0;i<n;++i)cout<<ans[i]<<" "; cout<<endl;
    int mx=0;
    for(int i=0;i<n;++i)mx=max(mx,ans[i]);
    cout<<mx<<endl;
}
