#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
set<pair<int, int>> edge;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
    }
    if (m == n * 1ll * (n - 1) / 2) cout << 0 << endl;
    else cout << n << endl;
    return 0;
}
