#include <bits/stdc++.h>
using namespace std;

int pos[505][3];
int ho[505], djho[505];
int djs[505];
double dist[505][505];
vector<int> g[505];
set<pair<int, pair<int, int>>> gg[505];

double dd[505];
bool vis[505];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

double calc_dist(int a, int b) { return dist[a][b] + 0.5 * djho[F(b)] - 1; }
double calc_dist(pair<int, int> p) { return calc_dist(p.first, p.second); }

bool has_edge(set<pair<int, pair<int, int>>> &st, int x) {
	auto it = st.lower_bound(make_pair(x, make_pair(INT_MIN, INT_MIN)));
	return it != st.end() && it->first == x;
}

pair<int, pair<int, int>> get_edge(set<pair<int, pair<int, int>>> &st, int x) {
	auto it = st.lower_bound(make_pair(x, make_pair(INT_MIN, INT_MIN)));
	return *it;
}

void U(int x, int y) {
	x = F(x), y = F(y);
	if (x == y) return;
	// cerr << "start big U of x y " << x << ' ' << y << endl;
	djs[y] = x;
	djho[x] += djho[y];

	if (has_edge(gg[x], y)) gg[x].erase(get_edge(gg[x], y));
	for (auto &pp : gg[y]) {
		int now = pp.first;
		if (now == x) continue;
		auto edge = pp.second;
		// cerr << "pp to now = " << now << endl;
		
		if (has_edge(gg[x], now)) {
			auto ppp = get_edge(gg[x], now);
			if (calc_dist(ppp.second) > calc_dist(edge)) {
				gg[x].erase(ppp);
				gg[x].insert(pp);
			}
		} else gg[x].insert(pp);

		if (has_edge(gg[now], x)) {
			if (has_edge(gg[now], y)) {
				auto xp = get_edge(gg[now], x);
				auto yp = get_edge(gg[now], y);
				gg[now].erase(yp);
				if (calc_dist(xp.second) > calc_dist(yp.second)) {
					gg[now].erase(xp);
					yp.first = x;
					gg[now].insert(yp);
				}
			}
		} else {
			if (has_edge(gg[now], y)) {
				auto yp = get_edge(gg[now], y);
				gg[now].erase(yp);
				yp.first = x;
				gg[now].insert(yp);
			}
		}
	}
	// cerr << "Finish big U" << endl;
}

int main() {
	int ts = 0;
	int n, m; while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= n; ++i) gg[i].clear();

		for (int i = 1; i <= n; ++i) cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> ho[i];
		for (int i = 1; i <= n; ++i) djho[i] = ho[i], djs[i] = i;

		vector<int> o(n);
		iota(o.begin(), o.end(), 1);
		sort(o.begin(), o.end(), [&] (const int a, const int b) { return pos[a][2] < pos[b][2]; });

		while (m--) {
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j) {
			gg[i].insert(make_pair(j, make_pair(i, j)));
			dist[i][j] = hypot(hypot(pos[i][0] - pos[j][0], pos[i][1] - pos[j][1]), pos[i][2] - pos[j][2]);
			if (!ho[i] || !ho[j]) dist[i][j] = 1e22;
		}

		double ans = 1e22;
		for (int now : o) {
			// cerr << "now = " << now << endl;
			for (int i : g[now]) {
				if (pos[i][2] <= pos[now][2]) {
					U(i, now);
				}
			}

			if (pos[now][2] < pos[1][2] || pos[now][2] < pos[n][2]) continue;
			
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= n; ++i) dd[i] = 1e22;
			dd[F(1)] = 0;
			pq.emplace(0, F(1));

			while (pq.size()) {
				while (pq.size() && vis[pq.top().second]) pq.pop();
				if (pq.empty()) break;
				int now = pq.top().second;
				vis[now] = 1;
				for (auto &pp : gg[now]) {
					if (dd[pp.first] > dd[now] + calc_dist(pp.second) && (pp.first == F(n) || djho[pp.first] >= 2)) {
						dd[pp.first] = dd[now] + calc_dist(pp.second);
						pq.emplace(dd[pp.first], pp.first);
					}
				}
			}

			// cerr << "Current ans = " << dd[F(n)] + djho[F(1)] * 0.5 << endl;
			// for (int i = 1; i <= n; ++i) {
			// 	for (int j = 1; j <= n; ++j) {
			// 		cout << calc_dist(i, j) << ' ';
			// 	}
			// 	cout << endl;
			// }
			// for (int i = 1; i <= n; ++i) cout << djs[i] << ' '; cout << endl;
			// for (int i = 1; i <= n; ++i) cout << dd[i] << ' '; cout << endl;

			ans = min(ans, dd[F(n)] + djho[F(1)] * 0.5);
		}

		cout << "Case " << (++ts) << ": ";
		if (ans > 1e20) cout << "impossible" << endl;
		else cout << fixed << setprecision(4) << ans << endl;
	}
}
