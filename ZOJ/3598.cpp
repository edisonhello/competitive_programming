#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const double pi = acos(-1);
bool same(double a, double b) { return abs(a - b) < eps; }

struct P {
    double x, y, z;
    P() : x(0), y(0), z(0) {}
    P(double x, double y, double z) : x(x), y(y), z(z) {}
    P operator + (P b) { return P(x + b.x, y + b.y, z + b.z); }
    P operator - (P b) { return P(x - b.x, y - b.y, z - b.z); }
    P operator * (double b) { return P(x * b, y * b, z * b); }
    P operator / (double b) { return P(x / b, y / b, z / b); }
    double operator * (P b) { return x * b.x + y * b.y + z * b.z; }
    P operator ^ (P b) { return P(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }
    // double operator ^ (P b) { return x * b.y - y * b.x; }
    double abs() { return hypot(hypot(x, y), z); }
    P unit() { return *this / abs(); }
};

double calc(P a, P b, P c) {
    P o(0, 0, 0);
    P d1 = a ^ b;
    P d2 = a ^ c;
    // return d1 -> d2
    return acos((d1 * d2) / (d1.abs() * d2.abs()));
}

int main() {
    int t; cin >> t; while (t--) {
        P p[3];
        for (int i = 0; i < 3; ++i) {
            double o, q; cin >> o >> q;
            o = (double)o / 360 * 2 * pi;
            q = (double)q / 360 * 2 * pi;
            p[i] = P(cos(o) * cos(q), sin(o) * cos(q), sin(q));
        }
        // for (int i = 0; i < 3; ++i) cerr << "p = " << p[i].x << ", " << p[i].y << endl;
        double a = calc(p[0], p[1], p[2]) + calc(p[1], p[2], p[0]) + calc(p[2], p[0], p[1]);
        cout << fixed << setprecision(2) << (a / (2 * pi) * 360) << '\n';
    }
}
