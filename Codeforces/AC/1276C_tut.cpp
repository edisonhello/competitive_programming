#include <bits/stdc++.h>
using namespace std;
// #include </home/edison/Coding/cpp/template/debug.cpp>

int suf[455555];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; 
	map<int, int> mp; for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		++mp[t];
	}

	int sn = int(sqrt(n)) + 2;
	vector<pair<int, int>> vp;
	for (auto &p : mp) vp.emplace_back(p.second, p.first);
	sort(vp.begin(), vp.end());
	reverse(vp.begin(), vp.end());
	int mx = 0, wi = -1;
	int tp = 0;
	for (int i = (int)vp.size() - 1; i >= 0; --i) suf[i] = suf[i + 1] + vp[i].first;
	while (--sn) {
		for (; tp < (int)vp.size(); ++tp) {
			if (vp[tp].first < sn) break;
		}
		int su = tp * sn + suf[tp];
		// PDE(sn, tp, su);
		if (su >= sn * sn) {
			if (su / sn < sn) continue;
			int am = su / sn * sn;
			if (am > mx) {
				// PDE("up");
				mx = am;
				wi = sn;
			}
		}
	}

	vector<vector<int>> ans(wi, vector<int>(mx / wi, 0));

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	for (auto &p : mp) pq.emplace(min(wi, p.second), p.first);

	vector<int> nu;
	for (int j = 0; j < mx / wi; ++j) {
		vector<pair<int, int>> se;
		for (int i = 0; i < wi; ++i) {
			pair<int, int> nw = pq.top(); pq.pop();
			nu.push_back(nw.second);
			if (nw.first - 1) se.emplace_back(nw.first - 1, nw.second);
		}
		for (auto &p : se) pq.push(p);
	}


	mp.clear();
	for (int i : nu) ++mp[i];
	vp.clear();
	for (auto p : mp) vp.emplace_back(p.second, p.first);
	sort(vp.begin(), vp.end());
	reverse(vp.begin(), vp.end());
	nu.clear();
	for (auto p : vp) for (int i = 0; i < p.first; ++i) nu.push_back(p.second);

	int i = -1, j = -1, it = 0;
	while (it < (int)nu.size()) {
		++i, ++j;
		if (i >= wi) i = 0;
		if (j >= mx / wi) j = 0;
		if (ans[i][j]) ++i;
		if (i >= wi) i = 0;
		ans[i][j] = nu[it++];
	}

	cout << mx << endl;
	cout << wi << ' ' << mx / wi << endl;
	for (int i = 0; i < wi; ++i) {
		for (int j = 0; j < mx / wi; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}

}
