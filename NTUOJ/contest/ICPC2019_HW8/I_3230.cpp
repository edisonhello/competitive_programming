#include <bits/stdc++.h>
using namespace std;

const long long mod = 2013265921;

long long dp[2][666 * 666];
long long diff[666 * 666];

int main() {
	int n, k; cin >> n >> k;
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		int o = (i & 1), p = (i & 1) ^ 1;
		memset(dp[o], 0, 666 * 666 * 4);
		memset(diff, 0, sizeof(diff));
		long long add = 0;
		for (int j = 0; j <= i * i; ++j) {
			add += dp[p][j];
			if (add >= mod) add -= mod;
			add -= diff[j];
			if (add < 0) add += mod;
			dp[o][j] += add;
			if (dp[o][j] >= mod) dp[o][j] -= mod;
			diff[j + i] += dp[p][j];
			if (diff[j + i] >= mod) diff[j + i] -= mod;
			// for (int k = 0; k < i; ++k) {
			// 	dp[o][j + k] += dp[p][j];
			// 	if (dp[o][j + k] >= mod) dp[o][j + k] -= mod;
			// }
		}
		// for (int j = 0; j <= i * i; ++j) cout << "dp[" << i << "][" << j << "] = " << dp[i & 1][j] << endl;
	}
	cout << dp[n & 1][k] << endl;
}
