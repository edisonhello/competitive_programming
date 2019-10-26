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

vector<L> tangent(C c1, C c2) {
    if (c1.r < c2.r) swap(c1, c2);
    if (same((c1.c - c2.c).abs() + c2.r, c1.r)) {
        P i = (c2.c - c1.c).unit() * c1.r;
        P j = P(i.y, -i.x);
        return vector<L>{L(c1.c + i, c1.c + i + j)};
    }
    if ((c1.c - c2.c).abs() + c2.r < c1.r) return vector<L>();
    vector<L> res;
    double d = (c1.c - c2.c).abs(), e = c1.r - c2.r;
    double o = acos(e / d);
    P i = (c2.c - c1.c).unit();
    P j = i.spin(o), k = i.spin(-o);
    // cerr << "d = " << d << " e = " << e << " o = " << o << endl;
    res.emplace_back(c1.c + j * c1.r, c2.c + j * c2.r);
    res.emplace_back(c1.c + k * c1.r, c2.c + k * c2.r);
    if (same(d, c1.r + c2.r)) {
        P i = (c2.c - c1.c).unit() * c1.r;
        P j = P(i.y, -i.x);
        res.emplace_back(c1.c + i, c1.c + i + j);
    } else if (d > c1.r + c2.r) {
        double d = (c1.c - c2.c).abs(), e = c1.r + c2.r;
        double o = acos(e / d);
        // cerr << "2 d = " << d << " e = " << e << " o = " << o << endl;
        P i = (c2.c - c1.c).unit();
        P j = i.spin(o), k = i.spin(-o);
        res.emplace_back(c1.c + j * c1.r, c2.c - j * c2.r);
        res.emplace_back(c1.c + k * c1.r, c2.c - k * c2.r);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(5);

    P a, b; double c, d;
    while (cin >> a.x >> a.y >> c >> b.x >> b.y >> d) {
        if (same(a.x, 0) && same(a.y, 0) && same(c, 0) &&
            same(b.x, 0) && same(b.y, 0) && same(d, 0)) break;
        if (same(a.x, b.x) && same(a.y, b.y) && same(c, d)) {
            cout << "-1" << '\n';
            continue;
        }
        vector<L> tls = tangent(C(a, c), C(b, d));
        vector<vector<double>> ans;
        for (L &l : tls) {
            P s = l.project(a), t = l.project(b);
            ans.emplace_back(vector<double>{s.x, s.y, t.x, t.y, (s - t).abs()});
        }
        sort(ans.begin(), ans.end(), [&] (const vector<double> &a, const vector<double> &b) {
            return same(a[0], b[0]) ? a[1] < b[1] : a[0] < b[0];
        });
        cout << ans.size() << '\n';
        for (auto &a : ans) for (int i = 0; i < 5; ++i) { 
            cout << a[i] + eps << " \n"[i == 4];
        }
    }
}
