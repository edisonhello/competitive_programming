#include <bits/stdc++.h>
using namespace std;

int64_t solve2(auto v) {
  int n = v.size();
  auto pre = v;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      pre[i][j] += pre[i][j - 1];
    }
  }

  vector dp(n + 1, vector(n + 1, (int64_t)1e18));
  dp[0][n] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp[i + 1][k] =
            min(dp[i + 1][k], dp[i][j] + (k ? pre[i][k - 1] : (int64_t)0));
      }
    }
  }

  int64_t mn = INT_MAX;
  for (int i = 0; i <= n; ++i) {
    mn = min(mn, dp[n][i]);
  }
  return mn;
}

int64_t solve(auto v) {
  int64_t mn = LLONG_MAX;
  mn = solve2(v);

  for (auto &vv : v) {
    reverse(vv.begin(), vv.end());
  }
  mn = min(mn, solve2(v));

  reverse(v.begin(), v.end());
  mn = min(mn, solve2(v));

  for (auto &vv : v) {
    reverse(vv.begin(), vv.end());
  }
  mn = min(mn, solve2(v));

  return mn;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int nn = n * 2;
    vector v(nn, vector(nn, (int64_t)0));

    for (int i = 0; i < nn; ++i) {
      for (int j = 0; j < nn; ++j) {
        cin >> v[i][j];
      }
    }

    int64_t base = 0;
    for (int i = n; i < nn; ++i) {
      for (int j = n; j < nn; ++j) {
        base += v[i][j];
        cerr << "Base + " << i << ' ' << j << ' ' << v[i][j] << endl;
      }
    }

    int64_t hyp = 0;
    for (int i = n; i < nn; ++i) {
      for (int j = 0; j < n; ++j) {
        hyp += v[i][j];
        cerr << "hyp + " << i << ' ' << j << ' ' << v[i][j] << endl;
      }
    }

    cerr << "base hyp " << base << ' ' << hyp << endl;

    vector tmp(n, vector(n, (int64_t)0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        tmp[i][j] = -v[i + n][j] + v[i][j + n];
      }
    }

    cerr << "tmp" << endl;
    for (auto &v : tmp) {
      for (int i : v) {
        cerr << i << ' ';
      }
      cout << endl;
    }

    cout << base + hyp + solve(tmp) << '\n';
  }
}
