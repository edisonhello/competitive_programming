#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<pair<int, string>> ss;
	for (int i = 1; i < n; ++i) {
		ss.emplace_back(m - 1, "R");
		ss.emplace_back(m - 1, "L");
		ss.emplace_back(1, "D");
	}
	for (int i = 1; i < m; ++i) {
		ss.emplace_back(1, "R");
		ss.emplace_back(n - 1, "U");
		ss.emplace_back(n - 1, "D");
	}
	ss.emplace_back(m - 1, "L");
	ss.emplace_back(n - 1, "U");
	
	vector<pair<int, string>> ans;
	for (auto &p : ss) {
		int o = min(p.first, k);
		if (o) ans.emplace_back(o, p.second);
		k -= o;
	}
	if (k) exit((cout << "NO" << endl, 0));
	cout << "YES" << endl << ans.size() << endl;
	for (auto &p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}
}
