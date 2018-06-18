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

const ld PI=acos(-1);
const ld eps=1e-13;
const ll mod=1e9+7;

#define cplx complex<ld>

cplx a[524288],b[524288],r[524288],o[524288];
int N=262144,base;

void fft(cplx *x){
    int size=0,mask=(N>>1)-1;
    for(int i=base-1;i>=0;--i,size=size*2+1,mask>>=1){
        for(int j=0;j<N;++j){
            int front=j>>i,back=j&mask;
            int a=(front&size)<<1,b=a+1;
            r[j]=x[(a<<i)|back]+x[(b<<i)|back]*o[front<<i];
        }
        for(int j=0;j<N;++j)x[j]=r[j];
    }
}
void ifft(cplx *x){
    fft(x); reverse(x+1,x+N);
    for(int i=0;i<N;++i)x[i]/=N;
}

int val[200005];

int main(){
    CPPinput;
    int n,x; cin>>n>>x;
    for(int i=1;i<=n;++i)cin>>val[i];
    for(int i=1;i<=n;++i){
        if(val[i]<x)val[i]=1;
        else val[i]=0;
        PDE(i,val[i]);
    }
    vector<int> nval;
    nval.pb(1);
    for(int i=1;i<=n;++i){
        if(val[i])nval.pb(1);
        else ++nval.back();
    }
    PDE(nval);
    long long ans0=0;
    for(int i:nval)ans0+=1ll*i*(i-1)/2;
    N=nval.size()-1;
    for(int i=0;i<=N;++i)a[i]=cplx(nval[i],0);
    for(int i=N,j=0;i>=0;--i,++j)b[i]=cplx(nval[j],0);
    ++N; N<<=1;
    while(N!=lowbit(N))N+=lowbit(N);
    while((1<<base)<N)++base;
    for(int i=0;i<N;++i)o[i]=exp(2*i*PI/N*cplx(0,1));
    // for(int i=0;i<=N;++i)cout<<(ll)a[i].real()<<" "; cout<<endl;
    // for(int i=0;i<=N;++i)cout<<(ll)b[i].real()<<" "; cout<<endl;
    PDE(N,base);
    fft(a); fft(b);
    for(int i=0;i<N;++i)a[i]*=b[i];
    ifft(a);
    PDE("ffted");
    // for(int i=0;i<=N;++i)cout<<(ll)(a[i].real()+0.5)<<" "; cout<<endl;
    cout<<ans0<<" ";
    int cnt=1;
    for(int i=nval.size()-2;i>=0;--i){
        cout<<(long long)(a[i].real()+0.5)<<" ";
        ++cnt;
    }
    while(cnt<=n)++cnt,cout<<0<<" ";
    cout<<endl;
}
