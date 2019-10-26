#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-9;

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

struct L {
    // ax + by + c = 0
    double a, b ,c, o;
    P pa, pb;
    L() : a(0), b(0), c(0), o(0), pa(), pb() {}
    L(P pa, P pb) : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb), o(atan2(-a, b)), pa(pa), pb(pb) {}
    P project(P p) { return pa + (pb - pa).unit() * ((pb - pa) * (p - pa) / (pb - pa).abs()); }
    P reflect(P p) { return p + (project(p) - p) * 2; }
    double get_ratio(P p) { return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs()); }
};

bool cmp(const P &a, const P &b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }

struct CH {
    vector<P> p, u, d;
    CH() {}
    CH(vector<P> ps) {
        sort(ps.begin(), ps.end(), cmp);
        for (int i = 0; i < ps.size(); ++i) {
            while (p.size() >= 2 && ((ps[i] - p[p.size() - 2]) ^ (p[p.size() - 1] - p[p.size() - 2])) >= 0) p.pop_back();
            p.push_back(ps[i]);
        }
        int t = p.size();
        for (int i = (int)ps.size() - 2; i >= 0; --i) {
            while (p.size() > t && ((ps[i] - p[p.size() - 2]) ^ (p[p.size() - 1] - p[p.size() - 2])) >= 0) p.pop_back();
            p.push_back(ps[i]);
        }
        for (int i = 0; i < t; ++i) d.push_back(p[i]);
        for (int i = t; i < p.size(); ++i) u.push_back(p[i]);
        p.pop_back();
    }
};

int main() {
    int n, l; while (cin >> n >> l) {
        vector<P> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
        CH ch(p);
        double ans = 0;
        for (int i = 0; i < ch.p.size(); ++i) ans += (ch.p[i] - ch.p[(i + 1) % ch.p.size()]).abs();
        ans += 2 * acos(-1) * l;
        cout << fixed << setprecision(0) << ans << endl;
    }
}
