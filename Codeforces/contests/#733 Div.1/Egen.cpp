#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(0) * clock());

  int t = 10;
  cout << t << endl;
  
  while (t--) {
    int n = rand() % 12 + 1;
    string z = "bbcdbefghijklbbbbbbbb";
    while (n--) cout << z[rand() % 16];
    cout << '\n';
  }
}
