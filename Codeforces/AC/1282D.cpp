#include <bits/stdc++.h>
using namespace std;

int guess(string s) {
	map<string, int> mp;
	if (auto it = mp.find(s); it != mp.end())
		return it->second;
	cout << s << endl;
	fflush(stdout);
	int t; cin >> t;
	if (t == 0) exit(0);
	return mp[s] = t;
}


int main() {
	string a300, b300;
	for (int i = 0; i < 300; ++i) a300 += "a", b300 += "b";
	int len_a = guess(a300), len_b = guess(b300);
	int len = 600 - len_a - len_b; 
	int ca = len_b - 300 + len, cb = len_a - 300 + len;
	if (ca == 0) {
		string ans;
		for (int i = 0; i < cb; ++i) ans += "b";
		guess(ans);
	} if (cb == 0) {
		string ans;
		for (int i = 0; i < ca; ++i) ans += "a";
		guess(ans);
	}
	string base, ans;
	for (int i = 0; i < len; ++i) base += "a";
	ans = base;
	int ge = 0;
	for (int i = 0; i < len - 1; ++i) {
		base[i] = 'b';
		if (guess(base) == cb - 1) ans[i] = 'b', ++ge;
		base[i] = 'a';
	}
	if (ge != cb) ans.back() = 'b';
	guess(ans);
}
