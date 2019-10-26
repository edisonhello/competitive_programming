#include <bits/stdc++.h>
using namespace std;

struct node {
    node *l, *r;
    long long sum;
    node() : l(0), r(0), sum(0) {}
    node(node *z) : l(z->l), r(z->r), sum(z->sum) {}
} *root[150005];

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r) return;
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid + 1, r);
}
void modify(node *now, int l, int r, int mx, int v) {
    if (l == r) {
        now->sum += v;
        return;
    }
    if (mx <= mid) modify(now->l = new node(now->l), l, mid, mx, v);
    else modify(now->r = new node(now->r), mid + 1, r, mx, v);
    now->sum = now->l->sum + now->r->sum;
}
long long query(node *nl, node *nr, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return nr->sum - nl->sum;
    if (qr < l || r < ql) return 0;
    return query(nl->l, nr->l, l, mid, ql, qr) + query(nl->r, nr->r, mid + 1, r, ql, qr);
}

long long a[150005], b[150005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    build(root[0] = new node(), 1, n);
    for (int i = 1; i <= n; ++i) modify(root[i] = new node(root[i - 1]), 1, n, lower_bound(b + 1, b + n + 1, a[i]) - b, a[i]);
    while (m--) {
        int l, r; cin >> l >> r;
        long long x = 0;
        while (true) {
            // cerr << "id to = " << upper_bound(b + 1, b + n + 1, x + 1) - b << endl;
            long long y = query(root[l - 1], root[r], 1, n, 1, upper_bound(b + 1, b + n + 1, x + 1) - b - 1);
            // cerr << "y = " << y << endl;
            if (x == y) break;
            x = y;
        }
        cout << x + 1 << '\n';
    }
}
