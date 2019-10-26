#include <bits/stdc++.h>
using namespace std;

#define INT vector<int> 

INT operator + (const INT a, const INT b) {
    INT rt(max(a.size(), b.size()), 0);
    for (int i = 0; i < (int)a.size(); ++i) rt[i] += a[i];
    for (int i = 0; i < (int)b.size(); ++i) rt[i] += b[i];
    for (int i = 0; i < (int)rt.size() - 1; ++i) if (rt[i] > 9) {
        ++rt[i + 1];
        rt[i] -= 10;
    }
    while (rt.back() > 9) {
        rt.back() -= 10;
        rt.push_back(1);
    }
    return rt;
}
INT operator * (const INT a, const INT b) {
    INT rt(a.size() + b.size(), 0);
    for (int i = 0; i < (int)a.size(); ++i) for (int j = 0; j < (int)b.size(); ++j)
        rt[i + j] += a[i] * b[j];
    for (int i = 0; i < (int)rt.size() - 1; ++i) {
        if (rt[i] > 9) {
            rt[i + 1] += rt[i] / 10;
            rt[i] %= 10;
        }
    }
    while (rt.back() > 9) {
        rt.push_back(rt.back() / 10);
        rt[rt.size() - 2] %= 10;
    }
    while (rt.size() && rt.back() == 0) rt.pop_back();
    if (rt.empty()) rt = {0};
    return rt;
}
INT operator * (const INT a, const int b) {
    INT bb; bb.push_back(b);
    return a * bb;
}

INT prepow[1005][21], tab[21][21], npow[1005];

INT solve(int x, int n) {
    int l = 0, r = n;
    vector<int> status(n, 0);
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (x >= m) {
            status[m] = -1;
            l = m;
        } else {
            status[m] = 1;
            r = m;
        }
    }
    status[l] = 999;
    int mbig = 0, msml = 0, abtr = 0;
    for (int i = 0; i < n; ++i) {
        if (status[i] == -1) ++msml;
        if (status[i] == 1) ++mbig;
        if (status[i] == 0) ++abtr;
    }
    return tab[msml][mbig] * npow[abtr];
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
#endif
    int n; cin >> n;
    npow[0].push_back(1);
    for (int i = 1; i <= n; ++i) npow[i] = npow[i - 1] * n;
    for (int i = 0; i <= n; ++i) {
        prepow[i][0].push_back(1);
        for (int j = 1; j <= 20; ++j) {
            prepow[i][j] = prepow[i][j - 1] * i;
        }
    }
    for (int a = 0; a <= 20; ++a) for (int b = 0; b <= 20; ++b) {
        tab[a][b].push_back(0);
        for (int i = 1; i <= n; ++i) {
            tab[a][b] = tab[a][b] + prepow[i][a] * prepow[n - i][b];
        }
    }

    INT ans; ans.push_back(0);
    for (int i = 0; i < n; ++i) ans = ans + solve(i, n);

    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i;
    cout << '\n';
}
