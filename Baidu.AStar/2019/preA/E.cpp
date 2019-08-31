#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
    /* a[1] = 1;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 1; j < i; ++j) {
            a[i] = (a[i] + a[j] * j) % i;
        }
    }
    for (int z = 0; z < 6; ++z) 
        for (int i = 1; i <= 100; ++i) if (i % 6 == z) cout << i << " " << a[i] << endl; */
    int t; cin >> t; while (t--) {
        long long n; cin >> n;
        if (n % 6 == 0) {
            cout << n / 6 * 3 << '\n';
        } else if(n % 6 == 1) {
            cout << n / 6 * 4 + 1 << '\n';
        } else if (n % 6 == 2) {
            cout << n / 6 * 3 + 1 << '\n';
        } else if (n % 6 == 3) {
            cout << n / 6 << '\n';
        } else if( n % 6 == 4) {
            cout << n - 1<< '\n';
        } else cout << n / 6 << '\n';
    }
}
