#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> z;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t; z.push_back(t);
	}
	reverse(z.begin(), z.end());
	multiset<int> st;
	if (z[0] == -1) exit((cout << 0 << endl, 0));
	long long ans = z[0];
	for (int y = n / 2, i = 1; ; y >>= 1) {
		for (int x = 0; x < y; ++x) {
			st.insert(z[i++]);
			if (st.count(-1)) break;
		}
		if (st.count(-1)) break;
		ans += *st.begin();
		st.erase(st.begin());
	}
	cout << ans << endl;

}
