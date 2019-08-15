#include <bits/stdc++.h>
using namespace std;

set<int> G[200005], cG[200005], mem[200005], bel[200005], cuts;
int dfn[200005], low[200005], nt, cc;
bitset<200005> matched;

void dfs1(int now, int pa) {
    static stack<int> st;
    st.push(now);
    int sons = 0;
    dfn[now] = low[now] = ++nt;
    bool cut = false;
    for (int i : G[now]) if (i != pa) {
        if (dfn[i]) {
            low[now] = min(low[now], dfn[i]);
        } else {
            ++sons;
            dfs1(i, now);
            low[now] = min(low[now], low[i]);
            if (low[i] >= dfn[now]) {
                ++cc;
                cut = true;
                while (st.top() != now) {
                    bel[st.top()].insert(cc);
                    mem[cc].insert(st.top());
                    st.pop();
                }
                bel[st.top()].insert(cc);
                mem[cc].insert(st.top());
            }
        }
    }
    if (pa == 0 && sons == 1) cut = false;
    if (cut) cuts.insert(now);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    dfs1(1, 0);

    /* cerr << "cuts = {";
    for (int i : cuts) cerr << i << " ";
    cerr << "}" << endl; */

    for (int i : cuts) {
        for (int j : bel[i]) {
            cG[i].insert(n + j);
            cG[n + j].insert(i);
        }
    }

    /* cerr << "cc = " << cc << endl;
    for (int i = 1; i <= cc; ++i) {
        cout << "cc[" << i << "] = {";
        for (int j : mem[i]) cout << j << " ";
        cout << "}" << endl;
    } */

    queue<int> q;
    for (int i = 1; i <= n + cc; ++i) if (cG[i].size() == 1u) q.push(i);

    if (q.empty()) q.push(n + 1);

    auto plug = [&] (const int &x) -> void {
        for (int i : G[x]) {
            G[i].erase(x);
        }
        G[x].clear();
        matched[x] = 1;
        // cerr << "use " << x << endl;
    };

    int ans = 0;
    while (q.size()) {
        int now = q.front(); q.pop();
        // cerr << "now = " << now << endl;
        if (now > n) {
            int unmatched = 0;
            for (int i : mem[now - n]) if (!matched[i]) ++unmatched;
            // cerr << "unmatched: " << unmatched << ", mem[now - n].size() = " << mem[now - n].size() << endl;
            if (unmatched == (int)mem[now - n].size()) {
                ans += unmatched / 2;
                if (unmatched % 2 == 0) {
                    for (int i : mem[now - n]) plug(i);
                } else {
                    // cerr << "cG[now].size() = " << cG[now].size() << endl;
                    if (cG[now].size()) {
                        int stay = *cG[now].begin();
                        // cerr << "stay = " << stay << endl;
                        for (int i : mem[now - n]) if (i != stay) plug(i);
                    } else {
                        for (int i : mem[now - n]) plug(i);
                    }
                }
            } else {
                queue<int> q;
                for (int i : mem[now - n]) if (!matched[i] && G[i].size() == 1u) q.push(i);
                while (q.size()) {
                    int nox = q.front(); q.pop();
                    if (G[nox].size() != 1u || matched[nox]) continue;
                    int noy = *G[nox].begin();
                    if (matched[noy]) continue;
                    for (int i : G[noy]) if (i != nox && G[i].size() == 2u && !matched[i]) q.push(i);
                    ++ans;
                    plug(nox), plug(noy);
                }
            }
        }
        for (int i : cG[now]) {
            cG[i].erase(now);
            if (cG[i].size() == 1u) q.push(i);
        }
        cG[now].clear();
        // cerr << "ans = " << ans << endl;
    }
    cout << ans << endl;
}
