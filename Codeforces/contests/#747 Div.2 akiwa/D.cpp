#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> djs(n * 2);
    iota(djs.begin(), djs.end(), 0);

    function<int(int)> F = [&](int x) {
      return x == djs[x] ? x : djs[x] = F(djs[x]);
    };
    auto U = [&](int x, int y) { djs[F(x)] = F(y); };

    while (m--) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      --u, --v;
      if (s[0] == 'i') {
        U(u, v + n);
        U(u + n, v);
      } else {
        U(u, v);
        U(u + n, v + n);
      }
    }

    int bad = 0;
    vector<int> cnt(n * 2, 0), sz(n * 2, 0);
    vector<int> used(n * 2, 0);
    for (int i = 0; i < n; ++i) {
      if (F(i) == F(i + n)) bad = 1;
    }
    for (int i = 0; i < 2 * n; ++i) {
      if (i >= n) ++cnt[F(i)];
      ++sz[F(i)];
    }

    if (bad) {
      cout << -1 << '\n';
    } else {
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        if (used[F(i)]) continue;
        used[F(i)] = used[F(i + n)] = 1;
        ans += max(cnt[F(i)], cnt[F(i + n)]);
      }
      cout << ans << '\n';
    }
  }
}
