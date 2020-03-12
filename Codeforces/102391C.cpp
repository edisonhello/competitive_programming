#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;

	vector<string> mp(n);
	vector<vector<int>> g(n * m), ig(n * m);

	auto $ = [&] (const int a, const int b) { return a * m + b };

	for (int i = 0; i < n; ++i) {
		cin >> mp[i];
		for (int j = 0; j < m; ++j) {
			auto AddEdge = [&] (const int a, const int b) {
				g[a].push_back(b);
				ig[b].push_back(a);
			};

			if (mp[i][j] != 'U' && i) AddEdge($(i, j), $(i - 1, j));
			if (mp[i][j] != 'D' && i < n - 1) AddEdge($(i, j), $(i + 1, j));
			if (mp[i][j] != 'L' && j) AddEdge($(i, j), $(i, j - 1));
			if (mp[i][j] != 'R' && j < m - 1) AddEdge($(i, j), $(i, j + 1));
		}
	}
	
	vector<bool> vis(n * m, false);
	vector<int> tp;

	function<void(int)> Dfs = [&] (const int now) {
		for (int i : g[now]) if (!vis[i]) Dfs(i);
		tp.push_back(now);
	};
	for (int i = 0; i < n * m; ++i) if (!vis[i]) Dfs(i);

	reverse(tp.begin(), tp.end());
	fill(vis.begin(), vis.end(), false);
	vector<int> bel(n * m);
	int cc = 0;
	function<void(int, int)> iDfs = [&] (const int now, const int cc) {
		bel[now] = cc;
		for (int i : ig[now]) iDfs(i, cc);
	};
	for (int i : tp) if (!vis[i]) iDfs(i, cc++);

	vector<vector<int>> mem(cc);
	for (int i = 0; i < n * m; ++i) mem[bel[i]].push_back(i);

	vector<tuple<int, int, int, int>> scc_rect(cc, make_tuple(n - 1, 0, m - 1, 0));
	for (int i = 0; i < cc; ++i) {
		for (int j : mem[i]) {
			scc_rect[i] = make_tuple(min(get<0>(scc_rect[i]), j / m), max(get<1>(scc_rect[i]), j / m), min(get<2>(scc_rect[i]), j % m), max(get<3>(scc_rect[i]), j % m));
		}
	}

	vector<set<int>> cg(cc), icg(cc);
	for (int i = 0; i < n * m; ++i) {
		for (int j : g[i]) if (bel[j] != bel[i]) cg[bel[i]].insert(bel[j]);
		for (int j : ig[i]) if (bel[j] != bel[i]) icg[bel[i]].insert(bel[j]);
	}

	vis.resize(cc);
	fill(vis.begin(), vis.end(), false);
	vector<tuple<int, int, int, int>> can_from = scc_rect;
	function<void(int)> iCDfs = [&] (const int now) {
		vis[now] = true;
		for (int i : icg[now]) {
			if (!vis[i]) iCDfs(i);
			can_from[now] = make_tuple(min(get<0>(can_from[now]), get<0>(can_from[i])), max(get<1>(can_from[now]), get<1>(can_from[i])), min(get<2>(can_from[now]), get<2>(can_from[i])), max(get<3>(can_from[now]), get<3>(can_from[i])));
		}
	};

	fill(vis.begin(), vis.end(), false);
	vector<tuple<int, int, int, int>> cant_go = scc_rect;
	function<void(int)> CDfs = [&] (const int now) {
		auto Inverse = [&] (tuple<int, int, int, int> in) {
			if (get<0>(in) == 0 && get<1>(in) == 1) 
		};
		vis[now] = true;
		cant_go[i] = Inverse(cant_go[i]);
		for (int i : cg[now]) {
			if (!vis[i]) CDfs(i);
			cant_go[i] = make_tuple(max(get<0>(cant_go[now]), get<0>(cant_go[i])), min(get<1>(cant_go[now]), get<1>(cant_go[i])), max(get<2>(cant_go[now]), get<2>(cant_go[i])), min(get<3>(cant_go[now]), get<3>(cant_go[i])));
		}
	}:


}
