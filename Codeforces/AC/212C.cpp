#include <bits/stdc++.h>
using namespace std;

string spin(string s) {
    string t = s;
    for (int i = 0; i < (int)s.size(); ++i) {
        int j = (i + 1) % s.size();
        if (s[i] == 'A' && s[j] == 'B') swap(t[i], t[j]);
    }
    return t;
}

long long rec[155][2];

int main() {
    string s; cin >> s;
    int n = s.size();
    for (char &c : s) c -= 'A';
    auto go = [&] () {
        for (int i = 1; i < n; ++i) {
            if (s[i] == 0) {
                if (s[i - 1] == 0) {
                    rec[i][0] = rec[i - 1][0] + rec[i - 1][1];
                    rec[i][1] = 0;
                } else {
                    rec[i][0] = rec[i - 1][1];
                    rec[i][1] = rec[i - 1][0];
                }
            } else {
                if (s[i - 1] == 0) {
                    rec[i][0] = rec[i - 1][0] + rec[i - 1][1];
                    rec[i][1] = rec[i - 1][1];
                } else {
                    rec[i][0] = rec[i - 1][1];
                    rec[i][1] = rec[i - 1][1];
                }
            }
            //  cerr << "rec["<<i<<"]["<<0<<"] = " << rec[i][0] <<", rec["<<i<<"]["<<1<<"] = " << rec[i][1] << endl;
        }
    };
    long long ans = 0;
    if (s.back() == 0 && s[0] == 0) {
        rec[0][0] = 1; go(); ans = rec[n - 1][0] + rec[n - 1][1];
    } else if (s.back() == 0 && s[0] == 1) {
        rec[0][0] = 1; go(); ans = rec[n - 1][0] + rec[n - 1][1]; 
        memset(rec, 0, sizeof(rec));
        rec[0][1] = 1; go(); ans += rec[n - 1][1];
    } else if (s.back() == 1 && s[0] == 0) {
        rec[0][0] = 1; go(); ans = rec[n - 1][1];
        memset(rec, 0, sizeof(rec));
        rec[0][1] = 1; go(); ans += rec[n - 1][0];
    } else {
        rec[0][0] = 1; go(); ans = rec[n - 1][1];
        memset(rec, 0, sizeof(rec));
        rec[0][1] = 1; go(); ans += rec[n - 1][1];
    }
    cout << ans << endl;
    /* for (int i = 3; i <= 10; ++i) {
        map<string, vector<string>> mp;
        for (int j = 0; j < (1 << i); ++j) {
            string s;
            for (int z = 0; z < i; ++z) {
                s += (j & (1 << z)) ? "A" : "B";
            }
            mp[spin(s)].push_back(s);
        }
        for (auto it : mp) {
            cout << it.first << " : ";
            for (string s : it.second) cout << s << ", ";
            cout << endl;
        }
        cout <<endl;
    } */
}
