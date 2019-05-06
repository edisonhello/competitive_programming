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
const ll mod=998244353;

long long go(string s, int m) {
    reverse(s.begin(), s.end());
    int n = s.size();
    vector<int> djs(4 * n + 5, 0); iota(djs.begin(), djs.end(), 0); // s be 0, s be 1, t be 0, t be 1, ,, each size n
    int master = djs.size() - 1;
    int banned = djs.size() - 2;
    function<int(int)> F = [&](int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); };
    auto U = [&](int u, int v) { PDE("u", u, v); djs[F(u)] = F(v); };
    auto C = [&](int u, int v) { return F(u) == F(v); };
    auto op = [&](int size, int pos) { return size - 1 - pos; };
    // cerr << "constrant of given string" << endl;
    for (int i = 0; i < m; ++i) {
        if (s[i] == '?') {
        } else if (s[i] == '0') {
            U(i, i + n + n);
            U(i + n, i + n + n + n);
        } else if (s[i] == '1') {
            U(i + n, i + n + n);
            U(i, i + n + n + n);
        }
    }
    // cerr << "constrant of palindromes" << endl;
    for (int i = 0; i < n; ++i) {
        U(i, op(n, i));
        U(i + n, op(n, i) + n);
    }
    for (int i = 0; i < m; ++i) {
        U(i + n + n, op(m, i) + n + n);
        U(i + n + n + n, op(m, i) + n + n + n);
    }
    // cerr << "constrant of unmatch bits" << endl;
    for (int i = m; i < n; ++i) {
        if (s[i] == '0') U(master, i), U(banned, i + n);
        else if (s[i] == '1') U(master, i + n), U(banned, i);
        U(master, i + n + n), U(banned, i + n + n + n);
    }
    // cerr << "constrant of leading 1" << endl;
    U(master, n - 1 + n), U(banned, n - 1);
    U(master, m - 1 + n + n + n), U(banned, m - 1 + n + n);
    for (int i = 0; i < n; ++i) if (C(i, i + n)) return 0;
    for (int i = 0; i < m; ++i) if (C(i + n + n, i + n + n + n)) return 0;
    set<int> used; used.insert(F(banned));
    long long ans = 1;
    auto db = [&]() { ans *= 2; ans %= mod; };
    for (int i = m; i < n; ++i) {
        if (s[i] == '1') {
            used.insert(F(i));
            used.insert(F(i + n));
        } else if (s[i] == '0') {
            used.insert(F(i));
            used.insert(F(i + n));
        } else {
            if (used.count(F(i))) continue;
            if (used.count(F(i + n))) continue;
            used.insert(F(i));
            used.insert(F(i + n));
            // cerr << "double by string s at pos " << i << endl;
            if (F(i) != F(i + n)) db();
        }
    }
    for (int i = 0; i < m; ++i) {
        if (used.count(F(i)) + used.count(i + n) == 0) {
            used.insert(F(i));
            used.insert(F(i + n));
            // cerr << "double by string s at pos " << i << endl;
            if (F(i) != F(i + n)) db();
        }
        if (used.count(F(i + n + n)) + used.count(F(i + n + n + n)) == 0) {
            used.insert(F(i + n + n));
            used.insert(F(i + n + n + n));
            // cerr << "double by string t at pos " << i << endl;
            if (F(i + n + n) != F(i + n + n + n)) db();
        }
    }
    return ans;
}

int main(){
    CPPinput;
    string s; cin >> s;
    int n = s.size();
    long long ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        long long add = go(s, i);
        ans += add;
        PDE(i, add, ans);
    }
    cout << ans % mod << endl;
}
