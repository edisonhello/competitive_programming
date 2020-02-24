#include <bits/stdc++.h>
using namespace std;

int bit[200005];
int ans[200005];

int main() {
	int n; cin >> n;
	string s; cin >> s; s = " " + s;
	vector<pair<char, int>> v;
	for (int i = 1; i <= n; ++i) v.emplace_back(s[i], i);
	sort(v.begin(), v.end());
	for (auto [c, p] : v) {
		for (int x = p; x < 200005; x += x & -x) ans[p] = max(ans[p], bit[x]);
		++ans[p];
		for (int x = p; x; x -= x & -x) bit[x] = max(bit[x], ans[p]);
	}

	cout << *max_element(ans + 1, ans + 1 + n) << endl;
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << endl;
}
