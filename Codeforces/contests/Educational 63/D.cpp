#include <bits/stdc++.h>
using namespace std;

long long a[300005], dp[300005][3]; // not start, using, stop

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    memset(dp, 0xc0, sizeof(dp));
    dp[0][0] = 0;
    long long mx = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max({a[i], dp[i - 1][0] + a[i]});
        dp[i][1] = max({a[i] * x, dp[i - 1][0] + a[i] * x, dp[i - 1][1] + a[i] * x});
        dp[i][2] = max({a[i], dp[i - 1][0] + a[i], dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]});
        mx = max({mx, dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << mx << endl;
}
