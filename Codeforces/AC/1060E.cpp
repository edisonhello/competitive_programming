#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int d[maxn][2];
vector<int> g[maxn];
long long ans;

void dfs1(int now, int pa) {
    d[now][0] = 1;
    for (int i : g[now]) {
         if (i == pa) continue;
         dfs1(i, now);
         d[now][1] += d[i][0];
         d[now][0] += d[i][1];
    }
}

void dfs2(int now, int pa, int d0, int d1) {
    int s0 = 0, s1 = 0;
    for (int i : g[now]) {
        if (i == pa) continue;
        s0 += d[i][0];
        s1 += d[i][1];
    }
    ans += 1ll * d[now][0] * d1;
    // cout << now << " " << d0 << " " << d1 << endl;
    ans += 1ll * d1 * d[now][1];
    long long oo = 0;
    for (int i : g[now]) {
        if (i == pa) continue;
        oo += 1ll * d[i][0] * (d[now][1] - d[i][0]);
        dfs2(i, now, d1 + s0 - d[i][0], d0 + s1 + 1 - d[i][1]);
    }
    ans += (oo >> 1);
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1, 0, 0);
    cout << ans << endl;
}
