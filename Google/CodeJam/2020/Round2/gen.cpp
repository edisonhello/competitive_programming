#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0) * clock());
	int t = 1; cout << t << endl; while (t--) {
		int n = rand() % 5 + 1;
		int m = rand() % 3 + (n - 1);
		cout << n << endl;
		vector<vector<pair<int, int>> g(n + 1);
		for (int i = 1; i < n; ++i) {
			int v = rand() % i;
			g[u + 1].emplace_back(v + 1, rand() % 5 + 1);
			g[v + 1].emplace_back(u + 1, rand() % 5 + 1);
		}
	}
}
