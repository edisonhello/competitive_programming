#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, q; cin >> n >> q;
  vector<int64_t> a(n), b(n), pre(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  
  pre[0] = a[0];
  for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];
  
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
  vector<bool> vis(n + 1, false);
  vector<int64_t> dis(n + 1, 1e18);
  
  dis[n] = 0;
  for (int i = 0; i < n; ++i) {
    dis[i] = b[i];
    pq.push(pair{static_cast<int64_t>(dis[i]), i});
  }
  while (pq.size()) {
    int x = pq.top().second;
    // cerr << "x = " << x << endl;
    
    if (vis[x]) { pq.pop(); continue; }
    
    vis[x] = 1;
    
    int y = (x + 1) % n;
    if (!vis[y] && dis[x] + a[x] < dis[y]) dis[y] = dis[x] + a[x], pq.push(pair{static_cast<int64_t>(dis[y]), y});
    
    y = (x + n - 1) % n;
    if (!vis[y] && dis[x] + a[y] < dis[y]) dis[y] = dis[x] + a[y], pq.push(pair{static_cast<int64_t>(dis[y]), y});
  }
  
  // for (int i = 0; i < n; ++i) cerr << "dis " << i << " = " << dis[i] << endl;
  
  auto query = [&](int x, int y) -> int64_t {
    if (x == y) return 0;
    if (x < y) return pre[y - 1] - (x == 0 ? 0 : pre[x - 1]);
    return (y == 0 ? 0 : pre[y - 1]) + (pre[n - 1] - (x == 0 ? 0 : pre[x - 1]));
  };
  
  while (q--) {
    int x, y;
    cin >> x >> y; --x, --y;
    if (y == n) {
      cout << dis[x] << '\n';
      continue;
    }
    int64_t a1 = query(x, y), a2 = query(y, x), a3 = dis[x] + dis[y];
    cout << min(min(a1, a2), a3) << '\n';
  }
}
