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
const ll mod=998244353;

int c[1111];
int mem[1111][1111];
bool vis[1111][1111];

int dp(int l, int r, int st) {
    PDE(l, r, st);
    if (l >= r) return 1;
    if (vis[l][r]) return mem[l][r];
    vis[l][r] = 1;
    int at = l;
    for (int i = l + 1; i <= r; ++i) if (c[i] < c[at]) at = i;
    PDE(at, c[at], st);
    if (c[at] <= st) return 0;
    int L = at, R = at;
    for (int i = l; i <= r; ++i) if (c[at] == c[i]) R = i;
    for (int i = r; i >= l; --i) if (c[at] == c[i]) L = i;
    PDE(L, R);
    long long lans = 0, rans = 0, ans = 0;
    for (int i = R; i <= r; ++i) rans += dp(R + 1, i, c[at]) * 1ll * dp(i + 1, r, c[at]) % mod;
    for (int i = L; i >= l; --i) lans += dp(i, L - 1, c[at]) * 1ll * dp(l, i - 1, c[at]) % mod;
    PDE(lans, rans, ans);
    for (int i = L, j; i <= R; i = j) {
        for (j = i + 1; j <= R && c[j] != c[at]; ++j);
        PDE("call ", i + 1, j - 1);
        ans = ans * dp(i + 1, j - 1, c[at]) % mod;
    }
    return mem[l][r] = (lans % mod) * (rans % mod) % mod;
}

int main(){
    CPPinput;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> c[i];
    m = unique(c, c + m + 1) - c - 1;
    for (int i = 1; i <= n; ++i) {
        int l = 1e9, r = -1;
        for (int j = 1; j <= m; ++j) if (c[j] == i) l = min(l, j), r = max(r, j);
        for (int j = l; j <= r; ++j) if (c[j] < i) { cout << 0 << '\n'; exit(0); }
    }
    for (int j = 1; j <= m; ++j) PDE(j, c[j]);
    cout << dp(1, m, 0) << endl;
}
