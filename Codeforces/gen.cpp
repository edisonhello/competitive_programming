#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
	int n = 100; cout << n << endl;
	for (int i = 1; i <= n; ++i) {
		cout << rand() % 2000000001 - 1000000000 << ' ' << rand() % 2000000001 - 1000000000 << '\n';
	}
}
