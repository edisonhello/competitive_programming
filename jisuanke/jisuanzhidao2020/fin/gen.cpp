#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 100000, m = 100000;
	cout << n << ' ' << m << endl;
	// for (int i = 0; i < n; ++i) cout << rand() % 1000000000 + 1 << ' ';
	for (int i = 0; i < n; ++i) cout << 7122 << ' ';
	cout << endl;
	while (m--) {
		int l = rand() % n + 1, r = rand() % n + 1;
		if (r < l) swap(l, r);
		cout << l << ' ' << r << ' ' << rand() % 20 + 1 << '\n';
	}
}
