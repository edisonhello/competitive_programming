#include <bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define fread fread_unlocked
#define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112], *ptr=buffer, *end=buffer+4096;
    inline void writebyte(char c) {
        *ptr = c; ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
    }
    template <typename T> inline void writeint(T x, char endc='\n'){
        if(x<0)*ptr = '-', ++ptr, x=-x; if(!x)*ptr='0', ++ptr;
        char *s=ptr, c; T t;
        while(x){ t=x/10; c=x-10*t+'0'; *ptr=c, ++ptr, x=t; }
        char *f=ptr-1; while(s<f)swap(*s,*f), ++s, --f;
        if(ptr>end)fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
        *ptr=endc, ++ptr;
    }

    template<typename T>
    inline void output(T x){ writeint(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ writeint(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int ops[100005][3];

struct node {
    int ans, lr, tag;
    void blue() {
        ans = 1;
        lr = 3;
        tag = 2;
    }
    void yell() {
        ans = 0;
        lr = 0;
        tag = 1;
    }
} seg[400005 * 4];

node operator + (const node &a, const node &b) {
    node rt;
    rt.ans = a.ans + b.ans - ((a.lr & 1) && (b.lr & 2));
    rt.lr = (a.lr & 2) | (b.lr & 1);
    rt.tag = 0;
    return rt;
}

#define mid ((l + r) >> 1)
#define lc ((o << 1) | 0)
#define rc ((o << 1) | 1)
void push(int o) {
    if (seg[o].tag == 1) {
        seg[lc].yell();
        seg[rc].yell();
        seg[o].tag = 0;
    } else {
        seg[lc].blue();
        seg[rc].blue();
        seg[o].tag = 0;
    }
}
void pull(int o) {
    seg[o] = seg[lc] + seg[rc];
}

void blue(int o, int l, int r, int ml, int mr) {
    if (ml <= l && r <= mr) {
        seg[o].blue();
        return;
    }
    if (seg[o].tag) push(o);
    if (ml <= mid) blue(lc, l, mid, ml, mr);
    if (mr > mid) blue(rc, mid + 1, r, ml, mr);
    pull(o);
}
void yell(int o, int l, int r, int ml, int mr) {
    if (ml <= l && r <= mr) {
        seg[o].yell();
        return;
    }
    if (seg[o].tag) push(o);
    if (ml <= mid) yell(lc, l, mid, ml, mr);
    if (mr > mid) yell(rc, mid + 1, r, ml, mr);
    pull(o);
}

node query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[o];
    if (seg[o].tag) push(o);
    if (qr <= mid) return query(lc, l, mid, ql, qr);
    if (ql > mid) return query(rc, mid + 1, r, ql, qr);
    return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
}

int main() {
    int n, q; rit(n, q); 
    vector<int> num; num.reserve(q * 4 + 1); num.push_back(0);
    ops[0][0] = 1; ops[0][1] = 0; ops[0][2] = 0;
    for (int i = 1; i <= q; ++i) {
        rit(ops[i][0], ops[i][1], ops[i][2]);
        num.push_back(ops[i][1]);
        if (ops[i][1] > 0) num.push_back(ops[i][1] - 1);
        num.push_back(ops[i][2]);
        if (ops[i][2] < n) num.push_back(ops[i][2] + 1);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    auto get_new = [&] (int &x) {
        x = upper_bound(num.begin(), num.end(), x) - num.begin();
    };
    for (int i = 0; i <= q; ++i) {
        get_new(ops[i][1]);
        get_new(ops[i][2]);
    }
    n = num.size();
    for (int i = 0; i <= q; ++i) {
        // cout << ops[i][0] << " " << ops[i][1] << " " << ops[i][2] << endl;
        if (ops[i][0] == 1) blue(1, 1, n, ops[i][1], ops[i][2]);
        else if (ops[i][0] == 2) yell(1, 1, n, ops[i][1], ops[i][2]);
        else pit(query(1, 1, n, ops[i][1], ops[i][2]).ans);
    }
}
