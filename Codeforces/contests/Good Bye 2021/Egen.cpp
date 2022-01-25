#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(0) * clock());

  int t = 3;
  cout << t << endl;
  while (t--) {
    int n = rand() % 10 + 1;
    cout << n << endl;

    for (int i = 0; i < n; ++i) {
      cout << char(rand() % 3 + 'a');
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      cout << char(rand() % 3 + 'a');
    }
    cout << endl;
  }
}
