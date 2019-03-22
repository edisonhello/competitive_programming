#include <bits/stdc++.h>
using namespace std;

int main() {
    double t1, t3, t2, x1, x2;
    while (cin >> t1 >> t3 >> t2 >> x1 >> x2) {
        double m = (x2 - x1) / (t2 - t1);
        double x3 = x1 + (t3 - t1) * m;
        cout << fixed << setprecision(6) << x3 << endl;
    }
}
