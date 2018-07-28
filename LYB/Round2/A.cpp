#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 5;

#define getchar gtx

inline int gtx() {
    const int N = 4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread_unlocked(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline void rit(T& x) {
    char c = 0;
    while (c = getchar(), (c < '0') || c > '9') ;
    (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
}

template <typename T, typename ...Args>
inline void rit(T& x, Args& ...args) { rit(x); rit(args...); }

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite_unlocked(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;

namespace segtree {
    struct data {
        unsigned int x, y;
        data(unsigned int x = 0, unsigned int y = 0): x(x), y(y) {}
        data operator+(const data &rhs) const {
            return data(x + rhs.x, y + rhs.y);
        }
        void apply(int l, int r, unsigned int t) {
            long long lr = (l + r - 1) * 1ll * (r - l) / 2;
            x += t * (r - l);
            y += lr * t;
        }
    } st[maxn * 3];
    unsigned int tg[maxn * 3];
    void push(unsigned int l, unsigned int r, unsigned int o) {
        if (tg[o] == 0) return;
        if (r - l == 1) return;
        st[(o << 1) + 1].apply(l, (l + r) >> 1, tg[o]);
        st[(o << 1) + 2].apply((l + r) >> 1, r, tg[o]);
        tg[(o << 1) + 1] += tg[o];
        tg[(o << 1) + 2] += tg[o];
        tg[o] = 0;
    } 
    void modify(unsigned int l, unsigned int r, unsigned int ql, unsigned int qr, unsigned int v, unsigned int o = 0) {
        push(l, r, o);
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) {
            tg[o] += v;
            st[o].apply(l, r, v);
            return;
        }
        modify(l, (l + r) >> 1, ql, qr, v, (o << 1) + 1);
        modify((l + r) >> 1, r, ql, qr, v, (o << 1) + 2);
        st[o] = st[(o << 1) + 1] + st[(o << 1) + 2];
    }
    data query(unsigned int l, unsigned int r, unsigned int ql, unsigned int qr, unsigned int o = 0) {
        push(l, r, o);
        if (l >= qr || ql >= r) return data();
        if (l >= ql && r <= qr) return st[o];
        return query(l, (l + r) >> 1, ql, qr, (o << 1) + 1) +
               query((l + r) >> 1, r, ql, qr, (o << 1) + 2);
    }
}

int main() {
    unsigned int n, q; rit(n, q);
    unsigned int t, l, r; unsigned int x; 
    while (q--) {
        rit(t, l, r, x);
        --l;
        if (t == 1) {
            segtree::modify(0, n, l, r, x);
            continue;
        }
        unsigned int d; rit(d);
        segtree::data dt = segtree::query(0, n, l, r);
        unsigned int ans = dt.x * x;
        unsigned int tans = dt.y - dt.x * (unsigned int)l;
        ans += tans * d;
        pit(ans);
    }
    return 0;
}
