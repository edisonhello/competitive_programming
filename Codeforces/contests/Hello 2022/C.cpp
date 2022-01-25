#include <bits/stdc++.h>
using namespace std;

vector<int> p, q;

void run() {
  auto qq = q;
  for (int i = 1; i < (int)p.size(); ++i) {
    qq[i] = q[p[i]];
  }
  q = qq;
}

int query(int x) {
#ifndef TEST
  cout << "? " << x << endl;
  int y;
  cin >> y;
  return y;
#else
  int rt = q[x];
  run();
  return rt;
#endif
}

void answer(vector<int> v) {
#ifndef TEST
  cout << "!";
  for (int i = 1; i < (int)v.size(); ++i) {
    cout << ' ' << v[i];
  }
  cout << endl;
#else
  if (v != p) {
    cout << "err" << endl;
    cout << "try ";
    for (int i : v) cout << i << ' ';
    cout << endl;
    cout << "ans ";
    for (int i : p) cout << i << ' ';
    cout << endl;
    exit(1);
  }
#endif
}

int main() {
  srand(time(0) * clock());
  int t;
  cin >> t;
  while (t--) {
    int n;
#ifndef TEST
    cin >> n;
#else
    n = 40;
    p.resize(n + 1); iota(p.begin(), p.end(), 0);
    q.resize(n + 1); iota(q.begin(), q.end(), 0);
    random_shuffle(p.begin() + 1, p.end());
#endif

    vector<int> ans(n + 1);
    vector<int> got(n + 1, 0);

    int tm = 0;

    for (int i = 1; i <= n; ++i) {
      if (got[i]) continue;

      int val = query(i);
      int start = val;
      vector<int> lp = {start};
      ++tm;

      while (true) {
        val = query(i);
        ++tm;
        if (val == start) break;
        lp.push_back(val);
      }

      for (int x : lp) got[x] = 1;

      // after tm i will be `start`

      for (int j = 0; j < (int)lp.size(); ++j) {
        if (lp[j] == i) {
          for (int jj = (j + 1) % lp.size(), kk = j, z = 0; z < (int)lp.size(); ++z) {
            ans[lp[kk]] = lp[jj];
            jj = (jj + 1) % lp.size();
            kk = (kk + 1) % lp.size();

          }
        }
        // int first_at = (tm + j) % lp.size();
        // if (first_at == 0) {
        //   int pt = i;
        //   for (int k = 0; k < (int)lp.size(); ++k) {
        //     ans[pt] = lp[k];

        //   }

        // }
      }

    }
    answer(ans);
  }
}
