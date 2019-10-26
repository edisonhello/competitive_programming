#include <bits/stdc++.h>
using namespace std;

vector<int> g[10005];

int main() {
    srand(time(0) * clock());
    int n = rand() % 10 + 2;
    cout << n << endl;
    for (int i = 1; i < n; ++i) {
        cout << i + 1 << ' ' << rand() % i + 1 << endl;
    }
}
