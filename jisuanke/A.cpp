#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> a) {
    vector<int> l;
    for (int i : a) {
        if (l.empty() || i > l.back()) l.push_back(i);
        else *lower_bound(l.begin(), l.end(), i) = i;
    }
    return l.size();
}

int main() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        a.push_back(t);
    }
    int len = lis(a);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> b;
        for (int j = 0; j < n; ++j) if (j != i) b.push_back(a[j]);
        if (lis(b) != len) ++cnt;
    }
    cout << cnt << endl;
}
