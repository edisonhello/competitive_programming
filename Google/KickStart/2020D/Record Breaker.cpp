#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, T = 0; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        vector<bool> ok1(n, false);
        ok1[0] = 1;
        int mx = v[0];
        for (int i = 1; i < n; ++i) {
            if (v[i] > mx) ok1[i] = 1;
            mx = max(mx, v[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (ok1[i] && (i == n - 1 || v[i] > v[i + 1])) ++cnt;
        }
        
        cout << "Case #" << (++T) << ": " << cnt << endl;
    }
}
