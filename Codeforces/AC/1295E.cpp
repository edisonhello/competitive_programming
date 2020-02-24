#include <bits/stdc++.h>
using namespace std;

int per[200005], pos[200005], co[200005];
long long mn[200005 * 4], tag[200005 * 4];

#define mid ((l + r) >> 1)
void addtag(int o, int l, int r, long long v) {
	// cerr << "add tag " << o << ' ' << l << ' ' << r << ' ' << v << endl;
	mn[o] += v;
	tag[o] += v;
	// cerr << "mn tag = " << mn[o] << ' ' << tag[o] << endl;
}

void push(int o, int l, int r) {
	addtag(o * 2 + 1, l, mid, tag[o]);
	addtag(o * 2 + 2, mid + 1, r, tag[o]);
	tag[o] = 0;
}

void pull(int o) {
	mn[o] = min(mn[o * 2 + 1], mn[o * 2 + 2]);
}

void modify(int o, int l, int r, int ml, int mr, int v) {
	// cerr << "modify " << o << ' ' << l << ' ' << r << ' ' << ml << ' ' << mr << ' ' << v << endl;
	if (r < ml || mr < l) return;
	if (ml <= l && r <= mr) {
		addtag(o, l, r, v);
		return;
	}
	push(o, l, r);
	modify(o * 2 + 1, l, mid, ml, mr, v);
	modify(o * 2 + 2, mid + 1, r, ml, mr, v);
	pull(o);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> per[i];
		pos[per[i]] = i;
	}
	for (int i = 1; i <= n; ++i) cin >> co[i];
	for (int i = 1; i <= n; ++i) {
		modify(0, 1, n - 1, pos[i], n - 1, co[pos[i]]);
		// cerr << "mn[0] = " << mn[0] << endl;
	}
	long long ans = mn[0];
	// cerr << "init ans = " << ans << endl;
	for (int i = 1; i <= n; ++i) {
		modify(0, 1, n - 1, pos[i], n - 1, -co[pos[i]]);
		modify(0, 1, n - 1, 1, pos[i] - 1, co[pos[i]]);
		ans = min(ans, mn[0]);
		// cerr << "i = " << i << " update with " << mn[0] << endl;
	}

	cout << ans << endl;
}
