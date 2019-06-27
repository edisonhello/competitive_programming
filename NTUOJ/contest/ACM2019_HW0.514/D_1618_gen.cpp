#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int t = 10; cout << t << endl; while (t--) {
        int n = 1000; cout << n << endl;
        for (int i = 0; i < n; ++i) cout << char(rand() % 26 + 'a'); cout << endl;
        int q = 10000; cout << q << endl;
        while (q--) {
            int l = rand() % n + 1, r = rand() % n + 1;
            if (l > r) swap(l, r);
            cout << l << " " << r << endl;
        }
    }
}
