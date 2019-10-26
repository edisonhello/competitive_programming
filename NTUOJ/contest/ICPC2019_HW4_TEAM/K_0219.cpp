#include <bits/stdc++.h>
using namespace std;

typedef array<array<int, 3>, 3> State;

const int t = 42374116;

int parse(State s) {
    int x = 0, p = 1;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
        x += s[i][j] * p;
        p *= 9;
    }
    return x;
}
State parse(int x) {
    State s;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
        s[i][j] = x % 9;
        x /= 9;
    }
    return s;
}

unordered_map<int, int> mp;
int solve(int s) {
    queue<int> q; q.push(s);
    mp.clear(); mp[s] = 0;
    while (mp.count(t) == 0 && q.size()) {
        int now = q.front(); q.pop();
        State s = parse(now);
        auto push = [&] (const State &s) -> void {
            int z = parse(s);
            if (mp.count(z)) return;
            mp[z] = mp[now] + 1;
            q.push(z);
        };
        int match = 0;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) if (s[i][j] == (i * 3) + j + 1) ++match;
        int unmatch = 8 - match;
        if (mp[now] + unmatch > 20) continue;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            if (s[i][j] == 0) {
                if (i) {
                    swap(s[i][j], s[i - 1][j]);
                    push(s);
                    swap(s[i][j], s[i - 1][j]);
                }
                if (i != 2) {
                    swap(s[i][j], s[i + 1][j]);
                    push(s);
                    swap(s[i][j], s[i + 1][j]);
                }
                if (j) {
                    swap(s[i][j], s[i][j - 1]);
                    push(s);
                    swap(s[i][j], s[i][j - 1]);
                }
                if (j != 2) {
                    swap(s[i][j], s[i][j + 1]);
                    push(s);
                    swap(s[i][j], s[i][j + 1]);
                }
                break;
            }
        }
    }
    if (mp.count(t) == 0) return -1;
    return mp[t];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        State s;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> s[i][j];
        int z = solve(parse(s));
        if (z == -1) cout << "Hard" << '\n';
        else cout << z << '\n';
    }
}
