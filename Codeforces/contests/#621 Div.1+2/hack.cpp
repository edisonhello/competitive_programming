#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t; while (t--) {
		int n, x; cin >> n >> x;
		vector<int> a;
		int x1 = 0;
		for (int i = 0; i < n; ++i) {
			int t; cin >> t; a.push_back(t);
			if (t == x) {
				cout << 1 << endl;
				x1 = 1;
			}
		}
		if (x1) continue;
		sort(a.begin(), a.end());
		if (a[n - 1] >= (x + 1) / 2) { cout << 2 << endl; continue; }
		int xxxx = (x - a[i - 1] * 2) / a[n - 1] + 1;
		x -= xxxx * a[n - 1];
		int find1 = 0;
		auto it = find(a.begin(), a.end(), x);
		if (it != a.end()) find1 = 1;
		if (find1 == 1) {
			cout << xxxx + 1 << endl;
			x1 = 1;
		}
		if (x1 == 1) continue;
		cout << xxxx + 2 << endl;
	}
}
