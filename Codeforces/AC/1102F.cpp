#include<bits/stdc++.h>
using namespace std;

int n, m, a[20][10004];
int to[20];
bitset<20> dp[1 << 18];

bool ok(int K) {
    for (int head = 1; head <= n; ++head) {
        memset(to, 0, sizeof(to));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (j == head) {
                    bool ok = 1;
                    for (int z = 1; z < m; ++z) {
                        ok &= abs(a[i][z] - a[j][z + 1]) >= K;
                    }
                    if (ok) to[i] |= (1 << j);
                } else {
                    bool ok = 1;
                    for (int z = 1; z <= m; ++z) {
                        ok &= abs(a[i][z] - a[j][z]) >= K;
                    }
                    if (ok) to[i] |= (1 << j);
                }
            }
        }
        for (int i = 0; i < (1 << (n + 1)); ++i) dp[i].reset();
        dp[1 << head][head] = 0;
        queue<pair<int, int>> q; q.emplace(1 << head, head);
        int cnt = 0;
        while (q.size()) {
            auto &p = q.front();
            for (int i = 1; i <= n; ++i) if ((to[p.second] & (1 << i)) && !(p.first & (1 << i))) {
                if ((p.first | (1 << i)) == (1 << (n + 1)) - 2)
                    if ((to[i] & (1 << head))) return 1;
                    else continue;
                if (dp[p.first | (1 << i)][i]) continue;
                q.emplace(p.first | (1 << i), i);
                dp[p.first | (1 << i)][i] = 1;
            }
            q.pop();
            ++cnt;
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    if (n == 1) {
        int mn = INT_MAX;
        for (int i = 1; i < m; ++i) mn = min(mn, abs(a[1][i] - a[1][i + 1]));
        cout << mn << endl;
        exit(0);
    }
    int L = 0, R = 1000000000; 
    while (R > L) {
        int M = (L + R + 1) >> 1;
        if (ok(M)) L = M;
        else R = M - 1;
    }
    cout << L << endl;
}
