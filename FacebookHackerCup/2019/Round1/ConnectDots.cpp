#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct point{ 
    int x, y;
} ps[800005];



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; for (int T = 1; T <= t; ++T) {
        cerr << "Start " << T << endl;
        cout << "Case #" << T << ": ";
        int n, h, v; cin >> n >> h >> v;
        auto ok = [&] (const int ANS) -> bool {
            cerr << "Checking ANS = " << ANS << endl;
            vector<int> id(n); iota(id.begin(), id.end(), 0);
            auto cmpx = [&] (const int &a, const int &b) -> bool { return make_pair(ps[a].x, a) < make_pair(ps[b].x, b); };
            auto cmpy = [&] (const int &a, const int &b) -> bool { return make_pair(ps[a].y, a) < make_pair(ps[b].y, b); };
            sort(id.begin(), id.end(), [&] (const int &a, const int &b) -> bool {
                return ps[a].y < ps[b].y;
            });
            set<int, decltype(cmpx)> in(cmpx), out(cmpx);
            auto check_val = [&] (const int VANS) -> bool {
                if (VANS > ANS) return false;
                if ((int)out.size() > h) return false;
                if (out.empty()) return true;
                return ps[*prev(out.end())].x + VANS <= ANS;
            };
            for (int i = 0; i < n; ++i) out.insert(i);
            if (check_val(0)) return true;
            for (int i : id) { // 
                out.erase(i);
                in.insert(i);
                if ((int)in.size() > v) {
                    out.insert(*in.begin());
                    in.erase(in.begin());
                }
                if (check_val(ps[i].y)) return true;
            }
            return false;
        };
        int x1, x2, ax, bx, cx, dx; cin >> x1 >> x2 >> ax >> bx >> cx >> dx;
        int y1, y2, ay, by, cy, dy; cin >> y1 >> y2 >> ay >> by >> cy >> dy;
        ps[0].x = x1, ps[0].y = y1;
        ps[1].x = x2, ps[1].y = y2;
        for (int i = 2; i < n; ++i) {
            tie(x1, x2) = make_pair(x2, (1ll * ax * x1 + 1ll * bx * x2 + cx) % dx + 1);
            tie(y1, y2) = make_pair(y2, (1ll * ay * y1 + 1ll * by * y2 + cy) % dy + 1);
            ps[i].x = x2, ps[i].y = y2;
        }
        // for (int i = 0; i < n; ++i) cerr << "p " << i << " = " << ps[i].x << " " << ps[i].y << endl;
        long long L = 0, R = 2000007122; 
        while (R > L) {
            long long M = (L + R) >> 1;
            if (ok(M)) R = M;
            else L = M + 1;
        }
        if (L == 2000007122) L = -1;
        cout << L << endl;
    }
}
