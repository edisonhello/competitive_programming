#include <bits/stdc++.h>
using namespace std;

vector<int> cal;
int prv[300005];
int bit[1000005];
int ans[300005][2];

void add(int x, int v) {
	for (; x < 1000005; x += x & -x) bit[x] += v;
}

int query(int x) {
	int a = 0;
	for (; x; x -= x & -x) a += bit[x];
	return a;
}

int query(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int t; cin >> t;
		cal.push_back(t);
	}

	int nt = 0;
	for (int i = n; i >= 1; --i) {
		prv[i] = ++nt;
		add(nt, 1);
		ans[i][0] = ans[i][1] = i;
	}

	for (int i : cal) {
		int p = prv[i];
		add(p, -1);
		ans[i][1] = max(ans[i][1], query(p + 1, nt) + 1);
		prv[i] = ++nt;
		add(nt, 1);
		ans[i][0] = 1;
	}

	for (int i = 1; i <= n; ++i) ans[i][1] = max(ans[i][1], query(prv[i] + 1, nt) + 1);

	for (int i = 1; i <= n; ++i) cout << ans[i][0] << ' ' << ans[i][1] << '\n';
}
