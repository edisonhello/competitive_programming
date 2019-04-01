#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; while (cin >> n >> m) {
        if (m <= 1) {
            cout << "Boring!\n";
            continue;
        }
        vector<int> v; 
        while (n) {
            v.push_back(n);
            n /= m;
        }
        bool ok = true;
        for (int i = 0; i < int(v.size()); ++i) {
            if (v[i] % m && v[i] != v.back()) {
                ok = false;
            }
        }
        if (ok) {
            if (v.empty()) cout << "Boring!\n";
            else if (v.size() == 1u) cout << "Boring!\n";
            else if (v.back() != 1) cout << "Boring!\n";
            else for (int i = 0; i < int(v.size()); ++i) {
                cout << v[i] << " \n"[v[i] == v.back()];
            }
        } else {
            cout << "Boring!\n";
        }
    }
}
