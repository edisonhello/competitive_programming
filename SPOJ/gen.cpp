#include <bits/stdc++.h>
using namespace std;


int main() {
    srand(time(0) * clock());
    int t = 10; cout << t << endl;
    for (int i = 0; i < t; ++i) {
        for (int i = 0; i < 300; ++i) cout << rand() % 10 + '0'; cout << " ";
        for (int i = 0; i < 300; ++i) cout << rand() % 10 + '0'; cout << endl;
    }
}
