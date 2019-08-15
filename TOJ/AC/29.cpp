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

namespace sa {
const int maxn = 1e6 + 5;
bool t[maxn * 2];
char s[maxn];
int hi[maxn], rev[maxn];
int _s[maxn * 2], sa[maxn * 2], c[maxn * 2], x[maxn], p[maxn], q[maxn * 2];    
// sa[i]: sa[i]-th suffix is the i-th lexigraphically smallest suffix.
// hi[i]: longest common prefix of suffix sa[i] and suffix sa[i - 1].
void pre(int *sa, int *c, int n, int z) {
    memset(sa, 0, sizeof(int) * n);
    memcpy(x, c, sizeof(int) * z);
}
void induce(int *sa, int *c, int *s, bool *t, int n, int z) {
    memcpy(x + 1, c, sizeof(int) * (z - 1));
    for (int i = 0; i < n; ++i) if (sa[i] && !t[sa[i] - 1]) sa[x[s[sa[i] - 1]]++] = sa[i] - 1;
    memcpy(x, c, sizeof(int) * z);
    for (int i = n - 1; i >= 0; --i) if (sa[i] && t[sa[i] - 1]) sa[--x[s[sa[i] - 1]]] = sa[i] - 1;
}
void sais(int *s, int *sa, int *p, int *q, bool *t, int *c, int n, int z) {
    bool uniq = t[n - 1] = true;
    int nn = 0, nmxz = -1, *nsa = sa + n, *ns = s + n, last = -1;
    memset(c, 0, sizeof(int) * z);
    for (int i = 0; i < n; ++i) uniq &= ++c[s[i]] < 2;
    for (int i = 0; i < z - 1; ++i) c[i + 1] += c[i];
    if (uniq) {
        for (int i = 0; i < n; ++i) sa[--c[s[i]]] = i;
        return;
    }
    for (int i = n - 2; i >= 0; --i) t[i] = (s[i] == s[i + 1] ? t[i + 1] : s[i] < s[i + 1]);
    pre(sa, c, n, z);
    for (int i = 1; i <= n - 1; ++i) if (t[i] && !t[i - 1]) sa[--x[s[i]]] = p[q[i] = nn++] = i;
    induce(sa, c, s, t, n, z);
    for (int i = 0; i < n; ++i) if (sa[i] && t[sa[i]] && !t[sa[i] - 1]) {
        bool neq = last < 0 || memcmp(s + sa[i], s + last, (p[q[sa[i]] + 1] - sa[i]) * sizeof(int));
        ns[q[last = sa[i]]] = nmxz += neq;
    }
    sais(ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
    pre(sa, c, n, z);
    for (int i = nn - 1; i >= 0; --i) sa[--x[s[p[nsa[i]]]]] = p[nsa[i]];
    induce(sa, c, s, t, n, z);
}
int build() {
    int n = 0; char c; 
    for (; isalpha(c = gtx()); ++n) s[n] = c;
    // cerr << "N = " << n << endl;
    for (int i = 0; i < n; ++i) _s[i] = s[i] - 'a' + 1;
    _s[n] = 0; // s shouldn't contain 0
    sais(_s, sa, p, q, t, sa::c, n + 1, 30);
    for (int i = 0; i < n; ++i) sa[i] = sa[i + 1];
    return n;
}}

int main() {
    int t; rit(t); while (t--) {
        int m = sa::build();
        // for (int i = 0; i < m; ++i) cerr << "sa[" << i << "] = " << sa::sa[i] << endl;
        // for (int i = 0; i < m; ++i) cerr << "rev[" << i << "] = " << sa::rev[i] << endl;
        int n; rit(n); for (int i = 0; i < n; ++i) {
            int l = 0, r = m - 1;
            bool no = false;
            int z = 0;
            for (char c; isalpha(c = gtx()); ++z) {
                // cerr << "Get " << c << endl;
                if (no) continue;
                int L = l, R = r;
                while (L < R) {
                    int M = (L + R) >> 1;
                    if (sa::sa[M] + z >= m || sa::s[sa::sa[M] + z] < c) L = M + 1;
                    else R = M;
                }
                if (sa::sa[L] + z >= m || sa::s[sa::sa[L] + z] < c) ++L;
                l = L;
                // cerr << "new L = " << l << endl;
                if (l > r) { no = true; continue; }
                R = r;
                while (L < R) {
                    int M = (L + R + 1) >> 1;
                    if (sa::s[sa::sa[M] + z] > c) R = M - 1;
                    else L = M;
                }
                if (sa::s[sa::sa[R] + z] > c) --R;
                r = R;
                // cerr << "new R = " << r << endl;
                if (l > r) { no = true; continue; }
                // cerr << "Get " << c << ", l r = " << l << " " << r << endl;
            }
            puts(no ? "n" : "y");
        }
    }
}

