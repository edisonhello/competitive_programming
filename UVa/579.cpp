#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m; while (scanf("%d:%d\n", &h, &m) != EOF) {
        if (h == 0 && m == 0) break;
        double mm = 360. / 60 * m;
        double hh = 360. / 12 * h + 360. / 720 * m;
        double hx = cos(hh / 360 * 2 * acos(-1));
        double hy = sin(hh / 360 * 2 * acos(-1));
        double mx = cos(mm / 360 * 2 * acos(-1));
        double my = sin(mm / 360 * 2 * acos(-1));
        double tj = acos(hx * mx + hy * my);
        printf("%.3lf\n", tj / 2 / acos(-1) * 360);
    }
}
