#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const long long inf = 1e18;
vector<int> g[maxn], ds[maxn];
int s[maxn], t[maxn], d[maxn], a[maxn], c[maxn];

struct fenwick {
    vector<long long> dat;
    void init(int sz) {
        dat.resize(sz);
        for (int i = 0; i < sz; ++i) dat[i] = inf;
    }
    void add(int p, long long v) {
        for (; p < dat.size(); p += p & -p)
            dat[p] = min(dat[p], v);
    }
    long long query(int p) {
        long long v = inf;
        for (; p; p -= p & -p)
            v = min(v, dat[p]);
        return v;
    }
};

fenwick bit[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d %d", &s[i], &t[i], &d[i], &a[i], &c[i]);
        g[t[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) ds[i].push_back(a[j]);
        if (i == 1) ds[i].push_back(0);
        sort(ds[i].begin(), ds[i].end());
        ds[i].resize(unique(ds[i].begin(), ds[i].end()) - ds[i].begin());
        bit[i].init(ds[i].size() + 10);
    }
    bit[1].add(1, 0);
    for (int i = 2; i <= n; ++i) {
        for (int j : g[i]) {
            int x = upper_bound(ds[s[j]].begin(), ds[s[j]].end(), d[j]) - ds[s[j]].begin();
            int y = lower_bound(ds[i].begin(), ds[i].end(), a[j]) - ds[i].begin() + 1;
            long long dp = bit[s[j]].query(x);
            bit[i].add(y, dp + c[j]);
        }
    }
    int q; scanf("%d", &q);
    while (q--) {
        int p, q; scanf("%d %d", &p, &q);
        q = upper_bound(ds[p].begin(), ds[p].end(), q) - ds[p].begin();
        long long ans = bit[p].query(q);
        if (ans > 1e17) ans = -1;
        printf("%lld\n", ans);
    }
}
