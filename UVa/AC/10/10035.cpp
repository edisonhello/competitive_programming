#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; while (cin >> a >> b) {
        if (a == "0" && b == "0") break;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < b.size()) a += '0';
        while (a.size() > b.size()) b += '0';
        a += "0"; b += "0";
        int c = 0;
        for (int i = 0; i < int(a.size()); ++i) {
            int x = a[i] - '0' + b[i] - '0';
            if (x > 9) ++c;
            a[i] = x % 10 + '0';
            if (x > 9) ++a[i + 1];
        }
        if (c == 0) cout << "No carry operation.\n";
        else if (c == 1) cout << "1 carry operation.\n";
        else cout << c << " carry operations.\n";
    }
}
