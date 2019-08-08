#include <bits/stdc++.h>
using namespace std;

bitset<10008> np;
vector<int> p;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= 10000; ++i) if (!np[i]) {
		p.push_back(i);
		for (int j = i * i; j <= 10000; j += i) np[j] = 1;
	}
	int n; cin >> n; while (n--) {
		int x; cin >> x;
		int ans[2] = {1, x}, ptr = 1;
		for (int i : p) if (i * i > x) break; else if (x % i == 0) {
			while (x % i == 0) x /= i;
			ans[ptr] = i; ptr ^= 1;
		}
		if (x != 1) ans[ptr] = x;
		cout << ans[0] << " " << ans[1] << '\n';
	}
}
