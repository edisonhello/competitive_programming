#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, T = 0; cin >> t; while (t--) {
		int n; cin >> n;
		vector<int> v(n + 1);
		for (int i = 1; i <= n; ++i) cin >> v[i];

		vector<vector<int>> dp(n + 1, vector<int>(5, 1000000000));

		dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 0;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= 4; ++j) {
				for (int k = 1; k <= 4; ++k) {
					if (v[i] == v[i - 1]) {
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + !(j == k));
					} else if (v[i] < v[i - 1]) {
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + !(j < k));
					} else {
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + !(j > k));
					}
				}
			}
		}

		cout << "Case #" << (++T) << ": " << min(min(min(dp[n][1], dp[n][2]), dp[n][3]), dp[n][4]) << endl;
	}
}
