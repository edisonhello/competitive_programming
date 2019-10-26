#include <bits/stdc++.h>
using namespace std;

struct node {
    node *l, *r;
    double a, b;
    node() : l(0), r(0), a(0), b(111111) {}
    bool update(int x1, int x2, double sl, double of) {
        int res = (int)(x1 * sl + of < x1 * a + b) + (int)(x2 * sl + of < x2 * a + b);
        // cerr << "update " << x1 << " " << x2 << " res = " << res << endl;
        if (res == 0) return true;
        if (res == 1) return false;
        a = sl, b = of;
        return true;
    }
    void force_update(double x, double sl, double of) {
        if (sl * x + of < a * x + b) a = sl, b = of;
    }
    double get(double x) { return x * a + b; }
} *root;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r - 1) return;
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid, r);
}

void update(node *now, int l, int r, int ml, int mr, double sl, double of) {
    if (mr <= l || r <= ml) return;
    if (ml <= l && r <= mr && now->update(l, r, sl, of)) return;
    if (l == r - 1) return now->force_update(l + 0.5, sl, of), void();
    update(now->l, l, mid, ml, mr, sl, of);
    update(now->r, mid, r, ml, mr, sl, of);
}

double query(node *now, int l, int r, int x) {
    if (l == r - 1) return now->get(x + 0.5);
    if (x < mid) return min(now->get(x + 0.5), query(now->l, l, mid, x));
    else return min(now->get(x + 0.5), query(now->r, mid, r, x));
}

void del(node *now) {
    if (now->l) del(now->l);
    if (now->r) del(now->r);
    delete now;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int w, h; cin >> w >> h;
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
        v.emplace_back(w, 0); ++n;
        build(root = new node(), 0, h);
        for (int i = 1; i < n; ++i) {
            int l = v[i].second, r = v[i - 1].second;
            int ly = w - v[i].first, ry = w - v[i - 1].first;
            if (l == r) continue;
            if (r < l) swap(l, r), swap(ly, ry);
            double sl = (double)(ry - ly) / (r - l);
            // cerr << "At " << l << " " << ly << " " << r << " " << ry << endl;
            // cerr << "Update " << 0 << " " << h << " " << l << " " << r << " " << sl << " " << ly - l * sl << endl;
            update(root, 0, h, l, r, sl, ly - l * sl);
        }
        double ans = 0;
        for (int i = 0; i < h; ++i) ans += query(root, 0, h, i);
        // for (int i = 0; i < h; ++i) cerr << "ans of " << i + 0.5 << " is " << query(root, 0, h, i) << endl;
        cout << fixed << setprecision(12) << ans << '\n';
        del(root);
    }
}
