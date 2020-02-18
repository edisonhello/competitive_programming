#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

bitset<401> dp[2][401][401];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		string s, t; cin >> s >> t;
		for (int j = 0; j <= (int)t.size(); ++j) for (int k = j; k <= (int)t.size(); ++k) dp[0][j][k].reset();
		for (int k = 0; k < (int)t.size(); ++k) dp[0][0][k][k] = 1;
		bool ans = 0;
		for (int i = 1; i <= (int)s.size(); ++i) {
			for (int j = 0; j <= (int)t.size(); ++j) for (int k = j; k <= (int)t.size(); ++k) dp[i & 1][j][k].reset();
			for (int j = 0; j < (int)t.size(); ++j) for (int k = j; k <= (int)t.size(); ++k) {
				// cerr << i << ' ' << j << ' ' << k << " dp[i - 1][j][k] = " << dp[(i - 1) & 1][j][k] << endl;
				if (s[i - 1] == t[j] && j + 1 <= k) dp[i & 1][j + 1][k] |= dp[(i - 1) & 1][j][k];
				// cerr << i << ' ' << j + 1 << ' ' << k << " (push) dp = " << dp[i & 1][j + 1][k] << endl;
				if (k < (int)t.size() && s[i - 1] == t[k]) dp[i & 1][j][k + 1] |= dp[(i - 1) & 1][j][k];
				// cerr << i << ' ' << j << ' ' << k + 1 << " (push) dp = " << dp[i & 1][j][k + 1] << endl;
				// cerr << "after push " << dp[i][j + 1][k] << ' ' << dp[i][j][k + 1] << endl;
				dp[i & 1][j][k] |= dp[(i - 1) & 1][j][k];
			}
			for (int j = 0; j <= (int)t.size(); ++j) if (dp[i & 1][j][t.size()][j]) ans = 1;
		}
		if (ans) {
			cout << "YES" << '\n';
		} else
			cout << "NO" << '\n';
	}
}
