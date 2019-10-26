#include <bits/stdc++.h>
using namespace std;

int m[1005][2], n;

int go(int now, int pos) {
    static map<pair<int, int>, int> mp;
    if (now == n) return 0;
    if (mp.count(make_pair(now, pos))) return mp[make_pair(now, pos)];
    int l = m[now][0], r = m[now][1];
    if (l <= pos && pos <= r) return go(now + 1, pos);
    int mn = INT_MAX;
    if (r <= pos) {
        mn = (pos - r) / 2 + (pos - r) % 2 + go(now + 1, r);
        if (r - 1 >= l)
            mn = min(mn, (pos - r + 1) / 2 + (pos - r + 1) % 2 + go(now + 1, r - 1));
    } else {
        mn = (l - pos) / 2 + (l - pos) % 2 + go(now + 1, l);
        if (l + 1 <= r)
            mn = min(mn, (l + 1 - pos) / 2 + (l + 1 - pos) % 2 + go(now + 1, l + 1));
    }
    return mp[make_pair(now, pos)] = mn;
}

int main() {
    int t; cin >> t; while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> m[i][0] >> m[i][1];
        int LL = m[0][0], RR = m[0][1];
        for (int i = 1; i < n; ++i) {
            int LLL = max(LL, m[i][0]), RRR = min(RR, m[i][1]);
            if (LLL > RRR) break;
            LL = LLL, RR = RRR;
        }
        cout << min(go(0, LL), min(go(0, LL + 1), min(go(0, RR), go(0, RR - 1)))) << '\n';
    }
}
