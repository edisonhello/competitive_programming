#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    string s;
    cin >> s;

    int stop = n;
    bool fall = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] < s[i - 1]) fall = 1;
      else if (s[i] == s[i - 1]) {
        if (!fall) {
          stop = i;
          break;
        }
      }
      if (s[i] > s[i - 1]) {
        stop = i;
        break;
      }
    }

    for (int i = 0; i < stop; ++i) cout << s[i];
    for (int i = stop - 1; i >= 0; --i) cout << s[i];
    cout << '\n';
  }
}
