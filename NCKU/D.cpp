#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const long long mod = 1e9 + 123, p = 131;

long long h[maxn], pw[15];
vector<string> z[15];
int cnt[200];

map<long long, int> mp[15];

int main() {
    int n; 
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> n && n) {
        vector<string> v;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= 10; ++i) mp[i].clear();
        for (int i = 1; i <= 10; ++i) z[i].clear();
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            v.push_back(s);
            long long q = 0;
            for (int j = 0; j < s.size(); ++j) {
                q = (q * p + s[j]) % mod;
            }
            mp[s.size()][q] = i;
        }
        pw[0] = 1;
        for (int i = 1; i <= 10; ++i) pw[i] = pw[i - 1] * p % mod;
        string t; cin >> t;
        h[0] = t[0];
        for (int i = 1; i < t.size(); ++i) h[i] = (h[i - 1] * p + t[i]) % mod;
        for (int i = 1; i <= 10; ++i) {
            for (int j = 0; j < t.size(); ++j) {
                if (j - i + 1 >= 0) {
                    int x = j - i + 1;
                    long long a = x == 0 ? h[j] : (h[j] - pw[i] * h[x - 1] % mod + mod) % mod;
                    if (mp[i].find(a) != mp[i].end()) ++cnt[mp[i][a]];
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) mx = max(mx, cnt[i]);
        cout << mx << '\n';
        for (int i = 0; i < n; ++i) if (cnt[i] == mx) cout << v[i] << '\n';
    }
    return 0;
}
