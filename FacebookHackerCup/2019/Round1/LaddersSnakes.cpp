#include <bits/stdc++.h>
using namespace std;

struct dinic {
    static const int inf = 1e9;
    static const int maxn = 105;
    struct edge {
        int dest, cap, rev;
        edge(int d, int c, int r): dest(d), cap(c), rev(r) {}
    };
    vector<edge> g[maxn];
    int qu[maxn], ql, qr;
    int lev[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            g[i].clear();
    }
    void add_edge(int a, int b, int c) {
        // if (c) cerr << "add_edge " << a << " " << b << " " << c << endl;
        g[a].emplace_back(b, c, g[b].size() - 0);
        g[b].emplace_back(a, 0, g[a].size() - 1);
    }
    void view_edge() {
        for (int i = 0; i < maxn; ++i) if (g[i].size()) {
            for (edge &e : g[i]) cerr << "edge from " << i << " to " << e.dest << " left " << e.cap << endl;
        }
    }
    bool bfs(int s, int t) {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        ql = qr = 0;
        qu[qr++] = s;
        while (ql < qr) {
            int x = qu[ql++];
            for (edge &e : g[x]) if (lev[e.dest] == -1 && e.cap > 0) {
                lev[e.dest] = lev[x] + 1;
                qu[qr++] = e.dest;
            }
        }
        return lev[t] != -1;
    }
    int dfs(int x, int t, int flow) {
        if (x == t) return flow;
        int res = 0;
        for (edge &e : g[x]) if (e.cap > 0 && lev[e.dest] == lev[x] + 1) {
            int f = dfs(e.dest, t, min(e.cap, flow - res));
            res += f;
            e.cap -= f;
            g[e.dest][e.rev].cap += f;
        }
        if (res == 0) lev[x] = -1;
        return res;
    }
    int operator()(int s, int t) {
        int flow = 0;
        for (; bfs(s, t); flow += dfs(s, t, inf));
        return flow;
    }
};

struct node {
    node *l, *r;
    int pri, sz, val;
    int lz() { return l ? l->sz : 0; }
    int rz() { return r ? r->sz : 0; }
    void pull() { sz = lz() + rz() + 1; }
    node(int v = 0) : l(0), r(0), pri(rand()), sz(1), val(v) {}
};
void printtree(node *now) {
    if (!now) return;
    if (now->l) cerr << "(", printtree(now->l), cerr << ")";
    cerr << now->val;
    if (now->r) cerr << "(", printtree(now->r), cerr << ")";
}

node *merge(node *a, node *b) {
    if (!a) return b; if (!b) return a;
    if (a->pri > b->pri) return a->r = merge(a->r, b), a->pull(), a;
    else return b->l = merge(a, b->l), b->pull(), b;
}
void split_val(node *now, int val, node *&a, node *&b) {
    if (!now) return a = b = 0, void();
    if (now->val <= val) a = now, split_val(now->r, val, a->r, b);
    else b = now, split_val(now->l, val, a, b->l);
    now->pull();
}
void split_sz(node *now, int sz, node *&a, node *&b) {
    if (!now) return a = b = 0, void();
    if (now->lz() >= sz) b = now, split_sz(now->l, sz, a, b->l);
    else a = now, split_sz(now->r, sz - 1 - now->lz(), a->r, b);
    now->pull();
}

int sz(node *now) {
    if (now) return now->sz;
    return 0;
}

void del(node *now) {
    if (now->l) del(now->l);
    if (now->r) del(now->r);
    delete now;
}

void insert(node *&root, int l, int r) {
    // cerr << "before insert " << l << " " << r << " : ", printtree(root); cerr << endl;
    node *a, *b, *c, *d;
    split_val(root, l - 1, a, d);
    split_val(d, r, b, c);
    if (sz(a) & 1) a = merge(a, new node(l - 1));
    if (sz(c) & 1) c = merge(new node(r + 1), c);
    if (b) del(b);
    root = merge(a, c);
    // cerr << "after insert " << l << " " << r << " : ", printtree(root); cerr << endl;
}
int calc(node *now) {
    // cerr << "calc: ", printtree(now); cerr << endl;
    assert((sz(now) & 1) == 0);
    int ans = 0;
    while (sz(now)) {
        node *a, *b, *c, *d;
        split_sz(now, 1, a, d);
        split_sz(d, 1, b, c);
        ans += b->val - a->val + 1;
        delete a;
        delete b;
        now = c;
    }
    return ans;
}

ostream& operator << (ostream &o, tuple<int, int, int> t) {
    o << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
    return o;
}

int main() {
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        cout << "Case #" << T << ": ";
        int n, h; cin >> n >> h;
        vector<tuple<int, int, int>> ld;
        for (int i = 0; i < n; ++i) {
            int x, a, b; cin >> x >> a >> b;
            ld.emplace_back(x, a, b);
        }
        dinic sv;
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
            int l = max(get<1>(ld[i]), get<1>(ld[j])), r = min(get<2>(ld[i]), get<2>(ld[j]));
            // cerr << ld[i] << " " << ld[j] << " intersect at " << l << " " << r << endl;
            if (l >= r) continue;
            l = max(l, 1), r = min(r, h - 1);
            // build(root = new node(), 1, h - 1);
            node *root = merge(new node(l), new node(r - 1));
            for (int k = 0; k < n; ++k) if (k != i && k != j) {
                if ((get<0>(ld[i]) < get<0>(ld[k]) && get<0>(ld[k]) < get<0>(ld[j])) || (get<0>(ld[j]) < get<0>(ld[k]) && get<0>(ld[k]) < get<0>(ld[i]))) {
                    int ll = max(l, get<1>(ld[k])), rr = min(r, get<2>(ld[k]));
                    if (ll >= rr) continue;
                    // cerr << ld[k] << " blocks " << ll << " to " << rr << endl;
                    insert(root, ll, rr - 1);
                }
            }
            int wei = calc(root);
            sv.add_edge(i, j, wei);
            sv.add_edge(j, i, wei);
            // cerr << "between " << i << " " << j << " , wei = " << wei << endl;
        }
        for (int i = 0; i < n; ++i) if (get<1>(ld[i]) == 0) sv.add_edge(n, i, 1e8);
        for (int i = 0; i < n; ++i) if (get<2>(ld[i]) == h) sv.add_edge(i, n + 1, 1e8);
        int ans = sv(n, n + 1);
        // sv.view_edge();
        if (ans >= 1e8) cout << -1 << endl;
        else cout << ans << endl;
    }
}
