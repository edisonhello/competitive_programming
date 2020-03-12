#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());

	int b = rand() % 3 + 1, k = rand() % 3 + 1; cout << b << ' ' << k << endl;
	int pre = 0;
	for (int i = 0; i < 15; ++i) {
		int z = rand() % 3;
		if (z == 0) {
			cout << "V" << rand() % 4 + 1 << ' ';
		} else if (z == 1 && pre) {
			cout << "E" << ' ';
			--pre;
		} else {
			cout << "R" << rand() % 3 + 1 << ' ';
			++pre;
		}
	}
	while (pre--) cout << "E" << ' ';
	cout << endl;
}
