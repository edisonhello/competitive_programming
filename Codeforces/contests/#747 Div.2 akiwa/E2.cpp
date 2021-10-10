#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1000000007;

ll dep;

ll dp[2005][7];
ll rst[2005];

int pw(ll b, ll n) {
  ll a = 1;
  while (n) {
    if (n & 1) a = a * b % mod;
    b = b * b % mod;
    n >>= 1;
  }
  return a;
}


vector<int> dfs(int now, int dep) {
  if (dep > ::dep) assert(0);
  if (now > 2000) {
    ll down = (1ll << (::dep - dep + 1)) - 1;
    return vector<int>(6, pw(4, down) % mod);
  }
  if (dep == ::dep) {
    auto v = vector<int>(6, 1);
    if (rst[now]) {
      v = vector<int>(6, 0);
      v[rst[now] - 1] = 1;
    }
    return v;
  }
  auto a1 = dfs(now * 2 + 0, dep + 1);
  auto a2 = dfs(now * 2 + 1, dep + 1);
  vector<int> vv(6, 0);
  for (int me = 1; me <= 6; ++me) if (!rst[now] || rst[now] == me) {
    for (int i = 1; i <= 6; ++i) for (int j = 1; j <= 6; ++j) if (me != i && me != j && abs(me - i) != 3 && abs(me - j) != 3) {
      vv[me - 1] = (vv[me - 1] + 1ll * a1[i - 1] * a2[j - 1]) % mod;
    }
  }
  return vv;
}

int main() {
  cin >> dep;
  int n; cin >> n;
  while (n--) {
    ll z; cin >> z;
    string c; cin >> c;
    if (c[0] == 'w') rst[z] = 1;
    if (c[0] == 'y') rst[z] = 4;
    if (c[0] == 'g') rst[z] = 2;
    if (c[0] == 'b') rst[z] = 5;
    if (c[0] == 'r') rst[z] = 3;
    if (c[0] == 'o') rst[z] = 6;
  }

  auto way = dfs(1, 1);
  ll sum = 0;
  for (int i : way) sum += i;
  cout << sum % mod << endl;
}
