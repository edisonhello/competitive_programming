#include <bits/stdc++.h>
using namespace std;

struct rec {
    int x1, y1, x2, y2;
    void inp() { cin >> x1 >> y1 >> x2 >> y2; }
    tuple<int, int, int, int> get() { return make_tuple(x1, y1, x2, y2); }
} r[222];

int id[888][888], mvx[888][888], mvy[888][888];
vector<pair<int, double>> G[888 * 888];

double d[888 * 888];
bitset<888*888> vis;
double dijk(int s, int t) {
    priority_queue<pair<double ,int>, vector<pair<double, int>>, greater<pair<double,int>>> pq;
    pq.emplace(0, s);
    for (int i = 0; i < 888*888; ++i) d[i] = 1e12;
    d[s] = 0;
    vis.reset();
    while (pq.size()) {
        int now = pq.top().second; pq.pop();
        if (vis[now]) continue;
        vis[now] = 1;
        //cerr << "d[" << now << "] = " << d[now] << '\n';
        for (auto &e : G[now]) {
            if (d[e.first] > d[now] + e.second) {
                d[e.first] = d[now] + e.second;
                pq.emplace(d[e.first], e.first);
            }
        }
    }
    return d[t];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        memset(r, 0, sizeof(r));
        memset(id, 0, sizeof(id));
        memset(mvx, 0, sizeof(mvx));
        memset(mvy, 0, sizeof(mvy));
        for (int i = 0; i < 888 * 888; ++i) G[i].clear();

        int n; cin >> n;
        for (int i = 0; i < n; ++i) r[i].inp();
        int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
        vector<int> xs = {ax, bx}, ys = {ay, by};
        for (int i = 0; i < n; ++i) xs.push_back(r[i].x1), xs.push_back(r[i].x2);
        for (int i = 0; i < n; ++i) ys.push_back(r[i].y1), ys.push_back(r[i].y2);
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin()); 
        ys.resize(unique(ys.begin(), ys.end()) - ys.begin()); 
        //cerr << "xs: "; for (int i : xs) cerr << i << " "; cerr << endl;
        //cerr << "ys: "; for (int i : ys) cerr << i << " "; cerr << endl;
        for (int i = 0; i < n; ++i) {
            int ax, ay, bx, by; tie(ax, ay, bx, by) = r[i].get();
            ax = upper_bound(xs.begin(), xs.end(), ax) - xs.begin();
            bx = upper_bound(xs.begin(), xs.end(), bx) - xs.begin();
            ay = upper_bound(ys.begin(), ys.end(), ay) - ys.begin();
            by = upper_bound(ys.begin(), ys.end(), by) - ys.begin();
            mvx[bx + 1][by + 1]++; mvx[ax + 1][by + 1]--; mvx[bx + 1][ay]--; mvx[ax + 1][ay]++;
            //printf("mvx[%d][%d]++, mvx[%d][%d]--, mvx[%d][%d]--, mvx[%d][%d]++\n", bx + 1, by + 1, ax + 1, by + 1, bx + 1, ay, ax + 1, ay);
            mvy[bx + 1][by + 1]++; mvy[ax][by + 1]--; mvy[bx + 1][ay + 1]--; mvy[ax][ay + 1]++;
            //printf("mvy[%d][%d]++, mvy[%d][%d]--, mvy[%d][%d]--, mvy[%d][%d]++\n", bx + 1, by + 1, ax, by + 1, bx + 1, ay + 1, ax, ay + 1);
        }
        /*for (int i = 0 ; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << mvx[i][j] << " " ;
            }
            cout << endl;
        }
        for (int i = 0 ; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << mvy[i][j] << " " ;
            }
            cout << endl;
        }*/
        for (int i = 0; i < 888; ++i) for (int j = 0; j < 888; ++j) {
            mvx[i][j] = mvx[i][j] 
                      + (i ? mvx[i - 1][j] : 0) 
                      + (j ? mvx[i][j - 1] : 0)
                      - (i && j ? mvx[i - 1][j - 1] : 0);
            mvy[i][j] = mvy[i][j] 
                      + (i ? mvy[i - 1][j] : 0) 
                      + (j ? mvy[i][j - 1] : 0)
                      - (i && j ? mvy[i - 1][j - 1] : 0);
        }
        /*for (int i = 0 ; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << mvx[i][j] << " " ;
            }
            cout << endl;
        }
        for (int i = 0 ; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << mvy[i][j] << " " ;
            }
            cout << endl;
        }*/
        int nn = 0;
        for (int i = 0; i < (int)xs.size(); ++i) for (int j = 0 ; j < (int)ys.size(); ++j)
            id[i][j] = ++nn;
        //for (int i = 0; i < (int)xs.size(); ++i) for (int j = 0; j < (int)ys.size(); ++j) cerr << "id " << i << " " << j << " = " << id[i][j] << endl;
        for (int i = 0; i < (int)xs.size(); ++i) for (int j = 0; j < (int) ys.size(); ++j) {
            if (i) {
                int a = id[i - 1][j], b = id[i][j];
                int d = xs[i] - xs[i - 1];
                // int k = mvx[i + 2][j + 2] - mvx[i + 1][j + 2] - mvx[i + 2][j + 1] + mvx[i + 1][j + 1];
                int k = mvx[i+1][j+1];
                // printf("mvx[%d][%d] - mvx[%d][%d] - mvx[%d][%d] + mvx[%d][%d] = %d\n", i+2,j+2,i + 1,j+2,i+2,j + 1,i + 1,j + 1,k);
                double t = (double)d / (k + 1);
                //cerr << a << " to " << b << " use " << t << ". d = " << d << ", k = " << k << endl;
                G[a].emplace_back(b, t);
                G[b].emplace_back(a, t);
            } 
            if (j) {
                int a = id[i][j - 1], b = id[i][j];
                int d = ys[j] - ys[j - 1];
                // int k = mvy[i + 2][j + 2] - mvy[i + 2][j + 1] - mvy[i + 1][j + 2] + mvy[i+1][j+1];
                int k = mvy[i+1][j+1];
                // printf("mvy[%d][%d] - mvy[%d][%d] - mvy[%d][%d] + mvy[%d][%d] = %d\n", i+2,j+2,i+1,j+2,i+2,j+1,i+1,j+1,k);
                double t = (double)d / (k + 1);
                //cerr << a << " to " << b << " use " << t << ". d = " << d << ", k = " << k << endl;
                G[a].emplace_back(b, t);
                G[b].emplace_back(a, t);
            }
        }
        for (int i = 0; i < (int)xs.size(); ++i) {
            if (xs[i] == ax) ax = i;
            if (xs[i] == bx) bx = i;
        }
        for (int i = 0; i < (int)ys.size(); ++i) {
            if (ys[i] == ay) ay = i;
            if (ys[i] == by) by = i;
        }
        cout << fixed << setprecision(5) << dijk(id[ax][ay], id[bx][by]) << '\n';
    }
}
