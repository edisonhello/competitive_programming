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

pii pos[266];
int ans[1000006];

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i)cin>>pos[i].first>>pos[i].second;
    for(int i=0;i<m;++i){
        for(int j=i+1;j<m;++j){
            int dx=pos[i].first-pos[j].first;
            int dy=pos[i].second-pos[j].second;
            if(dy==0)continue;
            int online=0;
            for(int k=0;k<m;++k){
                int ddx=pos[i].first-pos[k].first;
                int ddy=pos[i].second-pos[k].second;
                if(1ll*dx*ddy==1ll*ddx*dy)++online;
            }
            PDE(i,j,online);
            if(dx==0){
                if(pos[i].first<=n && pos[i].first>=1)ans[pos[i].first]=max(ans[pos[i].first],online);
            }
            else{
                int g=__gcd(dx,dy); dx/=g, dy/=g;
                PDE(i,j,dx,dy);
                if(pos[j].second%dy==0){
                    int ts=pos[j].second/dy;
                    ll x0=pos[j].first-1ll*ts*dx;
                    PDE(ts,x0);
                    if(x0>=1 && x0<=n)ans[x0]=max(ans[x0],online);
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;++i)sum+=max(1,ans[i]);
    for(int i=1;i<=n;++i)PDE(i,ans[i]);
    cout<<sum<<endl;
}
