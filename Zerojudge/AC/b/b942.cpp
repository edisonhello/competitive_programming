#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; while (getline(cin, s)) {
        vector<int> v;
        stringstream ss(s);
        int t; while (ss >> t) v.push_back(t);
        int n = v.size(), sum = 0;
        for (int i : v) sum += i;
        set<int> fi, se;
        // cout << "aoao" << endl;
        for (int i = 0; i < (1 << min(14, n)); ++i) {
            int sum = 0;
            for (int j = 0; j < 14; ++j) {
                if (i & (1 << j)) sum += v[j];
            }
            fi.insert(sum);
            // cout << i << " " << (1 << min(14, n)) << endl;
        }
        for (int i = 0; i < (1 << max(min(14, n - 14), 0)); ++i) {
            int sum = 0;
            for (int j = 0; j < 14; ++j) {
                if (i & (1 << j)) sum += v[j + 14];
            }
            se.insert(sum);
            // cout << i << " " << (1 << min(14, n)) << endl;
        }
        // cout << "lala" << endl;
        int ans = INT_MIN;
        for (int i : se) {
            ans = max(ans, i * (sum - i));
            int ha = sum / 2 - i;
            auto it = fi.lower_bound(ha);
            if (it != fi.end()) ans = max(ans, (i + *it) * (sum - i - *it));
        }
        cout << ans << '\n';
    }
}
