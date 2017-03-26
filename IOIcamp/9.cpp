#include <bits/stdc++.h>
using namespace std;

int t, k, mod;

inline void add(int &a, int b){
    a += b;
    if (a > mod) a -= mod;
}

long long pow(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2) return pow(a * a % mod, b / 2) * a % mod;
    else return pow(a * a % mod, b / 2);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> k >> mod;
        int ans = pow(2, k);
        add(ans, pow(3, k));
        add(ans, pow(5, k));
        add(ans, pow(7, k));
        add(ans, pow(11, k));
        add(ans, pow(13, k));
        add(ans, pow(17, k));
        add(ans, pow(19, k));
        add(ans, pow(23, k));
        add(ans, pow(29, k));
        add(ans, pow(31, k));
        add(ans, pow(37, k));
        add(ans, pow(41, k));
        add(ans, pow(43, k));
        add(ans, pow(47, k));
        add(ans, pow(53, k));
        add(ans, pow(59, k));
        add(ans, pow(61, k));
        add(ans, pow(67, k));
        add(ans, pow(71, k));
        add(ans, pow(73, k));
        add(ans, pow(79, k));
        add(ans, pow(83, k));
        add(ans, pow(89, k));
        add(ans, pow(97, k));
        cout << ans << endl;
    }
    return 0;
}
