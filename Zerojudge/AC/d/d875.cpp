#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n; while (cin >> n) {
        vector<long long> v;
        long long now = 0;
        long long i = 1;
        for (; ; ++i) {
            if (i * (i - 1) / 2 + i * (i + 1) / 2 >= n) {
                for (int j = 1; j <= i; ++j) v.push_back(j);
                for (int j = i - 1; j >= 1; --j) v.push_back(j);
                break;
            }
            if (i * (i + 1) >= n) {
                for (int j = 1; j <= i; ++j) v.push_back(j);
                for (int j = i; j >= 1; --j) v.push_back(j);
                break;
            }
        }
        // cerr << "stop at i = " << i << endl;
        for (long long i : v) now += i;
        for (int z = 0; z < now - n; ++z) {
            v[i - 1 - z]--;
        }
        for (long long i : v) cout << i << ' ';
        cout << '\n';
    }
}
