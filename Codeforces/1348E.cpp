#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

constexpr int C = 1000;

int x[505][2];
long long dp[2][C + 5][C + 5];

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	// int n = 500, k = 1;
	for (int i = 1; i <= n; ++i) cin >> x[i][0] >> x[i][1];
	// for (int i = 1; i <= n; ++i) x[i][0] = x[i][1] = 1000000000;
	memset(dp, -0x3f, sizeof(dp));

	auto Update = [&] (int o, int a, int b, long long y) { 
		while (a >= k) a -= k, ++y;
		while (b >= k) b -= k, ++y;
		dp[o][a][b] = max(dp[o][a][b], y); 
	};

	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		int o = i & 1;
		for (int a = 0; a <= k; ++a) for (int b = 0; b <= k; ++b) dp[o][a][b] = dp[o ^ 1][a][b];
		for (int a = k; a >= 0; --a) {
			for (int b = k; b >= 0; --b) {
				[&, u=x[i][0], v=x[i][1]] () mutable {
					{
						int y = u / k;
						int z = y + (u - y * k + v) / k;
						int vv = v - max(0, z * k - u); 
						if (b + vv <= C) Update(o, a, b + vv, dp[o ^ 1][a][b] + z);
					}
					{
						int y = v / k;
						int z = y + (v - y * k + u) / k;
						int uu = u - max(0, z * k - v);
						if (a + uu <= C) Update(o, a + uu, b, dp[o ^ 1][a][b] + z);
					};
					if (a + u % k <= C && b + v % k <= C)
						Update(o, a + u % k, b + v % k, dp[o ^ 1][a][b] + u / k + v / k);
				} ();
				if (a < k && x[i][0] > k - a) [&, u=x[i][0], v=x[i][1]] () mutable {
					// Update(dp[o][k][b], dp[o ^ 1][a][b]); 
					u -= k - a;
					[&, v] () mutable {
						int y = u / k;
						int z = y + (u - y * k + v) / k;
						v -= max(0, z * k - u);
						if (b + v <= C) Update(o, k, b + v, dp[o ^ 1][a][b] + z);
					} ();
					[&, u] () mutable {
						int y = v / k;
						int z = y + (v - y * k + u) / k;
						u -= max(0, z * k - v);
						if (k + u <= C) Update(o, k + u, b, dp[o ^ 1][a][b] + z);
					} ();
					if (k + u % k <= C && b + v % k <= C)
						Update(o, k + u % k, b + v % k, dp[o ^ 1][a][b] + u / k + v / k);
				} ();
				if (b < k && x[i][1] > k - b) [&, u=x[i][0], v=x[i][1]] () mutable {
					// Update(dp[o][a][k], dp[o ^ 1][a][b]); 
					v -= k - b;
					[&, v] () mutable {
						int y = u / k;
						int z = y + (u - y * k + v) / k;
						v -= max(0, z * k - u);
						if (k + v <= C) Update(o, a, k + v, dp[o ^ 1][a][b] + z);
					} ();
					[&, u] () mutable {
						int y = v / k;
						int z = y + (v - y * k + u) / k;
						u -= max(0, z * k - v);
						if (a + u <= C) Update(o, a + u, k, dp[o ^ 1][a][b] + z);
					} ();
					if (a + u % k <= C && k + v % k <= C)
						Update(o, a + u % k, k + v % k, dp[o ^ 1][a][b] + u / k + v / k);
				} ();
				if (a < k && x[i][0] > k - a && b < k && x[i][1] > k - b) [&, u=x[i][0], v=x[i][1]] () mutable {
					// Update(dp[o][k][k], dp[o ^ 1][a][b]); 
					u -= k - a; v -= k - b;
					[&, v] () mutable {
						int y = u / k;
						int z = y + (u - y * k + v) / k;
						v -= max(0, z * k - u);
						if (k + v <= C) Update(o, k, k + v, dp[o ^ 1][a][b] + z);
					} ();
					[&, u] () mutable {
						int y = v / k;
						int z = y + (v - y * k + u) / k;
						u -= max(0, z * k - v);
						if (k + u <= C) Update(o, k + u, k, dp[o ^ 1][a][b] + z);
					} ();
					if (k + u % k <= C && k + v % k <= C)
						Update(o, k + u % k, k + v % k, dp[o ^ 1][a][b] + u / k + v / k);
				} ();
			}
		}
		// for (int i = C; i >= 0; --i) for (int j = C; j >= 0; --j) {
		// 	if (i >= k) Update(o, i - k, j, dp[o][i][j] + 1);
		// 	if (j >= k) Update(o, i, j - k, dp[o][i][j] + 1);
		// 	// cout << "dp " << o << ' ' << i << ' ' << j << " = " << dp[o][i][j] << endl;
		// }
	}

	long long mx = INT_MIN;
	for (int a = 0; a <= C; ++a) for (int b = 0; b <= C; ++b)
		mx = max(mx, dp[n & 1][a][b]);
	cout << mx << endl;
}
