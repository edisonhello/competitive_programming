#include <bits/stdc++.h>
using namespace std;

struct Seg {
#define M ((L + R) >> 1)
    Seg *lc, *rc;
    int mx = 0, tag = 0;
    Seg(int L, int R) {
        lc = rc = nullptr; mx = 0;
        if (L == R) return;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    void pull() {
        mx = max(lc->mx, rc->mx);
    }
    void push() {
        if (tag == 0 || !lc) return; 
        lc->mx += tag; lc->tag += tag;
        rc->mx += tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
    push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            mx += v; tag += v;
            return;
        }
        lc->modify(L, M, l, r, v);rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
    push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return mx;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
}

struct seg1
{
    int size, id;
    seg1 *lc, *rc;
    seg1()
    {
        lc = rc = NULL;
        size = 0;
    }
}

struct seg2
{
    int size;
    seg2 *lc, *rc;
    seg1 *cur;
    seg2()
    {
        lc = rc = NULL;
        size = 0;
        cur = new seg1();
    }
}

void modify(seg1 *t, int l ,int r, int x, int dlt, int car)
{
    int m = (l + r) >> 1;
    t -> size += dlt;
    if ( l == r) t -> id = car;
    if (x <= m) modify(t -> lc, l ,m, x, dlt);
    else modift(t -> rc, m + 1, r, dlt);
}

seg2 *build(int l, int r)
{
    seg2 *ret = new seg2();
    if (l == r) return ret;
    int m = (l + r) >> 1;
    ret -> lc = build(l, m);
    ret -> rc = build(m + 1, r);
    return ret;
}

void modi(seg2* t, int l, int r, int x, int y, int dlt)
{
    int m = (l + r) >> 1;
    modify(t -> cur, 1, maxn, y, dlt, x);
    if (x <= m && sz(t -> lc)) modi(t -> lc, l, m, x, y, dlt);
    else if (sz(t -> rc)) modi(t -> rc, m + 1, r, x, y, dlt);
}

void dfs(seg1 *t, int l, int r)
{
    if (!t) return;
    if (l ==r) to.push(mp(l, t -> id));
    int m = (l + r) >> 1;
    if (sz(t -> lc)) dfs(t -> lc, l ,m);
    if (sz(t -> rc)) dfs(t -> rc, m + 1, r);
}

void query(seg1 *t, int l, int r, int c, int d)
{
    int m = (l + r) >> 1;
    if (l > d || c > r) return;
    if (l >= c && r <= d) dfs(t, 1, maxn);
    query(t -> lc, l, m, c, d); query(t -> rc, m + 1, r, c, d);
}

void qry(seg2* t, int l, int r, int a, int b, int c, int d)
{
    int m = (l + r) >> 1;
    if (l > b || a > r) return;
    if (l >= a && r <= b) {
        queryZ(t -> cur, 1, maxn, c, d); return;
    }
    qry(t->lc, l, m, a, b, c, d); qry(t->rc, m + 1, r, a, b, c, d);
}

int main()
{
    seg2 *meow = new seg2
    int n; for (int i = 0; i< n; ++i)

}
