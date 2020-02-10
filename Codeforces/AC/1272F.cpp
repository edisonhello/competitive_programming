#include <bits/stdc++.h>
using namespace std;

short dp[202][202][202];
tuple<short, short, short> cf[202][202][202];

void upd(int q, int w, int e, int r, int t, int y) {
	if (dp[q][w][e] > dp[r][t][y] + 1) {
		dp[q][w][e] = dp[r][t][y] + 1;
		cf[q][w][e] = make_tuple(r, t, y);
	}
}

int main() {
	string s, t; cin >> s >> t;
	s = s + " ", t = t + " ";
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = 0; j < (int)t.size(); ++j) {
			for (int z = 0; z <= 200; ++z) {
				upd(i, j, z + 1, i, j, z);
				if (s[i] == '(') upd(i + 1, j, z + 1, i, j, z);
				if (t[j] == '(') upd(i, j + 1, z + 1, i, j, z);
				if (s[i] == '(' && t[j] == '(') upd(i + 1, j + 1, z + 1, i, j, z);

				if (z) {
					upd(i, j, z - 1, i, j, z);
					if (s[i] == ')') upd(i + 1, j, z - 1, i, j, z);
					if (t[j] == ')') upd(i, j + 1, z - 1, i, j, z);
					if (s[i] == ')' && t[j] == ')') upd(i + 1, j + 1, z - 1, i, j, z);
				}

				// cerr << "dp[" << i << "][" << j << "][" << z << "] = " << dp[i][j][z] << endl;
			}
		}
	}
	for (int z = 200; z > 0; --z) {
		upd(s.size() - 1, t.size() - 1, z - 1, s.size() - 1, t.size() - 1, z);
	}

	int q = s.size() - 1, w = t.size() - 1, e = 0;
	string ans;
	while (q || w || e) {
		auto [r, t, y] = cf[q][w][e];
		if (y < e) ans += '(';
		else ans += ')';
		tie(q, w, e) = make_tuple(r, t, y);
		// cerr << "q w e " << q << ' ' << w << ' ' << e << endl;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
