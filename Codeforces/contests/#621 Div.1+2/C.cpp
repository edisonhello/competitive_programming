#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	long long mo = 0;
	for (int i = 'a'; i <= 'z'; ++i) {
		long long cc= 0 ;
		for (char c : s) if (c == i) ++cc;
		mo = max(mo, cc);
	}

	for (int i = 'a'; i <= 'z'; ++i) {
		for (int j = 'a'; j <= 'z'; ++j) {
			long long cc = 0, ii = 0;
			for (char c : s) {
				if (c == j) cc += ii;
				if (c == i) ++ii;
			}
			mo = max(mo, cc);
		}
	}

	cout << mo << endl;
}
