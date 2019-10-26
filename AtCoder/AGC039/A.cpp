#include <bits/stdc++.h>
using namespace std;

long long check(string s) {
    int prv = -1;
    long long rt = 0;
    for (char c : s) if (c == prv) {
        ++rt;
        prv = -1;
    } else prv = c;
    return rt;
}

int main() {
    string s; int k; cin >> s >> k;
    if (k <= 100) {
        string t;
        for (int i = 0; i < k; ++i) t += s;
        cout << check(t) << endl;
    } else if (k % 2 == 0) {
        string t;
        for (int i = 0; i < 50; ++i) t += s;
        long long zz = check(t);
        long long zzz = check(t + s + s);
        cout << zz + (zzz - zz) * (k - 50) / 2 << endl;
    } else {
        string t;
        for (int i = 0; i < 51; ++i) t += s;
        long long zz = check(t);
        long long zzz = check(t + s + s);
        cout << zz + (zzz - zz) * (k - 51) / 2 << endl;
    }
}
