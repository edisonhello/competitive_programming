#include <bits/stdc++.h>
using namespace std;

string s[105], rs[105];
int dp[105][105];
pair<int, int> cf[105][105];

int dfs(int l, int r) {
	if (r < l) {
		return 0;
	}
	dp[l][r] = -100;
	if (s[l] == rs[r]) {
		int z = dfs(l + 1, r - 1);
		if (z > dp[l][r]) {
			dp[l][r] = z;
			cf[l][r] = make_pair(l + 1, r - 1);
		}
	} {
		int z = dfs(l, r - 1);
		if (z > dp[l][r]) {
			dp[l][r] = z;
			cf[l][r] = make_pair(l, r - 1);
		}
	} {
		int z = dfs(l + 1, r);
		if (z > dp[l][r]) {
			dp[l][r] = z;
			cf[l][r] = make_pair(l + 1, r);
		}
	}
	return dp[l][r];
}

bool u[105];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) rs[i] = s[i], reverse(rs[i].begin(), rs[i].end());
	string sl, sr; 
	for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) if (!u[i] && !u[j]) {
		if (s[i] == rs[j]) {
			u[i] = u[j] = 1;
			sl += s[i], sr += rs[j];
		}
	}

	for (int i = 1; i <= n; ++i) if (!u[i] && s[i] == rs[i]) {
		sl += s[i];
		break;
	}

	reverse(sr.begin(), sr.end());

	cout << sl.size() + sr.size() << endl;
	cout << sl << sr << endl;
	// dfs(1, n);
	// int l = 1, r = n;
	// string sl, sr;
	// while (l <= r) {
	// 	auto [nl, nr] = cf[l][r];
	// 	if (nl != l && nr != r) {
	// 		sl += s[l], sr += rs[r];
	// 	}
	// 	l = nl, r = nr;
	// 	cerr << l << ' ' << r << endl;
	// }
	// reverse(sr.begin(), sr.end());
	// cout << sl.size() + sr.size() << endl;
	// cout << sl << sr << endl;
}
