#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  vector<int> cnt(26, 0);
  for (char &c : s) {
    c -= 'A';
    cnt[c]++;
  }

  vector<vector<int>> d(26, vector<int>(26, 1000000000));

  for (int i = 0; i < 26; ++i) d[i][i] = 0;

  int m; cin >> m;
  while (m--) {
    string t; cin >> t;
    d[t[0] - 'A'][t[1] - 'A'] = 1;
  }

  for (int k = 0; k < 26; ++k) for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  long long mn = INT_MAX;
  for (int i = 0; i < 26; ++i) {
    long long c = 0;

    for (int j = 0; j < 26; ++j) {
      c += d[j][i] * 1ll * cnt[j];
    }

    mn = min(mn, c);
  }

  if (mn >= 1e8) cout << -1 << '\n';
  else cout << mn << endl;

  

}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
