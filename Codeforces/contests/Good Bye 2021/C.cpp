#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int mn = n - 1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double d = (double)(v[j] - v[i]) / (j - i);
        int cnt = 0;
        for (int k = 0; k < n; ++k) if (k != i && k != j) {
          double should = v[i] + (k - i) * d;
          if (abs(should - v[k]) < 1e-9);
          else ++cnt;
        }
        mn = min(mn, cnt);
      }
    }
    cout << mn << '\n';
  }
}
