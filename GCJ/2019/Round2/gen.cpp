#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int t = 1; cout << t << endl;
    int n = 10; cout << n << endl;
    vector<pair<int, pair<int, int>>> v;
    int i = rand() % 100 + 1, j = rand() % 100 + 1;
    while (n--) {
        int a = rand() % 100 + 1;
        int b = rand() % 100 + 1;
        v.emplace_back(a * i + b * j, make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for (auto p : v) cout << p.second.first << " " << p.second.second << endl;
}
