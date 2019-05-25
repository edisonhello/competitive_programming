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

struct frac {
    long long u, d;
    frac() : u(0), d(1) {}
    frac(long long _u, long long _d) : u(_u), d(_d) {
        long long g = __gcd(u, d);
        u /= g; d /= g;
        if (d < 0) d = -d, u = -u;
    }
};

bool operator < (const frac &a, const frac &b) {
    return a.u * b.d < b.u * a.d;
}
bool operator > (const frac &a, const frac &b) {
    return a.u * b.d > b.u * a.d;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    frac L, R;
    L.u = -1000000001; R.u = -1; R.d = 1000000001;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i + 1].first >= v[i].first && v[i + 1].second >= v[i].second) continue;
        if (v[i + 1].first <= v[i].first && v[i + 1].second <= v[i].second) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if (v[i + 1].second < v[i].second) {
            frac f(v[i + 1].second - v[i].second, v[i + 1].first - v[i].first);
            if (f.u * R.d < R.u * f.d) R = f;
        }
        if (v[i + 1].first < v[i].first) {
            frac f(v[i + 1].second - v[i].second, v[i + 1].first - v[i].first);
            if (f.u * L.d > L.u * f.d) L = f;
        }
    }
    if (!(L < R)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    PDE(L.u, L.d, R.u, R.d);
    swap(L, R); L.u *= -1; R.u *= -1;
    auto slow_ab = [&] (const frac L, const frac R) {
        for (long long u = 1, d = 1; ; ++u) {
            if (u * L.d > L.u * d) {
                while (u * R.d >= d * R.u) ++d;
                if (u * L.d > L.u * d) {
                    return make_pair(u, d);
                }
            }
        }
    };
    auto fast_ab = [&] (const frac L, const frac R) {
        for (long long u = 1, d = 1; ;) {
            u = (L.u * d) / L.d + 1;
            d = (u * R.d) / R.u + 1;
            PDE(u, d);
            if (u * L.d > L.u * d) {
                return make_pair(u, d);
            }
        }
    };
    pair<int, int> slow = slow_ab(L, R);
    pair<int, int> fast = fast_ab(L, R);
    PDE(slow, fast);
    assert(slow == fast);
    cout << fast.first << " " << fast.second << endl;
}

int main(){
    CPPinput;
    int Ts; cin >> Ts; 
    for (int t = 1; t <= Ts; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }

}
