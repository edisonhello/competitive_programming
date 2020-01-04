#include <bits/stdc++.h>
using namespace std;

pair<int, int> ev[100005][2];

int lap(pair<int, int> a, pair<int, int> b) {
	return max(a.first, b.first) <= min(a.second, b.second);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < 2; ++j) 
			cin >> ev[i][j].first >> ev[i][j].second;
	
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
		if (lap(ev[i][0], ev[j][0]) + lap(ev[i][1], ev[j][1]) == 1) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;
}
