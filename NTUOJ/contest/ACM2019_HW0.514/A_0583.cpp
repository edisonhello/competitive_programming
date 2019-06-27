#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000;

long long a[10000007];

int main() {
    for (int i = 1; i <= maxn; ++i) for (long long j = 1ll * i * i; j <= maxn; j += i) ++a[j];
    for (int i = 2; i <= maxn; ++i) a[i] += a[i - 1];
    int t; scanf("%d", &t);
    while (t--) { int n; scanf("%d", &n); printf("%lld\n", a[n]); }
}
