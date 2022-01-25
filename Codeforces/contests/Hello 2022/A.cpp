#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t; while (t--) {
    int n, k; cin >> n >> k;
    if (k * 2 > n + 1) {
      cout << -1 << '\n';
      continue;
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i % 2 == 0 && j % 2 == 0 && i == j && k > 0) {
            cout << "R";
            --k;
          } else {
            cout << ".";
          }
        }
        cout << '\n';
      }
    }
  }
}
