#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n), a;
  for (int &i : v) cin >> i;
  for (int i = 0; i < n; ++i) {
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (abs(v[i] - v[j]) < k) ok = 0;
    }
    if (ok) a.push_back(i + 1);
  }
  cout << a.size() << endl;
  for (int i : a) cout << i << ' ';
  cout << endl;
}
