#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define var(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int maxn = 500 + 10;
char c[maxn][maxn];
int ud[maxn][maxn], lr[maxn][maxn], xy[maxn + maxn + maxn][maxn], yx[maxn + maxn + maxn][maxn];
bool u[maxn][maxn][2], d[maxn][maxn][2];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> c[i][j];
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) ud[j][i] = ud[j][i - 1] + (c[i][j] == '1');
    } 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) lr[i][j] = lr[i][j - 1] + (c[i][j] == '1');
    }
    for (int j = -m; j <= m; ++j) {
        for (int i = 1, k = j; i <= n; ++i, ++k) yx[j + m][i] = yx[j + m][i - 1] + (k <= m ? c[i][k] == '1' : 0);
    }
    for (int j = 1; j <= m + m; ++j) {
        for (int i = 1, k = j; i <= n; ++i, --k) xy[j + m][i] = xy[j + m][i - 1] + (k >= 1 ? c[i][k] == '1' : 0);
    } 
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(u, false, sizeof(u));
        memset(d, false, sizeof(d));
        for (int j = 1; j <= m; ++j) {
            for (int k = j + 1; k <= m; ++k) {
                int len = k - j;
                if (i + len > n) continue;
                int pk = j - (i - 1), pj = k + (i - 1);
                if (lr[i][k] - lr[i][j - 1]) continue;
                if (ud[k][i + len] - ud[k][i - 1] == 0 && yx[pk + m][i + len] - yx[pk + m][i - 1] == 0) ++ans, u[j][k][0] = true;
                if (ud[j][i + len] - ud[j][i - 1] == 0 && xy[pj + m][i + len] - xy[pj + m][i - 1] == 0) ++ans, u[j][k][1] = true;
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int k = j + 1; k <= m; ++k) if ((k - j) % 2 == 0) {
                int len = (k - j) >> 1;
                if (u[j][j + len][0] && u[j + len][k][1]) ++ans;
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int k = j + 1; k <= m; ++k) {
                int len = k - j;
                if (i - len < 1) continue;
                int pk = k + (i - len - 1), pj = j - (i - len - 1);
                if (lr[i][k] - lr[i][j - 1]) continue;
                if (ud[k][i] - ud[k][i - len - 1] == 0 && xy[pk + m][i] - xy[pk + m][i - len - 1] == 0) ++ans, d[j][k][0] = true;
                if (ud[j][i] - ud[j][i - len - 1] == 0 && yx[pj + m][i] - yx[pj + m][i - len - 1] == 0) ++ans, d[j][k][1] = true;
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int k = j + 1; k <= m; ++k) if ((k - j) % 2 == 0) {
                int len = (k - j) >> 1; 
                if (d[j][j + len][0] && d[j + len][k][1]) ++ans;
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int k = j + 1; k <= m; ++k) {
                int len = (k - j) >> 1;
                if (i - len < 1 || i + len > n) continue;
                if (d[j][k][1] && u[j][k][1]) ++ans;
                if (d[j][k][0] && u[j][k][0]) ++ans;
            }
        }
    } 
    cout << ans << endl;
}
