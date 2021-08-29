#include <bits/stdc++.h>
using namespace std;

int wf[55];
int pm[55][55];
int alive[55];

void hw() { cout << "lieren" << '\n'; }
void ww() { cout << "langren" << '\n'; }

void solve() {
  int n; cin >> n;
  int wolf = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> wf[i];
    if (wf[i]) wolf = i;
    alive[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cin >> pm[i][j];
  }

  int hc = n - 1, pc = n, day = 1, prevdie = 0;

  while (true) {
    int die = -1;
    if (day == 1) {
      die = pm[wolf][1];
    } else {
      for (int j = 1; j <= n; ++j) {
        if (alive[pm[prevdie][j]]) { die = pm[prevdie][j]; break; }
      }
    }

    assert(die != -1);
    assert(alive[die]);
    if (die == wolf) {
      hw();
      return;
    }
    --pc;
    --hc;
    prevdie = die;
    alive[die] = 0;
    if (pc <= 2) {
      ww();
      return;
    }

    ++day;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
