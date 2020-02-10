#include <bits/stdc++.h>
using namespace std;

int a[300005][8];
int st[300005];
int ok[1 << 8];
int ans[2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> num;
	num.reserve(n * m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
		num.push_back(a[i][j]);
	}
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());

	auto check = [&] (int bnd) -> bool {
		for (int i = 0; i < n; ++i) {
			int _st = 0;
			for (int j = 0; j < m; ++j) 
				if (a[i][j] >= bnd) _st |= 1 << j;
			st[i] = _st;
		}
		for (int i = 0; i < (1 << m); ++i) ok[i] = -1;
		for (int i = 0; i < n; ++i) ok[st[i]] = i;
		for (int z = (1 << m) - 1; z >= 0; --z) for (int zz = z; zz; zz -= zz & -zz) 
			ok[z ^ (zz & -zz)] = max(ok[z ^ (zz & -zz)], ok[z]);
		for (int i = 0; i < n; ++i) {
			if (ok[((1 << m) - 1) ^ st[i]] >= 0) {
				ans[0] = i;
				ans[1] = ok[((1 << m) - 1) ^ st[i]];
				return 1;
			}
		}
		return 0;
	};

	int L = 0, R = num.size() - 1;
	while (L < R) {
		int M = (L + R + 1) >> 1;
		if (check(num[M])) L = M;
		else R = M - 1;
	}

	check(num[L]);
	cout << ans[0] + 1 << ' ' << ans[1] + 1 << endl;
}
