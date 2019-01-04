#include<bits/stdc++.h>
using namespace std;

const int maxc = 2e6 + 3;
const int mod = 998244353;

bitset<maxc> np;
int md[maxc];
map<int, int> mp;
vector<int> p;

void init() {
    for (int i = 2; i < maxc; ++i) {
        if (np[i]) continue;
        md[i] = i;
        p.push_back(i);
        for (auto j = 1ll * i * i; j < maxc; j += i) {
            md[j] = i;
            np[j] = true;
        }
    }
}

long long meow(long long x) {
    while (x > 1) {
        bool get = false;
        if (x < maxc) {
            ++mp[md[x]];
            x /= md[x];
            get = true;
        } else {
            for (int i: p) {
                if (x % i == 0) {
                    ++mp[i];
                    x /= i;
                    get = true;
                    break;
                }
            }
        }
        if (!get) break;
    }
    if (x > 1) {
        int q = sqrt(x);
        for (int i = max(2, q - 1000); i < q + 1000; ++i) {
            if (x % i == 0) {
                ++mp[i];
                x /= i;
                // cout << " become " << x << " and " << i << endl;
                if (x == 1) break;
                ++mp[x];
                return 1;
            }
        }
    }
    return x;
}

int main() {
    init();
    int n; cin >> n;
    vector<long long> lo;
    while (n--) {
        long long x; cin >> x;
        // cout << x << " become ";
        x = meow(x);
        // cout << x << endl;
        if (x > 1) lo.push_back(x);
    }
    while (true) {
        vector<long long> nlo;
        int sh = 1;
        for (long long x: lo) if (sh == 1) for (long long y: lo) if (sh == 1) {
            if (x == y) continue;
            sh = __gcd(x, y);
        }
        if (sh == 1) break;
        vector<int> np;
        for (long long x: lo) {
            if (x % sh == 0) {
                ++mp[sh];
                x /= sh;
                if (x == 1) continue;
                ++mp[x];
                np.push_back(x);
            } else {
                nlo.push_back(x);
            }
        }
        lo.swap(nlo);
        nlo.clear();
        while (true) {
            vector<int> nnp;
            for (long long x: lo) {
                for (int i: np) {
                    if (x % i == 0) {
                        ++mp[i];
                        x /= i;
                        if (x == 1) continue;
                        ++mp[x];
                        nnp.push_back(x);
                    } else {
                        nlo.push_back(x);
                    }
                }
            }
            if (nnp.empty()) break;
            np.swap(nnp); nnp.clear();
            lo.swap(nlo); nlo.clear();
        }
    }

    int ans = 1;
    for (auto &p: mp) {
        ans = 1ll * ans * (p.second + 1) % mod;
    }
    for (int i = 0; i < int(lo.size()); ++i) {
        ans = 4ll * ans % mod;
    }
    cout << ans << endl;
}
