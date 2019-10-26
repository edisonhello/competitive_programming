#include<bits/stdc++.h>
using namespace std;

string mp[300005], ans[300005], tmp[300005];
int now = INT_MAX;
bool flag = false;

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> mp[i];
        ans[i] = mp[i];
    }
    string temp = "ACGT";
    do {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            tmp[i] = "";
            if (i & 1) {
                char u1 = temp[0], u0 = temp[1];
                int pos = 0, neg = 0;
                for (int j = 0; j < m; ++j) {
                    if (j & 1) {
                        if (mp[i][j] != u1) ++pos;
                        if (mp[i][j] != u0) ++neg;
                    } else {
                        if (mp[i][j] != u0) ++pos;
                        if (mp[i][j] != u1) ++neg;
                    }
                }
                cnt += min(pos, neg);
                if (pos < neg) {
                    while (int(tmp[i].size()) < m) tmp[i] += u0, tmp[i] += u1;
                    tmp[i].resize(m);
                } else {
                    while (int(tmp[i].size()) < m) tmp[i] += u1, tmp[i] += u0;
                    tmp[i].resize(m);
                }
            } else {
                char u1 = temp[2], u0 = temp[3];
                int pos = 0, neg = 0;
                for (int j = 0; j < m; ++j) {
                    if (j & 1) {
                        if (mp[i][j] != u1) ++pos;
                        if (mp[i][j] != u0) ++neg;
                    } else {
                        if (mp[i][j] != u0) ++pos;
                        if (mp[i][j] != u1) ++neg;
                    }
                }
                cnt += min(pos, neg);
                if (pos < neg) {
                    while (int(tmp[i].size()) < m) tmp[i] += u0, tmp[i] += u1;
                    tmp[i].resize(m);
                } else {
                    while (int(tmp[i].size()) < m) tmp[i] += u1, tmp[i] += u0;
                    tmp[i].resize(m);
                }
            }
        }
        if (cnt < now) {
            now = cnt;
            for (int i = 0; i < n; ++i) ans[i] = tmp[i];
        }
    } while (next_permutation(temp.begin(), temp.end()));
    for (int i = 0; i < max(n, m); ++i) tmp[i] = "";
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) tmp[j] += mp[i][j];
    swap(n, m);
    for (int i = 0; i < n; ++i) mp[i] = tmp[i];
    do {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            tmp[i] = "";
            if (i & 1) {
                char u1 = temp[0], u0 = temp[1];
                int pos = 0, neg = 0;
                for (int j = 0; j < m; ++j) {
                    if (j & 1) {
                        if (mp[i][j] != u1) ++pos;
                        if (mp[i][j] != u0) ++neg;
                    } else {
                        if (mp[i][j] != u0) ++pos;
                        if (mp[i][j] != u1) ++neg;
                    }
                }
                cnt += min(pos, neg);
                if (pos < neg) {
                    while (int(tmp[i].size()) < m) tmp[i] += u0, tmp[i] += u1;
                    tmp[i].resize(m);
                } else {
                    while (int(tmp[i].size()) < m) tmp[i] += u1, tmp[i] += u0;
                    tmp[i].resize(m);
                }
            } else {
                char u1 = temp[2], u0 = temp[3];
                int pos = 0, neg = 0;
                for (int j = 0; j < m; ++j) {
                    if (j & 1) {
                        if (mp[i][j] != u1) ++pos;
                        if (mp[i][j] != u0) ++neg;
                    } else {
                        if (mp[i][j] != u0) ++pos;
                        if (mp[i][j] != u1) ++neg;
                    }
                }
                cnt += min(pos, neg);
                if (pos < neg) {
                    while (int(tmp[i].size()) < m) tmp[i] += u0, tmp[i] += u1;
                    tmp[i].resize(m);
                } else {
                    while (int(tmp[i].size()) < m) tmp[i] += u1, tmp[i] += u0;
                    tmp[i].resize(m);
                }
            }
        }
        if (cnt < now) {
            now = cnt;
            for (int i = 0; i < n; ++i) ans[i] = tmp[i];
            flag = true;
        }
    } while (next_permutation(temp.begin(), temp.end()));
    if (flag) {
        for (int i = 0; i < max(n, m); ++i) tmp[i] = "";
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) tmp[j] += ans[i][j];
    }
    swap(n, m);
    if (flag) for (int i = 0; i < n; ++i) ans[i] = tmp[i];
    for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
    cerr << "cost = " << now << endl;
}
