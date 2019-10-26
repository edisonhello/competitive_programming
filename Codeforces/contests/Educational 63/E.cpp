#include <bits/stdc++.h>
using namespace std;

const int mod = 1000003;

int ans[55], x[55], coef[55];
int mat[55][20];

int pw(int b, int n, int m, int a = 1) {
    while (n) {
        if (n & 1) a = 1ll * a * b % mod;
        b = 1ll * b * b % mod; n >>= 1;
    } return a;
}

int inv(int x) {
    return pw(x, mod - 2, mod);
}

int main() {
    for (int i = 0; i <= 49; ++i) {
        cout << "? " << i << endl;
        cin >> ans[i];
        int x = 1;
        for (int j = 0; j <= 10; ++j) mat[i][j] = x, (x *= i) %= mod;
    }
    for (int j = 0; j <= 10; ++j) {
        for (int i = j; i <= 49; ++i) {
            if (mat[i][j]) {
                for (int k = 0; k <= 10; ++k) swap(mat[i][k], mat[j][k]); swap(ans[i], ans[j]);
            }
        }
        if (mat[j][j] == 0) break;
        for (int i = j + 1; i <= 49; ++i) {
            while (mat[i][j] % mat[j][j]) {
                if (mat[i][j] > mat[j][j]) {
                    int t = mat[i][j] / mat[j][j];
                    for (int k = 0; k <= 10; ++k) mat[i][k] = (mat[i][k] - mat[j][k] * 1ll * t % mod + mod) % mod;
                    ans[i] = (ans[i] - ans[j] * 1ll * t % mod + mod) % mod;
                } else {
                    int t = mat[j][j] / mat[i][j] - (mat[j][j] % mat[i][j] ? 0 : 1);
                    for (int k = 0; k <= 10; ++k) mat[j][k] = (mat[j][k] - mat[i][k] * 1ll * t % mod + mod) % mod;
                    ans[j] = (ans[j] - ans[i] * 1ll * t % mod + mod) % mod;
                }
            }
            int t = mat[i][j] / mat[j][j];
            for (int k = 0; k <= 10; ++k) mat[i][k] = (mat[i][k] - mat[j][k] * 1ll * t % mod + mod) % mod;
            ans[i] = (ans[i] - ans[j] * 1ll * t % mod + mod) % mod;
        }
        /* cerr << "mat : " << endl;
        for (int i = 0; i <= 4; ++i) {
            for (int j = 0; j <= 5; ++j) cout << mat[i][j] << " ";
            cout << " = " << ans[i] << endl;
        } */
    }
    for (int i = 0; i <= 10; ++i) {
        int t = inv(mat[i][i]);
        for (int j = 0; j <= 10; ++j) mat[i][j] = mat[i][j] * 1ll * t % mod;
        ans[i] = ans[i] * 1ll * t % mod;
    }
    for (int i = 10; i >= 0; --i) {
        for (int j = i + 1; j <= 10; ++j) {
            ans[i] = (ans[i] - coef[j] * 1ll * mat[i][j] % mod + mod) % mod;
        }
        coef[i] = ans[i];
        // cerr << "get coef[" << i << "] = " << coef[i] << endl;
    }
    for (int x = 0; x < 1000003; ++x) {
        int sum = 0;
        int xx = 1;
        for (int i = 0; i <= 10; ++i) {
            sum += coef[i] * 1ll * xx % mod;
            xx = 1ll * xx * x % mod;
        }
        if (sum % mod == 0) {
            cout << "! " << x << endl;
            exit(0);
        }
    }
    cout << "! -1" << endl;
}
