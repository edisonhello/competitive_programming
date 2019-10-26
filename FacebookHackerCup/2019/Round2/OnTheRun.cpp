#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        cout << "Case #" << T << ": ";
        int n, m, k; cin >> n >> m >> k;
        if (k == 1) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            cout << "N\n";
        } else {
            int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
            int g = abs(a - c) + abs(b - d);
            int h = abs(a - e) + abs(b - f);
            int i = abs(c - e) + abs(d - f);
            if (g % 2 == 0 && h % 2 == 0 && i % 2 == 0) cout << "Y\n";
            else cout << "N\n";
        }
    }
}
