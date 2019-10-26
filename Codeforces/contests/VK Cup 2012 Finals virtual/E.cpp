#include <bits/stdc++.h>
using namespace std;

vector<int> G[100004];
int cdeg[100004];

int dfs(int now, int pa) {
    int sz = 1;
    for (int i : G[now]) {
        if (i == pa) continue;
        sz += dfs(i, now);
    }
    return sz;
}

int main() {
    int n; cin >> n; 
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bitset<5005> ans;
    for (int i = 1; i <= n; ++i) {
        vector<int> sz;
        for (int j : G[i]) sz.push_back(dfs(j, i));
        bitset<5005> ok;
        ok[0] = 1;
        for (int i : sz) ok |= (ok << i);
        ans |= ok;
    }

    ans[0] = 0;
    ans[n - 1] = 0;
    cout << ans.count() << endl;
    for (int i = 1; i < n - 1; ++i) if (ans[i]) cout << i << ' ' << n - 1 - i << '\n';
}
