#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<long long> a(n), nu;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 2) nu.push_back(a[i] - 1);
		if (a[i] > 1) nu.push_back(a[i]);
		nu.push_back(a[i] + 1);
	}
	sort(nu.begin(), nu.end());
	nu.resize(unique(nu.begin(), nu.end()) - nu.begin());
	random_shuffle(nu.begin(), nu.end());
	nu.resize(min((int)nu.size(), 20));

	long long mn = LLONG_MAX;
	vector<long long> prim;
	for (long long i : nu) {
		for (int j = 2; 1ll * j * j <= i; ++j) {
			if (i % j == 0) {
				prim.push_back(j);
				while (i % j == 0) i /= j;
			}
		}
		if (i > 1) prim.push_back(i);
	}
	sort(prim.begin(), prim.end());
	prim.resize(unique(prim.begin(), prim.end()) - prim.begin());
	
	for (long long p : prim) {
		long long cnt = 0;
		for (long long i : a) {
			long long d = i % p;
			cnt += min(d == i ? LLONG_MAX : d, p - d);
		}
		mn = min(mn, cnt);
	}

	cout << mn << endl;
}
