#include <bits/stdc++.h>
using namespace std;

int getw() {
	return rand() % 1000 * (rand() & 1 ? 1 : -1);
}

int main(){
	srand(time(0) * clock());
	int t = 1; cout << t << endl;
	int n = 6, m = 8, q = rand() % 5 + 3;
	n = max(n, 2);
	m = min(m, n * (n - 1) / 2);
	m = max(m, n - 1);
	cout << n << ' ' << m << ' ' << q << endl;
	set<pair<int, int>> eg;
	for (int i = 1; i < n; ++i) {
		int p = rand() % i;
		eg.insert(minmax(p, i));
		cout << p << ' ' << i << ' ' << getw() << '\n';
	}
	while ((int)eg.size() < m) {
		int u = rand() % n, v = rand() % n;
		if (eg.count(minmax(u, v)) || u == v) continue;
		eg.insert(minmax(u, v));
		cout << u << ' ' << v << ' ' << getw() << '\n';
	}
	while (q--) {
		int c = rand() % 2;
		cout << c << ' ';
		if (c == 0) {
			int u = rand() % n, v = rand() % n;
			while (u == v) u = rand() % n, v = rand() % n;
			cout << u << ' ' << v << ' ' << getw() << '\n';
		} else {
			int u = rand() % n, v = rand() % n;
			while (u == v) u = rand() % n, v = rand() % n;
			cout << u << ' ' << v << '\n';
		}
	}
}
