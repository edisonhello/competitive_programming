#include <bits/stdc++.h>
using namespace std;
#define data fshuiejfo

struct data {
	int l, r;
	double val;
};

vector<data> v;

void add(int x) {
	if (v.empty()) {
		v.push_back({1, 1, (double)x});
	} else {
		int i = v.back().r + 1;
		int nl = i;
		double tot = x;
		int pp = 1;
		while (v.size()) {
			int npp = pp + (v.back().r - v.back().l + 1);
			double ntt = tot + (v.back().r - v.back().l + 1) * v.back().val;
			if (ntt / npp < v.back().val) {
				nl = v.back().l;
				v.pop_back();
				tot = ntt;
				pp = npp;
			} else break;
		}
		v.push_back({nl, i, tot / pp});
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t; cin >> t;
		add(t);
	}
	for (data &d : v) {
		for (int i = d.l; i <= d.r; ++i) {
			cout << fixed << setprecision(12) << d.val << '\n';
		}
	}
}
