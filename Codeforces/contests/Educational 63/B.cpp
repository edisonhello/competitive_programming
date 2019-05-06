#include <bits/stdc++.h>
using namespace std;

bitset<300005> er;

void YES() { cout << "YES" << endl; exit(0); }
void NO() { cout << "NO" << endl; exit(0); } 

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int c8 = 0, cn8 = 0;
    reverse(s.begin(), s.end());
    for (int i = 10; i < n; ++i) {
        if (s[i] == '8') ++c8;
        else ++cn8;
    }
    if (c8 > cn8) YES();
    NO();
}
