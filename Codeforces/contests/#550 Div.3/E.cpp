#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

int main() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    for (char c : s) a.push_back(c - 'a');
    for (char c : t) b.push_back(c - 'a');
    for (int i = 0; i < n; ++i) a[i] += b[i];
    for (int i = n - 1; i > 0; --i) if (a[i] >= 26) a[i] -= 26, ++a[i - 1];
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) a[i + 1] += 26;
        a[i] >>= 1;
    }
    for (int i : a) {
        cout << char(i + 'a');
    }
    cout << endl;
}
