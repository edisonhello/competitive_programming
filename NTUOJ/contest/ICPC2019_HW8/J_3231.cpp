#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

vector<int> s = {1, 1, 1};
vector<int> k2 = {1, 3, 6, 10, 17, 28, 44, 68, 104};
vector<int> k3 = {1, 1, 2, 6, 24, 72, 180, 428, 1042, 2512, 5912, 13592, 30872, 69560, 155568, 345282, 761312, 1669612, 3645236, 7927404, 17180092};

int main() {
	while (s.size() <= 1000020) {
		int n = s.size();
		s.push_back(((s[n - 1] + s[n - 3]) % mod + mod) % mod);
	}
	while (k2.size() <= 1000020) {
		int n = k2.size();
		k2.push_back(((3ll * s[n + 2] + s[n - 1 + 2] + s[n - 2 + 2] - 2 - n - 2) % mod + mod) % mod);
	}
	while (k3.size() <= 1000020) {
		int n = k3.size();
		k3.push_back(((3ll*k3[n-1] - 4ll*k3[n-3] + 3ll*k3[n-4] - 4ll*k3[n-5] - 9ll*k3[n-6] + 2ll*k3[n-7] + 5ll*k3[n-8] + 9ll*k3[n-9] + 17ll*k3[n-10] + 16ll*k3[n-11] + 14ll*k3[n-12] + 8ll*k3[n-13] - 2ll*k3[n-14] - 5ll*k3[n-15] - 5ll*k3[n-16] - 6ll*k3[n-17] - 4ll*k3[n-18] - k3[n-19]) % mod + mod) % mod);
	}
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		if (k == 1) {
			if (n == 1) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		if (k == 2) {
			if (n == 1) cout << 1 << '\n';
			else if (n == 2) cout << 2 << '\n';
			else if (n == 3) cout << 6 << '\n';
			else cout << k2[n - 2] * 2 % mod << '\n';
		}
		if (k == 3) cout << k3[n] << '\n';
	}
}
