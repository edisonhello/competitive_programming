#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    multiset<int> st;
    for (int j = i; j < n; ++j) {
      st.insert(v[j]);
      if (st.size() >= 3u) {
        ll mn = *st.begin();
        ll mx = *prev(st.end());
        ll md = (mx + mn) / 2;
        auto it = st.lower_bound(md);
        ll best = 0;
        if (it != st.end()) {
          best = max(best, (ll)(mx - *it) * (*it - mn));
        } 
        if (it != st.begin()) {
          best = max(best, (ll)(mx - *prev(it)) * (*prev(it)- mn));
        }
        ans += best;
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  int t; cin >> t; while (t--) solve();
}
