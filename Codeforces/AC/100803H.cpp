#include <bits/stdc++.h>
// #define main sfffffjjfjeif
// #include "../template/template.cpp"
// #undef main
// #undef ll
using namespace std;

const double eps = 1e-9;
const double pi = acos(-1);
bool same(double a, double b) { return abs(a - b) < eps; }

#define sq(x) ((x) * (x))

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
    double angle() { 
        double o = atan2(y, x);
        if (o < 0) o += 2 * pi;
        return o; 
    }
};

ostream& operator << (ostream &o, P p) { o << "(" << p.x << ", " << p.y << ")"; return o; }

bool operator < (const P a, const P b) {
    return same(a.x, b.x) ? same(a.y, b.y) ? 0 : a.y < b.y : a.x < b.x;
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

vector<pair<double, double>> Intersect(C a, C b) {
    vector<pair<double, double>> p;
    double d = (a.c - b.c).abs();
    if (d <= b.r - a.r) {
        p = {{0, 2 * pi}};
    } else if (same(a.r + b.r, d)) {
        double o = (b.c - a.c).angle();
        p.emplace_back(o, o);
    } else if (d <= a.r + b.r) {
        double o = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
        // PDE(o);
        double z = (b.c - a.c).angle();
        double l = z - o, r = z + o;
        // PDE(l, r);
        if (l < 0) p = {{l + 2 * pi, 2 * pi}, {0, r}};
        else if (r > 2 * pi) p = {{0, r - 2 * pi}, {l, 2 * pi}};
        else p = {{l, r}};
    }
    // PDE(a.c, b.c, p);
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
    r -= 2 * eps;
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

vector<L> tangent(C a, C b) {
#define Pij \
    P i = (b.c - a.c).unit() * a.r, j = P(i.y, -i.x);\
    z.emplace_back(a.c + i, a.c + i + j);
#define deo(I,J) \
    double d = (a.c - b.c).abs(), e = a.r I b.r, o = acos(e / d);\
    P i = (b.c - a.c).unit(), j = i.spin(o), k = i.spin(-o);\
    z.emplace_back(a.c + j * a.r, b.c J j * b.r);\
    z.emplace_back(a.c + k * a.r, b.c J k * b.r);
    if (a.r < b.r) swap(a, b);
    vector<L> z;
    if ((a.c - b.c).abs() + b.r < a.r) return z;
    else if (same((a.c - b.c).abs() + b.r, a.r)) { Pij; } 
    else {
        deo(-,+);
        if (same(d, a.r + b.r)) { Pij; } 
        else if (d > a.r + b.r) { deo(+,-); }
    }
    return z;
}

vector<P> tangent(C c, P p) {
    vector<P> z;
    double d = (p - c.c).abs();
    if (same(d, c.r)) {
        z.push_back(p);
    } else if (d > c.r) {
        double o = acos(c.r / d);
        P i = (p - c.c).unit(), j = i.spin(o) * c.r, k = i.spin(-o) * c.r;
        z.push_back(c.c + j);
        z.push_back(c.c + k);
    }
    return z;
}

vector<P> cbl[10];
vector<pair<int, double>> g[10005];

vector<P> crp;

int gid(P p) {
    return lower_bound(crp.begin(), crp.end(), p) - crp.begin();
}

void add_edge(P a, P b, double d) {
    int aa = gid(a), bb = gid(b);
    // cout << "connect " << a << " and " << b << " distance " << d << " (id = " << aa << ", " << bb << ")" << endl;
    g[aa].emplace_back(bb, d);
    g[bb].emplace_back(aa, d);
}

bitset<10005> vis;
double d[10005];
int cf[10005];
double dijkstra(P a, P b) {
    int s = gid(a), t = gid(b);
    // cout << "dijkstrea from " << a << " to " << b << " (id = " << s << " " << t << ")" << endl;
    for (int i = 0; i < 10005; ++i) d[i] = 1e9;
    d[s] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.emplace(0, s);
    while (pq.size()) {
        while (pq.size() && vis[pq.top().second]) pq.pop();
        if (pq.empty()) break;
        int now = pq.top().second; 
        vis[now] = 1;
        for (auto &e : g[now]) {
            if (d[e.first] > d[now] + e.second) {
                d[e.first] = d[now] + e.second;
                pq.emplace(d[e.first], e.first);
                cf[e.first] = now;
            }
        }
    }
    // int tt = t;
    // while (tt != s) {
    //     cout << "backtracking: " << tt << endl;
    //     tt = cf[tt];
    // }
    // cout << "backtracking: " << tt << endl;
    return d[t];
}

int main() {
    int n; P st(0, 0), gl;
    cin >> n >> gl.x >> gl.y;
    const double R = 100;
    vector<P> ps(n);
    for (int i = 0; i < n; ++i) cin >> ps[i].x >> ps[i].y;
    crp.push_back(st), crp.push_back(gl);
    for (P p : ps) {
        auto vp = tangent(C(p, R), st);
        for (P pp : vp) crp.push_back(pp);
        vp = tangent(C(p, R), gl);
        for (P pp : vp) crp.push_back(pp);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto vl = tangent(C(ps[i], R), C(ps[j], R));
            for (L ll : vl) crp.push_back(ll.pa), crp.push_back(ll.pb);
        }
    }
    sort(crp.begin(), crp.end());
    crp.resize(unique(crp.begin(), crp.end()) - crp.begin());
    for (int i = 0; i < (int)crp.size(); ++i) {
        P p = crp[i];
        for (int j = 0; j < n; ++j) {
            if (same((p - ps[j]).abs(), 100)) {
                cbl[j].push_back(p);
            }
        }
        // cout << "crp[" << i << "]: " << crp[i] << endl;
    }
    for (int i = 0; i < (int)crp.size(); ++i) {
        for (int j = i + 1; j < (int)crp.size(); ++j) {
            // cout << "checking segment " << crp[i] << " to " << crp[j] << " (id = " << i << ", " << j << ")" << endl;
            bool yes = true;
            for (int z = 0; z < n; ++z) {
                vector<P> ips = CircleCrossLine(crp[i], crp[j], ps[z], R);
                if (ips.size()) { yes = false; break; } 
            }
            // cout << "result yes = " << yes << endl;
            if (yes) {
                add_edge(crp[i], crp[j], (crp[i] - crp[j]).abs()); // straight 
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        // cout << "checking circle i = " << i << " center at " << ps[i] << endl;
        vector<double> pts;
        for (P p : cbl[i]) pts.push_back((p - ps[i]).angle());
        for (P p : cbl[i]) pts.push_back((p - ps[i]).angle() + 2 * pi);
        sort(pts.begin(), pts.end(), greater<double>());
        vector<pair<double, double>> una = {{4 * pi, 4 * pi}};
        for (int j = 0; j < n; ++j) if (i != j) {
            auto tuna = Intersect(C(ps[i], R), C(ps[j], R));
            for (auto p : tuna) una.push_back(p), una.emplace_back(p.first + 2 * pi, p.second + 2 * pi);
        }
        sort(una.begin(), una.end());
        double cr = 0;
        vector<pair<double, double>> avl;
        for (auto &p : una) {
            if (p.first <= cr) cr = max(cr, p.second);
            else {
                avl.emplace_back(cr, p.first);
                cr = p.second;
            }
        }
        // PDE(i, ps[i], una, avl);
        double pvs = 0;
        int pvsok = 0;
        for (auto &p : avl) {
            pvsok = 0;
            while (pts.size() && pts.back() < p.first) pts.pop_back();
            while (pts.size() && pts.back() < p.second) {
                if (pvsok) {
                    add_edge(ps[i] + P(1, 0).spin(pvs) * R, ps[i] + P(1, 0).spin(pts.back()) * R, (pts.back() - pvs) * R);
                }
                pvsok = 1;
                pvs = pts.back();
                pts.pop_back();
            }
        }
    }
    double ans = dijkstra(st, gl);
    if (ans > 1e8) ans = 0;
    cout << fixed << setprecision(15) << ans << endl;
}
