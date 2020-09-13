#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, T = 0; cin >> t; while (t--) {
		int n, a, b; cin >> n >> a >> b;
		vector<vector<int>> pa(20, vector<int>(n + 1, 0));
		vector<vector<int>> g(n + 1);
		for (int i = 2; i <= n; ++i) {
			cin >> pa[0][i];
			g[pa[0][i]].push_back(i);
		}
		vector<int> dep(n + 1, 0);

		long long ab = 1ll * a / __gcd(a, b) * b;

		auto Dfs = [&] (auto self, int now, int cd) {
			++dep[cd];
			for (int i : g[now]) {
				self(self, i, cd + 1);
			}
		};

		auto GetPa = [&] (int now, int dep) {
			for (int z = 19; z >= 0; --z) if (dep & (1 << z)) now = pa[z][now];
			return now;
		};

		for (int z = 1; z < 20; ++z) for (int i = 1; i <= n; ++i) 
			pa[z][i] = pa[z - 1][pa[z - 1][i]];

		vector<int> paa(n + 1), pab(n + 1), paab(n + 1);
		vector<vector<int>> ga(n + 1), gb(n + 1), gab(n + 1);
		for (int i = 1; i <= n; ++i) paa[i] = GetPa(i, a), pab[i] = GetPa(i, b), paab[i] = GetPa(i, ab > n ? n + 5 : ab);
		for (int i = 1; i <= n; ++i) {
			if (paa[i]) ga[paa[i]].push_back(i);
			if (pab[i]) gb[pab[i]].push_back(i);
			if (paab[i]) gab[paab[i]].push_back(i);
		}

		vector<int> sza(n + 1, 1), szb(n + 1, 1), szab(n + 1, 1);

		double ans = 0;
		for (int i = n; i >= 1; --i) {
			for (int j : ga[i]) sza[i] += sza[j];
			for (int j : gb[i]) szb[i] += szb[j];
			for (int j : gab[i]) szab[i] += szab[j];

			ans += (double)sza[i] / n + (double)szb[i] / n - (double)sza[i] * szb[i] / n / n;

			// cerr << i << ' ' << sza[i] << ' ' << szb[i] << ' ' << szab[i] << endl;
		}

		cout << fixed << setprecision(10) << "Case #" << (++T) << ": " << ans << endl;
	}
}
