#include <bits/stdc++.h>
using namespace std;

int a[52][20004], pre[52][20004];
int dp[52][20004], predp[52][20004], sufdp[52][20004];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pre[i][j] = pre[i][j - 1] + a[i][j];

	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max(j - k >= 1 ? predp[i - 1][j - k] : 0, j + k <= m ? sufdp[i - 1][j + k] : 0) + pre[i][j + k - 1] - pre[i][j - 1];
			for (int kk = j - k + 1; kk <= j + k - 1; ++kk) {
				dp[i][j] = max(dp[i][j], 
							   dp[i - 1][kk] + pre[i][j + k - 1] - pre[i][j - 1] - (pre[i][min(kk + k - 1, j + k - 1)] - pre[i][max(kk, j) - 1]));
			}
			dp[i][j] += pre[i + 1][j + k - 1] - pre[i + 1][j - 1];
			// cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			mx = max(mx, dp[i][j]);
		}
		for (int j = 1; j <= m; ++j) predp[i][j] = max(predp[i][j - 1], dp[i][j]);
		for (int j = m; j >= 1; --j) sufdp[i][j] = max(sufdp[i][j + 1], dp[i][j]);
	}

	cout << mx << endl;
}
