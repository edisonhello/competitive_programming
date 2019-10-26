#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1000000007;
 
vector<int> g[200005];
int d[3][200005];
 
void dfs(int now, int pa, int nd, int id) {
    d[id][now] = nd;
    for (int i : g[now]) if (i != pa) {
        dfs(i, now, nd + 1, id);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool no = false;
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() > 3u) no = true;
            // cerr << "g[" << i << "].size() = " << g[i].size() << endl;
        }
        if (no) {
            cout << "-1" << endl;
            for (int i = 1; i <= n; ++i) g[i].clear();
            continue;
        }
        dfs(1, 0, 0, 0);
        int mx = max_element(d[0], d[0] + n + 1) - d[0];
        dfs(mx, 0, 0, 1);
        int mx2 = max_element(d[1], d[1] + n + 1) - d[1];
        dfs(mx2, 0, 0, 2);
        int anst = 10000000, id = 0;
        for (int i = 1; i <= n; ++i) if (g[i].size() < 3u) {
            int lv = max(d[1][i], d[2][i]);
            if (lv < anst) {
                anst = lv;
                id = i;
            }
        }
        int ans = 1;
        for (int i = 0; i <= anst; ++i) {
            ans = (ans * 2) % mod;
        }
        ans = (ans - 1 - n + mod) % mod;
        cout << id << " " << ans << '\n';
 
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i <= n; ++i) d[0][i] = d[1][i] = d[2][i] = 0;
    }
}
