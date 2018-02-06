#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
using type = long double;
const type inf = 1e9, eps = 1e-8;

struct point {
    type x, y;
    point(type _x, type _y): x(_x), y(_y) {}
    point(): x(0), y(0) {}
    bool operator<(const point &p) const { return x == p.x ? y > p.y : x < p.x; }
    bool operator>(const point &p) const { return x == p.x ? y < p.y : x > p.x; }
};

struct line {
    type m, k, x;
    bool vert;
    line(point a, point b) {
        if (a.x == b.x) {
            vert = true;
            x = a.x;
            return;
        }
        vert = false;
        m = (a.y - b.y) / (a.x - b.x);
        k = a.y - m * a.x;
    }
    point intersect(line &rhs) {
        if (vert && rhs.vert) return point(-inf, -inf);
        if (vert) return point(x, rhs.m * x + rhs.k);
        if (rhs.vert) return point(rhs.x, m * rhs.x + k);
        if (fabs(rhs.m - m) < eps) return point(-inf, -inf);
        type x = (rhs.k - k) / (m - rhs.m);
        type y = m * x + k;
        return point(x, y);
    }
    bool on(point p) {
        return fabs(p.y - (m * p.x + k)) < eps;
    }
    line() {}
};

point st;
string i2n[maxn];
map<string, int> n2i;
line l[maxn];
vector<pair<point, int>> p[maxn];
int cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r;
    long long n; cin >> r >> n;
    cin >> st.x >> st.y;
    for (int i = 0; i < r; ++i) {
        cin >> i2n[i];
        point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        l[i] = line(a, b);
    }
    for (int i = 0; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
            point is = l[i].intersect(l[j]);
            if (is.x == -inf) continue;
            p[i].push_back(make_pair(is, j)); p[j].push_back(make_pair(is, i));
        }
    }
    for (int i = 0; i < r; ++i) sort(p[i].begin(), p[i].end());
    int now = -1;
    for (int i = 0; i < r; ++i) if (l[i].on(st)) now = i;
    assert(now >= 0);
    int dir = 0;
    point pos = st;
    int turn = 0, to = -1, pst = now;
    memset(cnt, -1, sizeof(cnt));
    // for (int i = 0; i < r; ++i) {
        // for (auto j : p[i]) cout << j.second << ": " << j.first.x << ' ' << j.first.y << ", "; cout << endl;
    // }
    while (true) {
        // cout << "now = " << now << " dir = " << dir << endl;
        // cout << "pos = " << pos.x << ' ' << pos.y << endl;
        cnt[now] = turn;
        // cout << "cnt[now] = " << cnt[now] << endl;
        if (dir == 0) {
            vector<pair<point, int>>::iterator it;
            if (l[now].vert) it = --upper_bound(p[now].begin(), p[now].end(), make_pair(point(l[now].x, pos.y), r));
            else it = upper_bound(p[now].begin(), p[now].end(), make_pair(pos, r));
            if (it == p[now].end()) return cout << i2n[now] << endl, 0;
            to = it->second;
            pos = it->first;
            if (l[now].m <= 0 && l[to].m >= 0 || l[to].vert) dir = 1;
        } else {
            vector<pair<point, int>>::iterator it;
            if (l[now].vert) it = upper_bound(p[now].begin(), p[now].end(), make_pair(point(l[now].x, pos.y), r));
            else it = lower_bound(p[now].begin(), p[now].end(), make_pair(pos, -1));
            if (it == p[now].begin()) return cout << i2n[now] << endl, 0;
            --it;
            to = it->second;
            pos = it->first;
            if (l[now].m >= 0 && l[to].m <= 0 || l[to].vert) dir = 0;
        }
        if (turn == pst) return cout << i2n[to] << endl, 0;
        if (to == now) break;
        now = to;
        ++turn;
    }
    // cout << "turn = " << turn << endl;
    for (int i = 0; i < r; ++i) if (cnt[i] == n % turn) return cout << i2n[i] << endl, 0;
}
