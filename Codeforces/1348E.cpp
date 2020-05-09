#include <bits/stdc++.h>
using namespace std;

int b[505][2];
int dp[505][1005][1005];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> b[i][0] >> b[i][1];
	memset(dp, 0x3f, sizeof(dp));

	auto Need = [&] (int x) { return (x + k - 1) / k; };
	auto Update = [&] (int &x, int y) { x = min(x, y); };

	dp[0][0][0] = 0;
	dp[0][k][0] = 1;
	dp[0][0][k] = 1;
	dp[0][k][k] = 2;
	for (int i = 1; i <= n; ++i) {
		for (int a = 0; a <= 1000; ++a) {
			for (int b = 0; b <= 1000; ++b) {
				Update(dp[i][a][b], dp[i - 1][a][b] + Need(b[i][0]) + Need(b[i][1]));
				if (a + k <= 1000) Update(dp[i][a + k][b], dp[i - 1][a][b] + 1);
				if (b + k <= 1000) Update(dp[i][a][b + k], dp[i - 1][a][b] + 1);
			}
		}
	}
}
