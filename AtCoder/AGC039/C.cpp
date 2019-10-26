#include <bits/stdc++.h>
using namespace std;

long long up(long long x, int n) {
    if (x & 1) return x >> 1;
    else return (x >> 1) + (1ll << (n - 1));
}

long long sol(int n, long long x) {
    int c = 1;
    long long o = x;
    set<int> v;
    x = up(x, n);
    while (x != o) {
        x = up(x, n), ++c;
        if (v.count(x)) break;
        v.insert(x);
    }
    if (o == x) return c;
    return 0;
}

int main() {
    for (int n = 1; n <= 16; ++n) {
        for (int x = 0; x <= 65566; ++x) {
            long long s = sol(n, x);
            if (!s) continue;
            if (s == 2 * n) continue;
            printf("n = %d, x = %d, val = %lld\n", n, x, s);
            // cout << bitset<10>(x) << endl;
        }
        cout << endl;
    }
}
