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

bool same(double a, double b) { return abs(a - b) < eps; }
int sign(double a) { return a == abs(a) ? 1 : -1; }

struct P {
    double x, y;
    P() : x(0), y(0) {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P b) { return P(x + b.x, y + b.y); }
    P operator - (P b) { return P(x - b.x, y - b.y); }
    P operator * (double b) { return P(x * b, y * b); }
    P operator / (double b) { return P(x / b, y / b); }
    double operator * (P b) { return x * b.x + y * b.y; }
    double operator ^ (P b) { return x * b.y - y * b.x; }
    double abs() { return hypot(x, y); }
    P unit() { return *this / abs(); }
};

struct L{
    // ax + by + c = 0
    double a, b ,c;
    P pa, pb;
    L() : a(0), b(0), c(0), pa(), pb() {}
    L(P pa, P pb) : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb), pa(pa), pb(pb) {}
    double get_position(P p) { return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs()); }
};

bool parallel(L x, L y) {
    return same(x.a * y.b, x.b * y.a);
}

P intersect(L x, L y) {
    return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a);
}

vector<P> tri[105];

int main(){
    CPPinput;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        tri[i].resize(3);
        for (int j = 0; j < 3; ++j) cin >> tri[i][j].x >> tri[i][j].y;
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            P now = tri[i][j], nxt = tri[i][(j + 1) % 3];
            L lnow = L(now, nxt);
            vector<double> splits = {0.0, 1.0};
            for (int ii = 0; ii < n; ++ii) if (ii != i) {
                for (int j = 0; j < 3; ++j) {
                    L lcut = L(tri[ii][j], tri[ii][(j + 1) % 3]);
                    if (parallel(lnow, lcut)) continue;
                    P xp = intersect(lnow, lcut);
                    double pos = lnow.get_position(xp);
                    double ipos = lnow.get_position(xp);
                    if (pos <= eps || pos >= 1 - eps || ipos <= eps || ipos >= 1 - eps) continue;
                    splits.push_back(pos);
                }
            }
            sort(splits.begin(), splits.end());
            splits.resize(unique(splits.begin(), splits.end(), [] (const double a, const double b) { return abs(a - b) < eps; }) - splits.begin());
            double len = (nxt - now).abs();
            for (int j = 1; j < (int)splits.size(); ++j) {
                P mid = now + (nxt - now) * (splits[j] + splits[j - 1]) / 2;
                // cerr << "seeing " << (splits[j] + splits[j - 1]) / 2 << " : " << mid.x << " " << mid.y << endl;
                bool inside = false;
                for (int ii = 0; ii < n; ++ii) if (ii != i) {
                    /* double agl = 0;
                    for (int j = 0; j < 3; ++j) {
                        P v1 = tri[ii][j] - mid, v2 = tri[ii][(j + 1) % 3] - mid;
                        agl += acos((v1.abs() * v1.abs() + v2.abs() * v2.abs() - (v1 - v2).abs() * (v1 - v2).abs()) / (2 * v1.abs() * v2.abs())) * sign(v1 ^ v2);
                        // cerr << v1.x << " " << v1.y << " ; " << v2.x << " " << v2.y << endl;
                        // cerr << acos((v1.abs() * v1.abs() + v2.abs() * v2.abs() - (v1 - v2).abs() * (v1 - v2).abs()) / (2 * v1.abs() * v2.abs())) << endl;
                    }
                    // cerr << "Agl = " << agl << endl;
                    if (abs(agl) > eps) { inside = true; break; } */
                    P to(100009, 100007);
                    L ll(mid, to);
                    int cnt = 0;
                    for (int j = 0; j < 3; ++j) {
                        L lll(tri[ii][j], tri[ii][(j + 1) % 3]);
                        P xp = intersect(ll, lll);
                        double ipos = lll.get_position(xp);
                        if (ipos < 0 || ipos > 1) continue;
                        double pos = ll.get_position(xp);
                        if (pos < 0 || pos > 1) continue;
                        ++cnt;
                    }
                    if (cnt & 1) { inside = true; break; }
                    
                }
                if (!inside) ans += len * (splits[j] - splits[j - 1]);
            }
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}
