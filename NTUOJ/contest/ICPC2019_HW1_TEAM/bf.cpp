#include <bits/stdc++.h>
using namespace std;

int es[35][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> es[i][0] >> es[i][1];
    int mx = 0;
    for (int z = 0; z < (1 << m); ++z) {
        set<int> st;
        bool no = false;
        for (int i = 0; i < m; ++i) if (z & (1 << i)) {
            if (st.count(es[i][0]) || st.count(es[i][1])) { no = true; break; }
            st.insert(es[i][0]); st.insert(es[i][1]);
        }
        if (!no) mx = max(mx, (int)st.size() / 2);
    }
    cout << mx << endl;
}
