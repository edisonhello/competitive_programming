#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
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

struct L{
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

vector<P> CircleCrossLine(P a, P b, P o, double r) {
    double x0 = o.x, y0 = o.y;
    double x1 = a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    double dx = x2 - x1, dy = y2 - y1;
    double A = dx * dx + dy * dy;
    double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
    double C = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) - r * r;
    double delta = B * B - 4 * A * C;
    vector<P> ret;
    if (delta >= -eps) {
        double t1 = (-B - sqrt(abs(delta))) / (2 * A);
        double t2 = (-B + sqrt(abs(delta))) / (2 * A);
        if (t1 - 1.0 <= eps && t1 >= -eps) ret.emplace_back(x1 + t1 * dx, y1 + t1 * dy);
        if (t2 - 1.0 <= eps && t2 >= -eps) ret.emplace_back(x1 + t2 * dx, y1 + t2 * dy);
    }
	return ret;
}

double SectorArea(P a, P b, double r) {
    double theta = atan2(a.y, a.x) - atan2(b.y, b.x);
    while (theta <= 0) theta += 2 * pi;
    while (theta >= 2 * pi) theta -= 2 * pi;
    theta = min(theta, 2 * pi - theta);
    return r * r * theta / 2;
}

double AreaOfCircleTriangle(P a, P b, double r) {
    bool ina = a.abs() - r < 0, inb = b.abs() - r < 0;
    if (ina) {
        if (inb) return abs(a ^ b) / 2;
        else {
            vector<P> p = CircleCrossLine(a, b, P(0, 0), r);
            return SectorArea(b, p[0], r) + abs(a ^ p[0]) / 2.0;
        }
    } else {
        vector<P> p = CircleCrossLine(a, b, P(0, 0), r);
        if (inb) return SectorArea(p[0], a, r) + abs(p[0] ^ b) / 2.0;
        else {
            if (p.size() == 2u) return SectorArea(a, p[0], r) + SectorArea(p[1], b, r) + abs(p[0] ^ p[1]) / 2.0; 
            else return SectorArea(a, b, r);
        }
    }
}
double AreaOfCircleTriangle(vector<P> ps, double r) {
    double ans = 0;
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        double o = atan2(ps[i].y, ps[i].x) - atan2(ps[j].y, ps[j].x);
        if (o >= pi) o = o - 2 * pi;
        if (o <= -pi) o = o + 2 * pi;
        ans += AreaOfCircleTriangle(ps[i], ps[j], r) * (o >= 0 ? 1 : -1);
    }
    // cerr << "(" << ps[0].x << ", " << ps[0].y << "), ";
    // cerr << "(" << ps[1].x << ", " << ps[1].y << "), ";
    // cerr << "(" << ps[2].x << ", " << ps[2].y << "), ";
    // cerr << "r = " << r << ", get ans = " << abs(ans) << endl;
    return abs(ans);
}

double solve(P A, P B, P C, double r) {
    P O(0, 0);
    double curans = AreaOfCircleTriangle(vector<P>{A, B, C}, r);
    double d = 99, decay = 0.993;
    int step = 1511;
    while (step--) {
        double o = rand();
        P OO = O + P(cos(o), sin(o)) * d;
        double newans = AreaOfCircleTriangle(vector<P>{A - OO, B - OO, C - OO}, r);
        if (newans > curans) O = OO, curans = newans;
        d *= decay;
        // cerr << d << " " << step << endl;
    }
    return curans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, r; while (cin >> a >> b >> c >> r, a) {
        P A(0, 0), B(c, 0);
        P C((double)(a * a + c * c - b * b) / (2 * a * c), 0);
        C.y = sqrt(1 - C.x * C.x); C = C * a;
        cout << fixed << setprecision(2) << solve(A, B, C, r) << '\n';
    }
}
