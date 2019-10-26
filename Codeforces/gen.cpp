#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int t = 5; cout << t << endl; while (t--) {
        int n = rand() % 10 + 1; cout << n << endl;
        vector<pair<int, int>> v;
        for (int i = 1; i < n; ++i) {
            v.emplace_back(i, rand() % i);
        }
        vector<int> o(n);
        iota(o.begin(), o.end(), 1);
        for (auto &p : v) cout << o[p.first] << ' ' << o[p.second] << '\n';
    }
}
