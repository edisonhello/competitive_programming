#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, mod = 1e9 + 7;

inline int mul(int a, int b) { return a * 1ll * b % mod; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }

vector<int> G[maxn];
int f[maxn], invf[maxn];

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}
void init() {
    f[0] = 1; invf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = mul(f[i - 1], i);
        invf[i] = fpow(f[i], mod - 2);
    }
}
int dp[maxn], sz[maxn];
void dfs(int now, int fa) {
    // dp[now] = 1;
    sz[now] = 1;
    int x = 1;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        x = mul(x, dp[u]);
        sz[now] += sz[u];
    }
    x = mul(x, f[sz[now] - 1]);
    for (int u : G[now]) if (u != fa) x = mul(x, invf[sz[u]]);
    dp[now] = x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    init();
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(dp, 0, sizeof(dp));
        dfs(i, 0);
        ans = add(ans, dp[i]);
        // cout << dp[i] << endl;
    }
    cout << ans << endl;
}
