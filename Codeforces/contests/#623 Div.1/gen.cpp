#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 80, k = 10; cout << n << ' ' << k << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) cout << 0 << ' ';
			else cout << rand() % 100000001 << ' ';
		}
		cout << endl;
	}
}
