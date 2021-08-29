#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> p;
    vector<int> ss;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      ss.push_back(x);
      ss.push_back(y);
      p.emplace_back(x, y, i + 1);
      p.emplace_back(y, x, i + 1);
    }

    sort(ss.begin(), ss.end());
    ss.resize(unique(ss.begin(), ss.end()) - ss.begin());
    for (auto &[x, y, i] : p) {
      x = upper_bound(ss.begin(), ss.end(), x) - ss.begin();
      y = upper_bound(ss.begin(), ss.end(), y) - ss.begin();
    }

    sort(p.begin(), p.end(), [&](const auto A, const auto B) {
      auto [a, b, z] = A;
      auto [c, d, y] = B;
      if (a == c) return b > d;
      return a < c;
    });

    vector<int> bit(ss.size() + 5, -1);
    vector<int> ans(n + 2, -1);

    for (auto [x, y, i] : p) {
      int val = -1;
      for (int z = y - 1; z; z -= z & -z) {
        val = max(val, bit[z]);
      }
      for (int z = y; z < (int)bit.size(); z += z & -z) {
        bit[z] = i;
      }
      ans[i] = max(ans[i], val);
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
  }
}
