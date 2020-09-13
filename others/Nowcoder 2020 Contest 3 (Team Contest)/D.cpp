#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	if (m & 1) {
		cout << "No" << '\n';
		return;
	}
	if (m > 4 * n) {
		cout << "No" << '\n';
		return;
	}
	int sa = -1, sb = -1;
	for (int a = 1; a <= 100; ++a) for (int b = 1; b <= 100; ++b) {
		if (2 * (a + b) <= m && n <= a * b && n >= a && n >= b && n > (a - 1) * b) {
			sa = a, sb = b;
			break;
		}
	}
	if (sa == -1) {
		cout << "No" << '\n';
		return;
	}

	vector<vector<bool>> bl(sa, vector<bool>(sb, 0));
	for (int i = 0, c = 0; i < sa; ++i) for (int j = 0; j < sb; ++j) {
		if (c < n) ++c, bl[i][j] = 1;
	}

	// cerr << "sa sb " << sa << ' ' << sb << endl;
	int cur = 2 * (sa + sb);
	int fi_to = sb - 1;
	for (int i = sa - 1; i > 0; --i) for (int j = sb - 1; j > 0; --j) {
		if (cur >= m) break;
		if (!bl[i][j]) continue;
		bl[i][j] = 0;
		cur += 2;
		++fi_to;
	}

	// cerr << "cur = " << cur << endl;

	if (cur >= m) {
		assert(cur == m);
		// cerr << "output 1 " << endl;
		cout << "Yes" << '\n';
		for (int i = 0; i < sa; ++i) for (int j = 0; j < sb; ++j) if (bl[i][j]) cout << i << ' ' << j << '\n';
		for (int j = sb; j <= fi_to; ++j) cout << 0 << ' ' << j << '\n';
		return;
	}

	int far = 0;
	for (int i = sa - 1; i > 0; --i) {
		if (cur >= m) break;
		if (!bl[i][0]) continue;
		bl[i][0] = 0;
		cur += 2;
		++far;
	}

	for (int j = fi_to; j >= sb; --j) {
		if (cur >= m) break;
		--fi_to;
		cur += 2;
		++far;
	}

	for (int j = sb - 1; j > 0; --j) {
		if (cur >= m) break;
		if (!bl[0][j]) continue;
		bl[0][j] = 0;
		cur += 2;
		++far;
	}

	// cerr << "output 2 " << endl;
	assert(cur == m);
	cout << "Yes" << '\n';
	for (int i = 0; i < sa; ++i) for (int j = 0; j < sb; ++j) if (bl[i][j]) cout << i << ' ' << j << '\n';
	for (int j = sb; j <= fi_to; ++j) cout << 0 << ' ' << j << '\n';
	for (int i = 0; i < far; ++i) cout << 1000000000 << ' ' << i * 2 << '\n';
}

int main() {
	int t; cin >> t; while (t--) solve();
}
