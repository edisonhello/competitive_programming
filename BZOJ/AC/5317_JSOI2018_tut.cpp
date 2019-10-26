#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

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

bool parallel(L x, L y) { return same(x.a * y.b, x.b * y.a); }

P intersect(L x, L y) { return P(-x.b * y.c + x.c * y.b, x.a * y.c - x.c * y.a) / (-x.a * y.b + x.b * y.a); }

bool operator < (const P &a, const P &b) { return same(a.x, b.x) ? a.y < b.y : a.x < b.x; }
bool operator > (const P &a, const P &b) { return same(a.x, b.x) ? a.y > b.y : a.x > b.x; }

#define crx(a, b, c) ((b - a) ^ (c - a))

bool cmp(const P &a, const P &b) { return same(a.x, b.x) ? a.y < b.y : a.x < b.x; }
vector<P> convex(vector<P> ps) {
    vector<P> p;
    sort(ps.begin(), ps.end(), cmp);
    for (int i = 0; i < ps.size(); ++i) {
        while (p.size() >= 2 && crx(p[p.size() - 2], ps[i], p[p.size() - 1]) >= 0) p.pop_back();
        p.push_back(ps[i]);
    }
    int t = p.size();
    for (int i = (int)ps.size() - 2; i >= 0; --i) {
        while (p.size() > t && crx(p[p.size() - 2], ps[i], p[p.size() - 1]) >= 0) p.pop_back();
        p.push_back(ps[i]);
    }
    p.pop_back();
    return p;
}

int sgn(double x) { return same(x, 0) ? 0 : x > 0 ? 1 : -1; }

P isLL(P p1, P p2, P q1, P q2) {
    double a = crx(q1, q2, p1), b = -crx(q1, q2, p2);
    return (p1 * b + p2 * a) / (a + b);
}

bool cmp2(const P &a, const P &b) { return same(a.x, b.x) ? a.y > b.y : a.x > b.x; }
struct CH {
    int n;
    vector<P> p, u, d;
    CH() {}
    CH(vector<P> ps) : p(ps) {
        n = ps.size();
        rotate(p.begin(), min_element(p.begin(), p.end()), p.end());
        vector<P>::iterator t = max_element(p.begin(), p.end());
        d = vector<P>(p.begin(), ++t); --t;
        u = vector<P>(t, p.end()); u.push_back(p[0]);
    }
    int find(vector<P> &v, P d) {
        int l = 0, r = v.size();
        while (l + 5 < r) {
            int L = (l * 2 + r) / 3, R = (l + r * 2) / 3;
            if (v[L] * d > v[R] * d) r = R;
            else l = L;
        }
        int x = l;
        for (int i = l + 1; i < r; ++i) if (v[i] * d > v[x] * d) x = i;
        return x;
    }
    int findFarest(P v) {
        if (v.y > 0 || v.y == 0 && v.x > 0) return ((int)d.size() - 1 + find(u, v)) % p.size();
        return find(d, v);
    }
    P get(int l, int r, P a, P b) {
        int s = sgn(crx(a, b, p[l % n]));
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (sgn(crx(a, b, p[m % n])) == s) l = m;
            else r = m;
        }
        return isLL(a, b, p[l % n], p[(l + 1) % n]);
    }
    vector<P> getIS(P a, P b) {
        int X = findFarest((b - a).spin(pi / 2));
        int Y = findFarest((a - b).spin(pi / 2));
        if (X > Y) swap(X, Y);
        vector<P> rt;
        if (sgn(crx(a, b, p[X])) * sgn(crx(a, b, p[Y])) < 0) rt.push_back(get(X, Y, a, b)), rt.push_back(get(Y, X + n, a, b));
        return rt;
    }
    void update_tangent(P q, int i, int &a, int &b) {
        if (sgn(crx(q, p[a], p[i])) > 0) a = i;
        if (sgn(crx(q, p[b], p[i])) < 0) b = i;
    }
    void bs(int l, int r, P q, int &a, int &b) {
        if (l == r) return;
        update_tangent(q, l % n, a, b);
        int s = sgn(crx(q, p[l % n], p[(l + 1) % n]));
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (sgn(crx(q, p[m % n], p[(m + 1) % n])) == s) l = m;
            else r = m;
        }
        update_tangent(q, r % n, a, b);
    }
    bool contain(P p) {
        if (p.x < d[0].x || p.x > d.back().x) return 0;
        vector<P>::iterator it = lower_bound(d.begin(), d.end(), P(p.x, -1e12)), pit = it; --pit;
        if (it->x == p.x) {
            if (it->y > p.y) return 0;
        } else if (crx(*pit, *it, p) < -eps) return 0;
        it = lower_bound(u.begin(), u.end(), P(p.x, 1e12), cmp2); pit = it; --pit;
        if (it->x == p.x) {
            if (it->y < p.y) return 0;
        } else if (crx(*pit, *it, p) < -eps) return 0;
        return 1;
    }
};

int main() {
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    vector<P> a, b;
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        a.push_back(P(x, y));
    }
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        b.push_back(P(-x, -y));
    }
    a = convex(a), b = convex(b);
    P np = a[0] + b[0];
    vector<P> c; c.push_back(np);
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (i >= a.size()) {
            int nx = (j + 1) % b.size();
            np = np + (b[nx] - b[j]);
            ++j;
        } else if (j >= b.size()) {
            int nx = (i + 1) % a.size();
            np = np + (a[nx] - a[i]);
            ++i;
        } else {
            int ni = (i + 1) % a.size(), nj = (j + 1) % b.size();
            if (((a[ni] - a[i]) ^ (b[nj] - b[j])) >= 0) {
                np = np + (a[ni] - a[i]); ++i;
            } else {
                np = np + (b[nj] - b[j]); ++j;
            }
        }
        c.push_back(np);
    }
    c = convex(c);
    CH ch(c);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", ch.contain(P(x, y)) ? 1 : 0);
    }
}
