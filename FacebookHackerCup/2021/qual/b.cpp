#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<string> mp(n);

  for (int i = 0; i < n; ++i) cin >> mp[i];

  int mn = INT_MAX;
  set<set<pair<int, int>>> way;

  for (int i = 0; i < n; ++i) {
    set<pair<int, int>> st;
    bool no = 0;
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == 'X') continue;
      else if (mp[i][j] == 'O') no = 1;
      else {
        st.insert(make_pair(i, j));
      }
    }

    if (no) continue;

    if (st.size() < mn) {
      mn = st.size();
      way.clear();
      way.insert(st);
    } else if (st.size() == mn) {
      way.insert(st);
    }
  }

  for (int j = 0; j < n; ++j) {
    set<pair<int, int>> st;
    bool no = 0;
    for (int i = 0; i < n; ++i) {
      if (mp[i][j] == 'X') continue;
      else if (mp[i][j] == 'O') no = 1;
      else {
        st.insert(make_pair(i, j));
      }
    }

    if (no) continue;

    if (st.size() < mn) {
      mn = st.size();
      way.clear();
      way.insert(st);
    } else if (st.size() == mn) {
      way.insert(st);
    }
  }

  if (mn == INT_MAX) {
    cout << "Impossible" << endl;
  } else {
    cout << mn << ' ' << way.size() << endl;
  }
}

int main() {
  int t; cin >> t; 
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
