#include <bits/stdc++.h>
using namespace std;

struct node {
    node *l, *r;
    int sz, xo, mx, tg;
    node() : l(0), r(0), sz(1), xo(0), mx(0), tg(-1) {}
    void pull() {
        sz = l->sz + r->sz;
        xo = l->xo ^ r->xo;
        mx = max(l->mx, r->mx);
    }
    void add(int x) {
        tg = x;
        xo = sz & 1 ? x : 0;
        mx = x;
    }
    void push() {
        if (tg != -1) {
            l->add(tg);
            r->add(tg);
            tg = -1;
        }
    }
} *root;

pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b) {
    return make_pair(a.first ^ b.first, max(a.second, b.second));
}

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r) return;
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid + 1, r);
    now->pull();
}
void modify(node *now, int l, int r, int ml, int mr, int x) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) return now->add(x), void();
    now->push();
    modify(now->l, l, mid, ml, mr, x);
    modify(now->r, mid + 1, r, ml, mr, x);
    now->pull();
}
pair<int, int> query(node *now, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return pair<int, int>(0, 0);
    if (ql <= l && r <= qr) return make_pair(now->xo, now->mx);
    now->push();
    return query(now->l, l, mid, ql, qr) + query(now->r, mid + 1, r, ql, qr);
}
void del(node *now) {
    if (now->l) del(now->l);
    if (now->r) del(now->r);
    delete now;
}

int a[100005];
vector<int> G[100005];
int pa[19][100005], pos[100005], epos[100005], bel[100005], cpos[100005], cpa[100005], lwch[100005], dep[100005], cc, cn;

void dfs1(int now, int p, int d) {
    pa[0][now] = p;
    dep[now] = d;
    lwch[now] = now;
    for (int i = 1; i < 19; ++i) pa[i][now] = pa[i - 1][pa[i - 1][now]];
    for (int i : G[now]) if (i != p) {
        dfs1(i, now, d + 1);
        if (dep[lwch[now]] < dep[lwch[i]]) {
            lwch[now] = lwch[i];
        }
    }
}

void dfs2(int now, int p, int nowc, int nowp) {
    pos[now] = epos[now] = ++cn;
    bel[now] = nowc;
    cpos[now] = nowp;
    for (int i : G[now]) if (i != p && lwch[i] == lwch[now]) {
        dfs2(i, now, nowc, nowp + 1);
        epos[now] = max(epos[now], epos[i]);
    }
    for (int i : G[now]) if (i != p) if (lwch[i] != lwch[now]) {
        cpa[cc + 1] = now;
        dfs2(i, now, ++cc, 1);
        epos[now] = max(epos[now], epos[i]);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 18; i >= 0; --i) if ((dep[v] - dep[u]) & (1 << i)) v = pa[i][v];
    if (u == v) return u;
    for (int i = 18; i >= 0; --i) if (pa[i][u] != pa[i][v]) u = pa[i][u], v = pa[i][v];
    return pa[0][u];
}

void query(const int n, int u, int v) {
    int xo = 0, mx = 0;
    auto update = [&] (pair<int, int> p) -> void { xo ^= p.first, mx = max(mx, p.second); };
    int g = lca(u, v);
    while (bel[u] != bel[g]) {
        update(query(root, 1, n, pos[u] - cpos[u] + 1, pos[u]));
        u = cpa[bel[u]];
    }
    update(query(root, 1, n, pos[g], pos[u]));
    while (bel[v] != bel[g]) {
        update(query(root, 1, n, pos[v] - cpos[v] + 1, pos[v]));
        v = cpa[bel[v]];
    }
    update(query(root, 1, n, pos[g], pos[v]));
    update(query(root, 1, n, pos[g], pos[g]));
    cout << xo << " " << mx << '\n';
}
void query(const int n, int u) {
    pair<int, int> q = query(root, 1, n, pos[u], epos[u]);
    cout << q.first << " " << q.second << '\n';
}
void modify(const int n, int u, int v, int w) {
    int g = lca(u, v);
    while (bel[u] != bel[g]) {
        modify(root, 1, n, pos[u] - cpos[u] + 1, pos[u], w);
        u = cpa[bel[u]];
    }
    modify(root, 1, n, pos[g], pos[u], w);
    while (bel[v] != bel[g]) {
        modify(root, 1, n, pos[v] - cpos[v] + 1, pos[v], w);
        v = cpa[bel[v]];
    }
    modify(root, 1, n, pos[g], pos[v], w);
}
void modify(const int n, int u, int w) {
    modify(root, 1, n, pos[u], epos[u], w);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, 0, 0);
        dfs2(1, 0, ++cc, 1);
        build(root = new node(), 1, n);
        for (int i = 1; i <= n; ++i) modify(root, 1, n, pos[i], pos[i], a[i]);
        int q; cin >> q; while (q--) {
            int c; cin >> c;
            if (c == 1) {
                int u, v; cin >> u >> v;
                query(n, u, v);
            } else if (c == 2) {
                int u; cin >> u;
                query(n, u);
            } else if (c == 3) {
                int u, v, w; cin >> u >> v >> w;
                modify(n, u, v, w);
            } else {
                int u, w; cin >> u >> w;
                modify(n, u, w);
            }
        }
        for (int i = 1; i <= n; ++i) G[i].clear();
        cc = cn = 0;
        del(root);
    }
}
