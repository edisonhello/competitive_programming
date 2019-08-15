#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
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
};

P intersect(L x, L y) {
    if (same(x.a * y.b, x.b * y.a)) throw;
    return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a);
}

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
        if (t1 - 1.0 <= eps && t1 >= -eps) ret.push_back(P(x1 + t1 * dx, y1 + t1 * dy));
        if (t2 - 1.0 <= eps && t2 >= -eps) ret.push_back(P(x1 + t2 * dx, y1 + t2 * dy));
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
        if (inb) return abs(a ^ b) / 2; // triangle in circle
        else { // a point inside and another outside: calc sector and triangle area
            vector<P> p = CircleCrossLine(a, b, P(0, 0), r);
            return SectorArea(b, p[0], r) + abs(a ^ p[0]) / 2.0;
        }
    } else {
        vector<P> p = CircleCrossLine(a, b, P(0, 0), r);
        if (inb) return SectorArea(p[0], a, r) + abs(p[0] ^ b) / 2.0;
        else {
            if (p.size() == 2u) return SectorArea(a, p[0], r) + SectorArea(p[1], b, r) + abs(p[0] ^ p[1]) / 2.0; // segment ab has 2 point intersect with circle
            else return SectorArea(a, b, r); // segment has no intersect point with circle
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
        // cerr << "care " << ps[i].x << " " << ps[i].y << " and " << ps[j].x << " " << ps[j].y << " with o = " << o << " , area = " << AreaOfCircleTriangle(ps[i], ps[j], r) * (o >= 0 ? 1 : -1) << endl;
        ans += AreaOfCircleTriangle(ps[i], ps[j], r) * (o >= 0 ? 1 : -1);
    }
    return abs(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x1, y1, x2, y2, x3, y3, x4, y4, r;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &r) != -1) {
        vector<P> ps; 
        ps.push_back(P(x1 - x4, y1 - y4));
        ps.push_back(P(x2 - x4, y2 - y4));
        ps.push_back(P(x3 - x4, y3 - y4));
        cout << fixed << setprecision(2) << AreaOfCircleTriangle(ps, r) << '\n';
    }
}
