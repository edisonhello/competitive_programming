#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; while (t--) {
        long long n, a, b, c, d; cin >> n >> a >> b >> c >> d;
        if (d > b) swap(a, c), swap(b, d);
        long long L = 0, R = (n - 1) / b + 1;
        long long $$ = LLONG_MAX;
        auto cost = [&] (const long long z) {
            if (z < 0) return LLONG_MAX;
            return max(((n - z * b - 1) / d + 1), 0ll) * c + z * a;
        };
        auto update = [&] (const long long z) {
            if (z < 0) return;
            $$ = min($$, cost(z));
        };
        while (R > L) {
            long long M = (L + R) >> 1;
            update(M);
            update(M + 1);
            if (cost(M) > cost(M + 1)) L = M + 1;
            else R = M - 1;
        }
        update(L - 1);
        update(L);
        update(L + 1);
        cout << $$ << '\n';
    }
}
