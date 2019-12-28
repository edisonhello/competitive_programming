#include <bits/stdc++.h>
using namespace std;

int pipe[3][200005];
int dp[200005][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q; while (q--) {
		int n; cin >> n; 
		string s; cin >> s;
		for (int i = 1; i <= n; ++i) pipe[1][i] = (s[i - 1] <= '2' ? 1 : 2);
		cin >> s;
		for (int i = 1; i <= n; ++i) pipe[2][i] = (s[i - 1] <= '2' ? 1 : 2);
		for (int i = 0; i <= n + 1; ++i) dp[i][0] = dp[i][1] = dp[i][2] = 0;
		dp[0][1] = 1;
		for (int i = 1; i <= n; ++i) {
			if (dp[i - 1][1]) {
				if (pipe[1][i] == 1) dp[i][1] = 1;
				if (pipe[1][i] == 2 && pipe[2][i] == 2) dp[i][2] = 1;
			}
			if (dp[i - 1][2]) {
				if (pipe[2][i] == 1) dp[i][2] = 1;
				if (pipe[2][i] == 2 && pipe[1][i] == 2) dp[i][1] = 1;
			}
		}
		cout << (dp[n][2] ? "YES" : "NO") << '\n';
	}
}
