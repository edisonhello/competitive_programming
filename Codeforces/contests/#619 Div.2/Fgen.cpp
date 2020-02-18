#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0) * clock());
	int n = 100, m = 100, k = 40; cout << n << ' ' << m << ' ' << k << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << rand() % k + 1 << ' ';
		}
		cout << '\n';
	}
	int q = 100000; cout << q << endl;
	while (q--) {
		cout << rand() % n + 1 << ' ' << rand() % m + 1 << ' ' << rand() % n + 1 << ' ' << rand() % m + 1 << '\n';
	}
}
