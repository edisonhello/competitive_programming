#include <bits/stdc++.h>
using namespace std;
 
template <typename T> tuple<T, T, T> extgcd(T a, T b) {
	if (!b) return make_tuple(a, 1, 0);
	T d, x, y;
	tie(d, x, y) = extgcd(b, a % b);
	return make_tuple(d, y, x - (a / b) * y);
}
 
int main() {
	int n, A; cin >> n >> A;
	vector<long long> a(n), b(n), o(n);
	iota(o.begin(), o.end(), 1);
	for (int i = 0; i < n; ++i) cin >> a[i];
 
	for (int i = 0; i < n; ++i) for (int j = 1; j < n; ++j) {
		if (a[j - 1] < a[j]) {
			swap(a[j - 1], a[j]);
			swap(o[j - 1], o[j]);
		}
	}
 
	if (a[0] < A) exit((cout << -1 << endl, 0));
	{
		int g = 0;
		for (int i : a) g = __gcd(g, i);
		if (A % g) exit((cout << -1 << endl, 0));
	}
 
	long long AA = A;
	for (int i = n - 1; i > 0; --i) {
		long long gg = 0;
		for (int j = 0; j < i; ++j) gg = __gcd(gg, (long long)a[j]);
		auto [d, aa, bb] = extgcd(gg, a[i]);
		assert(AA % d == 0);
		long long tt = AA / d;
		aa *= tt; bb *= tt;
		b[i] = bb;
		if (i == 1) b[0] = aa;
		AA -= a[i] * b[i];
	}
 
	if (n == 1) {
		if (a[0] != A) {
			cout << -1 << endl;
			exit(0);
		} else b[0] = 1;
	}
 
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += 1ll * a[i] * b[i];
	}
	assert(sum == A);
 
	for (int i = 0; i < n; ++i) {
		cerr << "b[i] = " << b[i] << endl;
	}

	vector<vector<int>> ans;
	vector<long long> cur(n, 0);
	if (b[0] >= 0) {
		while (b[0] > 0) {
			assert(cur[0] == 0);
			ans.emplace_back(vector<int>{1, 0});
			cur[0] = a[0];
			--b[0];

			for (int i = 1; i < n; ++i) if (b[i] < 0) {
				while (b[i] < 0 && cur[0] > 0) {
					int f = min(cur[0], a[i] - cur[i]);
					if (f == 0) break;
					ans.emplace_back(vector<int>{3, 0, i});
					cur[0] -= f;
					cur[i] += f;

					if (cur[i] == a[i]) {
						ans.emplace_back(vector<int>{2, i});
						++b[i];
						cur[i] = 0;
					}
				}
			}
		}
	} else {
		while (b[0] < 0) {
			for (int i = 1; i < n; ++i) {
				while (b[i] > 0 || cur[i] > 0) {
					if (cur[i] == 0) {
						ans.emplace_back(vector<int>{1, i});
						--b[i];
						cur[i] = a[i];
					} else {
						int f = min(a[0] - cur[0], cur[i]);
						if (!f) break;
						ans.emplace_back(vector<int>{3, i, 0});
						cur[0] += f;
						cur[i] -= f;
					}
				}
			}

			assert(cur[0] == a[0]);
			ans.emplace_back(vector<int>{2, 0});
			cur[0] = 0;
			++b[0];
		}
	}

	while ([&] () -> bool { for (int i = 1; i < n; ++i) if (b[i]) return 1; return 0; } ()) {
		for (int i = 1; i < n; ++i) {
			while (cur[0] < a[0]) {
				if (cur[i] > 0) {
					int f = min(a[0] - cur[0], cur[i]);
					if (!f) break;
					ans.emplace_back(vector<int>{3, i, 0});
					cur[0] += f;
					cur[i] -= f;
				} else if (b[i] > 0) {
					ans.emplace_back(vector<int>{1, i});
					cur[i] = a[i];
					--b[i];
				} else break;
			}
		}

		for (int i = 1; i < n; ++i) {
			if (b[i] >= 0) continue;
			while (cur[0] > 0) {
				int f = min(a[i] - cur[i], cur[0]);
				if (!f) break;
				ans.emplace_back(vector<int>{3, 0, i});
				cur[0] -= f;
				cur[i] += f;

				if (cur[i] == a[i]) {
					ans.emplace_back(vector<int>{2, i});
					cur[i] = 0;
					++b[i];
				}
			}
		}
	}

	cout << ans.size() << endl;
	for (auto &v : ans) {
		for (int i = 0; i < (int)v.size(); ++i) {
			if (i) cout << ' ' << o[v[i]];
			else cout << v[i];
		}
		cout << '\n';
	}
} 
