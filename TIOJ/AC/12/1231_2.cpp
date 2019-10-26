#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>, greater<int>> mp;

int main() {
    int n; cin >> n; while (n--) {
        int a, b; cin >> a >> b;
        mp[b].push_back(a);
    }
    int t; cin >> t;
    long long ans = 0;
    int nt = t;
    priority_queue<int> pq;
    while (mp.size() && mp.begin()->first > t) {
        for (int i : mp.begin()->second) pq.push(i);
        mp.erase(mp.begin());
    }
    for (auto &p : mp) {
        while (nt > p.first && pq.size()) {
            ans += pq.top(); pq.pop(); --nt;
        }
        ans -= nt - p.first;
        nt = p.first;
        for (int i : p.second) pq.push(i);
        ans += pq.top(); pq.pop();
        --nt;
    }
    while (pq.size() && nt > 0) {
        ans += pq.top(); pq.pop();
        --nt;
    }
    ans -= nt;
    cout << max(0ll, ans) << endl;
}
