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
unordered_set<int> mem[N];

void solve() {

int n, q;
cin >> n >> q;

vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i], --a[i];

ll ans = 0;
for (int i = 1; i < n; ++i) {
  int u, v, c; cin >> u >> v >> c;
  g[--u].emplace_back(--v, c); g[v].emplace_back(u, c); ans += c;
}

vector<int> bo(n, -1), vis(n, 0), chf(n), cht(n), pa(n), paw(n); // [f, t)
int cbo = 0;
queue<int> bq; bq.push(0); vis[0] = 1; bo[0] = cbo++;
while (bq.size()) {
  int x = bq.front(); bq.pop(); chf[x] = cbo;
  for (auto [u, v] : g[x]) if (!(vis[u]++)) bq.push(u), bo[u] = cbo++, pa[u] = x, paw[u] = v;
  cht[x] = cbo;
}

auto add = [n](bit &b, int i, int w) { for (++i; i <= n; i += i & -i) b[i] += w; };
auto que = [n](bit &b, int i) { ll w = 0; for (++i; i; i -= i & -i) { auto t = b.find(i); if (t != b.end()) w += t->second; } return w; };

auto paint = [&](int i, int c) { 
  if (i && mem[c].count(pa[i])) ans -= paw[i]; 
  mem[c].insert(i); 
  ans -= que(b[c], cht[i] - 1) - que(b[c], chf[i] - 1);
  if (i) add(b[c], bo[i], paw[i]); 
};

auto unpaint = [&](int i, int c) { 
  if (i && mem[c].count(pa[i])) ans += paw[i]; 
  mem[c].erase(i); 
  ans += que(b[c], cht[i] - 1) - que(b[c], chf[i] - 1);
  if (i) add(b[c], bo[i], -paw[i]); 
};

for (int i = 0; i < n; ++i) paint(i, a[i]); 

while (q--) {
  int v, x; cin >> v >> x; --v, --x;
  unpaint(v, a[v]); a[v] = x; paint(v, a[v]); cout << ans << '\n';
}

for (int i = 0; i < n; ++i) g[i].clear(), b[i].clear(), mem[i].clear();

}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
