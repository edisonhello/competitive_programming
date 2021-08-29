#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    vector<int> v(n + 4);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> a(n + 4), b(n + 4);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> dp(n + 4, 0);
    int mx = 0;

    dp[1] = abs(a[2] - b[2]);
    for (int i = 2; i <= n; ++i) {
      if (a[i] == b[i]) {
        mx = max(mx, v[i] + 1);
        dp[i] = 1 + v[i] - abs(a[i + 1] - b[i + 1]);
      } else {
        mx = max(mx, v[i] + 1 + dp[i - 1]);
        dp[i] = dp[i - 1] + 1 + v[i] - abs(a[i + 1] - b[i + 1]);
      }

      // cerr << "dp " << dp[i] << " mx " << mx << endl;
    }

    cout << mx << '\n';
  }
}
