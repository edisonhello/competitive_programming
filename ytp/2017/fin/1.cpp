#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
bool p[maxn];

int main() {
    int n; cin >> n;
    vector<int> pr;
    p[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (!p[i]) pr.push_back(i);
        for (int j = 0; i * pr[j] <= n; ++j) {
            p[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        } 
    }
        for (int i = n; i >= 1; --i) {
            if (p[i] == p[n]) cout << i << ' ';
        }
        cout << endl;
}
