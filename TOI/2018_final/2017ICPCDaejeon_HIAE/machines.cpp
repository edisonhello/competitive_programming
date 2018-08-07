#pragma GCC optimize("no-stack-protector")
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

#define ll int
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
// const ll mod=1000000123;

int n;
unsigned ll val[1000006],hh[1000006],pp[1000006],ipp[1000006];

unsigned ll pw(unsigned ll b,unsigned ll n,unsigned ll a=1){
    while(n){
        if(n&1)a*=b;
        b*=b; n>>=1;
    } return a;
}

inline unsigned ll gethash(int l,int r){
    return (hh[r]-hh[l-1])*pp[n-r];
}

struct ANS{
    int mn,p,k;
    bool operator<(const ANS &b)const{
        return mn==b.mn?p<b.p:mn<b.mn;
    }
};

int main(){
    CPPinput;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>val[i];
    pp[0]=1;
    for(int i=1;i<=n;++i)pp[i]=pp[i-1]*17;
    // ipp[n]=pw(pp[n],mod-2,mod);
    // for(int i=n;i>=1;--i)ipp[i-1]=1ll*ipp[i]*i%mod;
    for(int i=1;i<=n;++i)hh[i]=hh[i-1]+val[i]*pp[i-1];
    // for(int i=1;i<=n;++i)cout<<"hh["<<i<<"]="<<hh[i]<<endl;
    ANS ans{n,0,n};
    // for(int i=1;i<=n;++i)cout<<"i: "<<i<<" , "<<gethash(i,i)<<endl;
    // for(int i=1;i<=n;++i)cout<<"ipp: "<<i<<" , "<<ipp[i]<<endl;
    // cout<<gethash(2,3)<<endl;
    // cout<<gethash(3,4)<<" , "<<gethash(5,6)<<endl;
    for(int p=n-1;p>=1;--p){
        // cout<<"working with p: "<<p<<endl;
        // cout<<"curr ans: "<<mn<<" "<<ap<<" "<<ak<<endl;
        int i,j;
        for(i=n-p-p+1,j=n-p;i>0;--i){
            if(gethash(i,j)==gethash(i+p,j+p))continue;
            else break;
        }
        if(gethash(j,j)!=gethash(j+p,j+p)){ /* cout<<"update with "<<p+j<<" "<<p<<" "<<j<<endl; */ ans=min(ANS{p+j,p,j},ans); continue; }
        int L=max(1,i+1),R=j,M;
        // cout<<"p: "<<p<<" ["<<L<<" , "<<R<<"]"<<endl;
        while(R>L){
            M=(L+R)>>1;
            if(gethash(M,j)==gethash(M+p,j+p))R=M;
            else L=M+1;
        }
        // cout<<"last L: "<<L<<endl;
        ans=min(ANS{p+L-1,p,L-1},ans);
        // cout<<"ans tuple: "<<mn<<" "<<ak<<" "<<ap<<endl;
    }
    // cout<<"mn: "<<mn<<endl;
    cout<<ans.k<<" "<<ans.p<<endl;
}
