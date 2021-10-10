#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
  int t; cin >> t; while (t--) {
    int n, k;
    cin >> n >> k;
    int base = 1;
    int sum = 0;
    for (int i = 0; i < 30; ++i) {
      if (k & (1 << i)) {
        sum = (sum + base) % mod;
      }
      base = (base * 1ll * n) % mod;
    }

    cout << sum << '\n';
  }
}
