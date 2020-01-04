#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0) * clock());
	int n = 2; cout << n << endl;
	for (int i = 0; i < n; ++i) {
		int l, r;
		l = rand() % 10 + 1, r = rand() % 10 + 1;
		if (r < l) swap(l, r);
		cout << l << ' ' << r << ' ';
		l = rand() % 10 + 1, r = rand() % 10 + 1;
		if (r < l) swap(l, r);
		cout << l << ' ' << r << '\n';
	}
}
