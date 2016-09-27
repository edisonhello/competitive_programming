#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define pii pair<int, int>
#define INF 1e9
using namespace std;

vector<pii> G[10010];
int d[10010], n, m, a, b, w, mn, cnt, s[10010], sz[10010], mns, start, node;
bool v[10010], p;

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i <= n; ++i) G[i].clear();
        for (int i = 0; i <= n; ++i) d[i] = INF;
        memset(v, false, sizeof(v));
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> w;
            G[a].push_back(pii(b, w));
            G[b].push_back(pii(a, w));
        }
        d[1] = 0;
        // v[1] = true;
        cnt = 0;
        // start = 1;
        node = 0;
        while (node < n) {
            mn = INF;
            for (int i = 1; i <= n; ++i) {
                if (!v[i] && d[i] < mn) {
                    mn = d[i];
                    mns = i;
                }
            }
            if(mn==INF)break;
            node++;
            cnt += mn;
            v[mns] = true;

            for (int j = 0; j < G[mns].size(); ++j) {
                if (!v[G[mns][j].first]) {
                    if (G[mns][j].second < d[G[mns][j].first]) {
                        d[G[mns][j].first] = G[mns][j].second;
                    }
                }
            }
        }
        // cout << "node: " << node << endl;
        if (node == n) cout << cnt << endl;
        else cout << -1 << endl;
    }
    return 0;
}
