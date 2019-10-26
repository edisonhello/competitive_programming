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
 
bool same(double a, double b) { return abs(a - b) < eps; }
 
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
    double a, b ,c, o;
    P pa, pb;
    L() : a(0), b(0), c(0), o(0), pa(), pb() {}
    L(P pa, P pb) : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb), o(atan2(-a, b)), pa(pa), pb(pb) {}
    P project(P p) { return pa + (pb - pa).unit() * ((pb - pa) * (p - pa) / (pb - pa).abs()); }
    P reflect(P p) { return p + (project(p) - p) * 2; }
    double get_position(P p) { return (p - pa) * (pb - pa) / (pb - pa).abs() / (pb - pa).abs(); }
};
 
bool parallel(L x, L y) {
    return same(x.a * y.b, x.b * y.a);
}
 
P intersect(L x, L y) {
    if (parallel(x, y)) throw;
    return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a);
}
 
vector<P> tri[105];
bool vis[105][3], vis2[105];
 
int main(){
    CPPinput;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        tri[i].resize(3);
        for (int j = 0; j < 3; ++j) cin >> tri[i][j].x >> tri[i][j].y;
        double ara = 0;
        for (int j = 0; j < 3; ++j) ara += tri[i][j] ^ tri[i][(j + 1) % 3];
        if (ara < 0) swap(tri[i][0], tri[i][2]);
        // cerr << "ara = " << ara << endl;
    }
    double ans = 0;
    while (true && (double)clock() / CLOCKS_PER_SEC < 0.1) {
        // cerr << "start" << endl;
        int si = -1, sj = 0;
        for (int i = 0; i < n; ++i) if (!vis2[i]) {
            for (int j = 0; j < 3; ++j) {
                if (si == -1 && !vis[i][j]) si = i, sj = j;
                if (si != -1 && !vis[i][j] && make_pair(tri[i][j].x, tri[i][j].y) < make_pair(tri[si][sj].x, tri[si][sj].y)) 
                    si = i, sj = j;
            }
        }
        if (si == -1) break;
        // cerr << "si = " << si << ", sj = " << sj << ", vis = " << vis[si][sj] << endl;
        double start_ans = ans;
        int ni = si, nj = sj;
        P pnow = tri[si][sj];
        P pto = tri[si][(sj + 1) % 3];
        bool mid = false;
        while (!(si == ni && sj == nj && ans > start_ans && !mid) && (double)clock() / CLOCKS_PER_SEC < 0.1) {
            // cerr << "ni = " << ni << ", nj = " << nj << " pnow = " << pnow.x << ", " << pnow.y << " pto = " << pto.x << ", " << pto.y << endl;
            if (!mid) vis[ni][nj] = 1, vis2[ni] = 1;
            double sect_pos = 1;
            int xi = ni, xj = (nj + 1) % 3;
            P pnxt;
            for (int i = 0; i < n; ++i) if (i != ni) {
                for (int j = 0; j < 3; ++j) {
                    int k = (j + 1) % 3;
                    if (parallel(L(pnow, pto), L(tri[i][j], tri[i][k]))) continue;
                    P xp = intersect(L(pnow, pto), L(tri[i][j], tri[i][k]));
                    double pos = L(pnow, pto).get_position(xp);
                    double ipos = L(tri[i][j], tri[i][k]).get_position(xp);
                    // cerr << i << " " << j << " pos = " << pos << ", ipos = " << ipos << ", xp = (" << xp.x << ", " << xp.y << ")" << endl;
                    if (ipos <= eps || ipos >= 1 - eps) continue;
                    if (pos <= eps || pos >= 1 - eps) continue;
                    if (pos < sect_pos) xi = i, xj = j, sect_pos = pos, pnxt = xp, mid = true;
                }
            }
            if (sect_pos == 1) {
                ans += (pnow - pto).abs();
                if (!mid) nj = (nj + 1) % 3;
                pnow = pto;
                pto = tri[ni][(nj + 1) % 3];
                mid = false;
            } else {
                ans += (pnxt - pnow).abs();
                ni = xi;
                nj = (xj + 1) % 3;
                pnow = pnxt;
                pto = tri[xi][(xj + 1) % 3];
            }
        }
        // cerr << "ans = " << ans << endl;
    }
    cout << fixed << setprecision(12) << ans << endl;
}
