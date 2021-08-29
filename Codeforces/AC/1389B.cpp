#include <bits/stdc++.h>
using namespace std;

int dp[100005][10];

int main() {
  int t; cin >> t; while (t--) {
    int n, k, z; cin >> n >> k >> z;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 10; ++j) dp[i][j] = -1e9;
    }

    dp[0][0] = a[1];
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j <= z; ++j) {
        int at = 1 + i - 2 * j;
        if (at < 1 || at > n) continue;
        if (at > 1) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[at - 1]);
        if (at < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[at + 1]);
      }
    }

    int mx = -1;
    for (int j = 0; j <= z; ++j) mx = max(mx, dp[k][j]);

    cout << mx << '\n';
  }
}
