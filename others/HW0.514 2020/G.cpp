#include <iostream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bitset<3005> g[3005], del;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		--u, --v;
		g[u][v] = g[v][u] = 1;
	}

	while (true) {
		bool z = 0;
		for (int i = 0; i < n; ++i) if (!del[i]) for (int j = i + 1; j < n; ++j) if (!del[j] && !g[i][j]) {
			del[i] = del[j] = 1;
			z = 1;
			break;
		}
		if (!z) break;
	}

	for (int i = 0, j = 0; j < n / 3; ++i) {
		if (!del[i]) {
			++j;
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';

}
