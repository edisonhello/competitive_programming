#include <bits/stdc++.h>
using namespace std;

const int maxn = 150000 + 5;

vector<int> G[maxn];
int djs[maxn], sz[maxn], ans[maxn];
bitset<maxn> v;

int F(int x) { return x == djs[x] ? x : F(djs[x]); }

void dfs(int l, int r, int x) {
    ans[l] = x;
    for (int i: G[x]) {
        dfs(l + 1, l + sz[i], i);
        l += sz[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) djs[i] = i;
    for (int i = 1; i <= n; ++i) sz[i] = 1;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        x = F(x), y = F(y);
        if (x == y) continue;
        if (sz[y] > sz[x]) swap(x, y);
        djs[y] = x;
        sz[x] += sz[y];
        G[x].push_back(y);
    }
    int ptr = 0;
    for (int i = 1; i <= n; ++i) {
        int x = F(i);
        if (v[x]) continue;
        v[x] = 1;
        dfs(ptr + 1, ptr + sz[x], x);
        ptr += sz[x];
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
}
