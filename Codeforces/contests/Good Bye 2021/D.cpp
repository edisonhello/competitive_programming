#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int x;
    cin >> x;

    vector dp(n + 5, vector(4, -n * 10));

    dp[0][3] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int pz = 0; pz < 4; ++pz) {
        for (int z = 0; z < 2; ++z) {
          bool ok = 1;

          {  // 2
            if (!z || !(pz & 1))
              ;
            else if (i > 1 && a[i] + a[i - 1] < 2 * x)
              ok = 0;
          }
          {  // 3
            if (!z || !(pz & 1) || !(pz & 2))
              ;
            else if (i > 2 && a[i] + a[i - 1] + a[i - 2] < 3 * x)
              ok = 0;
          }

          if (ok) {
            dp[i][((pz << 1) | z) & 3] =
                max(dp[i][((pz << 1) | z) & 3], dp[i - 1][pz] + z);
          }
        }
      }

      // for (int z = 0; z < 4; ++z) {
      //   cerr << "dp " << i << ' ' << z << " = " << dp[i][z] << endl;
      // }
    }

    int ans = 0;
    for (int z = 0; z < 4; ++z) {
      ans = max(ans, dp[n][z]);
    }

    cout << ans << '\n';
  }
}
