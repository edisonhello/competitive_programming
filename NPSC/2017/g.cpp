#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const int inf = 1e9 + 1;
int a[maxn],n;
long long dp[3][maxn];
bool v[maxn];

void solve() {
    // cout << "solve" << endl;
    for (int i = 0; i < 3; ++i) fill(dp[i], dp[i] + maxn, -1000000000000000009);
    dp[0][0] = 0; dp[1][0] = -1000000000000000009; dp[2][0] = -1000000000000000009;
    for (int i = 1; i <= n; ++i) {
        // dp[0][i] = dp[0][i - 1];
        dp[1][i] = max(dp[1][i - 1], (long long)a[i]);
        if (i > 1) dp[2][i] = max(dp[2][i - 1], dp[1][i - 2] + a[i]);
        // cout << dp[1][i] << ' ' << dp[2][i] << endl;
    }
    cout << dp[2][n] << endl;
    exit(0);
}
long long meow(){
    for (int i = 0; i < 3; ++i) fill(dp[i], dp[i] + maxn, -1000000000000000009);
    dp[0][0] = 0; dp[1][0] = -1000000000000000009; dp[2][0] = -1000000000000000009;
    for(int i=1;i<=n;++i)if(a[i]>0)a[i]=-inf;
    for (int i = 1; i <= n; ++i) {
        // dp[0][i] = dp[0][i - 1];
        dp[1][i] = max(dp[1][i - 1], (long long)a[i]);
        if (i > 1) dp[2][i] = max(dp[2][i - 1], dp[1][i - 2] + a[i]);
        // cout << dp[1][i] << ' ' << dp[2][i] << endl;
    }
    return dp[2][n];
}
void solve2(long long s){
    if(n==3 && v[2])exit((cout<<a[1]+a[3]<<endl,0));
    int pospos=0; for(int i=1;i<=n;++i)if(v[i])pospos=i;
    int mxneg=-1000000009;
    for(int i=1;i<=n;++i)if(!v[i] && abs(i-pospos)>1)mxneg=max(mxneg,a[i]);
    cout<<max(s+mxneg,meow())<<endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    long long s = 0;
    int c = 0, l = inf, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            ++c;
            s += a[i];
            v[i] = true;
            l = min(l, i); r = max(r, i);
        }
        // vif (a[i] > ma) mb = ma, ma = a[i];
        // else if (a[i] > mb)
    }
    if (c == 0) solve();
    if(c==1)solve2(s);
    for (int i = 1; i <= n; ++i) {
        if (i >= l && i <= r && !v[i]) return cout << s << endl, 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i]) {
            if (i != l && i != r) ans = max(ans, s - a[i]);
            // else;
        } else {
            if (i != l - 1 && i != r + 1) ans = max(ans, s + a[i]);
            else {
                if (i == l) {
                    if (i + 1 <= r) ans = max(ans, s + a[i] - a[i + 1]);
                } else {
                    if (i - 1 >= l) ans = max(ans, s + a[i] - a[i - 1]);
                }
            }
        }
    }
    cout << ans << endl;
    // for ()
}
