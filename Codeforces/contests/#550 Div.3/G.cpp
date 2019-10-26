#include <bits/stdc++.h>
using namespace std;

int a[200005], pos[200005], ans[200005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        if (lis.empty()) {
            lis.push_back(a[i]);
            pos[i] = 1;
        } else if (a[i] > lis.back()) {
            lis.push_back(a[i]);
            pos[i] = lis.size();
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            pos[i] = it - lis.begin() + 1;
            *it = a[i];
        }
    }
    for (int i = 0; i < n; ++i) ans[i] = 1;
    int req = lis.size();
    for (int i = n - 1; i >= 0; --i) {
        if (pos[i] == req) {
            ans[i] = 0;
            --req;
        }
    }
    vector<int> lds;
    for (int i = 0; i < n; ++i) if (ans[i]) lds.push_back(a[i]);
    if (lds.size() <= 1u);
    else {
        for (int i = 1; i < int(lds.size()); ++i) if (lds[i] >= lds[i - 1]) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << endl;
}
