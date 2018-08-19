#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
int dp[maxn][maxn];
pair<int, int> fr[maxn][maxn];
int d[maxn], s[maxn], id[maxn];
struct item { int d, s, i; } app[maxn];

int main() {
    int n, c; scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &d[i], &s[i]);
    for (int i = 1; i <= n; ++i) app[i] = item {d[i], s[i], i};
    sort (app + 1, app + n + 1, [](const item &a, const item &b) { return max(a.d, a.s) - a.s > max(b.d, b.s) - b.s; });
    for (int i = 1; i <= n; ++i) d[i] = app[i].d, s[i] = app[i].s, id[i] = app[i].i;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) dp[i][j] = -1;
    }
    dp[0][0] = c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] >= max(d[i + 1], s[i + 1])) {
                if (dp[i][j] + s[i + 1] > dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j] + s[i + 1];
                    fr[i + 1][j + 1] = make_pair(i, j);
                }
            }
            if (dp[i][j] > dp[i + 1][j]) {
                dp[i + 1][j] = dp[i][j];
                fr[i + 1][j] = make_pair(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) if (dp[n][i] >= 0) ans = i;
    int x = n, y = ans;
    vector<int> v;
    while (x) {
        int a, b; tie(a, b) = fr[x][y];
        if (b < y) v.push_back(x);
        x = a, y = b;
    }
    printf("%d\n", ans);
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) printf("%d ", id[v[i]]);
    puts("");
    return 0;
}
