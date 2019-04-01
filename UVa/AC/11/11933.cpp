#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned n; while (cin >> n, n) {
        unsigned a[2] = {0};
        unsigned p = 1;
        for (int i = 0; i < 32; ++i) {
            if ((1u << i) & n) {
                a[p ^= 1] |= (1u << i);
            }
        }
        cout << a[0] << " " << a[1] << '\n';
    }
}
