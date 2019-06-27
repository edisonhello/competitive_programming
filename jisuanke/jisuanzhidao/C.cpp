#pragma GCC optimize("O3")
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

int n, m;
vector<pair<int, int>> G[100005];
vector<pair<int, int>> ban[1005];
int g[1005][1005];

vector<int> dfs(int now, int pa) {
    vector<int> ans(m + 1, 1); ans[0] = 0;
    for (auto &p : G[now]) {
        if (p.first == pa) continue;
        vector<int> rt = dfs(p.first, now);
        vector<int> up(m + 1, 0);
        int ans_sum = 0, rt_sum = 0;
        for (int i = 1; i <= m; ++i) ans_sum = (ans_sum + ans[i]) % mod;
        for (int i = 1; i <= m; ++i) rt_sum = (rt_sum + rt[i]) % mod;
        for (int i = 1; i <= m; ++i) up[i] = 1ll * ans[i] * rt_sum % mod;
        for (auto &r : ban[p.second]) up[r.first] = (up[r.first] - 1ll * ans[r.first] * rt[r.second] % mod + mod) % mod;
        ans.swap(up);
    }
    return ans;
}

int main(){
    CPPinput;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= i; ++j) g[i][j] = g[j][i] = __gcd(i, j);
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) {
        ban[g[i][j]].emplace_back(i, j);
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> ans = dfs(1, 0);
    long long tot = 0;
    for (int i : ans) tot += i;
    cout << tot % mod << endl;
}
