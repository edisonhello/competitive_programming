#include <bits/stdc++.h>
using namespace std;

vector<int> inc[300005];
vector<int> g[600005];

int djs[600005], cnt[600005], is_ans[600005];

int cur, k;

int op(int x) { if (x == 2 * k + 1) return 2 * k + 2; if (x == 2 * k + 2) return 2 * k + 1; if (x <= k) return x + k; return x - k; }

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }
void U(int x, int y) {
	x = F(x), y = F(y);
	if (x == y) return;
	djs[x] = y;
	cnt[y] += cnt[x];
}

void clear(int x) {
	// cerr << "clear " << x << endl;
	if (is_ans[F(x)]) cur -= cnt[F(x)], is_ans[F(x)] = 0;
	if (is_ans[F(op(x))]) cur -= cnt[F(op(x))], is_ans[F(op(x))] = 0;
}

void add(int x) {
	// cerr << "add " << x << " cur = " << cur << endl;
	if (F(x) == F(k * 2 + 1) || F(x + k) == F(k * 2 + 2) || cnt[F(x)] <= cnt[F(op(x))]) {
		is_ans[F(x)] = 1;
		cur += cnt[F(x)];
	} else {
		is_ans[F(op(x))] = 1;
		cur += cnt[F(op(x))];
	}
	// cerr << "add [] cur = " << cur << endl;
}

int main() {
	int n; cin >> n >> k;
	string s; cin >> s;
	for (int i = 1; i <= k; ++i) {
		int c; cin >> c;
		for (int j = 1; j <= c; ++j) {
			int t; cin >> t;
			inc[t].push_back(i);
		}
	}

	for (int i = 1; i <= k; ++i) djs[i] = i, cnt[i] = 1; // choose
	for (int i = k + 1; i <= k * 2; ++i) djs[i] = i, is_ans[i] = 1; // can't choose
	djs[k * 2 + 1] = k * 2 + 1; is_ans[k * 2 + 1] = 1; // must choose 
	djs[k * 2 + 2] = k * 2 + 2; cnt[k * 2 + 2] = 1000000; // must not choose

	for (int i = 1; i <= n; ++i) {
		// cerr << "i = " << i << ' ' << inc[i].size() << endl;
		if (s[i - 1] == '0') {
			if (inc[i].size() == 2u) {
				clear(inc[i][0]);
				clear(inc[i][1]);
				U(inc[i][0], inc[i][1] + k);
				U(inc[i][0] + k, inc[i][1]);
				add(inc[i][0]);
			} else if (inc[i].size() == 1u) {
				clear(inc[i][0]);
				clear(k * 2 + 1);
				U(inc[i][0], k * 2 + 1);
				U(inc[i][0] + k, k * 2 + 2);
				add(inc[i][0]);
			} else assert(0);
		} else {
			if (inc[i].size() == 2u) {
				clear(inc[i][0]);
				clear(inc[i][1]);
				U(inc[i][0], inc[i][1]);
				U(inc[i][0] + k, inc[i][1] + k);
				add(inc[i][0]);
			} else if (inc[i].size() == 1u) {
				clear(inc[i][0]);
				clear(k * 2 + 1);
				U(inc[i][0] + k, k * 2 + 1);
				U(inc[i][0], k * 2 + 2);
				add(inc[i][0]);
			} else assert(1);
		}

		cout << cur << '\n';
	}

}
