#include <bits/stdc++.h>
using namespace std;


int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n, x; cin >> n >> x;
        deque<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
        
        sort(v.begin(), v.end());
        int cur = 0;
        int ans = 0;
        while (v.size()) {
			if (v[0].second - v[0].first >= x) {
				int z = (v[0].second - v[0].first) / x;
				ans += z;
				v[0].first += z * x;
				if (v[0].first == v[0].second) {
					v.pop_front();
				}
				continue;
			}
            ++ans;
            int r = v[0].first + x;
			// cerr << " ans r " << ans << ' ' << r << endl;
			// if (v.size()) cerr << v[0].second << endl;
            while (v.size() && v[0].second <= r) {
                v.pop_front();
            }
            if (v.size()) {
                v[0].first = max(v[0].first, r);
            }
        }
        cout << ans << endl;
    }
}
