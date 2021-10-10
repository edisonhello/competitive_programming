#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000007;

int pw(ll b, ll n) {
  ll a = 1;
  while (n) {
    if (n & 1) a = a * b % mod;
    b = b * b % mod;
    n >>= 1;
  }
  return a;
}

int main() {
  int n; cin >> n;

  cout << 6ll * pw(4, (1ll << n) - 2) % mod << endl;
}
