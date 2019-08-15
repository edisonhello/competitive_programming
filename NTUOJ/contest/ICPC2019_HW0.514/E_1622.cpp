#include <bits/stdc++.h>
using namespace std;

string mp[1005];
int id[1005][1005];
vector<int> G[1000006];
int dn[1000006], lw[1000006], sz[1000006], nt, yey, yey2;

void dfs(int now, int pa) {
    // cerr << "dfs " << now << " at time " << nt + 1 << endl;
    dn[now] = lw[now] = ++nt;
    sz[now] = 1;
    int cut = 0;
    vector<int> szs;
    for (int i : G[now]) if (!dn[i]) {
        dfs(i, now);
        lw[now] = min(lw[now], lw[i]);
        sz[now] += sz[i];
        if (lw[i] >= dn[now] && pa != -1) {
            ++cut;
            szs.push_back(sz[i]);
        }
    } else lw[now] = min(lw[now], dn[i]);
    if (cut) {
        ++yey;
        int zz = 0;
        for (int i = 1; i < (int)szs.size(); ++i) zz += szs[i];
        yey2 = min(yey2, zz);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        int iid = 0;
        for (int i = 0; i < n; ++i) cin >> mp[i];
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) id[i][j] = iid++;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (i && mp[i][j] == '#' && mp[i - 1][j] == '#') {
                G[id[i - 1][j]].push_back(id[i][j]);
                G[id[i][j]].push_back(id[i - 1][j]);
            }
            if (j && mp[i][j] == '#' && mp[i][j - 1] == '#') {
                G[id[i][j - 1]].push_back(id[i][j]);
                G[id[i][j]].push_back(id[i][j - 1]);
            }
        }
        yey2 = 1000000000;
        int cla = 0, lai = -1;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (mp[i][j] == '#') ++cla, lai = id[i][j];
        if (cla <= 2) { cout << -1 << '\n'; }
        else {
            dfs(lai, -1);
            if (yey == 1) cout << yey2 + 1 << '\n';
            else if (yey) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        for (int i = 0; i < iid; ++i) G[i].clear();
        for (int i = 0; i < iid; ++i) dn[i] = 0;
        for (int i = 0; i < iid; ++i) lw[i] = 0;
        nt = yey = 0;
    }
}
