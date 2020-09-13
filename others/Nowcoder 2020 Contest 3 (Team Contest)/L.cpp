#include <bits/stdc++.h>
using namespace std;


int main() {
	string s; cin >> s;
	string t = s.substr(0, 6);
	for (char &c : t) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
	if (t == "lovely") cout << "lovely" << endl;
	else cout << "ugly" << endl;
}
