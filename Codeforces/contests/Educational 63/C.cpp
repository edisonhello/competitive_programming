#include <bits/stdc++.h>
using namespace std;

long long x[300005], p[300005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= m; ++i) cin >> p[i];
    long long g = x[2] - x[1];
    for (int i = 3; i <= n; ++i) g = __gcd(g, x[i] - x[i - 1]);
    for (int i = 1; i <= m; ++i) {
        if (g % p[i] == 0) {
            cout << "YES" << endl;
            cout << x[1] << " ";
            cout << i << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
}
