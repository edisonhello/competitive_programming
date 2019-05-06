#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int n = 100000, q = 100000;
    cout << n << " " << q << endl;
    int L = n - 1, R = n - 1; 
    while (L + R) {
        if (L) {
            int res = rand() & 1;
            if ((res & 1) && R > L) {
                --R; cout << ")";
            } else {
                --L; cout << "(";
            }
        } else {
            --R;
            cout << ")";
        }
    }
    cout << endl;
    while (q--) {
        int p = rand() % (2 * n - 2) + 1;
        cout << p << " " << p << '\n';
    }
}
