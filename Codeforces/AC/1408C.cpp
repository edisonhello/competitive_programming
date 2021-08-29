#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int main() {
  int t; cin >> t; while (t--) {
    int n, l; cin >> n >> l;
    vector<int> pt(n + 4);
    pt[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> pt[i];
    pt[n + 1] = l;


    vector<double> ta(n + 4), tb(n + 4);
    ta[0] = 0;
    for (int i = 1; i <= n + 1; ++i) ta[i] = ta[i - 1] + (double)(pt[i] - pt[i - 1]) / i;

    tb[n + 1] = 0;
    for (int i = n; i >= 0; --i) tb[i] = tb[i + 1] + (double)(pt[i + 1] - pt[i]) / (n + 1 - i);

    for (int i = 0; i <= n; ++i) {
      if (ta[i] < tb[i] + eps && ta[i + 1] >= tb[i + 1] - eps) {
        double xa = pt[i], xb = pt[i + 1];
        double _ta = ta[i], _tb = tb[i + 1];
        double va = i + 1, vb = n + 1 - i;
        if (_ta < _tb) {
          xa += va * (_tb - _ta);
          _ta = _tb;
        } else {
          xb -= vb * (_ta - _tb);
          _tb = _ta;
        }
        cout << fixed << setprecision(12) << _ta + (xb - xa) / (va + vb) << '\n';
        break;
      }
    }
  }
}
