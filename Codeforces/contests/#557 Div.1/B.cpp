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

const vector<unsigned long long> primes = {7902131, 131, 89, 890301, 997, 107, 688379, 2341, 12413};
const vector<unsigned long long> mods = {1000000007, 1000000009, 1000000123, 1000000087, 1000000181, 1000000207, 1000000223, 1000001011, 1000001021, 1000001053, 1000001087};

vector<int> to[100005];
pair<unsigned long long, unsigned long long> hh[200005];

vector<int> kmp(const vector<pair<unsigned long long, unsigned long long>> &s) {
    PDE(s);
    vector<int> f(s.size(), 0);
    // f[i] = length of the longest prefix (excluding s[0:i]) such that it coincides with the suffix of s[0:i] of the same length
    // i + 1 - f[i] is the length of the smallest recurring period of s[0:i]
    int k = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) ++k;
        f[i] = k;
    }
    PDE(f);
    return f;
}

int main(){
    srand(time(0) * clock() * clock());
    unsigned long long p1 = primes[rand() % 9], p2 = primes[rand() % 9]; while (p2 == p1) p2 = primes[rand() % 9];
    unsigned long long mod1 = mods[rand() % 11], mod2 = mods[rand() % 11]; while (mod2 == mod1) mod2 = mods[rand() % 11];
    CPPinput;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        to[u].push_back((v + n - u) % n);
        to[v].push_back((u + n - v) % n);
    }
    for (int i = 1; i <= n; ++i) sort(to[i].begin(), to[i].end());
    for (int i = 1; i <= n; ++i) {
        unsigned long long &h1 = hh[i].first;
        unsigned long long &h2 = hh[i].second;
        for (int j : to[i]) h1 = (h1 * p1 + j) % mod1;
        for (int j : to[i]) h2 = (h2 * p2 + j) % mod2;
    }
    for (int i = 1; i <= n; ++i) hh[i + n] = hh[i];
    vector<pair<unsigned long long, unsigned long long>> v(hh + 1, hh + 1 + n + n);
    vector<int> res = kmp(v);
    for (int i = 1; i < (int)res.size() - 1; ++i) {
        if (res[i] >= n) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}
