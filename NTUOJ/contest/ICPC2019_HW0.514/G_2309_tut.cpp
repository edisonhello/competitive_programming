#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct edge {
        double f;
        int v, r;
    };
    vector<edge> G[234];
    int lev[234], idx[234];
    void init() {
        for (int i = 0; i < 234; ++i) G[i].clear();
    }
    void add_edge(int u, int v, double f) {
        G[u].push_back(edge{f, v, G[v].size()});
        G[v].push_back(edge{0, u, G[u].size() - 1});
        // cerr << " add edge " << u << " -> " << v << " : " << f << endl;
    }
    bool bfs(int s, int t) {
        memset(lev, 0, sizeof(lev));
        bitset<234> vis; vis[s] = 1;
        queue<int> q; q.push(s);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (edge &e : G[x]) if (!vis[e.v] && e.f > 1e-8) {
                lev[e.v] = lev[x] + 1;
                q.push(e.v);
                vis[e.v] = 1;
            }
        }
        return lev[t];
    }
    double dfs(int s, double le, int t) {
        if (s == t) return le;
        double gt = 0;
        for (int &i = idx[s]; i < (int)G[s].size(); ++i) {
            if (G[s][i].f > 1e-8 && lev[G[s][i].v] == lev[s] + 1) {
                double z = dfs(G[s][i].v, min(le, G[s][i].f), t);
                gt += z;
                le -= z;
                G[s][i].f -= z;
                G[G[s][i].v][G[s][i].r].f += z;
                if (le < 1e-8) break;
            }
        }
        return gt;
    }
    double flow(int s, int t) {
        double f = 0;
        while (bfs(s, t)) { memset(idx, 0, sizeof(idx)); f += dfs(s, 1e10, t); }
        // cerr << "flow: " << f << endl;
        return f;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<long long> a(n), deg(n, 0);
        for (long long &i : a) cin >> i;
        vector<pair<int, int>> e;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(a[i], a[j]) != 1) {
                    e.emplace_back(i, j);
                    ++deg[i], ++deg[j];
                    // cerr << "A edge in " << i << " " << j << endl;
                }
            }
        }
        auto run = [&] (const double rt) -> double {
            // cerr << "Run" << endl;
            Dinic svr;
            for (int i = 0; i < n; ++i) svr.add_edge(n, i, e.size());
            for (int i = 0; i < n; ++i) svr.add_edge(i, n + 1, e.size() + 2 * rt - deg[i]);
            for (auto &ee : e) svr.add_edge(ee.first, ee.second, 1), svr.add_edge(ee.second, ee.first, 1);
            return e.size() * n - svr.flow(n, n + 1);
        };
        double L = 0, R = e.size();
        int cnt = 100; while (cnt--) {
            // cerr << L << " <-> " << R << endl;
            double M = (L + R) / 2;
            if (run(M) > 0) L = M;
            else R = M;
        }
        double diff = 1e10;
        int x = -1, b = -1;
        for (int i = 1; i <= n; ++i) {
            if (abs(L * i - round(L * i)) < diff) {
                diff = abs(L * i - round(L * i));
                b = i;
                x = round(L * i);
            }
        }
        cout << x << "/" << b << '\n';
    }
}
