#include <cstdio>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

typedef double type_ans;
typedef double data;

type_ans ans = 1e30;
pair<int,int> ansid;

inline type_ans sq(data a) { return a * a; }

struct point {
    int id;
    data x, y, z;
    type_ans dis(const point& i) const { return sq(x - i.x) + sq(y - i.y) + sq(z - i.z); }
    bool operator<(const point& i) const { return make_tuple(y, x, z) < make_tuple(i.y, i.x, i.z); }
} pt[500003];

void solve2D(vector<point>& pts)
{
    sort(pts.begin(), pts.end(), [](const point& a, const point& b){ return a.x < b.x; });
    set<point> st;
    for (int i = 0, l = 0, N = pts.size(); i < N; i++) {
        auto it = st.insert(pts[i]).first;
        set<point>::iterator git;
        while (l < i && sq(it->x - (git = st.find(pts[l]))->x) > ans) st.erase(git), l++;
        if (it != st.begin()) {
            for (auto lit = prev(it); sq(it->y - lit->y) <= ans; lit--) {
                type_ans tmp = it->dis(*lit);
                if (tmp < ans) {
                    ans = tmp;
                    ansid = {it->id, lit->id};
                }
                if (lit == st.begin()) break;
            }
        }
        for (auto rit = next(it); rit != st.end() && sq(it->y - rit->y) <= ans; rit++) {
            type_ans tmp = it->dis(*rit);
            if (tmp < ans) {
                ans = tmp;
                ansid = {it->id, rit->id};
            }
        }
    }
}

void solve3D(int L, int R)
{
    if (L + 100 >= R) {
        for (int i = L; i < R; i++)
            for (int j = i + 1; j < R; j++) {
                type_ans tmp = pt[i].dis(pt[j]);
                if (tmp < ans) {
                    ans = tmp;
                    ansid = {pt[i].id, pt[j].id};
                }
            }
        return;
    }
    int M = (L + R) >> 1;
    solve3D(L, M); solve3D(M, R);
    vector<point> to2D;
    for (int i = M - 1; i >= L && sq(pt[i].z - pt[M].z) <= ans; i--) to2D.push_back(pt[i]);
    for (int i = M; i < R && sq(pt[i].z - pt[M].z) <= ans; i++)  to2D.push_back(pt[i]);
    solve2D(to2D);
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lf%lf%lf", &pt[i].x, &pt[i].y, &pt[i].z), pt[i].id = i + 1;
    sort(pt, pt + N, [](const point& a, const point& b){ return a.z < b.z; });
    solve3D(0, N);
    if (ansid.first > ansid.second) swap(ansid.first, ansid.second);
    printf("WARNING: galaxy%d and galaxy%d in %.3lf Uu\n", ansid.first, ansid.second, sqrt(ans));
}
