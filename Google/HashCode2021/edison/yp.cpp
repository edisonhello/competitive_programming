#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 100006;

#define F first
#define S second

string str_to_mp[N];
vector<int> G[N];
vector<int> in_G[N];

int x[N], y[N], e[N], w[N];
int cnt[N];

int main () {
    srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0);
    int d, n, m, k, f; cin >> d >> n >> m >> k >> f;
    // simultation, intersection, street, car, bonus
    map<string, int> mp;
    for (int i = 1; i <= m; ++i) {
        cin >> x[i] >> y[i];
        string str; cin >> str; mp[str] = i;
        str_to_mp[i] = str;
        int l; cin >> l;
        e[i] = (x[i] ^ y[i]);
        G[ x[i] ].push_back(i);
        w[i] = l;
        in_G[ y[i] ].push_back(i);
    }
    for (int i = 1; i <= k; ++i) {
        int p; cin >> p;
        while (p--) {
            string s; cin >> s;
            cnt[ mp[s] ]++;
        }
    }
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << endl;
        // cout << (int)in_G[i].size() << endl;
        /* for (int j: in_G[i]) {
            cout << str_to_mp[j] << ' ' << cnt[j] << endl;;
        } */
        int not0 = 0;
        for (int j: in_G[i]) {
            if (cnt[j] != 0) ++not0;
        }
        if (not0 == 0) {
            cout << 1 << endl;
            cout << str_to_mp[ in_G[i][0] ] << ' ' << 1 << endl;
        }
        else {
            cout << not0 << endl;
            // random_shuffle(in_G[i].begin(), in_G[i].end());
            /* sort(in_G[i].begin(), in_G[i].end(), [](const int &x, const int &y) {
                return cnt[x] > cnt[y] || cnt[x] == cnt[y] && x > y;
            }); */
            for (int j: in_G[i]) {
                if (cnt[j] != 0) cout << str_to_mp[j] << ' ' << cnt[j] / 25 + 1 << endl;
            }
        }
    }
}

