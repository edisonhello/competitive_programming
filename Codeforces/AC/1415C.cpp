#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t; while (t--) {
    int n, p, k; cin >> n >> p >> k;
    vector<int> v(n + 3);
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) {
      v[i] = s[i - 1] == '1';
    }
    int x, y; cin >> x >> y;

    vector<int> emp(n + 3, 0);
    
    for (int i = n; i >= 1; --i) {
      emp[i] += !v[i];
      if (i + k <= n) emp[i] += emp[i + k];
    }

    int mn = INT_MAX;
    for (int i = p, z = 0; i <= n; ++i, ++z) {
      mn = min(mn, z * y + x * emp[i]);
    }

    cout << mn << '\n';
  }
}
