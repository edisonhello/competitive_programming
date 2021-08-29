#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int f[200005];

int main() {

  f[1] = f[2] = 1;

  int n; cin >> n;
  
  for (int i = 3; i <= n; ++i) f[i] = (f[i - 1] + f[i - 2]) % mod;

  for (int i = 1; i <= n; ++i) f[n] = f[n] * 1ll * (mod + 1) / 2 % mod;

  cout << f[n] << endl;
}
