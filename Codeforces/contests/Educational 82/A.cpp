#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t; while (t--) {
		string s; cin >> s;
		bool all0 = true;
		for (char c : s) if (c == '1') all0 = false;
		if (all0 == false) {
			while (s[0] == '0') s = s.substr(1, s.size());
			while (s.back() == '0') s.pop_back();
		} else {
			cout << 0 << endl;
			continue;
		}
		int z = 0;
		for (char c : s) if (c == '0') ++z;
		cout << z << endl;
	}
}
