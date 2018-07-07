#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int a[8][8];

bool in(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool check(int x, int y) {
    for (int i = 0; i < 8; ++i) {
        int cnt = 0;
        bool ok = true, z = false;
        for (int j = 1; ; ++j) {
            int tx = x + dx[i] * j, ty = y + dy[i] * j;
            if (!in(tx, ty)) break;
            if (a[tx][ty] == 0) {
                ok = false;
                break;
            }
            if (a[tx][ty] == 2) {
                ++cnt;
            }
            if (a[tx][ty] == 1) {
                z = true;
                break;
            }
        }
        if (z && ok && cnt > 0) return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) if (a[i][j] == 0) {
            if (check(i, j)) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
