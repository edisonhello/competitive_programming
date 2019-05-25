#include <bits/stdc++.h>
using namespace std;

string s[1006];
uint64_t hh[1006][60], pp[60];
bitset<1006> mark;

uint64_t get_hash(int id, int l, int r) {
    return hh[id][r + 1] - hh[id][l] * pp[r - l + 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    pp[0] = 1;
    for (int i = 1; i < 60; ++i) pp[i] = pp[i - 1] * 7902131;
    int t; cin >> t; for (int ts = 1; ts <= t; ++ts) {
        cout << "Case #" << ts << ": ";
        int n; cin >> n; 
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            for (int j = 1; j <= (int)s[i].size(); ++j) {
                hh[i][j] = hh[i][j - 1] * 7902131 + s[i][j - 1];
            }
        }
        mark.reset();
        int ans = 0;
        for (int l = 50; l >= 1; --l) {
            map<uint64_t, vector<int>> mp;
            for (int i = 1; i <= n; ++i) if (!mark[i]) {
                if ((int)s[i].size() < l) continue;
                mp[get_hash(i, (int)s[i].size() - l, (int)s[i].size() - 1)].push_back(i);
            }
            for (auto &p : mp) {
                if (p.second.size() > 1u) {
                    ans += 2;
                    mark[p.second.back()] = 1;
                    p.second.pop_back();
                    mark[p.second.back()] = 1;
                }
            }
        }
        cout << ans << endl;
    }
}
