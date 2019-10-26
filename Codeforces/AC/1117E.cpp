#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, s;
string t1, t2, t3;

int main() {
    string t; cin >> t;
    int n = int(t.size());
    for (int i = 0; i < n; ++i) {
        int x = i;
        s1 += char(x % 26 + 'a'); x /= 26;
        s2 += char(x % 26 + 'a'); x /= 26;
        s3 += char(x % 26 + 'a'); x /= 26;
    }
    cout << "? " << s1 << endl;
    cin >> t1;
    cout << "? " << s2 << endl;
    cin >> t2;
    cout << "? " << s3 << endl;
    cin >> t3;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        x *= 26; x += t3[i] - 'a';
        x *= 26; x += t2[i] - 'a';
        x *= 26; x += t1[i] - 'a';
        s[x] = t[i];
    }
    cout << "! " << s << endl;
}
