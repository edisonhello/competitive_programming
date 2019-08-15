#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int n = 100; cout << n << endl;
    while (n--) {
        cout << rand() % 100000 << " "
             << rand() % 100000 << " "
             << rand() % 100000 << " "
             << rand() % 100000 << " "
             << rand() % 100000 << " "
             << rand() % 100000 << endl;
    }
}
