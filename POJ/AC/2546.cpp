#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
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
vector<P> intersect(C a, C b) {
    if (a.r > b.r) swap(a, b);
    double d = (a.c - b.c).abs();
    vector<P> ps;
    if (same(a.r + b.r, d)) ps.push_back(a.c + (b.c - a.c).unit() * a.r);
    else if (a.r + b.r > d && d + a.r > b.r + eps) {
        double o = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
        P i = (b.c - a.c).unit();
        ps.push_back(a.c + i.spin(o) * a.r);
        ps.push_back(a.c + i.spin(-o) * a.r);
    }
    return ps;
}

double intersect_area(C a, C b) {
    if (a.r > b.r) swap(a, b);
    double d = (a.c - b.c).abs();
    if (d >= a.r + b.r - eps) return 0;
    if (d + a.r <= b.r + eps) return sq(a.r) * acos(-1);
    double p = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
    double q = acos((sq(b.r) + sq(d) - sq(a.r)) / (2 * b.r * d));
    return p * sq(a.r) + q * sq(b.r) - a.r * d * sin(p);
}

int main() {
    C a, b; 
    cin >> a.c.x >> a.c.y >> a.r >> b.c.x >> b.c.y >> b.r;
    cout << fixed << setprecision(3) << intersect_area(a, b) << '\n';
}
