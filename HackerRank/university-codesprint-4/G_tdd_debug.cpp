#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
const int maxc = 3e5 + 1;
vector<int> r, c;

namespace std { template <> struct hash<pair<int, int>> { long long operator()(const pair<int, int> &p) const  { return p.first * 1ll * 3e5 + p.second; } }; }

struct dinic {
    static const int inf = 1e9, maxv = 6e5 + 10;
    struct edge {
        int to, cap, rev;
        edge() {}
        edge(int a, int b, int c): to(a), cap(b), rev(c) {}
    };
    vector<edge> graf[maxv];
    int s, t, lev[maxv];
    void init(int _s, int _t) {
        for (int i = 0; i < maxv; ++i) graf[i].clear();
        s = _s; t = _t;
    }
    unordered_set<pair<int, int>> ed;
    void add_edge(int a, int b, int cap) {
        if (ed.find(make_pair(a, b)) != ed.end()) return;
        ed.insert(make_pair(a, b));
        // if (b != maxc + maxc + 3 && a != maxc + maxc + 2) cout << "add_edge a = " << a << " b = " << b << endl;
        graf[a].push_back(edge(b, cap, graf[b].size()));
        graf[b].push_back(edge(a, 0, graf[a].size() - 1));
    }
    bool bfs() {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        queue<int> q; q.push(s);
        while (q.size()) {
            int now = q.front(); q.pop();
            for (auto e : graf[now]) if (e.cap > 0 && lev[e.to] == -1) {
                lev[e.to] = lev[now] + 1;
                q.push(e.to);
            }
        }
        return lev[t] != -1;
    }
    int flow(int now, int low) {
        if (now == t || low == 0) return low;
        int ret = 0;
        for (auto &e : graf[now]) if (e.cap > 0 && lev[e.to] == lev[now] + 1) {
            int tmp = flow(e.to, min(e.cap, low - ret));
            e.cap -= tmp; graf[e.to][e.rev].cap += tmp;
            ret += tmp;
        }
        if (ret == 0) lev[now] = -1;
        return ret;
    }
    int maxflow() {
        int ret = 0;
        while (bfs()) ret += flow(s, inf);
        return ret;
    }
    int mx[maxv], my[maxv];
    void build() {
        memset(mx, -1, sizeof(mx)); memset(my, -1, sizeof(my));
        for (int i = 0; i <= maxc; ++i) {
            for (auto e : graf[i]) if (e.to > maxc && e.to != maxc + maxc + 2 && e.cap == 0) {
                mx[i] = e.to;
                my[e.to] = i;
                // cout << "match x = " << i << " y = " << e.to - 1 - maxc << endl;
            }
        }
    } 
    bool vx[maxv], vy[maxv];
    void dfs(int now) {
        if (now <= maxc) {
            vx[now] = true;
            for (auto e : graf[now]) if (e.to > maxc && e.to <= maxc + maxc + 1) {
                if (e.to != mx[now] && !vy[e.to - 1 - maxc]) {
                    dfs(e.to);
                    break;
                }
            }
        } else {
            vy[now - 1 - maxc] = true;
            for (auto e : graf[now]) if (e.to <= maxc) {
                if (e.to == my[now] && !vx[e.to]) {
                    dfs(e.to);
                    break;
                }
            }
        }
    }
    void decompose() {
        build();
        memset(vx, false, sizeof(vx)); memset(vy, false, sizeof(vy));
        for (int i = 0; i <= maxc; ++i) if (mx[i] == -1 && !vx[i]) dfs(i);
        for (int i = 0; i <= maxc; ++i) if (!vx[i]) c.push_back(i);
        for (int i = 0; i <= maxc; ++i) if (vy[i]) r.push_back(i);
    }
} flow;


void add_rect(int y, int xp, int xn) { 
    for (int i = xp; i <= xn; ++i) {
        flow.add_edge(i, y + maxc + 1, 1);
        // cout << "add x = " << i << " y = " << y << endl;
    }
}

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    long long sum, tag;
    segtree(int l, int r) {
        sum = tag = 0;
        if (l == r) lc = rc = nullptr;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r);
    }
    void pull() { sum = lc->sum + rc->sum; }
    void push(int l, int r) {
        if (l == r || tag == 0) return;
        lc->tag += tag; lc->sum += (m - l + 1) * 1ll * tag;
        rc->tag += tag; rc->sum += (r - m + 0) * 1ll * tag;
        tag = 0;
    }
    void dfs(int l, int r, int prv, int now) {
        push(l, r);
        if (l == r) return add_rect(l, prv, now), void();
        if (lc->sum > 0) lc->dfs(l, m, prv, now);
        if (rc->sum > 0) rc->dfs(m + 1, r, prv, now);
    }
    void modify(int l, int r, int ql, int qr, int v) {
        push(l, r);
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) return tag += v, sum += (r - l + 1) * 1ll * v, void();
        lc->modify(l, m, ql, qr, v); rc->modify(m + 1, r, ql, qr, v);
        pull();
    }
#undef m   
} *sgt;

struct event { int pos, l, r, v; };
vector<event> v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    sgt = new segtree(0, maxc);
    int source = maxc + maxc + 2, sink = maxc + maxc + 3;
    flow.init(source, sink);
    for (int i = 0; i < n; ++i) {
        int xl, yl, xr, yr; cin >> xl >> yl >> xr >> yr;
        v[xl].push_back({ xl, yl, yr, 1 });
        v[xr + 1].push_back({ xr, yl, yr, -1 });
    }
    for (int i = 0; i <= maxc; ++i) {
        for (auto e : v[i]) sgt->modify(0, maxc, e.l, e.r, e.v);
        sgt->dfs(0, maxc, i, i);
    } 
        
    // cout << "done" << endl;
    for (int i = 0; i <= maxc; ++i) {
        flow.add_edge(source, i, 1);
        flow.add_edge(i + maxc + 1, sink, 1);
    }
    // cout << "done" << endl;
    // vector<int>     
    int ans = flow.maxflow();
    cout << ans << endl;
    flow.decompose();
    assert(r.size() + c.size() == ans);
    cout << c.size() << endl; 
    if (c.size()) cout << c[0];
    for (int i = 1; i < c.size(); ++i) cout << ' ' << c[i]; cout << endl;
    cout << r.size() << endl;
    if (r.size()) cout << r[0];
    for (int i = 1; i < r.size(); ++i) cout << ' ' << r[i]; cout << endl;
    return 0;
}
