#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        long long n, m; cin >> n >> m;
        if (n == 1) {
            if (m > 1) cout << "-1" << '\n';
            else if (m == 1) cout << "1" << '\n';
            else cout << "0" << '\n';
        } else if (n == 2) {
            if (m > 3) cout << "-1" << '\n';
            else if (m >= 2) cout << "2" << '\n';
            else if (m == 1) cout << "1" << '\n';
            else cout << "-1" << '\n';
        } else if (n == 3) {
            if (m < 2) cout << "-1" << '\n';
            else if (m <= 4) cout << "2" << '\n';
            else if (m <= 6) cout << "3" << '\n';
            else cout << "-1" << '\n';
        } else if (n == 4) {
            if (m < 3) cout << "-1" << '\n';
            else if (m <= 5) cout << "2" << '\n';
            else if (m <= 8) cout << "3" << '\n';
            else if (m <= 10) cout << "4" << '\n';
            else cout << "-1" << '\n';
        } else {
            if (m < n - 1) cout << "-1" << '\n';
            else if (m <= n + 1) cout << "2" << '\n';
            else if (m <= n + 1 + (n - 2) + 1) cout << "3" << '\n';
            else {
                auto ok = [&] (long long deg) {
                    
                    long long mm = m;
                    mm -= n;
                    deg -= 1;
                    // cerr << "ok(" << deg << ") = " << ((n * deg) / 2 >= mm) << endl;
                    if ((n * deg) / 2 >= mm) return 1;
                    return 0;
                };
                long long L = 4, R = n;
                while (L < R) {
                    long long D = (L + R) >> 1;
                    if (ok(D)) R = D;
                    else L = D + 1;
                }
                if (!ok(L)) cout << "-1" << '\n';
                else cout << L << '\n';
            }
        }
        cout << flush;
    }
}
