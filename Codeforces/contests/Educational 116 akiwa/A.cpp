#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n; while (n--) {
    string s; cin >> s;
    if (s[0] == s.back()) {
      cout << s << '\n';
      continue;
    } else if (s[0] != s.back()) {
      s.back() = s[0];
      cout << s << '\n';
      continue;
    }
  }
}
