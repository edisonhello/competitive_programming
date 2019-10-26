#include <bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> G[100005];
int pa[100005];

void dfs1(int now, int p) {
    pa[now] = p;
    for (int i : G[now]) if (i != p) dfs1(i, now);
}

int xo, mx;

bool dfs2(int now, int pa, int to) {
    if (now == to) {
        xo ^= a[now];
        mx = max(mx, a[now]);
        return true;
    }
    for (int i : G[now]) if (i != pa) {
        if (dfs2(i, now, to)) {
            xo ^= a[now];
            mx = max(mx, a[now]);
            return true;
        }
    }
    return false;
}
void dfs3(int now) {
    xo ^= a[now];
    mx = max(mx, a[now]);
    for (int i : G[now]) if (i != pa[now]) dfs3(i);
}
bool dfs4(int now, int pa, int to, int v) {
    if (now == to) {
        a[now] = v;
        return true;
    }
    for (int i : G[now]) if (i != pa) {
        if (dfs4(i, now, to, v)) {
            a[now] = v;
            return true;
        }
    }
    return false;
}
void dfs5(int now, int v) {
    a[now] = v;
    for (int i : G[now]) if (i != pa[now]) dfs5(i, v);
}

void query(const int n, int u, int v) {
    xo = mx = 0;
    dfs2(u, u, v);
    cout << xo << " " << mx << endl;
}
void query(const int n, int u) {
    xo = mx = 0;
    dfs3(u);
    cout << xo << " " << mx << endl;
}
void modify(const int n, int u, int v, int w) {
    dfs4(u, u, v, w);
}
void modify(const int n, int u, int w) {
    dfs5(u, w);    
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
        dfs1(1, 0);
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
    }
}
