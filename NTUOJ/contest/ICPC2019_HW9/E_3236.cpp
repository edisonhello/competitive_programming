// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <utility>
#include <functional>
#include <complex>
#include <climits>
#include <random>
#include <thread>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <tuple>
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
#define pii pair<int, int>
#define vint vector<int>
#define vpii vector<pair<int, int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x, v) memset((x), (v), sizeof(x))
#define RZUNI(x) sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
#define FIN(fname) freopen(fname, "r", stdin)
#define FOUT(fname) freopen(fname, "w", stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl
#define data datadetedoto

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() printf("%s: Line %d", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), fflush(stdout)
#define DEBUG 1
#define exit(x) cout << "exit code " << x << endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x) & (-(x)))

#define sq(x) ((x) * (x))

void JIZZ(string output = ""){ cout << output; exit(0); }

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

bool same(double a, double b) { return abs(a - b) < eps; }

struct P {
    double x, y;
    P() : x(0), y(0) {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P b) const { return P(x + b.x, y + b.y); }
    P operator - (P b) const { return P(x - b.x, y - b.y); }
    P operator * (double b) { return P(x * b, y * b); }
    P operator / (double b) { return P(x / b, y / b); }
    double operator * (P b) { return x * b.x + y * b.y; }
    double operator ^ (P b) { return x * b.y - y * b.x; }
    double abs() { return hypot(x, y); }
    P unit() { return *this / abs(); }
    P spin(double o) {
        double c = cos(o), s = sin(o);
        return P(c * x - s * y, s * x + c * y);
    }
    double angle() { return atan2(y, x); }
    double norm2() { return *this * *this; }
};

ostream& operator << (ostream &o, P a) {
    o << "(" << a.x << ", " << a.y << ")";
    return o;
}

bool operator < (const P a, const P b) {
    if (same(a.x, b.x)) return same(a.y, b.y) ? 0 : a.y < b.y;
    return a.x < b.x;
}
bool operator == (const P a, const P b) {
    return same(a.x, b.x) && same(a.y, b.y);
}

struct L {
    // ax + by + c = 0
    double a, b, c, o;
    P pa, pb;
    L() : a(0), b(0), c(0), o(0), pa(), pb() {}
    L(P pa, P pb) : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb), o(atan2(-a, b)), pa(pa), pb(pb) {}
    P project(P p) { return pa + (pb - pa).unit() * ((pb - pa) * (p - pa) / (pb - pa).abs()); }
    P reflect(P p) { return p + (project(p) - p) * 2; }
    double get_ratio(P p) { return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs()); }
};

bool parallel(L x, L y) { return same(x.a * y.b, x.b * y.a); }

P Intersect(L x, L y) { return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a); }

struct C {
    P c;
    double r;
    C(P c = P(0, 0), double r = 0) : c(c), r(r) {}
};

vector<P> Intersect(C a, C b) {
    if (a.r > b.r) swap(a, b);
    double d = (a.c - b.c).abs();
    vector<P> p;
    if (same(a.r + b.r, d)) p.push_back(a.c + (b.c - a.c).unit() * a.r);
    else if (a.r + b.r > d && d + a.r >= b.r) {
        double o = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
        P i = (b.c - a.c).unit();
        p.push_back(a.c + i.spin(o) * a.r);
        p.push_back(a.c + i.spin(-o) * a.r);
    }
    return p;
}
double IntersectArea(C a, C b) {
    if (a.r > b.r) swap(a, b);
    double d = (a.c - b.c).abs();
    if (d >= a.r + b.r - eps) return 0;
    if (d + a.r <= b.r + eps) return sq(a.r) * acos(-1);
    double p = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
    double q = acos((sq(b.r) + sq(d) - sq(a.r)) / (2 * b.r * d));
    return p * sq(a.r) + q * sq(b.r) - a.r * d * sin(p);
}
// remove second level if to get points for line (defalut: segment)
vector<P> CircleCrossLine(P a, P b, P o, double r) {
    double x = b.x - a.x, y = b.y - a.y, A = sq(x) + sq(y), B = 2 * x * (a.x - o.x) + 2 * y * (a.y - o.y);
    double C = sq(a.x - o.x) + sq(a.y - o.y) - sq(r), d = B * B - 4 * A * C;
    vector<P> t;
    if (d >= -eps) {
        d = max(0., d);
        double i = (-B - sqrt(d)) / (2 * A);
        double j = (-B + sqrt(d)) / (2 * A);
        if (i - 1.0 <= eps && i >= -eps) t.emplace_back(a.x + i * x, a.y + i * y);
        if (j - 1.0 <= eps && j >= -eps) t.emplace_back(a.x + j * x, a.y + j * y);
    }
	return t;
}

