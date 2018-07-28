#include <bits/stdc++.h>
using namespace std;

vector<string> meow, tt;
bool v[10];

string doo(string s, int a) {
    string ret = "";
    for (int i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) {
            int ind = (s[i] - 'A' + a) % 26;
            ret += (char)('A' + ind);
        } else ret += s[i];
    }
    return ret;
}
string upper(string s) {
    string ret = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a') ret += s[i] - 32;
        else ret += s[i];
    }
    return ret;
}
int main() {
    string s; cin >> s;
    int pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ',') {
            pos = i; break;
        }
    }
    meow.push_back("A"); meow.push_back("AN"); meow.push_back("AM"); meow.push_back("I"); meow.push_back("IT"); meow.push_back("IS"); meow.push_back(upper(s.substr(0, pos)));
    string t = s.substr(pos + 1, s.length() - pos - 1);
    stringstream ss(t); int n; ss >> n;
    string tmp;
    while (cin >> tmp) tt.push_back(upper(tmp));
    int ans = -1;
    for (int i = 0; i < 26; ++i) {
        memset(v, false, sizeof(v));
        for (string j : tt) {
            string l = doo(j, i);
            string lalal = "";
            for (int k = 0; k < l.length(); ++k) {
                if (isalpha(l[k])) lalal += l[k];
            }
            for (int k = 0; k < 7; ++k) {
                if (lalal == meow[k]) v[k] = true;
            }
        }
        int cnt = 0;
        for (int k = 0; k < 6; ++k) if (v[k]) ++cnt;
        if (cnt > 0 && v[6]) {
            if (ans != -1) {
                return cout << "NA" << endl, 0;
            } 
            ans = i;
        }
    }
    if (ans == -1) return cout << "NA" << endl, 0;
    string fuck = doo(tt[n - 1], ans);
    string fuk = "";
    for (int k = 0; k < fuck.length(); ++k) {
        if (isalpha(fuck[k])) fuk += fuck[k];
    }
    cout << fuk << endl;
    return 0;
}
