#include <bits/stdc++.h>
using namespace std;

struct node {
	int mx, tag;
} seg[1000006 * 4];

#define mid ((l + r) >> 1)
void addtag(int o, int v) {
	seg[o].mx += v;
	seg[o].tag += v;
}
void push(int o) {
	if (seg[o].tag) {
		addtag(o * 2 + 1, seg[o].tag);
		addtag(o * 2 + 2, seg[o].tag);
		seg[o].tag = 0;
	}
}
void pull(int o) {
	seg[o].mx = max(seg[o * 2 + 1].mx, seg[o * 2 + 2].mx);
}

void build(int o, int l, int r) {
	if (l == r) {
		seg[o].mx = INT_MIN;
		return;
	}
	build(o * 2 + 1, l, mid);
	build(o * 2 + 2, mid + 1, r);
	pull(o);
}

void update(int o, int l, int r, int x, int v) {
	if (l == r) {
		seg[o].mx = max(seg[o].mx, v);
		return;
	}
	if (x <= mid) update(o * 2 + 1, l, mid, x, v);
	else update(o * 2 + 2, mid + 1, r, x, v);
	pull(o);
}

void modify(int o, int l, int r, int ml, int mr, int v) {
	if (mr < l || r < ml) return;
	if (ml <= l && r <= mr) {
		addtag(o, v);
		return;
	}
	push(o);
	modify(o * 2 + 1, l, mid, ml, mr, v);
	modify(o * 2 + 2, mid + 1, r, ml, mr, v);
	pull(o);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, p; cin >> n >> m >> p;
	vector<pair<int, int>> wp(n), am(m);
	vector<tuple<int, int, int>> mst(p);
	for (int i = 0; i < n; ++i) cin >> wp[i].first >> wp[i].second;
	for (int i = 0; i < m; ++i) cin >> am[i].first >> am[i].second;
	for (int i = 0; i < p; ++i) cin >> get<0>(mst[i]) >> get<1>(mst[i]) >> get<2>(mst[i]);

	sort(wp.begin(), wp.end());
	sort(mst.begin(), mst.end());

	build(0, 1, 1000000);
	for (int i = 0; i < m; ++i) update(0, 1, 1000000, am[i].first, -am[i].second);

	long long mx = LLONG_MIN;
	int it = 0;
	for (auto w : wp) {
		for (; it < p && get<0>(mst[it]) < w.first; ++it) 
			modify(0, 1, 1000000, get<1>(mst[it]) + 1, 1000000, get<2>(mst[it]));
		// cerr << "-w.second = " << -w.second << ", seg[0].mx " << seg[0].mx << endl;
		mx = max(mx, 0ll - w.second + seg[0].mx);
	}
	cout << mx << endl;
}
