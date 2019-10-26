#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-15;
const double pi = acos(-1);
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
    P spin(double o) {
        double c = cos(o), s = sin(o);
        return P(c * x - s * y, s * x + c * y);
    }
};

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

struct C {
    P c;
    double r;
    C() : r(0) {}
    C(P c, double r) : c(c), r(r) {}
};

bool parallel(L x, L y) { return same(x.a * y.b, x.b * y.a); }

P intersect(L x, L y) { return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a); }

#define sq(x) ((x) * (x))
vector<pair<double, double>> cover_segment(C &a, C &b) {
    double d = (a.c - b.c).abs();
    vector<pair<double, double>> ps;
    if (same(a.r + b.r, d)) ;
    else if (d <= abs(a.r - b.r) + eps) {
        if (a.r < b.r) ps.emplace_back(0, 2 * pi);
    } else if (d < abs(a.r + b.r) - eps) {
        double o = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
        double z = atan2(b.c.y - a.c.y, b.c.x - a.c.x);
        if (z < 0) z += 2 * pi;
        double l = z - o, r = z + o;
        if (l < 0) l += 2 * pi;
        if (r > 2 * pi) r -= 2 * pi;
        if (l > r) ps.emplace_back(l, 2 * pi), ps.emplace_back(0, r);
        else ps.emplace_back(l, r);
    }
    return ps;
}

double coa(vector<C> cs) {
    int n = cs.size();
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<double, double>> seg = {{2 * pi, 2 * pi}};
        for (int j = 0; j < n; ++j) if (i != j) {
            vector<pair<double, double>> ps = cover_segment(cs[i], cs[j]);
            for (auto &e : ps) seg.push_back(e);
        }
        double now = 0;
        sort(seg.begin(), seg.end());
        auto F = [&] (double t) { return cs[i].r * (cs[i].r * t + cs[i].c.x * sin(t) - cs[i].c.y * cos(t)); };
        for (auto &e : seg) {
            if (e.first > now) ans += F(e.first) - F(now);
            now = max(now, e.second);
        }
    }
    return ans * 0.5;
}

bool bye[1005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<C> cs;
    for (int i = 0; i < n; ++i) {
        C c;
        cin >> c.c.x >> c.c.y >> c.r;
        if (!same(c.r, 0)) cs.push_back(c);
    }

    vector<C> cs2;
    for (int i = 0; i < cs.size(); ++i) {
        bool ok = true;
        for (int j = i + 1; j < cs.size(); ++j) {
            if (same(cs[i].c.x, cs[j].c.x) && same(cs[i].c.y, cs[j].c.y) && same(cs[i].r, cs[j].r)) { ok = false; break; }
        }
        if (ok) cs2.push_back(cs[i]);
    }

    cout << fixed << setprecision(5) << coa(cs2) << endl;
}
