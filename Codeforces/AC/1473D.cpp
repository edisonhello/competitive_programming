#include <bits/stdc++.h>
using namespace std;

int pp[200005], pm[200005], ps[200005], sp[200005], sm[200005];

int main() {
  int t; cin >> t; while (t--) {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = " " + s;

    for (int i = 1; i <= n; ++i) {
      if (s[i] == '+') {
        ps[i] = ps[i - 1] + 1;
        pm[i] = pm[i - 1];
        pp[i] = max(ps[i], pp[i - 1]);
      } else {
        ps[i] = ps[i - 1] - 1;
        pm[i] = max(-ps[i], pm[i - 1]);
        pp[i] = pp[i - 1];
      }
    }

    sp[n + 1] = sm[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
      if (s[i] == '-') {
        sp[i] = max(sp[i + 1] - 1, 0);
        sm[i] = sm[i + 1] + 1;
      } else {
        sp[i] = sp[i + 1] + 1;
        sm[i] = max(sm[i + 1] - 1, 0);
      }
    }

    while (m--) {
      int l, r; cin >> l >> r;
      int mn = -pm[l - 1], mx = pp[l - 1];
      mn = min(mn, ps[l - 1] - sm[r + 1]);
      mx = max(mx, ps[l - 1] + sp[r + 1]);
      cout << mx - mn + 1 << '\n';
    }
  }
}
