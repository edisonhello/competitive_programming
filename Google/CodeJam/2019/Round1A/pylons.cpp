#include <bits/stdc++.h>
using namespace std;

int n, m, ptr;
bitset<24> vis[24];
vector<pair<int, int>> ans;
vector<pair<int, int>> pos;

bool dfs(int x, int y) {
    // cerr << "dfs: " << x << " " << y << " dep " << ans.size() << endl;
    vis[x][y] = 1;
    ans.emplace_back(x, y);
    if ((int)ans.size() == n * m) return true;
    for (int z = 0; z < n * m; ++z) {
        ++ptr;
        if (ptr >= (int)pos.size()) ptr = 0;
        if (pos[ptr].first == x) continue;
        if (pos[ptr].second == y) continue;
        if (pos[ptr].first + pos[ptr].second == x + y) continue;
        if (pos[ptr].first - pos[ptr].second == x - y) continue;
        if (vis[pos[ptr].first][pos[ptr].second]) continue;
        if (dfs(pos[ptr].first, pos[ptr].second)) return true;
    }
    /* for (int i = 1; i <= n; ++i) {
        if (i == x) continue;
        for (int j = 1; j <= m; ++j) {
            if (j == y) continue;
            if (i + j == x + y) continue;
            if (i - j == x - y) continue;
            if (vis[i][j]) continue;
            if (dfs(i, j)) return true;
        }
    } */
    ans.pop_back();
    vis[x][y] = 0;
    return false;
}

int main() {
    srand(time(0) * clock() + clock() * clock());
    ans.reserve(500);
    pos.reserve(500);
    int t; cin >> t; for (int ts = 1; ts <= t; ++ts) {
        cout << "Case #" << ts << ": ";
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) vis[i].reset();
        ans.clear();
        pos.clear();
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pos.emplace_back(i, j);
        random_shuffle(pos.begin(), pos.end());
        ptr = 0;
        // cerr << "pos: ";
        // for (auto &e : pos) cerr << "(" << e.first << "," << e.second << ") ";
        // cerr << endl;
        if (dfs(2, 2)) {
            cout << "POSSIBLE" << endl;
            for (auto &e : ans) {
                cout << e.first << " " << e.second << endl;
            }
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
        /* vector<pair<int, int>> vec;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) vec.emplace_back(i, j);
        }
        while (random_shuffle(vec.begin(), vec.end()), true) {
            bool ok = true;
            for (int i = 1; i < (int)vec.size(); ++i) {
                if (vec[i].first == vec[i - 1].first) { ok = false; break; }
                if (vec[i].second == vec[i - 1].second) { ok = false; break; }
                if (vec[i].first + vec[i].second == vec[i - 1].first + vec[i - 1].second) { ok = false; break; }
                if (vec[i].first - vec[i].second == vec[i - 1].first - vec[i - 1].second) { ok = false; break; }
            }
            if (ok) {
                cout << "POSSIBLE" << endl;
                for (auto &e : vec) cout << e.first << " " << e.second << '\n';
                break;
            }
        } */
    }
}
