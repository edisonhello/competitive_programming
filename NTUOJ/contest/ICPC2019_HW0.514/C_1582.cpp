#include <bits/stdc++.h>
using namespace std;

int dp[55][55], a[55], dp2[55][55];
int main() {
    int t; scanf("%d", &t); while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        memset(dp, 0xc0, sizeof(dp));
        memset(dp2, 0xc0, sizeof(dp2));
        for (int i = 1; i <= n; ++i) dp[i][i] = dp[i][i + 1] = 0;
        for (int l = 3; l <= n; ++l) for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i + 1; k < j; ++k) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[j]);
        }
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dp2[i][j] = dp[i][j];
        for (int l = 3; l <= n; ++l) for (int i = 1; i <= n - l + 1; ++i) {
            int j = i  + l - 1;
            for (int k = i; k <= j; ++k) dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k][j]);
        }
        printf("%d\n", dp2[1][n]);
    }
}
