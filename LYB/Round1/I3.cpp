#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> g[maxn];
int dep[maxn], dp1[maxn], dp2[maxn];
int ans[maxn];

void dfs(int x, int p) {
    dep[x] = p ? dep[p] + 1 : 0;
    dp1[x] = 0;
    int a = -1, b = -1;
    for (int u : g[x]) if (u != p) {
        dfs(u, x);
        dp1[x] = max(dp1[x], dp1[u] + 1);
        dp2[x] = max(dp2[x], dp2[u]);
        if (dp1[u] > a) b = a, a = dp1[u];
        else if (dp1[u] > b) b = dp1[u];
    }
    dp2[x] = max(dp2[x], dp1[x]);
    if (a != -1 && b != -1) dp2[x] = max(dp2[x], a + b + 2);
}

void dfs2(int x, int p, int fdp1, int fdp2) {
    // printf("x = %d p = %d fdp1 = %d fdp2 = %d\n", x, p, fdp1, fdp2);
    ans[x] = fdp2;
    for (int u : g[x]) if (u != p) ans[x] += dp2[u];  
    pair<int, int> a = make_pair(-1, -1), b = make_pair(-1, -1), c = make_pair(-1, -1);
    pair<int, int> d = make_pair(-1, -1), e = make_pair(-1, -1), f = make_pair(-1, -1);
    for (int u : g[x]) if (u != p) {
        if (dp1[u] > a.first) c = b, b = a, a = make_pair(dp1[u], u);
        else if (dp1[u] > b.first) c = b, b = make_pair(dp1[u], u);
        else if (dp1[u] > c.first) c = make_pair(dp1[u], u);
        if (dp2[u] > d.first) f = e, e = d, d = make_pair(dp2[u], u);
        else if (dp2[u] > e.first) f = e, e = make_pair(dp2[u], u);
        else if (dp2[u] > f.first) f = make_pair(dp2[u], u);
    }
    for (int u : g[x]) if (u != p) {
        int y = a.second == u ? b.first : a.first;
        int z = d.second == u ? e.first : d.first;
        int f1 = max(fdp1 + 1, y + 1);
        int f2 = max(fdp2, z);
        vector<pair<int, int>> v = { a, b, c, make_pair(fdp1, -1) };
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int i = 0;
        while (i < 4 && v[i].second == u) ++i;
        y = v[i].first;
        ++i;
        while (i < 4 && v[i].second == u) ++i;
        z = v[i].first;
        // printf("u = %d y = %d z = %d\n", u, y, z);
        f2 = max(f2, y + z + 2);
        dfs2(u, x, f1, f2);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; ++i) printf("%d %d\n", dp1[i], dp2[i]);
    dfs2(1, 0, -1, 0);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}
