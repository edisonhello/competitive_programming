#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        s = " " + s;
        int q; cin >> q; while (q--) {
            int l, r; cin >> l >> r;
            int le = r - l + 1;
            for (int i = 1; i <= le; ++i) if (le % i == 0) {
                bool ok = true;
                for (int j = l; j + i <= r; ++j) if (s[j] != s[j + i]) {
                    ok = false;
                    break;
                }
                if (ok) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}
