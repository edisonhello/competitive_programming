#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

#define T long long 
#define Z 1000000000
#define W 9

using namespace std;

void sub(vector<T> &a, vector<T> &b) {
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    for (int i = 0; i < (int)a.size(); ++i) a[i] -= b[i];
}

void mul(const vector<T> &a, const vector<T> &b, vector<T> &r) {
    if (a.size() <= 256u) {
        r.resize(a.size() * 2 + 5, 0);
        for (int i = 0; i < (int)a.size(); ++i) for (int j = 0; j < (int)b.size(); ++j) {
            r[i + j] += a[i] * b[j];
            for (int z = 0; abs(r[i + j + z]) >= Z; ++z) {
                long long t = r[i + j + z] / Z;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
    // int t = 100; while (t--) {
        string a, b; cin >> a >> b;
        // string a, b;
        // while (a.size() < 30000u) a += rand() % 10 + '0';
        // while (b.size() < 30000u) b += rand() % 10 + '0';
        int flag = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.back() == '-') flag ^= 1, a.pop_back();
        if (b.back() == '-') flag ^= 1, b.pop_back();
        for (char &c : a) c -= '0';
        for (char &c : b) c -= '0';
        while (a.size() < b.size()) a += char(0);
        while (b.size() < a.size()) b += char(0);
        vector<T> va, vb, vr;
        for (int i = 0; i < (int)a.size(); i += 9) {
            va.push_back(
                a[i] + 
                (i + 1 < (int)a.size() ? a[i + 1] : 0) * 10 +
                (i + 2 < (int)a.size() ? a[i + 2] : 0) * 100 +
                (i + 3 < (int)a.size() ? a[i + 3] : 0) * 1000 + 
                (i + 4 < (int)a.size() ? a[i + 4] : 0) * 10000 + 
                (i + 5 < (int)a.size() ? a[i + 5] : 0) * 100000 + 
                (i + 6 < (int)a.size() ? a[i + 6] : 0) * 1000000 + 
                (i + 7 < (int)a.size() ? a[i + 7] : 0) * 10000000 + 
                (i + 8 < (int)a.size() ? a[i + 8] : 0) * 100000000);
            vb.push_back(
                b[i] + 
                (i + 1 < (int)a.size() ? b[i + 1] : 0) * 10 +
                (i + 2 < (int)a.size() ? b[i + 2] : 0) * 100 +
                (i + 3 < (int)a.size() ? b[i + 3] : 0) * 1000 + 
                (i + 4 < (int)a.size() ? b[i + 4] : 0) * 10000 + 
                (i + 5 < (int)a.size() ? b[i + 5] : 0) * 100000 + 
                (i + 6 < (int)a.size() ? b[i + 6] : 0) * 1000000 + 
                (i + 7 < (int)a.size() ? b[i + 7] : 0) * 10000000 + 
                (i + 8 < (int)a.size() ? b[i + 8] : 0) * 100000000);
        }
        mul(va, vb, vr);
        vr.push_back(0);
        for (int i = 0; i < (int)vr.size(); ++i) {
            if (vr[i] < 0) {
                long long t = vr[i] / Z - 1;
                vr[i + 1] += t;
                vr[i] -= t * Z;
            } else if (vr[i] >= Z) {
                long long t = vr[i] / Z;
                vr[i + 1] += t;
                vr[i] -= t * Z;
            }
        }
        while (vr.size() > 1u && vr.back() == 0) vr.pop_back();
        reverse(vr.begin(), vr.end());
        if (flag && (vr.size() != 1u || vr[0] != 0)) cout << "-";
        for (int i = 0; i < (int)vr.size(); ++i) {
            if (i) {
                cout << setw(W) << setfill('0') << vr[i];
            } else cout << vr[i];
        }
        cout << endl;
    }
}
