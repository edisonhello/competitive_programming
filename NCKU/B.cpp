#include <bits/stdc++.h>
using namespace std;

const int maxn = 26;
int xmin[maxn], xmax[maxn], ymin[maxn], ymax[maxn];
int x[maxn], y[maxn], ans[maxn];
vector<int> on[maxn], to[maxn];

bool cover(int a, int b) {
    return x[b] >= xmin[a] && x[b] <= xmax[a] && y[b] >= ymin[a] && y[b] <= ymax[a];
}

struct matching {
    vector<int> g[maxn];
    bool v[maxn];
    int m[maxn];
    void init(int n) {
        for (int i = 0; i < n; ++i) g[i].clear();
    }
    void add_edge(int a, int b) {
        g[a].push_back(b);
    }
    bool dfs(int x) {
        for (int u : g[x]) {
            if (!v[u]) {
                v[u] = true;
                if (m[u] == -1 || dfs(m[u])) {
                    m[u] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int operator()(int n) {
        int ret = 0;
        memset(m, -1, sizeof(m));
        for (int i = 0; i < n; ++i) {
            memset(v, false, sizeof(v));
            if(dfs(i)) ++ret;
        }
        return ret;
    }
} jizz;

int main() {
    int n, tc = 0;
    while (cin >> n, n) {
        ++tc;
        for (int i = 0; i < n; ++i) cin >> xmin[i] >> xmax[i] >> ymin[i] >> ymax[i];
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        vector<pair<int, int>> e;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cover(i, j)) e.emplace_back(i, j);
            }
        }
        jizz.init(n);
        for (auto i : e) jizz.add_edge(i.first, i.second);
        int mt = jizz(n);
        bool amb = false;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) if (jizz.m[i] != -1) {
            matching njizz;
            njizz.init(n);
            for (auto j : e) {
                if (j.first == jizz.m[i] && j.second == i) continue;
                njizz.add_edge(j.first, j.second);
            }
            int z = njizz(n);
            if (z < mt) ans.emplace_back(jizz.m[i], i);
        }
        sort(ans.begin(), ans.end());
        cout << "Heap " << tc << endl;
        if (ans.size() == 0) {
            cout << "none" << endl;
            cout << endl;
            continue;
        }
        for (int i = 0; i < ans.size(); ++i) {
            cout << "(" << (char)(ans[i].first + 'A') << "," << ans[i].second + 1 << ")";
            if (i + 1 < ans.size()) cout << " ";
        }
        cout << endl;
        cout << endl;
    } 
}
