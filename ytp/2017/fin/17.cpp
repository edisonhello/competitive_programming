#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
vector<int> G[maxn];
int a[maxn], sz;
bool v[maxn];

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) if (!v[u]) {
        dfs(u);
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (__gcd(a[i], a[j]) > 1) {
                G[i].push_back(j); G[j].push_back(i);
            } 
        }
    }
    int ans = 0;
    int cc = 0;
    for (int i =1; i <= n; ++i) {
        if (!v[i])dfs(i),++cc;
    }
    for (int i = 1; i <= n; ++i) {
        memset(v, false, sizeof(v));
        int cur = 0;
        if (G[i].size() == 0) ++cur;
        v[i] = true;
        for(int j = 1; j <= n; ++j) {
            if (!v[j]) dfs(j), ++cur;
        }
        if (cur > cc) ++ans;
    }
    cout << ans << endl;
    return 0;
}
