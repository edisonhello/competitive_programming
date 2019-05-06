#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 100000; cout << n << " ";
    int q = 100000; cout << q << endl;
    for (int i = 1; i <= n; ++i) {
        cout << rand() % 200001 - 100000;
        cout << " \n"[i == n];
    }
    for (int i = 1; i <= q; ++i) {
        cout << "<>"[rand() & 1] << " " << rand() % 200001 - 100000 << '\n';
    }
}
