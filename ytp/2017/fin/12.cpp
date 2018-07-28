#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
vector<int> G[maxn], R[maxn], tp;
int sz;
bool v[maxn];

void rdfs(int now) {
    v[now] = true;
    for (int u : R[now]) if (!v[u]) {
        rdfs(u);
    }
    tp.push_back(now);
}

void dfs(int now) {
    sz++;
    v[now] = true;
    for (int u : G[now]) {
        if (!v[u]) dfs(u);
    }
}
int main( ){
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }
    memset(v, false, sizeof(v));
    for (int i =1; i <=n; ++i) {
        if (!v[i]) rdfs(i);
    }
    reverse(tp.begin(), tp.end());
    int ans = 0;
    memset(v, false, sizeof(v));
    for (int i : tp) {
        if (!v[i]){
            dfs(i), ans = max(ans, sz);

            sz = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
