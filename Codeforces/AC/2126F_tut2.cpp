#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>

using namespace std;

#define pii pair<int, int>
#define ll int64_t
#define bit unordered_map<int, ll>
#define N 200000

vector<vector<pii>> g(N);
bit b[N];

void solve() {

int n, q;
cin >> n >> q;

vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i], --a[i];

ll ans = 0;
for (int i = 1; i < n; ++i) {
  int u, v, c; cin >> u >> v >> c;
  g[--u].emplace_back(--v, c); g[v].emplace_back(u, c);
}

vector<int> vis(n, 0), pa(n), paw(n);
queue<int> bq; bq.push(0); vis[0] = 1;
while (bq.size()) {
  int x = bq.front(); bq.pop();
  for (auto [u, v] : g[x]) if (!(vis[u]++)) bq.push(u), pa[u] = x, paw[u] = v, b[x][a[u]] += v, ans += (a[x] != a[u] ? v : 0);
}

auto paint = [&](int i, int c) { 
  ans -= b[i][c];
  if (i) {
    b[pa[i]][c] += paw[i];
    if (a[pa[i]] == c) ans -= paw[i];
  }
};

auto unpaint = [&](int i, int c) { 
  ans += b[i][c];
  if (i) {
    b[pa[i]][c] -= paw[i];
    if (a[pa[i]] == c) ans += paw[i];
  }
};

while (q--) {
  int v, x; cin >> v >> x; --v, --x;
  unpaint(v, a[v]); a[v] = x; paint(v, a[v]); cout << ans << '\n';
}

for (int i = 0; i < n; ++i) g[i].clear(), b[i].clear();

}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
