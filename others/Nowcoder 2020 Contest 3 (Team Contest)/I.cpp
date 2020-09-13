#include <bits/stdc++.h>
using namespace std;

const long long E18 = 1000000000000000000;

vector<int> solve_small(int n, int m, long long k) {
	// cerr << "solve small n m k " << n << ' ' << m << ' ' << k << endl;

	if (!n) return vector<int>();
	vector<int> ans(n, -1);
	vector<int> mul(n, 1);
	for (int i = n - 1, j = 1; i >= 0; --i) {
		mul[i] = j;
		++j;
		if (j > m) j = m;
	}
	
	vector<long long> sufmul(n, 1);
	for (int i = n - 2; i >= 0; --i) {
		if (sufmul[i + 1] > E18 / mul[i]) {
			sufmul[i] = E18 + 5;
		} else {
			sufmul[i] = sufmul[i + 1] * mul[i];
		}
	}
	sufmul.push_back(0);

	for (int i = 0; i < n; ++i) {
		if (sufmul[i + 1] < k) {
			vector<int> notfill;
			for (int j = i + 1; j <= n; ++j) notfill.push_back(j);
			int nn = notfill.size();
			vector<int> mul(nn, 1);
			for (int j = nn - 2; j >= 0; --j) {
				mul[j] = mul[j + 1] + 1;
				if (mul[j] >= m) mul[j] = m;
			}
			vector<bool> used(nn, false);

			for (int pos = i; pos < n; ++pos) {
				for (int put = 0; put < nn; ++put) if (!used[put]) {
					// cerr << "pos " << pos << "try put " << put << endl;
					vector<int> tmul = mul;
					tmul[put] = 1;
					for (int k = put - 1; k >= 0; --k) if (!used[k]) --tmul[k];
					long long tot = 1;
					for (int k = 0; k < nn; ++k) if (!used[k]) tot *= tmul[k];
					// cerr << "tot, k = " << tot << ' ' << k << endl;
					if (k <= tot) {
						mul = tmul;
						used[put] = 1;
						ans[pos] = notfill[put];
						break;
					} else {
						k -= tot;
					}
				}
			}
			
			return ans;
		} else {
			ans[i] = i + 1;
		}
	}

	return ans;
}

void solve() {
	int n, m; cin >> n >> m;
	long long k; cin >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int mx = 0;
	vector<int> ans(n, -1);
	set<int> vals;
	for (int i = 1; i <= n; ++i) vals.insert(i);
	for (int i = 0; i < n; ++i) {
		if (v[i] < mx) {
			ans[i + m - 1] = v[i];
			vals.erase(v[i]);
		}
		mx = max(mx, v[i]);
	}

	vector<int> _ans = solve_small(vals.size(), m, k);

	// cerr << "_ans: ";
	// for (int i : _ans) cerr << i << ' ';
	// cerr << endl;

	vector<int> vvals(vals.begin(), vals.end());
	for (int i = 0, j = 0; i < n; ++i) {
		if (ans[i] == -1) {
			ans[i] = vvals[_ans[j] - 1];
			++j;
		}
	}

	for (int i : ans) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) solve();
}
