#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		long long n, c1; cin >> n >> c1;
		long long c0 = n - c1;
		if (c1 == 0) {
			cout << 0 << '\n';
			continue;
		} else if (c0 == 0) {
			cout << n * (n + 1) / 2 << '\n';
			continue;
		}
		long long seg_0_count = c0 / (c1 + 1);
		long long seg_add_0_count = c0 % (c1 + 1);
		long long count_seg = c1 + 1;
		cout << n * (n + 1) / 2 - (count_seg - seg_add_0_count) * seg_0_count * (seg_0_count + 1) / 2 - seg_add_0_count * (seg_0_count + 1) * (seg_0_count + 2) / 2 << '\n';
	}
}
