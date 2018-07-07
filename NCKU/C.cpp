#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int inf = 100000000;

int main() {
    int t; while(cin >> t) {
    string s; getline(cin, s);
    while (t--) {
        getline(cin, s);
        vector<long long> v;
        long long x;
        stringstream ss(s);
        while (ss >> x) v.push_back(x);
        int n = v.size();
        long long  ans = -(1ll << 60) - 1;
        int al = -1, ar = -1;
        int z = 0;
        for (int i = 0; i < n; ) {
            if (v[i] == 0) {
                ++i;
                ++z;
                continue;
            }
            int j = i;
            while (j < n && v[j] != 0) ++j;
            int mins = 0;
            long long p = 1;
            for (int k = i; k < j; ++k) {
                p *= v[k];
                if (v[k] < 0) ++mins;
            }
            if (p > ans) {
                ans = p;
                al = i, ar = j - 1;
            }
            if (mins % 2 == 0) {
                if (p > ans) ans = p, al = i, ar = j - 1;
            } else {
                long long q = 1;
                int cc = -1;
                for (int k = i; k < j; ++k) if (v[k] < 0) {
                    if (k + 1 < j) cc = k + 1;
                    for (int r = k + 1; r < j; ++r) {
                        q *= v[r];
                    }
                    break;
                }
                if (cc != -1 && q > ans) ans = q, al = cc, ar = j - 1;
                q = 1;
                cc = -1;
                for (int k = j - 1; k >= i; --k) if (v[k] < 0) {
                    if (k - 1 >= i) cc = k - 1;
                    for (int r = k - 1; r >= i; --r) {
                        q *= v[r];
                    }
                    break;
                }
                if (cc != -1 && q > ans) ans = q, al = i, ar = cc;
            }
            i = j;
        }
        if (z > 0) ans = max(ans, 0ll);
        cout << ans << endl; 
    }
} }
