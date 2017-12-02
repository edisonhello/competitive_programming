#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;

int rit(){
    char c=0; bool flag=0; int x=0;
    while(c=fgetc(stdin),(c<'0'&&c!='-')||c>'9');
    c=='-'?(flag=1,x=0):(x=c-'0');
    while(c=fgetc(stdin),c>='0'&&c<='9')x=x*10+c-'0';
    if(flag)x=-x;
    return x;
}

struct segtree {
#define m ((l + r) >> 1)
    pair<int, int> v;
    segtree *lc, *rc;
    segtree(int l, int r, const vector<int> &vec) {
        lc = rc = nullptr;
        if (l == r) { v = make_pair(vec[l], l); return; }
        lc = new segtree(l, m, vec); rc = new segtree(m + 1, r, vec);
        pull();
    }
    void pull() { v = max(lc->v, rc->v); }
    int modify(int l, int r, int ql, int qr) {
        // cout << "l = " << l << " r = " << r << " ql = " << ql << " qr = " << qr << endl;
        if (l > qr || ql > r) return 0;
        if (v.first == 0) return 0;
        if (l == r) {--v.first; return 1;}
        // if (l == r) return 1;
        /* if (l >= ql && r <= qr) {
            // if (v.first == 0) return;
            int ret = 0;
            if (v.first) {
                ret += lc->
                // if (v.second <= m) lc->modify(l, m, ql, qr);
                // else rc->modify(m + 1, r, ql, qr);
                pull();
                ++ret;
            }
            return ret;
        } */
        if (v.first == 0) return 0;
        int ret = lc->modify(l, m, ql, qr) + rc->modify(m + 1, r, ql, qr);
        pull();
        return ret;
    }
    #undef m
} *st[maxn];

int parse(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
}
int n, m, q;
pair<int, int> get(int yy, int x, int y, int r) {
    int ll, rr;
    if(abs(y-yy) > r) return make_pair(n,0);
    ll = (ceil(-sqrt(r * r - abs(yy - y) * abs(yy - y))));
    rr = (int)sqrt(r * r - abs(yy - y) * abs(yy - y));
    return make_pair(max(x + ll,1), min(x + rr,m));
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    freopen("in.txt","w",stdout);
    cout<<1000<<" "<<1000<<" "<<100000<<endl;
    n=m=1000; q=100000;
    for (int i = 1; i <= n; ++i) {
        vector<int> v; v.push_back(0);
        string s;
        for (int j = 1; j <= m; ++j) {
            char c; cout<<'Z';
            v.push_back(parse(c));
        } cout<<endl;
        st[i] = new segtree(1, m, v);
    }

    while (q--) {
        int x=rand()%1000+1, y=rand()%1000+1, r=0;
        cout<<x<<" "<<y<<" "<<r<<endl;
        continue;
        int ll, rr, ret = 0;
        for (int i = 1; i <= n; ++i) {
            tie(ll, rr) = get(i, x, y, r);
            // cout << "i = " << i << " ll = " << ll << " rr = " << rr << endl;
            if (ll > rr) continue;

            ret += st[i]->modify(1, m, ll, rr);
        }
        // cout << ret << endl;
    }
    return 0;
}

