#include <bits/stdc++.h>
using namespace std;

set<int> G[5003];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].insert(v);
    }
    int mx = 1;
    for (int fi = 1; fi <= n; ++fi) {
        int base = G[fi].size();
        if (fi != 1) ++base;
        for (int j = 1; j <= n; ++j) {
            if (j == fi) continue;
            int nw = base + G[j].size();
            if (G[j].count(fi) || G[fi].count(j)) --nw;
            if (j == 1) --nw;
            mx = max(mx, nw);
        }
    }
    cout << mx << endl;
}
