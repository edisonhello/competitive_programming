#include <bits/stdc++.h>
using namespace std;

int rec[2000006];

/* int f(int x) {
    if (x == 1) return 1;
    if (x % 2 == 0) return f(x / 2);
    if (rec[x]) return rec[x];
    return rec[x] = f(x - 1) + f(x + 1);
} */

int f(int x) {
    if (x == 1) return 1;
    if (x % 2 == 0) return f(x / 2);
    if (rec[x]) return rec[x];
    return rec[x] = f(x / 2) + f(x / 2 + 1);
}

int main() {
    // for (int i = 1; i <= 50; ++i) cout << setw(3) << i << " " << setw(3) << f(i) << " " << bitset<10>(i) << endl;
    int x; cin >> x; cout << f(x) << endl;
}
