#include <bits/stdc++.h>
using namespace std;

bool is_good(vector<int> &p, int n, int m) {
  vector<int> djs(n);
  iota(djs.begin(), djs.end(), 0);

  function<int(int)> F = [&] (int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); };
  auto U = [&] (int x, int y) { djs[F(x)] = F(y); };

  for (int i = 0; i < n; ++i) U(i, p[i]);

  int blk = 0;
  for (int i = 0; i < n; ++i) blk += F(i) == i;

  return n - blk <= m;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }

  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    ++cnt[(-p[i] + i + n) % n];
  }

  // cout << "cnt ";
  // for (int i = 0; i < n; ++i) {
  //   cout << cnt[i] << ' ';
  // }
  // cout << endl;

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= n - 2 * m) {
      vector<int> pp(n);
      // cout << "try " << i << endl;
      for (int j = 0; j < n; ++j) pp[j] = p[(j + i + n) % n];
      // cout << "pp: ";
      // for (int i : pp) cout  << i << ' ';
      // cout << endl;
      if (is_good(pp, n, m)) {
        ans.push_back(i);
      }
    }
  }

  cout << ans.size();
  for (int i : ans) cout << ' ' << i;
  cout << '\n';
}

int main() {
  int t; cin >> t; while (t--) solve();
}
