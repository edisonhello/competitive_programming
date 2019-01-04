#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,sse,sse2,sse3,ssse3,sse4,tune=native")
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, maxc = 205;
const int mod = 998244353;

int n, a[maxn], dp[maxn][maxc][2], pre[maxc][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0) + clock());
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // n = 100000;
    // for (int i = 1; i <= n; ++i) a[i] = -1;
    for (int i = 1; i <= 200; ++i) if (a[1] == -1 || a[1] == i) dp[1][i][0] = 1;
    for (int i = 2; i <= n; ++i) {
        memset(pre, 0, sizeof(pre));
        for (int j = 1; j <= 200; ++j) {
            pre[j][0] += pre[j - 1][0] + dp[i - 1][j][0];
            pre[j][1] += pre[j - 1][1] + dp[i - 1][j][1];
            if (pre[j][0] >= mod) pre[j][0] -= mod;
            if (pre[j][1] >= mod) pre[j][1] -= mod;
        }
        for (int j = 1; j <= 200; ++j) if (a[i] == -1 || a[i] == j) {
            dp[i][j][0] += pre[j - 1][0];
            if (dp[i][j][0] >= mod) dp[i][j][0] -= mod;
            dp[i][j][0] += pre[j - 1][1];
            if (dp[i][j][0] >= mod) dp[i][j][0] -= mod;

            /* dp[i][j][0] += dp[i - 1][j][0];
            if (dp[i][j][0] >= mod) dp[i][j][0] -= mod;
            dp[i][j][0] += dp[i - 1][j][1];
            if (dp[i][j][0] >= mod) dp[i][j][0] -= mod; */
            dp[i][j][1] += dp[i - 1][j][0];
            if (dp[i][j][1] >= mod) dp[i][j][1] -= mod;
            dp[i][j][1] += dp[i - 1][j][1];
            if (dp[i][j][1] >= mod) dp[i][j][1] -= mod;

            dp[i][j][1] += pre[200][1];
            if (dp[i][j][1] >= mod) dp[i][j][1] -= mod;
            dp[i][j][1] -= pre[j][1];
            if (dp[i][j][1] < 0) dp[i][j][1] += mod;
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 200; ++i) {
        ans += dp[n][i][1];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
}
