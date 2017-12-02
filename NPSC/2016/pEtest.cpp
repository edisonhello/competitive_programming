#include <iostream>
#include <cstdlib>
#include <tuple>

using namespace std;

tuple<int, int> _pv[101][101];
int _dp[101][101];

int& dp(int a, int b)
{
    return (a > b) ? _dp[a][b] : _dp[b][a];
}
tuple<int, int>& pv(int a, int b)
{
    return (a > b) ? _pv[a][b] : _pv[b][a];
}

int cal1(int a, int b)
{
    int a1 = a, b1 = b;
    while (pv(a1, b1) != make_tuple(0, 0)) tie(a1, b1) = pv(a1, b1), cout << a1 << ' ' << b1 << endl;
    return dp(a, b);
}

int cal2(int a, int b)
{
    if (a > b) swap(a, b);
    int ans = 0;
    for (; a; swap(a, b)) { ans += b / a; b %= a; }
    return ans;
}

int main()
{
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++) dp(i, j) = 100000;
    for (int i = 1; i <= 100; i++) dp(i, i) = 1;

    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            for (int k = 1; k < j; k++)
                if (dp(i, k) + dp(i, j - k) < dp(i, j)) dp(i, j) = dp(i, k) + dp(i, j - k), pv(i, j) = tie(i, k);
            for (int k = 1; k < i; k++)
                if (dp(k, j) + dp(i - k, j) < dp(i, j)) dp(i, j) = dp(k, j) + dp(i - k, j), pv(i, j) = tie(k, j);
        }
    }

    srand(436540);
    for (int i = 0; i < 1000; i++) {
        int a, b;
        cin >> a >> b;
        cal1(a, b);
    }
}
