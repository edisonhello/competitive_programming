
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
  int n; cin >> n; while (n--) {
    ll n, k; cin >> n >> k;
    ll has = 1;
    ll tm = 0;
    while (has < n && has < k) {
      has *= 2;
      tm++;
    }
    if (has < n) {
      ll q = n - has;
      ll qt = q / k + !!(q % k);
      tm += qt;
    }
    cout << tm << '\n';
  }
}
