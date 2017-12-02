#include <iostream>
#include <algorithm>

using namespace std;

long long ans[4] = {10000000000000000ll};

void cal(long long a, long long K)
{
    long long M = K / a;
    for (long long C = 1; C * C <= M; C++) if (M % C == 0) {
        long long V[4] = {0, a, C, M / C};
        V[0] = 2*(V[1]*V[2]+V[2]*V[3]+V[1]*V[3]);
        sort(V + 1, V + 4);
        if (lexicographical_compare(V, V+4, ans, ans+4)) for (int i = 0; i < 4; i++) ans[i] = V[i];
    }
}

int main()
{
    long long K;
    cin >> K;
    for (long long CB = 1; CB*CB*CB <= K; CB++) if (K % CB == 0) cal(CB, K);
    //sort(V, V + 3);
    for (int i = 0; i < 4; i++) cout << ans[i] << ' ';
    cout << endl;
}
