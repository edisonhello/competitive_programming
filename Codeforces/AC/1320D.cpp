#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int pp[200005], ipp[200005];

int pw(int b, int n, int m, int a = 1) {
	while (n) {
		if (n & 1) a = 1ll * a * b % m;
		b = 1ll * b * b % m; n >>= 1;
	}
	return a;
}

int inv(int x) { return pw(x, mod - 2, mod); }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pp[0] = 1;
	for (int i = 1; i <= 200002; ++i) pp[i] = 131ll * pp[i - 1] % mod;
	ipp[200002] = inv(pp[200002]);
	for (int i = 200001; i >= 0; --i) ipp[i] = 131ll * ipp[i + 1] % mod;

	int n; cin >> n;
	string s; cin >> s;
	vector<int> pos;
	for (int i = 0; i < n; ++i) if (s[i] == '0') pos.push_back(i);

	if (pos.empty()) {
		int q; cin >> q; while (q--) cout << "Yes" << '\n';
		exit(0);
	}

	vector<int> hh(pos.size());
	hh[0] = ((pos[0] + 1) & 1) + 1;
	for (int i = 1; i < (int)pos.size(); ++i) {
		hh[i] = (hh[i - 1] + (((pos[i] - pos[i - 1]) & 1) + 1) * 1ll * pp[i]) % mod;
	}

	auto GetHH = [&] (int l, int r) -> int {
		// cerr << "Query " << l << ' ' << r << endl;
		int ll = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
		int rr = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;
		if (ll > rr) return 0;
		// cerr << "llrr " << ll << ' ' << rr << endl;
		int hhh = (hh[rr] - (ll ? hh[ll - 1] : 0) + mod) * 1ll * ipp[ll] % mod;
		// cerr << "hhh = " << hhh << ' ' << endl;
		hhh = (0ll + hhh - (((pos[ll] - (ll ? pos[ll - 1] : -1)) & 1) + 1) + (((pos[ll] - (l - 1)) & 1) + 1) + mod) % mod;
		// cerr << "hhh = " << hhh << endl;
		return hhh;
	};

	int q; cin >> q; while (q--) {
		int a, b, l; cin >> a >> b >> l;
		cout << (GetHH(a - 1, a + l - 2) == GetHH(b - 1, b + l - 2) ? "Yes" : "No") << '\n';
	}
}
