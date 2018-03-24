#include "lib2056.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main() {
    int n = Init();
    for (int i = 0; i < n; ++i) {
        int now = i;
        cout << "i = " << i << endl;
        while (true) {
            int q = Query(now);
            cout << "now = " << now << " q = " << q << endl;
            if (q == i) {
                Answer(now);
                break;
            }
            now = q;
        }
    }
    return 0;
}
