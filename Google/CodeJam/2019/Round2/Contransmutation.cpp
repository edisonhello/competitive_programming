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

vector<int> G[100005], iG[100005], cG[100005], tp, mem[100005], ciG[100005];
bitset<100005> vis;
long long bel[100005], have[100005], chave[100005];

void dfs(int now) {
    vis[now] = 1;
    for (int i : G[now]) if (!vis[i]) dfs(i);
    tp.push_back(now);
}
void dfs2(int now, int cc) {
    bel[now] = cc;
    mem[cc].push_back(now);
    vis[now] = 1;
    for (int i : iG[now]) if (!vis[i]) dfs2(i, cc);
}

long long dfs3mem[100005];
long long dfs3(int now) {
    if (vis[now]) return dfs3mem[now];
    vis[now] = 1;
    long long rt = 0;
    if (chave[now] && mem[now].size() > 1u) return -1;
    rt += chave[now];
    for (int i : ciG[now]) if (!vis[i]) {
        long long r = dfs3(i);
        if (r == -1) return -1;
        rt += r;
    }
    return dfs3mem[now] = rt % mod;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) G[i].clear(), iG[i].clear(), cG[i].clear();
    for (int i = 1; i <= n; ++i) mem[i].clear();
    for (int i = 1; i <= n; ++i) chave[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        G[i].push_back(a);
        G[i].push_back(b);
        iG[a].push_back(i);
        iG[b].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> have[i];
    vis.reset(); tp.clear();
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
    reverse(tp.begin(), tp.end());
    vis.reset();
    int cc = 0;
    for (int i : tp) if (!vis[i]) dfs2(i, ++cc);
    for (int i = 1; i <= n; ++i) for (int j : G[i]) {
        if (bel[i] != bel[j]) {
            cG[bel[i]].push_back(bel[j]);
            ciG[bel[j]].push_back(bel[i]);
        }
    }
    for (int i = 1; i <= n; ++i) chave[bel[i]] += have[i];
    for (int i = 1; i <= n; ++i) chave[bel[i]] %= mod;
    vis.reset();
    long long ans = dfs3(bel[1]);
    if (ans != -1) cout << ans << endl;
    else cout << "UNBOUNDED" << endl;
}

int main(){
    CPPinput;
    int Ts; cin >> Ts; 
    for (int t = 1; t <= Ts; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }

}
