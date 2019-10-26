#include <bits/stdc++.h>
using namespace std;

int a, b;

unordered_map<int, int> mp;
int f(int n) {
    if (mp.count(n)) return mp[n];
    if (n == 1) return a;
    else if (n == 2) return b;
    else return mp[n] = f(n - 1) * f(n - 2);
}

int pw(int b, int n, int m, int a = 1) {
    while (n) {
        if (n & 1) a = 1ll * a * b % m;
        b = 1ll * b * b % m; n >>= 1;
    } return a;
}

void pro(int a[][2], int b[][2], int c[][2], int m) {
    tie(c[0][0], c[0][1], c[1][0], c[1][1]) = make_tuple(
        (1ll * a[0][0] * b[0][0] + 1ll * a[0][1] * b[1][0]) % m,
        (1ll * a[0][0] * b[0][1] + 1ll * a[0][1] * b[1][1]) % m,
        (1ll * a[1][0] * b[0][0] + 1ll * a[1][1] * b[1][0]) % m,
        (1ll * a[1][0] * b[0][1] + 1ll * a[1][1] * b[1][1]) % m);
}

int _fib[1005];

int fib(int n, int m) {
    if (n == -1) return 1 % m;
    if (n == 0) return 0;
    if (n <= 39) {
        if (_fib[n] < m) return _fib[n];
        else return _fib[n] % m + m;
    }
    int a[2][2] = {{1, 0}, {0, 1}}, b[2][2] = {{1, 1}, {1, 0}};
    while (n) {
        if (n & 1) pro(a, b, a, m);
        pro(b, b, b, m); n >>= 1;
    } return a[1][0] % m + m;
}

int np[1000006];

int phi(int x) {
    int y = x;
    while (x > 1) {
        int p = np[x];
        while (x % p == 0) x /= p;
        y = y / p * (p - 1);
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= 1000000; ++i) {
        if (np[i]) continue;
        np[i] = i;
        for (long long j = 1ll * i * i; j <= 1000000; j += i) if (!np[j]) np[j] = i;
    }

    _fib[1] = 1;
    for (int i = 2; i <= 100; ++i) _fib[i] = _fib[i - 1] + _fib[i - 2];
    // for (int i = 0; i <= 100; ++i) cout << i << " " << _fib[i] << endl;

    // for (int i = 0; i < 10; ++i) cout << i << " " << fib(i, 100000) << endl;

    int t, T = 0; cin >> t; while (t--) {
        int p, n; cin >> a >> b >> p >> n;
        cout << "Case #" << (++T) << ": ";
        // cerr << "phi(p) = " << phi(p) << endl;
        // cerr << "fib 1 = " << fib(n - 2, phi(p)) << endl;
        // cerr << "fib 2 = " << fib(n - 1, phi(p)) << endl;
        cout << 1ll * pw(a, fib(n - 2, phi(p)), p) * pw(b, fib(n - 1, phi(p)), p) % p << endl;
        mp.clear();
        // cerr << "BF = " << f(n) << "%" << p << " = " << f(n) % p << endl;
    }
}
// fib : 0, 1, 1, 2, 3
// a ^ fib(n - 2) * b ^ fib(n - 1)
