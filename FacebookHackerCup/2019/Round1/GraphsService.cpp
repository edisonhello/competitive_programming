#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        cout << "Case #" << T << ": ";
        int n, m; cin >> n >> m;
        vector<vector<int>> d(n + 2, vector<int>(n + 2, 1000000000));
        for (int i = 1; i <= n; ++i) d[i][i] = 0;
        vector<tuple<int, int, int>> e;
        while (m--) {
            int u, v, w; cin >> u >> v >> w;
            e.emplace_back(u, v, w);
            d[u][v] = d[v][u] = w;
        }
        for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        bool no = false;
        for (auto &ee : e) {
            if (d[get<0>(ee)][get<1>(ee)] != get<2>(ee)) no = true;
        }
        if (no) cout << "Impossible" << endl;
        else {
            cout << e.size() << endl;
            for (auto &ee : e) {
                cout << get<0>(ee) << " " << get<1>(ee) << " " << get<2>(ee) << endl;
            }
        }
    }
}
