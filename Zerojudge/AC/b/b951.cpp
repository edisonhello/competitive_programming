#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; while (getline(cin, s)) {
        vector<int> v;
        stringstream ss(s);
        int t; while (ss >> t) v.push_back(t);
        int n = v.size(), sum = 0;
        for (int i : v) sum += i;
        bitset<125001> bs;
        bs[0] = 1;
        for (int i : v) bs |= bs << i;
        long long ans = 0;
        for (int i = bs._Find_first(); i < 125001; i = bs._Find_next(i)) {
            ans = max(ans, 1ll * i * (sum - i));
        }
        cout << ans << '\n';
    }
}
