#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    int all = 1;
    vector<int> nt;
    for (int i = 0; i < n; ++i) if (s[i] != c) {
      all = 0;
      nt.push_back(i);
    }

    if (all) {
      cout << 0 << '\n';
      continue;
    }

    int one = 0;
    for (int i = n / 2; i < n; ++i) {
      if (s[i] == c) {
        cout << 1 << '\n';
        cout << i + 1 << '\n';
        one = 1;
        break;
      }
    }

    if (!one) {
      cout << 2 << '\n';
      cout << n - 1 << ' ' << n << '\n';
    }
  }
}
