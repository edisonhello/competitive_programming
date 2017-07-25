#include <bits/stdc++.h>
using namespace std;

const int maxn = 30, inf = 1e9 + 1;
const int dx[] = { 1, 0, -1, 0}, dy[] = { 0, 1, 0, -1};
int h[maxn][maxn], d[maxn * maxn], n, m;
bool v[maxn * maxn];

bool ok(int x, int y) {
    return x >= 0 && x <n && y >= 0 && y < m;
}

vector<pair<int, int>> G[maxn * maxn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> h[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)  {
            for (int k = 0; k < 4; ++k) if (ok(i + dx[k], j + dy[k])) {
                int a = i + dx[k], b = j + dy[k];
                if (abs(h[i][j] - h[a][b]) <= 1) {
                    int d = abs(h[i][j] - h[a][b]);
                    G[i * n + j].push_back(make_pair(a * n + b, d));
                    G[a * n + b].push_back(make_pair(i * n + j, d));
                } 
            }
        } 
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(d, d + maxn * maxn, inf);
    pq.push(make_pair(0, 0));
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true;
        for (auto e : G[p.second]) {
            if ( d[e.first] > p.first + e.second) {
                d[e.first] = p.first + e.second;
                pq.push(make_pair(d[e.first], e.first));
            }
        }
    }
    if( d[(n-1)*n+m-1] != inf )cout << d[(n - 1) * n + m - 1] << endl;
    else cout<< "NA" << endl;
}

