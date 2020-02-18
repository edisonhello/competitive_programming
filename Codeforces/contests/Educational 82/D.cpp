#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		long long n; cin >> n;
		int m; cin >> m;
		vector<int> v;
		for (int i = 0; i < m; ++i) {
			int t; cin >> t;
			v.push_back(t);
		}
		sort(v.begin(), v.end());
		long long sum = 0;
		for (int i : v) sum += i;
		if (sum < n) {
			cout << -1 << endl;
			continue;
		}
		multiset<long long> st;
		int ans = 0;
		for (long long i : v) {
			if (n & (i - 1)) {
				while (n & (i - 1)) {
					i >>= 1;
					++ans;
					if (n & i) n ^= i;
				}
			} else if (n & i) {
				n -= i;
			} else {
				bool add = 1;
				while (true) {
					if (st.count(i)) {
						st.erase(st.find(i));
						i <<= 1;
						if (n & i) {
							n ^= i;
							add = 0;
							break;
						}
					} else break;
				}
				if (add) st.insert(i);
			}
		}
		assert(n == 0);
		cout << ans << endl;
	}
}
