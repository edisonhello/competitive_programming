#include <bits/stdc++.h>
using namespace std;

vector<int> G[1000006];
int mxdep[1000006], dep[1000006], to[1000006];

void dfs(int now) {
    to[now] = 0;
    mxdep[now] = dep[now];
    for (int i : G[now]) {
        dep[i] = dep[now] + 1;
        dfs(i);
        if (mxdep[i] > mxdep[now]) {
            mxdep[now] = mxdep[i];
            to[now] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i < n; ++i) {
            int p; cin >> p;
            G[p].push_back(i);
        }
        dfs(0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        pq.emplace(mxdep[0], 0);
        int ans = 0;
        while (k-- && pq.size()) {
            ans += pq.top().first;
            int now = pq.top().second;
            pq.pop();
            while (to[now] != 0) {
                for (int i : G[now]) if (i != to[now]) {
                    pq.emplace(mxdep[i] - dep[now], i);
                }
                now = to[now];
            }
        }
        for (int i = 0; i < n; ++i) G[i].clear();
        cout << ans << '\n';
    }
}
