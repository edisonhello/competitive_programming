#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;

  int ansadd = 0;
  vector<pair<int, int>> fre, cos;
  vector<int> num = {d};
  for (int i = 0; i < n; ++i) {
    int s, a; cin >> s >> a;
    if (s < d) continue;
    if (a < d) { ++ansadd; continue; }

    if (a <= s) fre.emplace_back(s, a);
    else cos.emplace_back(s, a);
    num.push_back(s);
    num.push_back(a);
  }
  sort(num.begin(), num.end());
  num.resize(unique(num.begin(), num.end()) - num.begin());

  vector<vector<int>> tag(num.size() + 3);
  vector<vector<int>> alt(num.size() + 3);
  for (auto &[s, a] : fre) {
    s = upper_bound(num.begin(), num.end(), s) - num.begin();
    a = upper_bound(num.begin(), num.end(), a) - num.begin();
    tag[s].push_back(a);
  }
  for (auto &[s, a] : cos) {
    s = upper_bound(num.begin(), num.end(), s) - num.begin();
    a = upper_bound(num.begin(), num.end(), a) - num.begin();
    alt[a].push_back(s);
  }

  vector<int> bit(num.size() + 3);
  auto add = [&](int x) { for (; x < (int)bit.size(); x += x & -x) ++bit[x]; };
  auto query = [&](int x) { int v = 0; for (; x; x -= x & -x) v += bit[x]; return v; };
  vector<int> dp(num.size() + 3);
  dp[0] = fre.size();

  for (int i = 1; i <= (int)num.size(); ++i) {
    dp[i] = dp[i - 1];
    for (int x : alt[i]) dp[i] = max(dp[i], dp[x] + 1 - (query(bit.size() - 1) - query(x)));
    for (int x : tag[i]) add(x);
  }

  cout << ansadd + dp[num.size()] << endl;
}
