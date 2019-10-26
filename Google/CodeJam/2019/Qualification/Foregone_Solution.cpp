#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; 
    for (int ts = 1; ts <= T; ++ts) {
        string s; cin >> s;
        int n = s.size();
        string t(n, '0');
        for (int i = 0; i < n; ++i) {
            if (s[i] == '4') --s[i], ++t[i];
        }
        reverse(t.begin(), t.end());
        while (t[t.size() - 1] == '0') t = t.substr(0, t.size() - 1);
        reverse(t.begin(), t.end());
        cout << "Case #" << ts << ": " << s << " " << t << '\n';
    }
}
