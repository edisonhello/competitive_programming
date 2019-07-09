#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

struct node {
    node *l, *r;
    int tag, mn, at;
    node() : l(0), r(0), tag(0), mn(0), at(0) {}
    void pull() {
        if (l->mn <= r->mn) {
            mn = l->mn;
            at = l->at;
        } else {
            mn = r->mn;
            at = r->at;
        }
    }
    void push() {
        l->add(tag);
        r->add(tag);
        tag = 0;
    }
    void add(int v) {
        tag += v;
        mn += v;
    }
} *root;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r) {
        now->at = l;
        return;
    }
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid + 1, r);
    now->pull();
}
void modify(node *now, int l, int r, int ml, int mr, int v) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) {
        now->add(v);
        return;
    }
    now->push();
    modify(now->l, l, mid, ml, mr, v);
    modify(now->r, mid + 1, r, ml, mr, v);
    now->pull();
}
pair<int, int> query(node *now, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return make_pair(INT_MAX, -1);
    if (ql <= l && r <= qr) return make_pair(now->mn, now->at);
    pair<int, int> L = query(now->l, l, mid, ql, qr);
    pair<int, int> R = query(now->r, mid + 1, r, ql, qr);
    if (L.first <= R.first) return L;
    return R;
}
void del(node *now) {
    if (now->l) del(now->l);
    if (now->r) del(now->r);
    delete now;
}

int pw2[1000006];
int main() {
    pw2[0] = 1;
    for (int i = 1; i <= 1000000; ++i) pw2[i] = pw2[i - 1] * 2 % mod;
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        cout << "Case #" << T << ": ";
        int n, k; cin >> n >> k;
        string s; cin >> s; s = " " + s;
        build(root = new node(), 1, n);
        int co = 0;
        for (int i = n; i >= 1; --i) {
            if (s[i] == 'A') modify(root, 1, n, i, n, 1);
            else modify(root, 1, n, i, n, -1);
            pair<int, int> t;
            while (t = query(root, 1, n, i, n), t.first < -k) {
                modify(root, 1, n, i, n, 2);
                s[i] = 'A';
                co += pw2[i];
                co %= mod;
            }
        }
        cout << co << endl;
        del(root);
    }
}
