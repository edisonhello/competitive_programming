#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
	int n = 120000; cout << n << endl;
	vector<int> v(n); iota(v.begin(), v.end(), 1);
	random_shuffle(v.begin(), v.end());
	for (int i : v) cout << i << ' '; cout << endl;
	int q = 120000; cout << q << endl;
	while (q--) {
		int l = rand() % n + 1, r = rand() % n + 1;
		if (r < l) swap(r, l);
		int k = rand() % (r - l + 1);
		cout << l << ' ' << r << ' ' << k << endl;
	}
}
