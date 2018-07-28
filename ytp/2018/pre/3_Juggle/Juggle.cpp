#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 555;
int a[101], c[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int x = 1;
    for (int i = 0; i < maxn - 111; ++i) {
        if (c[i]) c[i + a[i % n]] = c[i];
        else c[i] = x++, c[i + a[i % n]] = c[i];
    }
    printf("%d\n", x - 1);
}
