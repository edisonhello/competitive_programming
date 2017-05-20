#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 2147483647;

long long D[1000007], pD[1000007], H[1000007];
int BIT[1000007];
int N;

void modify(int pos, int s) {
    for (; pos <= N; pos += (pos & -pos)) BIT[pos] = min(s, BIT[pos]);
}

int query(int pos) {
    int ans = INF;
    for (; pos > 0; pos -= (pos & -pos)) ans = min(ans, BIT[pos]);
    return ans;
}


int main()
{
    cin >> N;
    for (int i = 0; i <= N + 2; i++) BIT[i] = INF;

    for (int i = 1; i <= N; i++) {cin >> D[i]; H[i] = D[i]; pD[i] = H[i] += H[i - 1];}
    sort(pD, pD + N + 1);
    int pN = unique(pD, pD + N + 1) - pD;
    for (int i = 0; i <= N; i++) H[i] = lower_bound(pD, pD + pN, H[i]) - pD + 1;

    long long ans = 0;
    //for (int i = 1; i <= N; i++) cout << H[i];
    for (int i = N; ~i; i--) {
            //cout << D[i];
        int p = query(H[i] - 1);
        //cout << p << ' ';
        if (p != INF) ans += N - p + 1;
        modify(H[i], i);
    }
    cout << ans << endl;
}
