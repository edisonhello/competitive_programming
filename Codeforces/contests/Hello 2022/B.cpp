#include <bits/stdc++.h>
using namespace std;

#define int int64_t


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    tuple<int, int, int> mn(INT_MAX, 0, -1), mx(INT_MIN, -1, -1);
    int fit_min = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int l, r, c;
      cin >> l >> r >> c;
      if (l < get<0>(mn) || (l == get<0>(mn) && c < get<1>(mn))) {
        if (l != get<0>(mn))
          fit_min = INT_MAX;
        mn = make_tuple(l, c, i);
      }
      if (r > get<0>(mx) || (r == get<0>(mx) && c < get<1>(mx))) {
        if (r != get<0>(mx))
          fit_min = INT_MAX;
        mx = make_tuple(r, c, i);
        }
      if (l == get<0>(mn) && r == get<0>(mx)) {
        fit_min = min(fit_min, c);
      }

      if (get<2>(mn) == get<2>(mx)) {
        cout << min(fit_min, get<1>(mn)) << '\n';
      } else {
        cout << min(fit_min, get<1>(mn) + get<1>(mx)) << '\n';
      }



    }
  }
}
