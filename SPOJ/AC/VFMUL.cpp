#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstring>

#define T long long 
#define Z 1000000000
#define W 9

using namespace std;

void sub(vector<T> &a, vector<T> &b) {
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    for (int i = 0; i < (int)a.size(); ++i) a[i] -= b[i];
    a.push_back(0);
    for (int i = 0; i < (int)a.size() - 1; ++i) if (abs(a[i]) >= Z) {
        T t = a[i] / Z;
        a[i + 1] += t;
        a[i] -= t * Z;
    }
    if (a.back() == 0) a.pop_back();
}

void mul(const vector<T> &a, const vector<T> &b, vector<T> &r) {
    if (a.size() <= 256u) {
        r.resize(a.size() * 2 + 5, 0);
        for (int i = 0; i < (int)a.size(); ++i) for (int j = 0; j < (int)b.size(); ++j) {
            r[i + j] += a[i] * b[j];
            for (int z = 0; abs(r[i + j + z]) >= Z; ++z) {
                T t = r[i + j + z] / Z;
                r[i + j + z + 1] += t;
                r[i + j + z] -= t * Z;
            }
        }
        while (r.size() > 1u && r.back() == 0) r.pop_back();
        return;
    }
    int n = a.size(), m = a.size() / 2;
    vector<T> a1(a.begin(), a.begin() + m), b1(b.begin(), b.begin() + m);
    vector<T> a2(a.begin() + m, a.end()), b2(b.begin() + m, b.end());
    vector<T> r1, r2, r3;
    mul(a1, b1, r1);
    mul(a2, b2, r2);

    sub(a2, a1), sub(b2, b1);
    if (a2.size() < b2.size()) a2.push_back(0);
    if (b2.size() < a2.size()) b2.push_back(0);
    mul(a2, b2, r3);
    r.resize(a.size() * 2 + 5, 0);
    for (int i = 0; i < (int)r1.size(); ++i) r[i] += r1[i];
    for (int i = 0; i < (int)r1.size(); ++i) r[i + m] += r1[i];
    for (int i = 0; i < (int)r2.size(); ++i) r[i + m] += r2[i];
    for (int i = 0; i < (int)r3.size(); ++i) r[i + m] -= r3[i];
    for (int i = 0; i < (int)r2.size(); ++i) r[i + m + m] += r2[i];
    for (int i = 0; i < (int)r.size() - 1; ++i) if (abs(r[i]) >= Z) {
        long long t = r[i] / Z;
        r[i + 1] += t;
        r[i] -= t * Z;
    }
    while (r.size() > 1u && r.back() == 0) r.pop_back();
    return;
}

char a[300005], b[300005];

int main() {
    int t; scanf("%d\n", &t); while (t--) {
    // int t = 100; while (t--) {
        scanf("%s %s\n", a, b);
        int n = strlen(a), m = strlen(b);
        // string a, b;
        // while (a.size() < 30000u) a += rand() % 10 + '0';
        // while (b.size() < 30000u) b += rand() % 10 + '0';
        int flag = 0;
        reverse(a, a + n);
        reverse(b, b + m);
        if (a[n - 1] == '-') flag ^= 1, --n;
        if (b[m - 1] == '-') flag ^= 1, --m;
        for (int i = 0; i < n; ++i) a[i] -= '0';
        for (int i = 0; i < m; ++i) b[i] -= '0';
        while (n < m) a[n++] = 0;
        while (m < n) b[m++] = 0;
        vector<T> va, vb, vr;
        for (int i = 0; i < n; i += 9) {
            va.push_back(
                a[i] + 
                (i + 1 < n ? a[i + 1] : 0) * 10 +
                (i + 2 < n ? a[i + 2] : 0) * 100 +
                (i + 3 < n ? a[i + 3] : 0) * 1000 + 
                (i + 4 < n ? a[i + 4] : 0) * 10000 + 
                (i + 5 < n ? a[i + 5] : 0) * 100000 + 
                (i + 6 < n ? a[i + 6] : 0) * 1000000 + 
                (i + 7 < n ? a[i + 7] : 0) * 10000000 + 
                (i + 8 < n ? a[i + 8] : 0) * 100000000);
            vb.push_back(
                b[i] + 
                (i + 1 < n ? b[i + 1] : 0) * 10 +
                (i + 2 < n ? b[i + 2] : 0) * 100 +
                (i + 3 < n ? b[i + 3] : 0) * 1000 + 
                (i + 4 < n ? b[i + 4] : 0) * 10000 + 
                (i + 5 < n ? b[i + 5] : 0) * 100000 + 
                (i + 6 < n ? b[i + 6] : 0) * 1000000 + 
                (i + 7 < n ? b[i + 7] : 0) * 10000000 + 
                (i + 8 < n ? b[i + 8] : 0) * 100000000);
        }
        mul(va, vb, vr);
        vr.push_back(0);
        for (int i = 0; i < (int)vr.size(); ++i) {
            if (vr[i] < 0) {
                T t = vr[i] / Z - 1;
                vr[i + 1] += t;
                vr[i] -= t * Z;
            } else if (vr[i] >= Z) {
                T t = vr[i] / Z;
                vr[i + 1] += t;
                vr[i] -= t * Z;
            }
        }
        while (vr.size() > 1u && vr.back() == 0) vr.pop_back();
        reverse(vr.begin(), vr.end());
        if (flag && (vr.size() != 1u || vr[0] != 0)) printf("-");
        for (int i = 0; i < (int)vr.size(); ++i) {
            if (i) {
                printf("%09lld", vr[i]);
            } else printf("%lld", vr[i]);
        }
        puts("");
    }
}
