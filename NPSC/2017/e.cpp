#pragma GCC optimize ("no-stack-protector,Ofast")
#include <cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<tuple>

#define fr fread_unlocked

// #define fr fread

using namespace std;

const short maxn = 1000 + 10;

inline char gchar(){
    const int N=1048576;
    static char buf[N];
    static char *p=buf,*end=buf;
    if(p==end){
        if((end=buf+fr(buf,1,N,stdin))==buf)return -1;
        p=buf;
    } return *p++;
}

inline int rit(){
    char c=0; bool flag=0; int x=0;
    while(c=gchar(),(c<'0'&&c!='-')||c>'9');
    c=='-'?(flag=1,x=0):(x=c-'0');
    while(c=gchar(),c>='0'&&c<='9')x=x*10+c-'0';
    if(flag)x=-x;
    return x;
}
short vec[1005];
struct segtree {
#define m ((l + r) >> 1)
    short v;
    segtree *lc, *rc;
    static segtree mem[2000010];
    static segtree *ptr;
    segtree() {}
    segtree(int l, int r) {
        lc = rc = nullptr;
        if (l == r) { v = vec[l]; return; }
        lc = new (ptr++) segtree(l, m); rc = new (ptr++) segtree(m + 1, r);
        pull();
    }
    void pull() { v = max(lc->v, rc->v);}
    int modify(int l, int r, int ql, int qr) {
        // if (sum == 0) return 0;
        // cout << "l = " << l << " r = " << r << " ql = " << ql << " qr = " << qr << endl;
        // if (l > qr || ql > r) return 0;
        // if (v == 0) return 0;
        if (l == r) {--v; return 1;}
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
        int ret = (lc->v && ql<=m ? lc->modify(l, m, ql, qr) : 0) + (rc->v && qr>m ? rc->modify(m + 1, r, ql, qr) : 0);
        pull();
        return ret;
    }
    #undef m
} *st[maxn], segtree::mem[2000010], *segtree::ptr = mem;

inline char parse(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
}
short n, m, sqrp[1600][maxn], sqrn[1600][maxn];
inline void init() {
    for (int r = 0; r < 1600; ++r) {
        for (int y = 0; y < maxn; ++y) {
            sqrn[r][y] = (ceil(-sqrt(r * r - y * y)));
            sqrp[r][y] = (int)sqrt(r * r - y * y);
        }
    }
}
inline pair<short, short> get(short yy, short x, short y, short r) {
    short ll, rr; r=min(short(1500),r);
    if(abs(y-yy) > r) return make_pair(n,0);
    ll = sqrn[r][abs(y - yy)];
    rr = sqrp[r][abs(y - yy)];
    // ll = (ceil(-sqrt(r * r - abs(yy - y) * abs(yy - y))));
    // rr = (int)sqrt(r * r - abs(yy - y) * abs(yy - y));
    return make_pair(max(x + ll,1), min(x + rr,int(m)));
}
long long tt[maxn];
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    init();
    int q;
    n=rit(),m=rit(),q=rit();
    // vector<int> v; v.push_back(0);
    long long tot = 0;
    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            char c; c = gchar();
            vec[j]=parse(c);
            tot += vec[j];
            tt[i] += vec[j];
        } gchar();
        st[i] = new (segtree::ptr++) segtree(1, m);
    }
    int now = 0;
    while (q--) {
        if (tot == now) { puts("0"); continue; }
        short x, y, r; y=rit(),x=rit(),r=rit();
        short ll, rr;
        int ret = 0;
        for (short i = 1; i <= n; ++i) {
            tie(ll, rr) = get(i, x, y, r);
            // cout << "i = " << i << " ll = " << ll << " rr = " << rr << endl;
            if (ll > rr || tt[i] == 0) continue;
            int qr = st[i]->modify(1, m, ll, rr);
            tt[i] -= qr;
            ret += qr;
        }
        now += ret;
        printf("%d\n", ret);
    }
    return 0;
}
