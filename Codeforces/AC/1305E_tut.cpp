#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	if (n == 1) {
		if (m) cout << -1 << endl;
		else cout << 1 << endl;
		exit(0);
	}
	if (n == 2) {
		if (m) cout << -1 << endl;
		else cout << 1 << ' ' << 2 << endl;
		exit(0);
	}
	vector<int> v = {1, 2};
	auto Calc = [&] (const int i) {
		int x = 0, y = v.size() - 1;
		int r = 0;
		while (x < y) {
			if (v[x] + v[y] == i) ++r, ++x, --y;
			else if (v[x] + v[y] > i) --y;
			else ++x;
		}
		return r;
	};
	int now = 0;
	for (int i = 3; i <= n; ++i) {
		if (now + Calc(i) >= m) {
			while (now + Calc(i) > m) {
				++i;
			}
			now += Calc(i);
			v.push_back(i);
			break;
		} else {
			now += Calc(i);
			v.push_back(i);
		}
	}
	if (now != m) {
		cout << -1 << endl;
		exit(0);
	}
	int d = v.back() + 1; now = 1000000000;
	while ((int)v.size() < n) v.push_back(now), now -= d;
	sort(v.begin(), v.end());
	for (int i : v) cout << i << ' ';
	cout << endl;
}
