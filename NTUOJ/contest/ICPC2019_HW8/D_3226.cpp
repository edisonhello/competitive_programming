#pragma GCC optimize("Ofast")
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
    double angle() { return atan2(y, x); }
};

struct L {
    // ax + by + c = 0
    P pa, pb;
    L() : pa(), pb() {}
    L(P pa, P pb) : pa(pa), pb(pb) {}
    double get_ratio(P p) { return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs()); }
	P get_pos(double x) {
		P dir = (pb - pa).unit();
		return pa + dir * x;
	}
};

double lenpre[1005];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<P> ps(n);
	for (int i = 0; i < n; ++i) cin >> ps[i].x >> ps[i].y;
	double totlen = 0;
	for (int i = 0; i < n; ++i) totlen += (ps[(i + 1) % n] - ps[i]).abs();
	double onelen = totlen / k;
	for (int i = 0; i < n; ++i) lenpre[i] = (i ? lenpre[i - 1] : 0) + (ps[(i + 1) % n] - ps[i]).abs();
	vector<double> offsets = {0, onelen};
	for (int i = 1; i < n - 1; ++i) {
		double o = lenpre[i];
		while (o > onelen) o -= onelen;
		offsets.push_back(o);
	}
	sort(offsets.begin(), offsets.end());

	double ans = 1e15;

	auto calc = [&] (double offset) {
		double cur = offset;
		int it = 0;
		vector<P> cps;
		for (int z = 0; z < k; ++z) {
			while (cur >= (ps[it] - ps[(it + 1) % n]).abs()) {
				cur -= (ps[it] - ps[(it + 1) % n]).abs();
				it = it == n - 1 ? 0 : it + 1;
			}
			cps.push_back(L(ps[it], ps[it == n - 1 ? 0 : it + 1]).get_pos(cur));
			cur += onelen;
		}
		double area = 0;
		for (int i = 0; i < k; ++i) {
			area += cps[i] ^ cps[i == k - 1 ? 0 : i + 1];
		}
		area = abs(area);
		ans = min(ans, area);
		return area;
	};

	for (int z = 0; z < (int)offsets.size(); ++z) {
		double L = offsets[z], R = offsets[(z + 1) % offsets.size()];
		int step = 30;
		while (step--) {
			double M1 = (L + L + R) / 3;
			double M2 = (L + R + R) / 3;
			double A1 = calc(M1);
			double A2 = calc(M2);
			if (A1 < A2) R = M2;
			else L = M1;
		}
	}

	cout << fixed << setprecision(20) << ans / 2 << endl;
}
