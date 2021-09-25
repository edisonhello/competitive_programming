#include <bits/stdc++.h>
using namespace std;

int sign(int x) {
  return x == 0 ? 0 : x > 0 ? 1 : -1;
}

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> pre[2];
  pre[0].push_back(0);
  pre[1].push_back(0);
  for (int i = 0; i < n; ++i) {
    pre[0].push_back(pre[0].back());
    pre[1].push_back(pre[1].back());
    if (s[i] == '+') {
      pre[i & 1].back()++;
    } else {
      pre[i & 1].back()--;
    }
  }

  auto query = [&] (int l, int r) {
    auto _query = [&] (int o, int l, int r) {
      return pre[o][r] - pre[o][l - 1];
    };
    return _query(l & 1, l, r) - _query(!(l & 1), l, r);
  };

  for (int i = 0; i < q; ++i) {
    int l, r; cin >> l >> r;

    if (query(l, r) == 0) {
      cout << 0 << '\n';
      continue;
    }

    int len = r - l + 1;
    if (len & 1) {
      int now = query(l, r);
      int found = 0;

      int L = l, R = r;
      while (L <= R) {
        int M = (L + R) >> 1;
        int nnow = query(l, M - 1) + query(M + 1, r) * ((M - 1 - l + 1) % 2 == 0 ? 1 : -1);
        if (nnow == 0) {
          found = 1;
          cout << 1 << '\n';
          cout << M << '\n';
          break;
        }
        if (sign(nnow) == sign(now)) R = M - 1;
        else L = M + 1;
      }

      assert(found);
    } else {
      --r;

      int now = query(l, r);
      int found = 0;

      int L = l, R = r;
      while (L <= R) {
        int M = (L + R) >> 1;
        int nnow = query(l, M - 1) + query(M + 1, r) * ((M - 1 - l + 1) % 2 == 0 ? 1 : -1);
        if (nnow == 0) {
          found = 1;
          cout << 2 << '\n';
          cout << M << ' ' << r + 1 << '\n';
          break;
        }
        if (sign(nnow) == sign(now)) R = M - 1;
        else L = M + 1;
      }

      assert(found);
    }
  }
}

int main() {
  int t; cin >> t; while (t--) solve();
}
