#include <bits/stdc++.h>
using namespace std;
#define double long double

const double pi = acos(-1);
const double eps = 1e-9;
#define sq(x) ((x) * (x))

double sign(double x) {
  if (x > eps) return 1;
  if (x < -eps) return -1;
  return 0;
}

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
  double a, b, c;
  P pa, pb;
  L() : a(0), b(0), c(0), pa(), pb() {}
  L(P pa, P pb) : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb), pa(pa), pb(pb) {}
  double get_ratio(P p) { return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs()); }
};

vector<P> CircleCrossLine(P a, P b, P o, double r) {
  double x = b.x - a.x, y = b.y - a.y, A = sq(x) + sq(y), B = 2 * x * (a.x - o.x) + 2 * y * (a.y - o.y);
  double C = sq(a.x - o.x) + sq(a.y - o.y) - sq(r), d = B * B - 4 * A * C;
  vector<P> t;
  if (d >= -eps) {
    d = max((double)0., d);
    double i = (-B - sqrt(d)) / (2 * A);
    double j = (-B + sqrt(d)) / (2 * A);
    if (i - 1 <= eps && i >= -eps) t.emplace_back(a.x + i * x, a.y + i * y);
    if (j - 1 <= eps && j >= -eps) t.emplace_back(a.x + j * x, a.y + j * y);
  }
  return t;
}

bool SegmentIntersect(P p1, P p2, P p3, P p4) {
  if (max(p1.x, p2.x) + eps < min(p3.x, p4.x) || max(p3.x, p4.x) + eps < min(p1.x, p2.x)) return false;
  if (max(p1.y, p2.y) + eps < min(p3.y, p4.y) || max(p3.y, p4.y) + eps < min(p1.y, p2.y)) return false;
  return sign((p3 - p1) ^ (p4 - p1)) * sign((p3 - p2) ^ (p4 - p2)) <= 0 &&
    sign((p1 - p3) ^ (p2 - p3)) * sign((p1 - p4) ^ (p2 - p4)) <= 0;
}

double AngleDiff(double a, double b) {
  if (b > a) swap(a, b);
  double o = a - b;
  return min(o, 2 * pi - o);
}

double _inmid(double l, double o, double r) {
  return l - eps <= o && o <= r + eps;
}

double InMid(double l, double o, double r) {
  return _inmid(l, o, r) || _inmid(l, o - 2 * pi, r) || _inmid(l, o + 2 * pi, r);
}

void solve() {
  int n, m; 
  double o, r; cin >> n >> m >> o >> r;
  o = o / 360 * (2 * pi);

  P st, dir, v;
  cin >> st.x >> st.y >> dir.x >> dir.y >> v.x >> v.y;
  dir = dir.unit();
  v = v.unit();

  vector<P> ps(n);
  for (int i = 0; i < n; ++i) cin >> ps[i].x >> ps[i].y;
  vector<int> ans(n, 1);

  auto Meow = [&] (P st, P dir, P v, double tlen) {
    L san1(st, st + dir.spin(-o / 2) * r);
    L san2(st, st + dir.spin(o / 2) * r);

    auto InitialIn = [&] (P p) {
      // cout << "test init in p " << p.x << " " << p.y << " dir = " << dir.x << ' ' << dir.y << endl;
      P d = (p - st);
      if (d.abs() > r + eps) return false;
      if (AngleDiff(d.angle(), dir.angle()) > o / 2 + eps) return false;
      return true;
    };
    auto FinalIn = [&] (P p) {
      // cout << "test final in p " << p.x << " " << p.y << " dir = " << dir.x << ' ' << dir.y << endl;
      P d = (p - (st + v * tlen));
      if (d.abs() > r + eps) return false;
      if (AngleDiff(d.angle(), dir.angle()) > o / 2 + eps) return false;
      return true;
    };
    auto SectWithCirc = [&] (L l) {
      auto res = CircleCrossLine(l.pa, l.pb, st, r);
      for (auto &p : res) {
        if (AngleDiff((p - st).angle(), dir.angle()) <= o / 2 + eps) return true;
      }
      return false;
    };

    for (int i = 0; i < n; ++i) {
      L l(ps[i], ps[i] - v * tlen);
      if (SegmentIntersect(l.pa, l.pb, san1.pa, san1.pb) || SegmentIntersect(l.pa, l.pb, san2.pa, san2.pb)) {
        // cerr << "i = " << i << " seg" << endl;
        ans[i] = 0;
      } else if (InitialIn(ps[i]) || FinalIn(ps[i])) {
        // cerr << "i = " << i << " init" << endl;
        ans[i] = 0;
      } else if (SectWithCirc(l)) {
        // cerr << "i = " << i << " circ" << endl;
        ans[i] = 0;
      }
    }
  };

  vector<tuple<int, double, double>> evs(m);
  for (int i = 0; i < m; ++i) {
    int a; double b, c; cin >> a >> b >> c;
    evs[i] = make_tuple(a, b, c);
  }
  // evs.emplace_back(1, (double)1000 * 2000 * 2000 * 10, 0);

  auto AngleDiff = [&](P a, P b) {
    return acos(a * b / (a.abs() * b.abs()));
  };

  for (int i = 0; i < n; ++i) {
    P dd = ps[i] - st;
    double dist = dd.abs();
    double odiff = AngleDiff(dd, dir);
    // cerr << "init dist odiff " << dist << ' ' << odiff << endl;
    // cerr << "o / 2 " << o / 2 << endl;
    if (dist < r + eps && odiff <= o / 2 + eps) {
      ans[i] = 0;
    } else if (dist < eps) {
      ans[i] = 0;
    }
  }

  double nt = 0;
  double total_spin_view = 0;
  double total_spin_dir = 0;
  P odir = dir;
  P ov = v;
  for (auto &[p, t, alp] : evs) {
    alp = alp / 360 * (2 * pi);

    Meow(st, dir, v, (t - nt));

    st = st + v * (t - nt);
    nt = t;

    if (p == 1) {
      // spin dir
      double dl = dir.angle() - o / 2;
      double dr = dir.angle() + o / 2;
      double nl = dl - alp;
      double nr = dr - alp;
      for (int i = 0; i < n; ++i) {
        double z = (ps[i] - st).angle();
        if ((ps[i] - st).abs() >= r + eps) continue;
        if (InMid(nl, z, dl) || InMid(nr, z, dr) || InMid(dl, z, dr) || InMid(nl, z, nr)) {
          ans[i] = 0;
        }
      }
      // cout << "dir = " << dir.x << ' ' << dir.y << endl;
      total_spin_view += alp;
      dir = odir.spin(-total_spin_view);
      // cout << "dir = " << dir.x << ' ' << dir.y << endl;
    } else {
      // spin v
      total_spin_dir += alp;
      v = ov.spin(-total_spin_dir);
    }

    for (int i = 0; i < n; ++i) {
      P dd = ps[i] - st;
      double dist = dd.abs();
      double odiff = AngleDiff(dd, dir);
      // cerr << "init dist odiff " << dist << ' ' << odiff << endl;
      // cerr << "o / 2 " << o / 2 << endl;
      if (dist < r + eps && odiff <= o / 2 + eps) {
        ans[i] = 0;
      } else if (dist < eps) {
        ans[i] = 0;
      }
    }

    // cerr << "new st nt v " << st.x << ' ' << st.y << ' ' << dir.x << ' ' << dir.y << ' ' << v.x << ' ' << v.y << endl;
  }

  for (int i : ans) cout << i;
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, T = 0;
  cin >> t; 
  while (t--) {
    ++T;
    cout << "Case #" << T << ": ";
    solve();
  }
}
