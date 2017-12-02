#include <iostream>

using namespace std;

long long MOD = 1000000007;
long long INV2 = 500000004;

struct mat {
    long long a1, a2, b1, b2;
};

mat operator*(const mat& a, const mat& b) {
    return (mat){(a.a1*b.a1+a.a2*b.b1)%MOD, (a.a1*b.a2+a.a2*b.b2)%MOD, (a.b1*b.a1+a.b2*b.b1)%MOD, (a.b1*b.a2+a.b2*b.b2)%MOD};
}

mat pow(mat a, long long pw)
{
    mat ans = {1, 0, 0, 1};
    while (pw) {
        if (pw & 1) ans = ans * a;
        a = a * a;
        pw >>= 1;
    }
    return ans;
}

long long F(long long s)
{
    if (!s) return 0;
    mat t = {1, 1, 1, 0};
    t = pow(t, s);
    return t.a2;
}

int main()
{
    int A;
    long long S, T;
    cin >> A;
    while (A--) {
        cin >> S >> T;
        cout << ( (F(T)*F(T+1)%MOD-F(S-1)* F(S) % MOD-F(T+2)+F(S+1)) % MOD + MOD) % MOD * INV2 % MOD << '\n';
    }
    return 0;
}
