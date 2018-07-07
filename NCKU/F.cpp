#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
string s[maxn];

long long dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * 1ll * (a.first - b.first) +
           (a.second - b.second) * 1ll * (a.second - b.second);
}

int main() {
    int n, m; cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '1') v.push_back(j);
        }
        if (v.size()) p.emplace_back(i, v[0]), p.emplace_back(i, v[v.size() - 1]);
    }
    long long ans = 0;
    for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j < p.size(); ++j) ans = max(ans, dist(p[i], p[j]));
    }
    long double sq = sqrt(ans);
    if (sq - floor(sq) < ceil(sq) - sq) cout << floor(sq) << endl;
    else cout << ceil(sq) << endl;
}
