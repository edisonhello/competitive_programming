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

string s;

int dfs(int l, int r, int val) {
    if (l > r) exit(7122);
    if (l == r) {
        if (s[l] == 'x') return val;
        if (s[l] == 'X') return !val;
        if (s[l] == '0') return 0;
        if (s[l] == '1') return 1;
    }
    if (l + 2 == r) {
        if (s[l + 1] == '&') return dfs(l, l, val) & dfs(r, r, val);
        if (s[l + 1] == '|') return dfs(l, l, val) | dfs(r, r, val);
        if (s[l + 1] == '^') return dfs(l, l, val) ^ dfs(r, r, val);
    }
    int x = -1, dep = 0;
    for (int i = l; i <= r; ++i) {
        if (s[i] == '(') ++dep;
        if (s[i] == ')') --dep;
        if (dep == 0) { x = i + 1; break; }
    }
    if (x == -1 || x > r) return dfs(l + 1, r - 1, val);
    if (s[x] == '&') return dfs(l, x - 1, val) & dfs(x + 1, r, val);
    if (s[x] == '|') return dfs(l, x - 1, val) | dfs(x + 1, r, val);
    if (s[x] == '^') return dfs(l, x - 1, val) ^ dfs(x + 1, r, val);
}

int main(){
    CPPinput;
    int n; cin >> n; for (int t = 1; t <= n; ++t) {
        cout << "Case #" << t << ": ";
        cin >> s;
        int L = 0, R = s.size() - 1;
        if (s[L] == '(') ++L, --R;
        int r0 = dfs(L, R, 0);
        int r1 = dfs(L, R, 1);
        if (r0 == r1) cout << "0\n";
        else cout << "1\n";
    }
}
