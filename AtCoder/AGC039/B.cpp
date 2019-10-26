#include <bits/stdc++.h>
using namespace std;

vector<int> g[205];
bitset<205> vis;
int c[205];

int go(int st, int n) {
    queue<int> q;
    q.push(st);
    bitset<205> vis; vis[st] = 1;
    int cnt = 1;
    while (vis.count() != n) {
        queue<int> nq;
        while (q.size()) {
            int now = q.front(); q.pop();
            for (int i : g[now]) if (!vis[i]) {
                nq.push(i);
                vis[i] = 1;
            }
        }
        ++cnt;
        q = nq;
    }
    return cnt;
}

void dfs(int now, int nc, vector<int> &mm) {
    mm.push_back(now);
    vis[now] = 1;
    c[now] = nc;
    for (int i : g[now]) if (!vis[i]) dfs(i, -nc, mm);
        else if (c[i] == c[now]) {
            cout << -1 << endl;
            exit(0);
        }
}

int calc(vector<int> mm) {
    int mx = 0;
    for (int i : mm) {
        mx = max(mx, go(i, mm.size()));
    }
    return mx;
}

int main() {
    int n; cin >> n; 
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        char c; cin >> c;
        if (c == '1') g[i].push_back(j), g[j].push_back(i);
    }
    vector<vector<int>> gr;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        gr.push_back(vector<int>());
        dfs(i, 1, gr.back());
    }
    int mx = 0;
    for (auto &v : gr) mx += calc(v);
    cout << mx << endl;
}
