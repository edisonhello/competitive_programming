#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long pw(long long b, long long n, long long m = mod, long long a = 1) {
    while (n) {
        if (n & 1) a = a * b % m;
        b = b * b % m; n >>= 1;
    } return a;
}
long long inv(int x) {
    return pw(x, mod - 2);
}

int h[1000006];
int L[1000006], R[1000006], act[1000006];

int mL(int x) {
    if (!act[L[x] - 1]) return L[x];
    return L[x] = mL(L[x] - 1);
}
int mR(int x) {
    if (!act[R[x] + 1]) return R[x];
    return R[x] = mR(R[x] + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i], --h[i];
    for (int i = 1; i <= n; ++i) L[i] = R[i] = i, act[i] = 0;
    vector<int> v(n); iota(v.begin(), v.end(), 1);
    sort(v.begin(), v.end(), [&] (const int &a, const int &b) { return h[a] > h[b]; });
    long long ans = 0;
    for (int i : v) {
        // ans += h[i];
        act[i] = 1;
        mL(i), mR(i);
        int ll = i - L[i], rr = R[i] - i;
        // ans += pw(h[i], wi);
        ans += (1 * (pw(h[i], ll + 1) - 1 + mod) * inv(h[i] - 1 + mod) % mod) * h[i] % mod * (1 * (pw(h[i], rr + 1) - 1 + mod) * inv(h[i] - 1 + mod) % mod) % mod;
        cerr << ll << " , " << rr << " , " << ans << endl;
    }
    cout << ans % mod << endl;
}
