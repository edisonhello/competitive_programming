#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> G[maxn];
bool ok;

int dfs(int now, int fa, int siz) {
    int ret = 1;
    // cout << "dfs now = " << now << " siz = " << siz << " ret = " << (ret == -1 ? 1 : ret) << endl;
    for (int u : G[now]) if (u != fa) {
        int res = dfs(u, now, siz);
        if (res == siz) continue;
        // if (ret != -1) { cout << "jizz now = " << now << endl; ok = false; continue; }
        ret += res;
        if (ret > siz) ok = false;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // int n; cin >> n;
    int n = 250000;
    for (int i = 0; i < n - 1; ++i) {
        // int a, b; cin >> a >> b;
        int a=i,b=i+1;
        G[a].push_back(b); G[b].push_back(a);
    }
    // cout << "done" << endl;
    vector<int> v;
    for (int i = 1; i <= n; ++i) if (n % i == 0) {
        ok = true;
        dfs(1, 0, n / i);
        // cout << endl;
        if (ok) v.push_back(i);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) cout << v[i] - 1 << ' '; cout << endl;
    return 0;
}
