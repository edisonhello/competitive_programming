#include <bits/stdc++.h>
using namespace std;
// #include </home/edison/Coding/cpp/template/debug.cpp>

vector<int> num;
vector<stack<pair<int *, int>>> rec;

void Assign(int &src, int val) {
	rec.back().emplace(&src, src);
	src = val;
}

#define mid ((l + r) >> 1)
struct Seg {
	int len, llen, rlen, v, tag;
	Seg() : len(0), llen(0), rlen(0), v(0), tag(0) {}
	void ontag() {
		if (llen == len) return;
		Assign(tag, 1);
		Assign(llen, len);
		Assign(rlen, len);
		Assign(v, 1);
	}
} segtree[200005 * 4 * 2 * 2];

void push(int o) {
	if (segtree[o].tag && !segtree[o * 2 + 1].tag) segtree[o * 2 + 1].ontag();
	if (segtree[o].tag && !segtree[o * 2 + 2].tag) segtree[o * 2 + 2].ontag();
}

void pull(int o) {
	Assign(segtree[o].llen, 
			segtree[o * 2 + 1].llen == segtree[o * 2 + 1].len ? segtree[o * 2 + 1].llen + segtree[o * 2 + 2].llen : segtree[o * 2 + 1].llen);
	Assign(segtree[o].rlen, 
			segtree[o * 2 + 2].rlen == segtree[o * 2 + 2].len ? segtree[o * 2 + 2].rlen + segtree[o * 2 + 1].rlen : segtree[o * 2 + 2].rlen);
	Assign(segtree[o].v, 
			segtree[o * 2 + 1].v + segtree[o * 2 + 2].v - (!!segtree[o * 2 + 1].rlen) - (!!segtree[o * 2 + 2].llen) + (segtree[o * 2 + 1].rlen || segtree[o * 2 + 2].llen));
}

void build_seg(int o, int l, int r) {
	segtree[o].len = r - l + 1;
	segtree[o].llen = segtree[o].rlen = segtree[o].v = segtree[o].tag = 0;
	if (l == r) return;
	build_seg(o * 2 + 1, l, mid);
	build_seg(o * 2 + 2, mid + 1, r);
}

void insert_seg(int o, int l, int r, int ml, int mr) {
	// PDE("insert_seg [BEG]", now->len, now->llen, now->rlen, now->v, l, r, ml, mr);
	if (segtree[o].llen == segtree[o].len) {
		return;
	}
	if (mr < l || r < ml) return;
	if (ml <= l && r <= mr) {
		segtree[o].ontag();
		return;
	}
	push(o);
	insert_seg(o * 2 + 1, l, mid, ml, mr);
	insert_seg(o * 2 + 2, mid + 1, r, ml, mr);
	pull(o);
	// PDE("insert_seg [END]", now->len, now->llen, now->rlen, now->v, l, r, ml, mr);
}

vector<pair<int, int>> timeseg[200005 * 4];

void build_time(int o, int l, int r) {
	timeseg[o].clear();
	if (l == r) return;
	build_time(o * 2 + 1, l, mid);
	build_time(o * 2 + 2, mid + 1, r);
}

void insert_time(int o, int l, int r, int ml, int mr, pair<int, int> &seg) {
	if (mr < l || r < ml) return;
	if (ml <= l && r <= mr) {
		timeseg[o].push_back(seg);
		return;
	}
	insert_time(o * 2 + 1, l, mid, ml, mr, seg);
	insert_time(o * 2 + 2, mid + 1, r, ml, mr, seg);
}

int ans;

void dfs_time(int o, int l, int r) {
	// PDE("dfs_time", l, r);
	rec.push_back(stack<pair<int *, int>>());
	for (auto &seg : timeseg[o]) {
		insert_seg(0, 1, num.size() * 2, seg.first, seg.second);
	}

	if (l != r) {
		dfs_time(o * 2 + 1, l, mid);
		dfs_time(o * 2 + 2, mid + 1, r);
	} else {
		ans = max(ans, segtree->v);
	}

	while (rec.back().size()) {
		*rec.back().top().first = rec.back().top().second;
		rec.back().pop();
	}
	rec.pop_back();
}

pair<int, int> segs[200005];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		ans = 0;
		num.clear();

		int n; cin >> n;
		build_time(0, 1, n);

		for (int i = 1; i <= n; ++i) {
			cin >> segs[i].first >> segs[i].second;
			num.push_back(segs[i].first);
			num.push_back(segs[i].second);
		}

		sort(num.begin(), num.end());
		num.resize(unique(num.begin(), num.end()) - num.begin());
		build_seg(0, 1, num.size() * 2);

		for (int i = 1; i <= n; ++i) {
			segs[i].first = (upper_bound(num.begin(), num.end(), segs[i].first) - num.begin()) * 2;
			segs[i].second = (upper_bound(num.begin(), num.end(), segs[i].second) - num.begin()) * 2;

			if (i - 1 >= 1) insert_time(0, 1, n, 1, i - 1, segs[i]);
			if (i + 1 <= n) insert_time(0, 1, n, i + 1, n, segs[i]);
		}
		dfs_time(0, 1, n);

		cout << ans << endl;
	}
}
