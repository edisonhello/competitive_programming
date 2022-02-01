#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
  int n; cin >> n; while (n--) {
    ll n, k; cin >> n >> k;
    ++k;
    vector<ll> has;
    for (int i = 0; i < n; ++i) {
      int t; cin >> t;
      has.push_back(pow((long double)10, (long double)t));
    }
    ll val = 0;
    for (int i = 0; i < n - 1; ++i) {
      ll mx = (has[i + 1] / has[i]) - 1;
      ll put = min(mx, k);
      val += has[i] * put;
      k -= put;
    }
    val += has.back() * k;
    cout << val << '\n';
  }
}
