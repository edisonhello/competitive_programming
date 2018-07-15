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
#include<complex>
#include<climits>

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

#define int long long

struct isap {
#define maxn 4100
    static const int inf = 2e14;
    struct edge {
        int dest, cap, rev;
        edge(int a, int b, int c): dest(a), cap(b), rev(c) {}
    };
    vector<edge> g[maxn];
    int it[maxn], gap[maxn], d[maxn];
    void ae(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size() - 0);
        g[b].emplace_back(a, 0, g[a].size() - 1);
    }
    int dfs(int x, int t, int tot, int flow) {
        if (x == t) return flow;
        for (int &i = it[x]; i < g[x].size(); ++i) {
            edge &e = g[x][i];
            if (e.cap > 0 && d[e.dest] == d[x] - 1) {
                int f = dfs(e.dest, t, tot, min(flow, e.cap));
                if (f) {
                    e.cap -= f;
                    g[e.dest][e.rev].cap += f;
                    return f;
                }
            }
        }
        if ((--gap[d[x]]) == 0) d[x] = tot;
        else d[x]++, it[x] = 0, ++gap[d[x]];
        return 0;
    }
    int operator()(int s, int t, int tot) {
        memset(it, 0, sizeof(it));
        memset(gap, 0, sizeof(gap));
        memset(d, 0, sizeof(d));
        int r = 0;
        gap[0] = tot;
        for (; d[s] < tot; r += dfs(s, t, tot, inf));
        return r;
    }
    void clear() {
        for (int i = 0; i < maxn; ++i) g[i].clear();
    }
#undef maxn
} meow;

int c[2222],er[2222];
vint gp[2222];

int32_t main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i],meow.ae(i,4099,c[i]);
    int os=0;
    for(int i=1,z;i<=m;++i){
        cin>>z>>er[i]; os+=er[i];
        gp[i].resize(z);
        for(int &x:gp[i])cin>>x;
        meow.ae(0,n+i,er[i]);
        for(int &x:gp[i])meow.ae(n+i,x,2e14);
    }
    int f=meow(0,4099,2+n+m);
    int maxans=os-f;

    vector<int> bye;
    for(auto &e:meow.g[4099]){
        if(e.cap>0)bye.pb(e.dest);
    }

    vector<int> must;
    for(int x:bye){
        /* meow.clear();
        for(int i=1;i<=n;++i)if(i!=x)meow.ae(i,4099,c[i]);
        int os=0;
        for(int i=1;i<=m;++i){
            bool inc=0;
            for(int z:gp[i])if(z==x){ inc=1; break; }
            if(inc)continue;
            os+=er[i];
            meow.ae(0,n+i,er[i]);
            for(int &x:gp[i])meow.ae(n+i,x,2e14);
        } */
        int f=meow(0,4099,2+n+m);
        if(os-f!=maxans)must.pb(x);
    }
    cout<<maxans<<endl;
    cout<<must.size()<<endl;
    for(int i:must)cout<<i<<" "; cout<<endl;
}
