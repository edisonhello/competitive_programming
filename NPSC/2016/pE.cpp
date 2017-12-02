#include <iostream>

using namespace std;

int _dp[101][101];

int& dp(int a, int b)
{
    return (a > b) ? _dp[a][b] : _dp[b][a];
}

int main()
{
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++) dp(i, j) = 100000;
    for (int i = 1; i <= 100; i++) dp(i, i) = 1;

    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            for (int k = 1; k < j; k++) dp(i, j) = min(dp(i, j), dp(i, k) + dp(i, j - k));
            for (int k = 1; k < i; k++) dp(i, j) = min(dp(i, j), dp(k, j) + dp(i - k, j));
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp(a, b) << endl;;
}
