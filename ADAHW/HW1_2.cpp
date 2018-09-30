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

#ifdef not_code
y > y0: (x - x0) * (y - y0)
        x*y - x0*y - x*y0 + x0y0
        => n*x*y - y*Ex0 - x*Ey0 + E(x0y0)
y < y0: (x - x0) * (y0 - y)
        x*y0 - x0*y0 - x*y + x0y
        => -n*x*y + x*Ey0 + y*Ex0 - E(x0y0)
#endif

pair<ll,ll> pt[100005];
ll pro[10005];
ll sx[10005],sy[10005];
int sz[10005];

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>pt[i].first>>pt[i].second,++pt[i].first,++pt[i].second;
    sort(pt+1,pt+1+n);
    long long ans=0;
    for(int i=1;i<=n;++i){
        {
            ll Ex0=[&]()->long long{ ll rt=0; for(int y=pt[i].second-1;y;y-=lowbit(y))rt+=sx[y]; return rt; }();
            ll Ey0=[&]()->long long{ ll rt=0; for(int y=pt[i].second-1;y;y-=lowbit(y))rt+=sy[y]; return rt; }();
            ll Ex0y0=[&]()->long long{ ll rt=0; for(int y=pt[i].second-1;y;y-=lowbit(y))rt+=pro[y]; return rt; }();
            int nn=[&]()->int{ int rt=0; for(int y=pt[i].second-1;y;y-=lowbit(y))rt+=sz[y]; return rt; }();
            ans+=nn*pt[i].first*pt[i].second-pt[i].second*Ex0-pt[i].first*Ey0+Ex0y0;
        }
        {
            ll Ex0=[&]()->long long{ ll rt=0; for(int y=10001;y;y-=lowbit(y))rt+=sx[y]; return rt; }()
                  -[&]()->long long{ ll rt=0; for(int y=pt[i].second;y;y-=lowbit(y))rt+=sx[y]; return rt; }();
            ll Ey0=[&]()->long long{ ll rt=0; for(int y=10001;y;y-=lowbit(y))rt+=sy[y]; return rt; }()
                  -[&]()->long long{ ll rt=0; for(int y=pt[i].second;y;y-=lowbit(y))rt+=sy[y]; return rt; }();
            ll Ex0y0=[&]()->long long{ ll rt=0; for(int y=10001;y;y-=lowbit(y))rt+=pro[y]; return rt; }()
                    -[&]()->long long{ ll rt=0; for(int y=pt[i].second;y;y-=lowbit(y))rt+=pro[y]; return rt; }();
            int nn=[&]()->int{ int rt=0; for(int y=10001;y;y-=lowbit(y))rt+=sz[y]; return rt; }()
                  -[&]()->int{ int rt=0; for(int y=pt[i].second;y;y-=lowbit(y))rt+=sz[y]; return rt; }();
            ans+=-nn*pt[i].first*pt[i].second+pt[i].first*Ey0+pt[i].second*Ex0-Ex0y0;
        }
        for(int y=pt[i].second;y<10005;y+=lowbit(y))++sz[y];
        for(int y=pt[i].second;y<10005;y+=lowbit(y))sx[y]+=pt[i].first;
        for(int y=pt[i].second;y<10005;y+=lowbit(y))sy[y]+=pt[i].second;
        for(int y=pt[i].second;y<10005;y+=lowbit(y))pro[y]+=pt[i].first*pt[i].second;
    }
    cout<<ans<<endl;
}