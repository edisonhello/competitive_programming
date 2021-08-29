#include <bits/stdc++.h>
using namespace std;

int v[200005], dp[200005][3];

int main() {
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    vector<int> v(n + 4);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    for (int i = 0; i <= n; ++i) dp[i][0] = dp[i][1] = 1e9;
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i - 1][1];
      if (i > 1) dp[i][0] = min(dp[i][0], dp[i - 2][1]);

      dp[i][1] = dp[i - 1][0] + v[i];
      if (i > 1) dp[i][1] = min(dp[i][1], dp[i - 2][0] + v[i - 1] + v[i]);
    }

    cout << min(dp[n][0], dp[n][1]) << '\n';
    
  }
}
