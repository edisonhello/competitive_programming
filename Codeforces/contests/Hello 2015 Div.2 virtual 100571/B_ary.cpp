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

struct mat{
    ll a[2][2];
    mat(){
        memset(this,0,sizeof(mat));
    }
};

mat operator*(const mat &a,const mat &b){
    mat o;
    for(int i=0;i<2;++i)for(int j=0;j<2;++j)for(int k=0;k<2;++k)
        (o[i][j]+=a[i][k]*b[k][j])%=mod;
    return o;
}
mat operator+(const mat &a,const mat &b){
    mat o;
    for(int i=0;i<2;++i)for(int j=0;j<2;++j){
        o[i][j]=a[i][j]+b[i][j];
        if(o[i][j]>=mod)o[i][j]-=mod;
    }
    return o;
}
void operator+=(mat &a,const mat &b){
    for(int i=0;i<2;++i)for(int j=0;j<2;++j){
        a[i][j]+=b[i][j];
        if(a[i][j]>=mod)a[i][j]-=mod;
    }
}
mat operator-(const mat &a,const mat &b){
    mat o;
    for(int i=0;i<2;++i)for(int j=0;j<2;++j){
        o[i][j]=a[i][j]-b[i][j];
        if(o[i][j]<0)o[i][j]+=mod;
    }
    return o;
}
void operator-=(mat &a,const mat &b){
    for(int i=0;i<2;++i)for(int j=0;j<2;++j){
        a[i][j]-=b[i][j];
        if(a[i][j]<0)a[i][j]+=mod;
    }
}

mat pw(mat b,int n){
    mat a; a[0][0]=a[1][1]=1;
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    }
    return a;
}

ll offset[100005];
mat dta[100005];
int cnt[100005];


int main(){
    CPPinput;
    int n,q; cin>>n>>q;
    ll f0,f1,a,b; cin>>f0>>f1>>a>>b;
    for(int i=1;i<=n;++i)cin>>offset[i];
    for(int i=1;i<=n+1;++i)open(dta[i]);
    mat tr;
    tr[0][0]=b; tr[0][1]=1; tr[1][0]=a;
    mat I;
    I[0][0]=I[1][1]=1;
    while(q--){
        int l,r; cin>>l>>r;
        int len=r-l+1;
        ++cnt[l]; dta[l]+=I;
        --cnt[r+1]; dta[r+1]-=pw(tr,len);
    }
    // cout<<"nya"<<endl;
    mat now;
    for(int i=1;i<=n;++i){
        now=now*tr;
        now+=dta[i];
        cout<<(f1*now[0][1]+f0*now[1][1]+offset[i])%mod<<" ";
    }
    cout<<endl;
}
