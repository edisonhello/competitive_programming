#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int off[100005];
int on[100005][7];
pair<double, int> dp[100005][1 << 7];
int n, p;

double check(double cost) {
	// cerr << "cost = " << cost << endl;
	for (int i = 0; i <= n; ++i) for (int j = 0; j < (1 << p); ++j) dp[i][j].first = 0, dp[i][j].second = 0;
	for (int i = 1; i <= n; ++i) for (int j = 0; j < (1 << p); ++j) {
		// cerr << i << ' ' << j << ' ' << off[i] << ' ' << dp[i - 1][j].first << ' ' << dp[i][j].first << endl;
		if (dp[i - 1][j].first > dp[i][j].first) 
			dp[i][j] = dp[i - 1][j];
		double vv = dp[i - 1][j].first + off[i] - cost;
		if (vv > dp[i][j].first) {
			dp[i][j].first = vv;
			dp[i][j].second = dp[i - 1][j].second + 1;
		}
		for (int jj = j; jj; jj -= jj & -jj) {
			int k = __builtin_ctz(jj);
			if (dp[i - 1][j].first + on[i][k] > dp[i][j ^ (1 << k)].first) {
				dp[i][j ^ (1 << k)].first = dp[i - 1][j].first + on[i][k];
				dp[i][j ^ (1 << k)].second = dp[i - 1][j].second;
			}
		}
	}

	// for (int i = 1; i <= n; ++i) for (int j = 0; j < (1 << p); ++j) {
	// 	cerr << "dp " << i << ' ' << j << " = " << dp[i][j].first << ' ' << dp[i][j].second << endl;
	// }
	// cerr << "value " << dp[n][0].first << endl;
	// cerr << "off count = " << dp[n][0].second << endl;
	return dp[n][0].second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k; cin >> n >> p >> k;
	for (int i = 1; i <= n; ++i) cin >> off[i];
	for (int i = 1; i <= n; ++i) for (int j = 0; j < p; ++j) cin >> on[i][j];

	double L = 0, R = 1000000000;
	int it = 33;
	while (it--) {
		double M = (L + R) / 2;
		if (check(M) > k) L = M;
		else R = M;
	}
	check(L);

	cout << (long long)round(dp[n][0].first + L * k) << endl;
}
