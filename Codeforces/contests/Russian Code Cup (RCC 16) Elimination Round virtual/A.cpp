#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, t; cin >> n >> m >> t;
    while (n--) {
        vector<int> a;
        int n; cin >> n;
        a.resize(n);
        for (int &i : a) cin >> i;
        // sort(a.begin(), a.end());

        int mx = 0;

        auto test = [&] (vector<int> &v) -> void {
            int mm = m;
            int c = 0;
            for (int i : v) {
                if (mm >= i) {
                    ++c;
                    mm -= i;
                } else break;
            }
            mx = max(mx, c);
        };

        test(a);
        for (int i = 0; i < n; ++i) {
            vector<int> b = a;
            b[i] = t;
            test(b);
        }
        cout << mx << '\n';
    }
}
