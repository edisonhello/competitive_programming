#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s >> s;
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] < s[i - 1]) {
            cout << "YES" << endl;
            cout << i << " " << i + 1 << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
}
