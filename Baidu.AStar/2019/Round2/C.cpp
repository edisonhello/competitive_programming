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
#define data datadetedoto

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

vector<int> g[100005];
int isson[100005], sz[100005], ans[100005];
int mn[100005];

void dfs1(int now) {
    sz[now] = 1;
    mn[now] = now;
    for (int i : g[now]) {
        dfs1(i);
        sz[now] += sz[i];
        mn[now] = min(mn[now], mn[i]);
    }
}

void dfs2(int now, int l, int r) {
    // cerr << "dfs2 " << now << " range " << l << " " << r << endl;
    // cerr << "son: "; for (int i : g[now]) cerr << i << " "; cerr << endl;
    if (now == mn[now]) {
        ans[now] = l;
        if (g[now].empty());
        else if (g[now].size() == 1u) dfs2(g[now][0], l + 1, r);
        // else if (mn[g[now][0]] < mn[g[now][1]]) dfs2(g[now][0], l + 1, l + sz[g[now][0]]),
        //                                         dfs2(g[now][1], l + sz[g[now][0]] + 1, r);
        // else dfs2(g[now][1], l + 1, l + sz[g[now][1]]),
        //      dfs2(g[now][0], l + sz[g[now][1]] + 1, r);
        // else if (sz[g[now][0]] < sz[g[now][1]]) dfs2(g[now][0], l, l + sz[g[now][0]] - 1), ans[now] = l + sz[g[now][0]],
        //                                         dfs2(g[now][1], l + sz[g[now][0]] + 1, r);
        // else dfs2(g[now][1], l, l + sz[g[now][1]] - 1), ans[now] = l + sz[g[now][1]],
        //      dfs2(g[now][0], l + sz[g[now][1]] + 1, r);
        else if (sz[g[now][0]] < sz[g[now][1]]) dfs2(g[now][0], l, l + sz[g[now][0]] - 1), ans[now] = l + sz[g[now][0]],
                                           dfs2(g[now][1], l + sz[g[now][0]] + 1, r);
        else if (sz[g[now][0]] > sz[g[now][1]]) dfs2(g[now][1], l, l + sz[g[now][1]] - 1), ans[now] = l + sz[g[now][1]],
                                                dfs2(g[now][0], l + sz[g[now][1]] + 1, r);
        else if (mn[g[now][0]] < mn[g[now][1]]) dfs2(g[now][0], l, l + sz[g[now][0]] - 1), ans[now] = l + sz[g[now][0]],
                                                dfs2(g[now][1], l + sz[g[now][0]] + 1, r);
        else dfs2(g[now][1], l, l + sz[g[now][1]] - 1), ans[now] = l + sz[g[now][1]],
             dfs2(g[now][0], l + sz[g[now][1]] + 1, r);
    } else if (g[now].size() == 1u) {
        ans[now] = r;
        dfs2(g[now][0], l, r - 1);
    } else {
        if (mn[g[now][0]] < mn[g[now][1]]) dfs2(g[now][0], l, l + sz[g[now][0]] - 1), ans[now] = l + sz[g[now][0]],
                                                dfs2(g[now][1], l + sz[g[now][0]] + 1, r);
        else dfs2(g[now][1], l, l + sz[g[now][1]] - 1), ans[now] = l + sz[g[now][1]],
             dfs2(g[now][0], l + sz[g[now][1]] + 1, r);
    }
}

int main(){
    CPPinput;
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            int a, b; cin >> a >> b;
            isson[a] = isson[b] = 1;
            if (a) g[i].push_back(a);
            if (b) g[i].push_back(b);
        }
        int root = -1;
        for (int i = 1; i <= n; ++i) if (!isson[i]) root = i;
        dfs1(root);
        dfs2(root, 1, n);

        int pw = 233;
        int sum = 0;
        for (int i = 1; i <= n; ++i) sum = (0ll + sum + (ans[i] ^ i) * 1ll * pw) % mod, pw = 1ll * pw * 233 % mod;
        // for (int i = 1; i <= n; ++i) cerr << "ans[" << i << "] = " << ans[i] << endl;

        cout << sum << '\n';

        for (int i = 1; i <= n; ++i) g[i].clear(), isson[i] = 0;
    }
}
