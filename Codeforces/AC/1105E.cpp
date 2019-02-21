#include<bits/stdc++.h>
using namespace std;

pair<int,unsigned long long> ev[100005];

unsigned long long hhh(){
    string s; cin>>s;
    unsigned long long r = 7122;
    for (char c:s) r = r * 7902131 + c;
    return r;
}

map<unsigned long long, int> mp;
bitset<55> G[55];

int gid(unsigned long long x) {
    int &it = mp[x];
    if (!it) return it = mp.size();
    else return it;
}

vector<int> o;
int ans;

void dfs(int now, int cur, bitset<55> &ok) {
    // cout << "dfs " << now << " " << cur << endl;
    now = ok._Find_next(now); 
    ans = max(ans, cur);
    if (double(clock()) / CLOCKS_PER_SEC > 1.98) return;
    while (now <= mp.size()) {
        bitset<55> nok = ok ^ (G[now] & ok);
        dfs(now, cur + 1, nok);
        now = ok._Find_next(now);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>ev[i].first;
        if (ev[i].first == 2) ev[i].second=hhh();
    }
    ev[++n] = make_pair(1, 0);
    for (int i = 1, j; i < n; i = j) {
        j = i + 1;
        for (; ev[j].first != 1; ++j);
        set<int> app;
        // cout << "range " << i << " to " << j << endl;
        for (int k = i + 1; k < j; ++k) app.insert(gid(ev[k].second));
        for (auto it: app) for (auto ti: app) {
            G[it][ti] = G[ti][it] = 1;
            // cout << "connect " << it << " and " << ti << endl;
        }
    }
    o.resize(m + 1); iota(o.begin(), o.end(), 0);
    sort(o.begin() + 1, o.end(), [&](const int &a, const int &b) -> bool { return G[a].count() < G[b].count(); });
    bitset<55> ok; ok.set();
    // cout << "mp.size = " << mp.size() << endl;
    dfs(0, 0, ok);
    cout << ans << endl;
}
