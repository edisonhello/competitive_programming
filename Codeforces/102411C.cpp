#include <bits/stdc++.h>
using namespace std;

#define $(x, y) (((x) << 16) | (y))

unordered_map<int, multiset<int>> g[2];
string mp[555];
vector<int> ans;

void add_edge(int a, int b, int c) {
	// cerr << "add_edge " << a << ' ' << b << endl;
	g[c][a].insert(b);
	g[c][b].insert(a);
}

void dfs(int now, int gt, int fr) {
	// cerr << "dfs " << now << endl;
	while (g[gt][now].size()) {
		int to = *g[gt][now].begin(); 
		g[gt][now].erase(g[gt][now].find(to));
		g[gt][to].erase(g[gt][to].find(now));
		dfs(to, !gt, now);
	}
	// cerr << "push " << fr << endl;
	ans.push_back(fr);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> m >> n;
	for (int i = 0; i < n; ++i) cin >> mp[i];

	int fi = -1;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (mp[i][j] == 'X') {
			if (fi == -1) fi = $(i, j);
			add_edge($(i, j), $(i + 1, j + 1), 0);
			add_edge($(i + 1, j + 1), $(i + 1, j), 1);
			add_edge($(i + 1, j), $(i, j + 1), 0);
			add_edge($(i, j + 1), $(i, j), 1);
		}
	}
	ans.push_back(fi);
	dfs(fi, 1, -1);

	ans.pop_back();
	ans.pop_back();
	cout << ans.size() - 1 << '\n';
	for (int i : ans) cout << (i & 65535) << ' ' << (i >> 16) << '\n';
}
