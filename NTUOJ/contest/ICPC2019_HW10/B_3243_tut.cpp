#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n;
vector<int> g[maxn];
bitset<maxn> vis;
vector<int> part;
int sz[maxn], mxch[maxn];
int sz0[maxn];

void dfs(int now, int pa = 0) {
    sz[now] = 1;
    mxch[now] = 0;
    part.push_back(now);
    for (int i : g[now]) if (i != pa && !vis[i]) {
        dfs(i, now);
        sz[now] += sz[i];
        if (sz[i] > sz[mxch[now]]) mxch[now] = i;
    }
}

int sz2[maxn], mxch2[maxn];
set<int> part2;
void dfs2(int now, int pa) {
    part2.insert(now);
    sz2[now] = 1;
    mxch2[now] = 0;
    for (int i : g[now]) if (i != pa) {
        dfs2(i, now);
        sz2[now] += sz2[i];
        if (sz2[i] > sz2[mxch2[now]]) mxch2[now] = i;
    }
}

int solve(int now, int cpa, bool first = false) {
    // cerr << "solve " << now << " " << cpa << endl;
    part.clear();
    dfs(now);
    if (first) for (int i = 1; i <= n; ++i) sz0[i] = sz[i];
    int cen = -1;
    for (int i : part) if (max(sz[mxch[i]], (int)part.size() - sz[i]) <= (int)part.size() / 2) cen = i; // player 1 put at cen
    // cerr << "cen = " << cen << endl;
    vis[cen] = 1;
    int ANS = 1e9;
    int way = -1;
    for (int i : g[cen]) {
        int goodans = (sz0[i] > sz0[cen] ? sz0[cen] : n - sz0[i]);
        part2.clear();
        dfs2(i, cen); // player 2 put at subtree contain i (root at cen)
        // cerr << "part2 = "; for (int i : part2) cerr << i << ' '; cerr << endl;
        int ccen = -1;
        for (int ii : part2) if (max(sz2[mxch2[ii]], (int)part2.size() - sz2[ii]) <= (int)part2.size() / 2) ccen = ii;
        if (ccen == -1) continue;
        int rt = 0;
        for (int ii : g[ccen]) if (part2.count(ii)) {
            rt = max(rt, sz2[ii] > sz2[ccen] ? (int)part2.size() - sz2[ccen] : sz2[ii]);
            // cerr << "ii = " << ii << ", rt = max " << (sz2[ii] > sz2[ccen] ? (int)part2.size() - sz2[ccen] : sz2[ii]) << endl;
        }
                
        // cerr << "if take i = " << i <<", goodans = " << goodans << ", rt = " << rt << endl;
        if (rt + goodans < ANS) {
            ANS = rt + goodans;
            way = i;
        }
    }
    if (way == -1) return -1;
    else if (vis[way]) return ANS;
    else return max(ANS, solve(way, cen));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << solve(1, 0, 1) << endl;
}
