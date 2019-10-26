#include <bits/stdc++.h>
using namespace std;


int main() {
    srand(time(0) * clock());
    int t = 1; cout << t << endl;
    int n = 8; cout << n << " ";
    int h = 12; cout << h << endl;
    for (int i = 1; i <= n; ++i) {
        int x = i; cout << x << " ";
        int l = rand() % (h + 1), r = rand() % (h + 1);
        if (l > r) swap(l, r);
        cout << l << " " << r << endl;
    }
}
