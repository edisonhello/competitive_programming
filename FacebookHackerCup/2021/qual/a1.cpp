#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  vector<int> cnt(256, 0);
  for (char c : s) {
    cnt[c]++;
  }

  auto isv = [&] (int z) { return z == 'A' || z == 'E' || z == 'I' || z == 'O' || z == 'U'; };

  int mn = INT_MAX;
  for (int i = 'A'; i <= 'Z'; ++i) {
    int cc = 0;
    for (int j = 'A'; j <= 'Z'; ++j) {
      if (!cnt[j]) continue;
      if (i == j) continue;
      if (isv(i) == isv(j)) cc += 2 * cnt[j];
      else cc += cnt[j];
    }
    mn = min(mn, cc);
  }

  cout << mn << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
