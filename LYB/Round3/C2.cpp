#include <bits/stdc++.h>
using namespace std;

const int maxn = 131, mod = 1e9 + 7;
bool v[maxn];
vector<int> p;
int mask[maxn], sp[maxn], dp[maxn][32][2];
int cnt[maxn];
vector<int> g[maxn];

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) p.push_back(i);
        for (int j = 0; i * p[j] < maxn; ++j) {
            v[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}
int fpow(int a, int n) {
    (n += mod - 1) %= mod - 1;
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return r;
}

int choose(int c, int p) { 
    if (c == 0) {
        if (p == 0) return 1;
        return 0;
    }
    return fpow(2, c - 1);
}

int solve(vector<int> x, bool f) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < 32; ++j) {
            for (int k = 0; k < 2; ++k) {
                (dp[i + 1][j][k] += choose(cnt[x[i]], 0) * 1ll * dp[i][j][k] % mod) %= mod;
                (dp[i + 1][j ^ mask[x[i]]][k ^ 1] += choose(cnt[x[i]], 1) * 1ll * dp[i][j][k] % mod) %= mod;
            }
        }
    }
    int ans = dp[x.size()][0][0];
    if (f) (ans += dp[x.size()][0][1]) %= mod;
    return ans;
}

int main() {
    sieve();
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        assert(x >= 1 && x <= 130);
        ++cnt[x];
    }
    for (int i = 1; i < maxn; ++i) sp[i] = -1;
    for (int i = 1; i < maxn; ++i) {
        int x = i;
        for (int j = 0; j < p.size(); ++j) {
            int c = 0;
            while (x % p[j] == 0) x /= p[j], c ^= 1;
            if (p[j] * p[j] < maxn && c) mask[i] ^= (1 << j);
            else if (p[j] * p[j] >= maxn && c) sp[i] = j;
        }
    }
    vector<int> s;
    for (int i = 1; i < maxn; ++i) {
        if (sp[i] == -1) s.push_back(i);
    }
    int ans = solve(s, true);
    for (int i = 1; i < maxn; ++i) {
        if (sp[i] != -1) g[sp[i]].push_back(i);
    }
    for (int i = 1; i < maxn; ++i) {
        if (g[i].size()) ans = ans * 1ll * solve(g[i], false) % mod;
    }
    (ans += mod - 1) %= mod;
    printf("%d\n", ans);
}
