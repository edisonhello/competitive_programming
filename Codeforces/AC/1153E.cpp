#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    int ans; cin >> ans;
    if (ans == -1) exit(0);
    else return ans & 1;
}

void answer(int a, int b, int c, int d) {
    printf("! %d %d %d %d\n", a, b, c, d);
    exit(0);
}

int main() {
    int n; cin >> n;
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    int xp = 0, yp = 0;
    for (int i = 1; i <= n; ++i) {
        int yr = query(1, 1, n, i);
        if (yr != yp) {
            if (yr) y1 = i;
            else y2 = i;
            yp ^= 1;
        }
        int xr = query(1, 1, i, n);
        if (xr != xp) {
            if (xr) x1 = i;
            else x2 = i;
            xp ^= 1;
        }
    }
    if (x1 == -1) {
        int L = 1, R = n;
        while (R > L) {
            int M = (L + R) >> 1;
            if (query(1, 1, M, y1)) R = M;
            else L = M + 1;
        }
        answer(L, y1, L, y2);
    } else if (y1 == -1) {
        int L = 1, R = n;
        while (R > L) {
            int M = (L + R) >> 1;
            if (query(1, 1, x1, M)) R = M;
            else L = M + 1;
        }
        answer(x1, L, x2, L);
    } else {
        if (query(1, 1, x1, y1)) {
            answer(x1, y1, x2, y2);
        } else {
            answer(x1, y2, x2, y1);
        }
    }
}
