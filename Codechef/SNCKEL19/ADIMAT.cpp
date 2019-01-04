// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

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
#define vpii vector<pair<int,int>>
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

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;


/* int dp(int s,int g,int mx){
    if(s<0 || g<0)return 0;
    if(s==0)return 1;
    if(g==0)return 0;
    if(g==1)return 1;
    if(s && !mx)return 0;
    int r=0;
    for(int x=mx;x;--x){
        r+=dp(s-x,g-1,x);
        if(r>=mod)r-=mod;
    }
    PDE(s,g,mx,r);
    return r;
} */

vector<long long> a[9]={
    {1,1,1,1,1,1,1,1,1},
    {1,2,3,4,5,6,7,8,9},
    {1,3,7,13,22,34,50,70,95},
    {1,4,13,36,87,190,386,734,1324},
    {1,5,22,87,317,1053,3250,9343,25207},
    {1,6,34,190,1053,5624,28576,136758,613894},
    {1,7,50,386,3250,28576,251610,2141733,17256831},
    {1,8,70,734,9343,136758,2141733,33642,660508,147108},
    {1,9,95,1324,25207,613894,17256831,508147108,14685630688}
};

int main(){
    CPPinput;
    for(int i=1;i<9;++i){
        for(int j=1;j<9;++j){
            cout<<a[i][j]-a[i-1][j]-a[i][j-1]<<" ";
        }
        cout<<endl;
    }
    /* int n,m; cin>>n>>m; 
    int tot=n*m;
    int ans=0;
    for(int i=0;i<=tot;++i){
        PDE(i);
        ans+=1ll*dp(i,n,m)*dp(i,m,n)%mod;
        if(ans>=mod)ans-=mod;
        PDE(ans);
    }
    cout<<ans<<endl; */
}

#ifdef OEIS

b(n, i) {
    if (n == 0) return {0};
    if (i < 1) return {};

}

b[n, i] = If[n == 0, {0}, 
    If[i<1, {}, Union[ Flatten[ Table[ Function[ {p}, p + j*x^i] /@ b[n - i*j, i-1], {j, 0, n/i}]]]]
];

g[n, k] = Sum[ Sum[ 2^Sum[ Sum[GCD[i, j] * Coefficient[s, x, i] * Coefficient[t, x, j], {j, 1, Exponent[t, x]}], {i, 1, Exponent[s, x]}] / Product[i^Coefficient[s, x, i] * Coefficient[s, x, i]!, {i, 1, Exponent[s, x]}] / Product[i^Coefficient[t, x, i] * Coefficient[t, x, i]!, {i, 1, Exponent[t, x]}], {t, b[n+k, n+k]}], {s, b[n, n]}];

A[n, k] := g[Min[n, k], Abs[n-k]];

1 1 1 1 1 1 1 1 1 ...
1 2 3 4 5 6 7 8 9 ...
1 3 7 13 22 34 50 70 95 ...
1 4 13 36 87 190 386 734 1324 ...
1 5 22 87 317 1053 3250 9343 25207 ...
1 6 34 190 1053 5624 28576 136758 613894 ...
1 7 50 386 3250 28576 251610 2141733 17256831 ...
1 8 70 734 9343 136758 2141733 33642 660508 147108 ...
1 9 95 1324 25207 613894 17256831 508147108 14685630688 ...

#endif
