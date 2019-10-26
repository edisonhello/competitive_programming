#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> no(m);
        for (int i = 0; i < m; ++i) cin >> no[i].first >> no[i].second;
        sort(no.begin(), no.end());
        int mx = 0;
        int L = 1, R = n - 1;
        multiset<int> st;
        for (auto &p : no) {
            st.insert(p.second);
            while (st.size() && *prev(st.end()) + p.first > n) st.erase(prev(st.end()));
            if ((int)st.size() > mx) {
                mx = st.size();
                L = p.first, R = n - p.first;
            }
        }
        cout << L << " " << R << '\n';
    }
}
