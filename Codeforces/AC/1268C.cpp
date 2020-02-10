#include <bits/stdc++.h>
using namespace std;
// #include </home/edison/Coding/cpp/template/debug.cpp>

int bit[200005], a[200005], pos[200005], c0[200005], c1[200005];
long long a1[200005], a2[200005];

void add(int x) {
	for (; x; x -= x & -x) ++bit[x];
}
int query(int x, int a = 0) {
	for (; x < 200005; x += x & -x) a += bit[x];
	return a;
}

int q0(int l, int r) {
	int a = 0;
	for (; r; r -= r & -r) a += c0[r];
	for (--l; l; l -= l & -l) a -= c0[l];
	return a;
}
int q1(int l, int r) {
	int a = 0;
	for (; r; r -= r & -r) a += c1[r];
	for (--l; l; l -= l & -l) a -= c1[l];
	return a;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) pos[a[i]] = i;
	for (int i = 1; i <= n; ++i) {
		int p = pos[i];
		a1[i] = a1[i - 1] + query(p);
		add(p);
		// PDE(i, p, a1[i]);
	}

	for (int i = 1; i <= n; ++i) for (int x = i; x < 200005; x += x & -x) ++c1[x];
	int f_r = -1;
	set<int> ze;
	long long cur = 0;
	for (int i = n; i >= 1; --i) {
		int p = pos[i];
		for (int x = p; x < 200005; x += x & -x) ++c0[x];
		for (int x = p; x < 200005; x += x & -x) --c1[x];
		ze.insert(p);
		
		if (f_r == -1) {
			cur += q1(p + 1, n);
			f_r = p;
		} else {
			if (p < f_r) cur += q1(1, p - 1) - q0(p + 1, f_r - 1);
			else cur += q1(p + 1, n) - q0(f_r, p - 1);
		}

		// PDE(cur, f_r);

		while (f_r <= n) {
			auto it = ze.upper_bound(f_r);
			
			if (long long d = q1(f_r + 1, n) - q1(1, f_r - 1); d > 0) {
				cur -= d;
				f_r = (it == ze.end() ? n + 1 : *it);
			} else break;
		}

		// PDE(cur, f_r);

		while (f_r >= 1) {
			auto it = ze.lower_bound(f_r);
			if (it == ze.begin()) break;
			int ll = *prev(it);

			if (long long d = q1(1, ll - 1) - q1(ll + 1, n); d > 0) {
				cur -= d;
				f_r = ll;
			} else break;
		}

		// PDE(cur, f_r);

		a2[i] = cur;
		// PDE(i, cur);
	}

	for (int i = 1; i <= n; ++i) cout << a1[i] + a2[i + 1] << ' ';
	cout << endl;
}
