#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> cnt(105, 0);
    for (int i = 0; i < n; ++i) {
      cnt[abs(v[i])]++;
    }

    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
      if (i) {
        ans += min(2, cnt[i]);
      } else {
        ans += min(1, cnt[i]);
      }
    }
    cout << ans << '\n';
  }
}
