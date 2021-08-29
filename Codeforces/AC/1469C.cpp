#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t; while (t--) {
    int n, h; cin >> n >> h;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int l = v[1] - (h - 1), r = v[1] + h - 1;

    bool no = 0;
    for (int i = 2; i < n; ++i) {
      int vv = v[i];
      if (vv + h - 1 < l || r < vv) {
        no = 1;
        break;
      }

      l = max(l, vv);
      r = min(r, vv + h - 1);
      if (l > r) {
        no = 1;
        break;
      }

      l -= h - 1;
      r += h - 1;
    }

    if (v[n] < l || r < v[n]) no = 1;

    cout << (no ? "NO" : "YES") << '\n';
  }
}
