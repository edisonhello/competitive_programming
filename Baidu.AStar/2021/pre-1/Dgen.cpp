#include <bits/stdc++.h>
using namespace std;


int main() {
  srand(time(0) * clock());

  int t = 1000; cout << t << endl;
  while (t--) {
    int a = rand() % 1000000000 + 1;
    int b = rand() % 1000000000 + 1;
    cout << a << ' ' << b << '\n';
  }
}
