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

int mp[104][104],match[104];
vector<int> G[104];
bitset<104> v;

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
        int n; cin>>n;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>mp[i][j];
        int ans=0;
        for(int z=-n;z<=n;++z){
            for(int i=1;i<=n;++i)G[i].clear();
            memset(match,-1,sizeof(match));
            int tot=0;
            for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
                if(mp[i][j]==z){
                    G[i].push_back(j);
                    ++tot;
                }
            }
            ans+=tot-[&]()->int{
                int ans=0;
                function<int(int)> dfs=[&](int now)->int{
                    for(int i:G[now]){
                        if(v[i])continue;
                        v[i]=1;
                        if(match[i]==-1 || dfs(match[i])){
                            match[i]=now;
                            return 1;
                        }
                    }
                    return 0;
                };
                for(int i=1;i<=n;++i){
                    v.reset();
                    if(dfs(i))++ans;
                }
                PDE(z,ans,tot);
                return ans;
            }();
        }
        cout<<"Case #"<<(++ks)<<": "<<ans<<endl;
    }
}
