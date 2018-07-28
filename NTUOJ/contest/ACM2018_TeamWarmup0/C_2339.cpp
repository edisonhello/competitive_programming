#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn], ans[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        map<int, int> c;
        for (int i = 0; i < n; ++i) ++c[a[i]];
        int k = 0;
        for (auto it : c) k += it.second / 2;
        vector<pair<int, int>> v;
        for (auto it : c) {
            v.emplace_back(0, it.first);
            int k = 1;
            for (int i = 1; i < it.second; i += 2) {
                v.emplace_back(k, it.first);
                if (i + 1 < it.second) v.emplace_back(k, it.first);
                ++k;
            }
        }
        sort(v.begin(), v.end());
        // for (int i = 0; i < v.size(); ++i) printf("%d ", v[i].second); puts("");
        set<int> s;
        int z = 0;
        for (int i = 0; i <= k; ++i) ans[i] = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (s.count(v[i].second)) ++z, s.erase(v[i].second);
            else s.insert(v[i].second);
            if (ans[z] == 0) ans[z] = i + 1;
        }
        printf("%d\n", k);
        for (int i = 1; i <= k; ++i) printf("%d%c", ans[i], " \n"[i == k]);
        if(k == 0) puts("");
    }
}
