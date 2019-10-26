#include <bits/stdc++.h>
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

bool parallel(L x, L y) { return same(x.a * y.b, x.b * y.a); }

P intersect(L x, L y) { return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a); }

bool pt_in_polygon(vector<P> ps, P p) {
    int c = 0;
    for (int i = 0; i < ps.size(); ++i) {
        int x = i;
        int y = (i + 1) % ps.size();
        if (same(ps[x].y, ps[y].y) && same(ps[x].y, p.y)) continue;
        if (ps[x].y > ps[y].y) swap(x, y);
        if (ps[x].y <= p.y && p.y < ps[y].y) {
            if (p.x <= ps[x].x + (ps[y].x - ps[x].x) / (ps[y].y - ps[x].y) * (p.y - ps[x].y)) ++c;
        }
    }
    return c & 1;
}

int main() {
    int n; while (cin >> n, n) {
        vector<P> ps(n);
        for (P &p : ps) cin >> p.x >> p.y;
        P p; cin >> p.x >> p.y;
        cout << (pt_in_polygon(ps, p) ? "T" : "F") << '\n';
    }
}
