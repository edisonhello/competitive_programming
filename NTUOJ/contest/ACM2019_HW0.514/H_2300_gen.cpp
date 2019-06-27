#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int t = 1; cout << t << endl;
    int n = 5; cout << n << endl;
    for (int i = 1; i <= n; ++i) cout << rand() % 10 << " "; cout << endl;
    for (int i = 2; i <= n; ++i) cout << rand() % (i - 1) + 1 << " " << i << endl; 
    int q = 5; cout << q << endl;
    while (q--) {
        int c = rand() % 4 + 1;
        cout << c << " ";
        if (c == 1) cout << rand() % n + 1 << " " << rand() % n + 1 << endl;
        if (c == 2) cout << rand() % n + 1 << endl;
        if (c == 3) cout << rand() % n + 1 << " " << rand() % n + 1 << " " << rand() % 10 << endl;
        if (c == 4) cout << rand() % n + 1 << " " << rand() % 10 << endl;
    }
}
