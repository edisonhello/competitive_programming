#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int a[maxn], pos[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int mx = 1, now = 0, np = 0;
    for (int i = 1; i <= n; ++i) {
        if (pos[i] > np) {
            ++now;
            mx = max(mx, now);
            np = pos[i];
        } else {
            now = 1;
            np = pos[i];
        }
    }
    cout << n - mx << endl;
}
