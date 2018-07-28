#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
int prv[maxn], nxt[maxn], pos[maxn];
int a[maxn];
bool u[maxn];

struct data {
    int diff, mi, mj;
    data(int a, int b, int c): diff(a), mi(b), mj(c) {}
    bool operator<(const data &rhs) const {
        if (diff != rhs.diff) return diff < rhs.diff;
        if (mi != rhs.mi) return mi < rhs.mi;
        return mj < rhs.mj;
    }
};

void debug(set<data> s) {
    for (auto k : s) {
        cout << k.diff << ' ' << k.mi << ' ' << k.mj << endl;
    }
}

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        v.emplace_back(a[i], i);
    }
    sort(v.begin(), v.end());
    set<data> s;
    // for (int i = 0; i < n; ++i) cout << "(" << v[i].first << ", " << v[i].second << ") "; cout << endl;
    for (int i = 0; i < n; ++i) pos[v[i].second] = i;
    for (int i = 0; i < n; ++i) prv[i] = nxt[i] = -1;
    for (int i = 1; i < v.size(); ++i) prv[v[i].second] = v[i - 1].second;
    for (int i = 0; i < v.size() - 1; ++i) nxt[v[i].second] = v[i + 1].second;
    for (int i = 1; i < v.size(); ++i) {
        int diff = v[i].first - v[i - 1].first;
        int x = min(v[i].second, v[i - 1].second);
        int y = max(v[i].second, v[i - 1].second);
        s.insert(data(diff, x, y));
    }
    while (s.size()) {
        // debug(s);
        int diff = s.begin()->diff;
        int x = s.begin()->mi;
        int y = s.begin()->mj;
        s.erase(s.begin());
        if (u[x] || u[y]) continue;
        u[x] = u[y] = true;
        printf("%d %d\n", x + 1, y + 1);
        int p = pos[x] < pos[y] ? x : y;
        int q = pos[x] < pos[y] ? y : x;
        int fr = prv[p], ba = nxt[q];
        if (fr != -1 && ba != -1) {
            nxt[fr] = ba;
            prv[ba] = fr;
            s.insert(data(abs(a[fr] - a[ba]), min(fr, ba), max(fr, ba)));
        } else if (fr != -1) {
            nxt[fr] = -1;
        } else if (ba != -1) {
            prv[ba] = -1;
        }
    } 
    return 0;
}
