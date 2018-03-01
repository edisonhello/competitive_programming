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

const int maxn = 1e6 + 10;
int a[maxn], nxt[maxn], prv[maxn], p[maxn];
int x[maxn], w[maxn], fr[maxn], ba[maxn], cf[maxn], cb[maxn];
bool v[maxn];
vector<int> pos[maxn];

void imp() {
    cout << "0\n-1\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]].push_back(i);
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < pos[i].size(); ++j) {
            if (j > 0) prv[pos[i][j]] = pos[i][j - 1];
            if (j + 1 < pos[i].size()) nxt[pos[i][j]] = pos[i][j + 1];
        }
    }
    int c, d; cin >> c >> d;
    for (int i = 1; i <= c; ++i) cin >> x[i];
    for (int i = 1; i <= d; ++i) cin >> w[i];
    p[c] = pos[x[c]].back();
    for (int i = c - 1; i > 0; --i) {
        auto it = lower_bound(pos[x[i]].begin(), pos[x[i]].end(), p[i + 1]);
        if (it == pos[x[i]].begin()) imp();
        p[i] = *prev(it);
    }
    fr[p[c]] = p[1];
    while (true) {
        if (!prv[p[c]]) break;
        p[c] = prv[p[c]];
        bool ok = true;
        for (int i = c - 1; i > 0 && ok; --i) {
            if (p[i] < p[i + 1]) continue;
            while (p[i] >= p[i + 1]) {
                if (!prv[p[i]]) {
                    ok = false;
                    break;
                }
                p[i] = prv[p[i]];
            }
        } 
        if (!ok) break;
        fr[p[c]] = p[1];
    }
    p[d] = pos[w[d]][0];
    for (int i = d - 1; i > 0; --i) {
        auto it = upper_bound(pos[w[i]].begin(), pos[w[i]].end(), p[i + 1]);
        if (it == pos[w[i]].end()) imp();
        p[i] = *it;
    }
    ba[p[d]] = p[1];
    while (true) {
        if (!nxt[p[d]]) break;
        p[d] = nxt[p[d]];
        bool ok = true;
        for (int i = d - 1; i > 0 && ok; --i) {
            if (p[i] > p[i + 1]) continue;
            while (p[i] <= p[i + 1]) {
                if (!nxt[p[i]]) {
                    ok = false;
                    break;
                }
                p[i] = nxt[p[i]];
            }
        } 
        if (!ok) break;
        ba[p[d]] = p[1];
    }
    // debug() << "fr = " << range(fr + 1, fr + n + 1);
    // debug() << "ba = " << range(ba + 1, ba + n + 1);
    int now = pos[x[c]][0];
    int okc = 0;
    for (int i = 1; i < fr[now]; ++i) ++cf[a[i]];
    for (int i = ba[now] + 1; i <= n; ++i) {
        ++cb[a[i]];
        if (cf[a[i]] && !v[a[i]]) v[a[i]] = true, ++okc;
    }
    vector<int> ans;
    if (okc > 0) ans.push_back(now);
    while (true) {
        if (!nxt[now]) break;
        now = nxt[now];
        if (!fr[now] || !ba[now]) break;
        for (int i = fr[prv[now]]; i < fr[now]; ++i) {
            ++cf[a[i]];
            if (cb[a[i]] && !v[a[i]]) v[a[i]] = true, ++okc;
        }
        for (int i = ba[prv[now]] + 1; i <= ba[now]; ++i) {
            --cb[a[i]];
            if (cb[a[i]] == 0 && v[a[i]]) v[a[i]] = false, --okc;
        }
        if (okc > 0) ans.push_back(now);
    }
    if (ans.size() == 0) imp();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i + 1 < ans.size()) cout << ' ';
        else cout << '\n';
    }
    return 0;
}
