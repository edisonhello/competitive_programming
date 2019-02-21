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

long long a[100005],b[100005];
long long c[100005],d[100005];

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<n;++i)c[i]=a[i+1]-a[i];
    for(int i=1;i<n;++i)d[i]=b[i+1]-b[i];
    sort(c+1,c+n);
    sort(d+1,d+n);
    for(int i=1;i<n;++i){
        if(c[i]!=d[i]){
            cout<<"No"<<endl;
            exit(0);
        }
    }
    if(a[1]!=b[1] || a[n]!=b[n]){
        cout<<"No"<<endl;
        exit(0);
    }
    cout<<"Yes"<<endl;
    /* while(1){
        int o; cin>>o;
        if(o<=1 || o>=n)continue;
        a[o]=a[o-1]+a[o+1]-a[o];
        for(int i=1;i<=n;++i)cout<<a[i]<<" ";
        cout<<endl;
        cout<<"(";
        for(int i=1;i<n;++i)cout<<a[i+1]-a[i]<<" ";
        cout<<")"<<endl;
    } */
}

#ifdef NOT_CODE
7 15 10 12
7 2 4 12
7 9 4 12
7 9 17 12
7 15 17 12
7 15 10 12

a b     c     d e f
a a+c-b c     d e f
a a+c-b a+d-b d e f
a a+d-c a+d-b d e f
a a+d-c d-c+b d e f

if selected is in mid:
    distance to LR will swap and remain mid

#endif