P center(const P &a, const P &b, const P &c) {
    P p0 = b - a, p1 = c - a;
    double c1 = p0 * p0 / 2, c2 = p1 * p1 / 2;
    double d = p0 ^ p1;
    double x = a.x + (c1 * p1.y - c2 * p0.y) / d;
    double y = a.y + (c2 * p0.x - c1 * p1.x) / d;
    return P(x, y);
}

vector<P> bound;
C min_enclosing(vector<P> &p) {
    random_shuffle(p.begin(), p.end());
    double r = 0;
    P cent;
    for (int i = 0; i < (int)p.size(); ++i) {
        if ((cent - p[i]).norm2() <= r) continue;
        cent = p[i];
        r = 0.0;
        bound = {p[i]};
        for (int j = 0; j < i; ++j) {
            if ((cent - p[j]).norm2() <= r) continue;
            cent = (p[i] + p[j]) / 2;
            r = (p[j] - cent).norm2();
            bound = {p[i], p[j]};
            for (int k = 0; k < j; ++k) {
                if ((cent - p[k]).norm2() <= r) continue;
                cent = center(p[i], p[j], p[k]);
                r = (p[k] - cent).norm2();
                bound = {p[i], p[j], p[k]};
            }
        }
    }
    return C(cent, sqrt(r));
}

bool check(vector<P> &ps, P outp, int r) {
    auto cc = min_enclosing(ps);
    PDE(outp, cc.c, cc.r, r, ps);
    if (cc.r > r) return 0;
    if ((outp - cc.c).abs() > r) {
        cout << outp.x << ' ' << outp.y << endl;
        cout << fixed << setprecision(20) << (long double)cc.c.x << ' ' << (long double)cc.c.y << endl;
        return 1;
    }
    P ncc = outp + (cc.c - outp).unit() * (r + eps * 2);
    for (auto &p : ps) {
        if ((ncc - p).abs() >= r) return false;
    }
    cout << outp.x << ' ' << outp.y << endl;
    cout << fixed << setprecision(20) << (long double)ncc.x << ' ' << (long double)ncc.y << endl;
    return 1;
}

int main() {
    CPPinput;
    int n, r; cin >> n >> r;
    vector<P> ps(n);
    for (int i = 0; i < n; ++i) cin >> ps[i].x >> ps[i].y;

    if (n == 1) {
        cout << ps[0].x << ' ' << ps[0].y << endl;
        cout << "2000000000 2000000000" << endl;
        exit(0);
    }

    C c = min_enclosing(ps);
    if (c.r <= r) {
        double dd = -1e9;
        int z = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            double dist = (ps[i] - c.c).abs();
            if (dist >= dd + eps) {
                dd = dist;
                z = i;
                cnt = 1;
            } else if (abs(dist - dd) < eps) ++cnt;
        }
        // cout << "dd = " << dd << ", r -eps = " << (long double)(r - eps) << endl;
        if (cnt <= 1 || dd <= r - eps) {
            P cc = ps[z] + (c.c - ps[z]).unit() * (r + eps * 2);
            cout << ps[z].x << ' ' << ps[z].y << '\n';
            cout << fixed << setprecision(20) << (long double)cc.x << ' ' << (long double)cc.y << '\n';
            exit(0);
        }
    }

    PDE(bound);
    auto _b = bound;

    for (auto p : _b) {
        vector<P> nps; nps.reserve(n - 1);
        for (auto &pp : ps) {
            if (pp == p) continue;
            nps.push_back(pp);
        }
        if (check(nps, p, r)) exit(0);
    }
    cout << -1 << endl;
}
