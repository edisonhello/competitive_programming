#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

int a[100005], seg[100005 * 4];

#define mid ((l + r) >> 1)
void build(int o, int l, int r) {
    if (l == r) {
        seg[o] = a[l];
        return;
    }
    build(o * 2 + 1, l, mid);
    build(o * 2 + 2, mid + 1, r);
    seg[o] = __gcd(seg[o * 2 + 1], seg[o * 2 + 2]);
}

int query(int o, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[o];
    return __gcd(query(o * 2 + 1, l, mid, ql, qr), query(o * 2 + 2, mid + 1, r, ql, qr));
}

unordered_map<int, long long> cnt;
unordered_map<int, int> fac;

int mp[1000006];

int main() {
    for (int i = 2; i <= 1000000; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            for (auto j = 1ll * i * i; j <= 1000000; j += i) mp[j] = i;
        }
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(0, 1, n);
    for (int i = 1; i <= n; ++i) {
        int ng = a[i];
        int nr = i;
        // cerr << "i = " << i << endl;
        while (nr <= n) {
            int L = nr, R = n;
            while (L < R) {
                int M = (L + R + 1) >> 1;
                if (query(0, 1, n, i, M) < ng) R = M - 1;
                else L = M;
            }
            cnt[ng] += L - nr + 1;

            nr = L + 1;
            ng = query(0, 1, n, i, L + 1);
        }
    }

    int q; cin >> q; while (q--) {
        int k; cin >> k;
        fac.clear();
        while (k > 1) {
            ++fac[mp[k]];
            k /= mp[k];
        }
        // long long ans = 1ll * n * (n + 1) / 2;
        long long ans = 0;
        auto Get = [&] (const int x) { return cnt.count(x) ? cnt[x] : 0; };
        function<void(unordered_map<int, int>::iterator, int)> Dfs = [&] (unordered_map<int, int>::iterator it, int now) {
            if (it == fac.end()) ans += Get(now);
            else for (int i = 0; i <= it->second; ++i) {
                Dfs(next(it), now);
                now *= it->first;
            }
        };
        Dfs(fac.begin(), 1);
        cout << ans << '\n';
    }
}
