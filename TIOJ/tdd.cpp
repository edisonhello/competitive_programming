#include <bits/stdc++.h>
using namespace std;

long double fpow(long double a, int n) {
    long double ret = 1.0;
    for (; n; n >>= 1, a *= a) if (n & 1) ret *= a;
    return ret;
}

int main() {
    int n, m; cin >> n >> m;
    long double ans = 0.0;
    for (int k = 1; k <= 10000; ++k) {
        // long double pk1 = (1.0 - fpow(0.5, k - 1)), pk2 = (1.0 - fpow(0.5, k - 2));
        // cout << pk1 << ' ' << pk2 << endl;
        // cout << (1.0 - fpow(pk1, m - 1)) << ' ' << (1.0 - fpow(pk2, n - m)) << endl;
        long double p = fpow(0.5, k);
        ans += p * fpow(1.0 - p, m - 1) * fpow(1.0 - p - p, n - m);
        // cout << ans << endl;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
