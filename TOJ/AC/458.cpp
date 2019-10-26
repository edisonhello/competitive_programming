#include <stack>
#include <cstdio> 
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<int> G[1000006];
int a[1003][1003], bel[1000006], ind[1000006];
vector<int> dx[2] = {{1, 0, -1, 0}, {1, 1, -1, -1}};
vector<int> dy[2] = {{0, 1, 0, -1}, {1, -1, 1, -1}};
stack<int> st;
bitset<1000006> ins;
int cc, nt, in[1000006], low[1000006];

void dfs(int now) {
    in[now] = low[now] = ++nt;
    st.push(now);
    ins[now] = 1;
    for (int i : G[now]) {
        if (in[i]) {
            if (ins[i]) low[now] = min(low[now], in[i]);
        } else {
            dfs(i);
            low[now] = min(low[now], low[i]);
        }
    }
    if (low[now] == in[now]) {
        while (st.top() != now) {
            bel[st.top()] = cc;
            ins[st.top()] = 0;
            st.pop();
        }
        bel[now] = cc++;
        ins[st.top()] = 0;
        st.pop();
    }
}

int main() {
    int n, m, ans = 0; cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans -= (a[i][j] == 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int z = 0; z < 2; ++z) if (a[i][j] & (1 << z)) for (int d = 0; d < 4; ++d) {
        int nx = i + dx[z][d], ny = j + dy[z][d];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny]) {
            G[i * m + j].push_back(nx * m + ny);
        }
    }
    for (int i = 0; i < n * m; ++i) if (!in[i]) dfs(i);
    for (int i = 0; i < n * m; ++i) for (int j : G[i]) ind[bel[j]] += (bel[i] != bel[j]);
    for (int i = 0; i < cc; ++i) ans += !ind[i];
    cout << ans << endl;
}
