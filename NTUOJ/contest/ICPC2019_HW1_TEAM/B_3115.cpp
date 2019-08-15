#include <bits/stdc++.h>
using namespace std;

set<int> G[100005];
int tin[100005], low[100005], nt;

int ccn;
map<pair<int, int>, int> bel;
vector<pair<int, int>> mem[100005];
vector<int> cuts;

vector<int> cG[200005];

bitset<200005> vis, vis2;

stack<pair<int, int>> st;
void dfs1(int now, int pa) {
    tin[now] = low[now] = ++nt;
    bool cutt = false;
    int cc = 0;
    for (int i : G[now]) if (i != pa) {
        if (tin[i]) {
            low[now] = min(low[now], tin[i]);
        } else {
            ++cc;
            st.emplace(minmax(now, i));
            dfs1(i, now);
            low[now] = min(low[now], low[i]);
            if (low[i] >= tin[now]) {
                ++ccn;
                cutt = true;
                while (st.top() != make_pair(min(i, now), max(i, now))) {
                    mem[ccn].push_back(st.top());
                    bel[st.top()] = ccn;
                    st.pop();
                }
                mem[ccn].push_back(st.top());
                bel[st.top()] = ccn;
                st.pop();
            }
        }
    }
    if (pa == 0 && cc == 1) cutt = false;
    if (cutt) cuts.push_back(now);
}

int ans, deg[200005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    dfs1(1, 0);

    // for (int i = 1; i <= ccn; ++i) {
    //     for (auto &p : mem[i]) cout << "(" << p.first<< ", " << p.second << ")";
    //     cout << endl;
    // }

    for (int i : cuts) if (!vis[i]) {
        vis[i] = 1;
        set<int> connected;
        for (int j : G[i]) {
            if (bel.count(minmax(i, j)) == 0) continue;
            int zz = bel[minmax(i, j)];
            if (connected.count(zz) == 0) {
                cG[zz + n].push_back(i);
                cG[i].push_back(zz + n);
                connected.insert(zz);
            }
        }
    }    
    vis.reset();

    queue<int> proc;
    for (int i = 1; i <= n + ccn; ++i) {
        if (cG[i].size() == 1u) {
            proc.push(i);
        }
        deg[i] = cG[i].size();
    }
    
    if (proc.empty()) {
        assert(ccn == 1);
        proc.push(n + 1);
    }

    auto bye = [&] (int x) {
        for (int i : G[x]) {
            G[i].erase(x);
        }
        G[x].clear();
        vis[x] = 1;
        // cout << "bye " << x << endl;
    };

    while (proc.size()) {
        int now = proc.front(); proc.pop();
        // cout << "now = " << now << endl;
        vis2[now] = 1;
        if (now > n) {
            int stay = -1;
            for (int i : cG[now]) if (i <= n && !vis2[i]) stay = i;
            // cout << "stay = " << stay << endl;
            set<int> members;
            for (auto &p : mem[now - n]) {
                members.insert(p.first);
                members.insert(p.second);
            }
            int deled = 0;
            for (int i : members) if (vis[i]) ++deled;
            if (deled) {
                queue<int> q;
                for (int i : members) if (G[i].size() == 1u) q.push(i);
                while (q.size()) {
                    int now = q.front(); q.pop();
                    // cout << "   now = " << now << endl;
                    if (G[now].size() != 1u) continue;
                    int j = *G[now].begin();
                    // cout << "   match = " << j << endl;
                    if (members.count(j) == 0) continue;
                    if (vis[now] || vis[j]) continue;
                    for (int k : G[j]) if (G[k].size() == 1u && members.count(k) && k != now) q.push(k);
                    bye(now);
                    bye(j);
                    ++ans;
                }
            } else if (members.size() % 2 == 0) {
                for (int i : members) bye(i);
                ans += members.size() / 2;
            } else {
                // cout << "Case use stay" << endl;
                for (int i : members) if (i != stay) bye(i);
                ans += members.size() / 2;
            }
        }
        for (int i : cG[now]) {
            --deg[i];
            if (deg[i] == 1) proc.push(i);
        }
        // cout << "after now = " << now << " , ans = " << ans << endl;
    }

    cout << ans << '\n';
}


