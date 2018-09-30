// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

long long a[300005];
int bsum[300005],bsumo[300005],bsume[300005],bmax[300005];

long long bf(int n){
    long long rt=0;
    for(int l=1;l<=n;++l){
        for(int r=l+1;r<=n;++r){
            int sum=0,mx=0;
            for(int z=l;z<=r;++z){
                int ccc=int(bitset<64>(a[z]).count());
                sum+=ccc;
                mx=max(ccc,mx);
            }
            if(sum>=mx*2 && sum%2==0)++rt;
        }
    }
    return rt;
}

int main(){
    srand(time(0)+clock());
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    // int n=100;
    // for(int i=1;i<=n;++i)a[i]=1ll*(rand()%1000000000+1)*(rand()%1000000000+1);
    // for(int i=1;i<=n;++i)a[i]=9;
    for(int i=1;i<=n;++i)bsum[i]=bsum[i-1]+int(bitset<64>(a[i]).count());
    for(int i=1;i<=n;++i)PDE(i,bsum[i]);
    for(int i=0;i<=n;++i)++(bsum[i]&1?bsumo:bsume)[i];
    for(int i=1;i<=n;++i)bsumo[i]+=bsumo[i-1];
    for(int i=1;i<=n;++i)bsume[i]+=bsume[i-1];
    long long ans=0;
    /* auto query=[&](int x,int a=0){ for(;x<300005;x+=lowbit(x))a=max(a,bmax[x]); return a; };
    auto add=[&](int x,int v){ for(;x;x-=lowbit(x))bmax[x]=max(bmax[x],v); }; */
    for(int r=1;r<=n;++r){
        // add(r,bsum[r]-bsum[r-1]);
        /* int L=1,R=r;
        while(L<R){
            int M=(L+R+1)>>1;
            PDE(M,bsum[r],bsum[M-1],query(M));
            if(bsum[r]-bsum[M-1]>=query(M)*2)L=M;
            else R=M-1;
        } */
        int l=r;
        int xx=0;
        for(int z=0;z<64;++z,--l){
            if(l==0)break;
            xx=max(xx,bsum[l]-bsum[l-1]);
            if(bsum[r]-bsum[l-1]>=xx*2 && (bsum[r]-bsum[l-1])%2==0)++ans;
        }
        if(l /* bsum[r]-bsum[L-1]>=query(L)*2 */ ){
            ans+=(bsum[r]&1?bsumo[l-1]:bsume[l-1]);
        }
        PDE(l,r,ans);
    }
    cout<<ans<<endl;
    /* if(bf(n)!=ans){
        cout<<"meow "<<bf(n)<<endl;
        for(int i=1;i<=n;++i)cout<<a[i]<<" "; cout<<endl;
    } */
}
