#include <bits/stdc++.h>
using namespace std;

template <typename T> tuple<T, T, T> extgcd(T a, T b) {
	if (!b) return make_tuple(a, 1, 0);
	T d, x, y;
	tie(d, x, y) = extgcd(b, a % b);
	return make_tuple(d, y, x - (a / b) * y);
}

bool notp[2000006];
vector<int> ps;
int ff[2000006];

int main() {
	for (int i = 2; i <= 2000000; ++i) {
		if (!notp[i]) {
			ps.push_back(i);
			ff[i] = i;
			for (long long j = 1ll * i * i; j <= 2000000; j += i) {
				ff[j] = i;
				notp[j] = 1;
			}
		}
	}
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) {
		long long a, b; cin >> a >> b;
		if (__gcd(a, b) != 1) {
			long long g = __gcd(a, b);
			a /= g, b /= g;
			cout << a + 1 << ' ' << b << ' ' << 1 << ' ' << b << '\n';
		} else {
			set<int> pf;
			long long bb = b;
			while (bb > 1) {
				pf.insert(ff[bb]);
				bb /= ff[bb];
			}

			if (pf.size() <= 1u) cout << "-1 -1 -1 -1" << '\n';
			else {
				long long p = *pf.begin();
				long long q = *next(pf.begin());
				auto t = extgcd(p, q);
				// cerr << "p q t " << p << ' ' << q << ' ' << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
				if (get<1>(t) < 0 || get<2>(t) > 0) {
					long long zzz = max(abs(get<1>(t)) / q, get<2>(t) / p) + 1;
					get<1>(t) += q * zzz;
					get<2>(t) -= p * zzz;
				}
				// cerr << "t " << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
				long long zz = a / get<0>(t);
				get<1>(t) *= zz;
				get<2>(t) *= zz;

				assert(get<2>(t) <= 0);
				get<2>(t) *= -1;

				long long x = get<1>(t) * p;
				long long y = get<2>(t) * q;
				long long bx = b;
				long long by = b;
				long long g = __gcd(bx, x);
				bx /= g;
				x /= g;
				g = __gcd(by, y);
				by /= g;
				y /= g;
				cout << x << ' ' << bx << ' ' << y << ' ' << by << endl;
			}
		}
	}
}
