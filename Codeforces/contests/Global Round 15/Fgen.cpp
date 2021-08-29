#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(0) * clock());
  int n = 3;
  cout << n << endl;

  vector<tuple<int, int, int>> v;

  for (int i = 0; i < n; ++i) {
    int x = rand() % 20;
    int y = rand() % 20;
    if (y > x) swap(x, y);
    int s = rand() % 2;
    v.emplace_back(x, y, s);
  }

  sort(v.begin(), v.end());
  for (auto [x, y, s] : v) {
    cout << x << ' ' << y << ' ' << s << endl;
  }
}
