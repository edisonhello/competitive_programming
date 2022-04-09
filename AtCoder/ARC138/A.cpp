#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;


    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<pair<int, int>> vl, vr;
    for (int i = k - 1; i >= 0; i--) {
        if (vl.empty() || v[i] <= vl.back().first) vl.emplace_back(v[i], i);
    }
    reverse(vl.begin(), vl.end());

    for (int i = k; i < n; ++i) {
        if (vr.empty() || v[i] >= vr.back().first) vr.emplace_back(v[i], i);
    }

    // for (auto p : vl) {
    //     cout << p.first << ' ' << p.second << endl;
    // }
    // cout << endl;
    // for (auto p : vr) {
    //     cout << p.first << ' ' << p.second << endl;
    // }

    int mn = INT_MAX;

    for (int i = vl.size() - 1, j = vr.size() - 1; i >= 0; --i) {
        while (j >= 0 && vl[i].first < vr[j].first) {
            mn = min(mn, vr[j].second - vl[i].second);
            --j;
        }
    }

    if (mn == INT_MAX) cout << -1 << endl;
    else cout << mn << endl;
}