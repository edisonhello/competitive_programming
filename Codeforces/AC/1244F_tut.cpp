#include <bits/stdc++.h>
using namespace std;
// #include </home/edison/Coding/cpp/template/debug.cpp>

struct Seg {
	int l, r;
	int ll, rr;
	char st, ed;
};

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	bool diff = s[0] != s[n - 1];
	for (int i = 0; i < n - 1; ++i) diff &= s[i] != s[i + 1];
	if (diff) {
		if (k & 1) for (char &c : s) c ^= 'W' ^ 'B';
		cout << s << endl;
		exit(0);
	}
	int fi = 0;
	for (int i = 1; i < n; ++i) if (s[i] == s[i - 1]) fi = i;
	string t = s; s = "";
	for (int i = fi; i < n; ++i) s += t[i];
	for (int i = 0; i < fi; ++i) s += t[i];

	vector<Seg> seg;
	for (int i = 0, j; i < n; i = j) {
		if (i + 2 < n) {
			if (s[i + 1] != s[i] && s[i + 2] == s[i]) {
				int k = i + 2;
				while (k < n && s[k] != s[k - 1]) ++k;
				--k;
				seg.push_back(Seg{i, k, -1, -1, s[i], s[k]});
				j = k;
			} else j = i + 1;
		} else j = i + 1;
	}
	// PDE(seg);

	for (Seg &sg : seg) {
		auto &[l, r, ll, rr, _1, _2] = sg;
		ll = l + k, rr = r - k;
		if (ll > rr) ll = (l + r) / 2 + 1, rr = (l + r) / 2;
	}

	char cur = s[0];
	string ans;
	auto it = seg.begin();
	while (it != seg.end() && it->l == -1) ++it;

	for (int i = 0; i < n; ++i) {
		if (it != seg.end()) {
			if (i < it->l) ans += s[i];
			else if (i < it->ll) ans += (cur = it->st);
			else if (i <= it->rr) {
				ans += cur;
				cur ^= 'W' ^ 'B';
			} else if (i < it->r) ans += (cur = it->ed);
			else if (i == it->r) {
				ans += (cur = it->ed);
				++it;
				while (it != seg.end() && it->l == -1) ++it;
			} else assert(0);
		} else ans += s[i];
	}

	int z = 0;
	for (int i = fi; i < n; ++i) s[i] = ans[z++];
	for (int i = 0; i < fi; ++i) s[i] = ans[z++];

	cout << s << endl;
}


// BBBBBBBBBBBBBBWBWBWBWWWWWWWWWWBWBWBWBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBWBWBWWWWWWWWWWWWBWBWBBBBBBBBBBBBBBB
