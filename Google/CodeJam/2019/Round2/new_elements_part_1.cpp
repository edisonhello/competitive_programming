#include <bits/stdc++.h>
using namespace std;
#define double long double
// #include "/home/edison/Coding/cpp/template/debug.cpp"

// void check_answer(vector<pair<int, int>> v, int oans) {
//     vector<vector<pair<int, int>>> st;
//     int it = 0;
//     for (double sl = -0.001; it <= 1000000; ++it, sl *= 1.0001) {
//         sort(v.begin(), v.end(), [&] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
//             return -a.first * sl + a.second < -b.first * sl + b.second;
//         });
//         if (st.empty() || v != st.back()) st.push_back(v);
//     }
//     PDE(oans, st.size());
//     if (oans != st.size()) exit(87);
//     PDE("ok", st);
// }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    set<pair<int, int>> slopes;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        if (v[i].first == v[j].first) continue;
        if (v[i].second == v[j].second) continue;
        int u = (v[j].second - v[i].second);
        int d = (v[j].first - v[i].first);
        if (1ll * u * d > 0) continue;
        int g = __gcd(u, d);
        u /= g;
        d /= g;
        slopes.insert(make_pair(u, d));
    }
    cout << slopes.size() + 1 << endl;
    return;
    // sort(slopes.begin(), slopes.end());
    // PDE(slopes);
    // int vars = 0;
    // double last = -1e19;
    // for (double i : slopes) {
    //     if (abs(last - i) > 1e-10) {
    //         last = i;
    //         vars++;
    //     }
    // }
    // check_answer(v, vars + 1);
    // cout << vars + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Ts; cin >> Ts; 
    for (int t = 1; t <= Ts; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
