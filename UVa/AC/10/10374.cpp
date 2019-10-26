#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; scanf("%d\n", &t); while (t--) {
        int n; scanf("\n%d\n", &n);
        unordered_map<string, string> pp;
        unordered_map<string, int> pv;
        while (n--) {
            string s, t; 
            getline(cin, s);
            getline(cin, t);
            // if (t == "independent") t = s + char(1);
            pp[s] = t;
        }
        int m; scanf("%d\n", &m);
        while (m--) {
            string s;
            getline(cin, s);
            if (pp.count(s) == 0) continue;
            pv[s]++;
        }
        int mx = -1, mxc = 0;
        string win;
        for (auto &p : pv) {
            if (p.second > mx) {
                mx = p.second;
                    mxc = 1;
                win = p.first;
            } else if (p.second == mx) {
                ++mxc;
            }
        }
        if (mxc != 1) {
            cout << "tie" << '\n';
        } else cout << pp[win] << '\n';
        if (t) cout << '\n';
    }
}
