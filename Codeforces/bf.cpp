#include <bits/stdc++.h>
using namespace std;



int main() {
	int b, k; cin >> b >> k;
	stack<vector<int>> prog;
	prog.push(vector<int>());
	string s;
	stack<int> rep;
	int n = 0;
	while (cin >> s) {
		if (s[0] == 'R') {
			int r = 0;
			for (int i = 1; i < (int)s.size(); ++i) r = r * 10 + s[i] - '0';
			rep.push(r);
			prog.push(vector<int>());
		} else if (s[0] == 'E') {
			vector<int> tmp = prog.top(); prog.pop();
			int r = rep.top(); rep.pop();
			while (r--) {
				for (int i : tmp) prog.top().push_back(i);
			}
		} else {
			int x = 0;
			for (int i = 1; i < (int)s.size(); ++i) x = x * 10 + s[i] - '0';
			n = max(n, x);
			prog.top().push_back(x - 1);
		}
	}

	vector<int> v = prog.top();
	cerr << "v: "; for (int i : v) cerr << i << ' '; cerr << endl;

	auto Solve = [&] (const int zr) -> long long {
		cerr << "zr = " << zr << endl;
		vector<int> id(13, -1);
		vector<int> vv;
		int nn = 0, cc = 0;
		for (int i : v) {
			++cc;
			if (zr & (1 << i)) continue;
			if (id[i] == -1) id[i] = nn++;
			vv.push_back(id[i]);
		}
		cerr << "vv: "; for (int i : vv) cerr << i << ' '; cerr << endl;
		vector<vector<int>> cnt(nn, vector<int>(nn, 0));
		int prev = -1;
		for (int i : vv) {
			if (prev != -1) cnt[prev][i]++;
			prev = i;
		}

		// cerr << "cnt = " << endl;
		// for (int i = 0; i < nn; ++i) {
		// 	for (int j = 0; j < nn; ++j) cerr << cnt[i][j] << ' ';
		// 	cerr << endl;
		// }

		vector<long long> cost(1 << nn);
		for (int z = 0; z < (1 << nn); ++z) 
			for (int i = 0; i < nn; ++i) if (z & (1 << i)) 
				for (int j = 0; j < nn; ++j) if (z & (1 << j)) 
					cost[z] += cnt[i][j];

		vector<long long> dp(1 << nn, -1e18);
		dp[0] = 0;
		for (int _ = 1; _ < b; ++_) {
			vector<long long> nw = dp;
			for (int z = 0; z < (1 << nn); ++z)
				for (int y = 0; y < (1 << nn); ++y) if (!(z & y) && __builtin_popcount(y) <= k) 
					nw[z | y] = max(nw[z | y], dp[z] + cost[y]);
			dp.swap(nw);
		}

		long long rr = cc + cost.back() - dp.back();
		if (nn) ++rr;
		cerr << "rr = " << rr << endl;
		return rr;
	};

	long long mn = LLONG_MAX;
	for (int z = 0; z < (1 << n); ++z) {
		if (__builtin_popcount(z) > k) continue;
		mn = min(mn, Solve(z));
	}
	cout << mn << endl;
}
