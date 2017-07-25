#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
struct Fenwick {
#define lowbit(x) (x & -x)
    int _bit[maxn][maxn];
    void init() {
        memset(_bit, 0, sizeof(_bit));
    }
    void add(int x, int y, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) {
            for (int j = y; j < maxn; j += lowbit(j)) {
                _bit[i][j] = max(_bit[i][j], v);
            }
        }
    }
    int query(int x, int y){
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) {
            for (int j = y; j; j -= lowbit(j)) {
                ret = max(ret, _bit[i][j]);
            }
        }
        return ret;
    }
} bit;
int a[maxn][maxn], dp[maxn][maxn];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i =1; i <= n;++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    bit.init();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int q = bit.query(i - 1, j - 1);
            dp[i][j] = q + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}
