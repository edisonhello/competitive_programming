#include <bits/stdc++.h>
using namespace std;

int a[1003], b[1004];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] && b[i]) {
                int g = __gcd(a[i], b[i]);
                cout << a[i] / g << "/" << b[i] / g << '\n';
                break;
            } else if (a[i]) {
                cout << "1/0" << '\n';
                break;
            } else if (b[i]) {
                cout << "0/1" << '\n';
                break;
            }
        }
    }
}
