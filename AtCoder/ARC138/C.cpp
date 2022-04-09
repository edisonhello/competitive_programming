#include <bits/stdc++.h>
using namespace std;

struct node {
    node *l, *r;
    int pri, sum, mn, val, sz;
    node(int v) : l(0), r(0), pri(rand()), sum(v), mn(v), val(v), sz(1) {}
    int lsz() { return l ? l->sz : 0; }
    int rsz() { return r ? r->sz : 0; }
    int lsum() { return l ? l->sum : 0; }
    int rsum() { return r ? r->sum : 0; }
    int lmn() { return l ? l->mn : 1'000'000'000; }
    int rmn() { return r ? r->mn : 1'000'000'000; }
    void pull() {
        sum = lsum() + rsum() + 1;
        sz = 1 + lsz() + rsz();
        mn = min(min(lmn(), lsum() + val), lsum() + val + rmn());
    }
};

node *merge(node *a, node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->pri > b->pri) {
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void split_sz(node *root, int sz, node *&a, node *&b) {
    if (!root) {
        a = b = 0;
        return;
    }
    if (root->lsz() < sz) {
        split_sz(root->r, sz - root->lsz() - 1, root->r, b);
        a = root;
    } else {
        split_sz(root->l, sz, a, root->l);
        b = root;
    }
    root->pull();
}

int main() {
    int n; cin >> n;

    vector<tuple<int, int, int>> v(n);
    node *root = 0;
    for (int i = 0; i < n; ++i) {
        int z; cin >> z;
        v[i] = make_tuple(z, i, -1);
    }

    sort(v.begin(), v.end());
    int64_t sum = 0;
    for (int i = 0; i < n / 2; ++i) get<2>(v[i]) = 1;
    for (int i = n / 2; i < n; ++i) sum += get<0>(v[i]);

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return get<1>(a) < get<1>(b);
    });

    for (int i = 0; i < n; ++i) {
        root = merge(root, new node(get<2>(v[i])));
    }

    for (int k = 0; k < n; ++k) {
        if (root->mn >= 0) {
            cout << k << ' ' << sum << endl;
            exit(0);
        }

        node *a, *b;
        split_sz(root, 1, a, b);
        root = merge(b, a);
    }

    exit(1);
}