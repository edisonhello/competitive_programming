#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1000, m = 1000;
    cout << n << " " << m << endl;
    for (int i = 2; i <= n; ++i) {
        cout << rand() % (i - 1) + 1 << " " << i << " " << i << endl;
    }
}
