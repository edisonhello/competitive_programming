#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    deque<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int x = 0;
    while (true) {
        while (v.size() and v.back() == x) v.pop_back();
        if (v.empty()) break;
        if (v.front() != x) {
            cout << "No" << endl;
            exit(0);
        }
        v.pop_front();
        x ^= 1;
    }

    cout << "Yes" << endl;


}