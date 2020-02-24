#include <bits/stdc++.h>
using namespace std;

struct P {
	int x, y;
} pos[2505];

bool Up(const P &a) {
	return a.x >= 0 ? a.y >= 0 : a.y > 0;
}

long long Cross(const P &a, const P &b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

P Sub(const P &a, const P &b) {
	return P{a.x - b.x, a.y - b.y};
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> pos[i].x >> pos[i].y;

	long long ans = 5ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
	for (int i = 0; i < n; ++i) {
		vector<P> ps;
		for (int j = 0; j < n; ++j) if (j != i) ps.push_back(pos[j]);

		sort(ps.begin(), ps.end(), [&] (const P &a, const P &b) -> bool {
			P aa = Sub(a, pos[i]), bb = Sub(b, pos[i]);
			if (Up(aa) && !Up(bb)) return 1;
			if (!Up(aa) && Up(bb)) return 0;
			return Cross(aa, bb) > 0;
		});

		for (int j = 0, k = 0, c = 0; j < (int)ps.size(); ) {
			while (true) {
				int kk = (k + 1) % ps.size();
				if (Cross(Sub(ps[j], pos[i]), Sub(ps[kk], pos[i])) > 0) k = kk, ++c;
				else break;
			}
			auto Calc = [] (long long x) {
				// cerr << "Calc " << x << endl;
				return x * (x - 1) * (x - 2) / 6;
			};
			ans -= Calc(c);

			if (j == k) ++k, ++c;
			++j, --c;
		}
	}

	cout << ans << '\n';
}
