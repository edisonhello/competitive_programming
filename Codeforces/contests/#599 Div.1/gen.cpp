#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) * clock());
    int n = rand() % 5 + 1; cout << n << endl;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        int t = rand() % 4 + 1; cout << t << ' ';
        while (t--) {
            int z = rand() % 20 - 10;
            while (st.count(z)) z = rand() % 20 - 10;
            st.insert(z);
            cout << z << ' ';
        }
        cout << endl;
    }
}
