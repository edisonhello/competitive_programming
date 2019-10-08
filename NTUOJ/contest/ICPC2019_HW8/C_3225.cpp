#include <bits/stdc++.h>
using namespace std;

#define HH uint64_t

string dfs3(HH h, int dep) {
	if (dep == 15) {
		if (h == 0) return "\n";
		else return "";
	}
	for (HH t : (dep == 14 ? vector<HH>{0} : vector<HH>{4, 5})) {
		HH ch = (h >> (56 - dep * 4)) ^ t;
		char c = (char)ch;
		if (c < 'A' || c > 'Z') continue;
		string rt = dfs3(h ^ (ch << (56 - dep * 4)), dep + 1);
		if (rt.size()) return string(1, c) + rt;
	}
	return "";
}

string dfs2(HH h) {
	for (HH t : vector<HH>{4, 5}) {
		HH lb = (h >> 60) ^ t;
		for (HH hb : vector<HH>{4, 5}) {
			char c = (hb << 4) | lb;
			if (c < 'A' || c > 'Z') continue;
			string rt = dfs3(h ^ (lb << 60) ^ hb, 0);
			if (rt.size()) return string(1, c) + rt;
		}
	}
	return "";
}

string dfs1(HH h, int dep) {
	if (dep == 5) return dfs2(h);
	for (char c : vector<char>{'A', 'B', 'Y', 'Z'}) {
		HH ch = (HH)c;
		ch <<= 4 * (4 - dep);
		string rt = dfs1(h ^ ch, dep + 1);
		if (rt.size()) return string(1, c) + rt;
	}
	return "";
}

int main() {
	int t; cin >> t; while (t--) {
		HH h; cin >> h;
		string ans = dfs1(h, 0);
		if (ans.empty()) ans = "impossible\n";
		cout << ans;
	}
}
