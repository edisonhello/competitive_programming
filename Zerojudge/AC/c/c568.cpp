#include <bits/stdc++.h>
using namespace std;

bitset<700005> dp;

int main() {
    int n; scanf("%d", &n);
    dp[700000] = 1;
    while (n--) {
        int w; scanf("%d", &w);
        dp |= (dp >> w) | (dp << (700000 - w));
    }
    printf("%d\n", 700000 - dp._Find_first());
}
