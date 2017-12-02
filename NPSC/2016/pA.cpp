#include <iostream>
#include <algorithm>

using namespace std;

struct point { long long x, y; } pt[100007];

long long data[100007], dis[100007];
long long as[100007], BIT[100007];

int N;

void add(int pos) {
    for (; pos <= N; pos += (pos & -pos)) BIT[pos]++;
}

int query(int pos) {
    int ans = 0;
    for (; pos > 0; pos -= (pos & -pos)) ans += BIT[pos];
    return ans;
}

void cal(int L, int U)
{
    int pN;
    for (int i = 1; i <= N; i++) BIT[i] = 0;
    for (int i = 0; i < N; i++) data[i] = dis[i] = pt[i].y - L * pt[i].x;
    sort(dis, dis + N);
    pN = unique(dis, dis + N) - dis;
    for (int i = 0; i < N; i++) data[i] = lower_bound(dis, dis + pN, data[i]) - dis + 1;
    for (int i = 0; i < N; i++) {
        as[i] += query(data[i]);
        add(data[i]);
    }

    for (int i = 1; i <= N; i++) BIT[i] = 0;
    for (int i = 0; i < N; i++) data[i] = dis[i] = pt[i].y - U * pt[i].x;
    sort(dis, dis + N);
    pN = unique(dis, dis + N) - dis;
    for (int i = 0; i < N; i++) data[i] = lower_bound(dis, dis + pN, data[i]) - dis + 1;
    for (int i = 0; i < N; i++) {
        as[i] -= query(data[i]);
        add(data[i]);
    }
}

int main()
{
    long long L, U, pN;
    cin >> N >> L >> U;
    if (L == U) { cout << "0\n"; return 0; }

    for (int i = 0; i < N; i++) cin >> pt[i].y, pt[i].x = i;

    cal(L, U);
    for (int i = 0; i < N; i++) pt[i].y = -pt[i].y;
    cal(L, U);

    long long ans = 0;
    for (int i = 0; i < N; i++) ans += as[i];

    if (!L) {
        for (int i = 0; i < N; i++) data[i] = pt[i].y;
        sort(data, data + N);
        long long l = 0;
        for (int i = 1; i < N; i++) {
            if (data[i] == data[i - 1]) l++;
            else {ans -= l * (l + 1) / 2; l = 0;}
        }
        ans -= l * (l + 1) / 2;
    }
    cout << ans << endl;
}
