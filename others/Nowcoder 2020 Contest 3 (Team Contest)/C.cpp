#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> &a, pair<double, double> &b) {
	return hypot(a.first - b.first, a.second - b.second);
}

double cross(pair<double, double> &a, pair<double, double> &b) {
	return a.first * b.second - a.second * b.first;
}

void solve() {
	int n = 20;
	vector<pair<double, double>> p(20);
	for (int i = 0; i < 20; ++i) cin >> p[i].first >> p[i].second;
	
	double area = 0;
	for (int i = 0; i < 20; ++i) area += cross(p[i], p[(i + 1) % n]);
	if (area < 0) reverse(p.begin(), p.end());

	vector<double> len(20);
	for (int i = 0; i < 20; ++i) len[i] = dist(p[i], p[(i + 1) % n]);

	// cerr << "len: ";
	// for (double i : len) cerr << i << ' ';
	// cerr << endl;

	int i = max_element(len.begin(), len.end()) - len.begin();
	// cerr << "i = " << i << endl;
	int l = (i - 1 + 20) % 20;
	int r = (i + 1) % 20;
	// cerr << "l r " << l << ' ' << r << endl;
	if (len[r] > len[l]) cout << "right" << '\n';
	else cout << "left" << '\n';
}

int main() {
	int t; cin >> t; while (t--) solve();
}
