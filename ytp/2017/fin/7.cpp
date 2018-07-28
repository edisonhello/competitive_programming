#include <bits/stdc++.h>
using namespace std;

vector<int> c;
int n, m;
long long tot;
map<int, int> ans1, ans2;

void dfs(int id, int nn, int s, map<int, int> cur) {
    if (s > m) return;
    cur[id]++;
    if(s+c[id] >m)return;
    if (nn == 1 && s + c[id] == m) {
        ++tot;
        if(ans1.empty())ans1=cur;
        ans2=cur;
        return;
    }
    if (nn == 1) return;
    for (int i = id; i < c.size(); ++i) {
        if (cur[i] < n) dfs(i, nn - 1, s + c[id], cur);
    }
}
int main() {
    cin >> n >> m;
    int x;
    while (cin >> x) c.push_back(x);
    for(int i=0;i<c.size();++i)dfs(i, n, 0, map<int, int>());
    cout << tot << endl;
    for (auto i = ans1.begin(); i != ans1.end();) {
        if(i->second){cout << c[i->first] << "x" << i->second;
        if (++i != ans1.end()) cout << ",";}
        else ++i;
    } cout << endl;
    for (auto i = ans2.begin(); i != ans2.end();) {
        if(i->second){cout << c[i->first] << "x" << i->second;
        if (++i != ans2.end()) cout << ",";}
        else ++i;
    } cout << endl;
}
