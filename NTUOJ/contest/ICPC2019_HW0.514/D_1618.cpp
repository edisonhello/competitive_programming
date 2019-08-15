#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
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
inline void rit(T &x){
    char c=0; 
    while(c=gtx(), (c<'0') || c>'9');
    (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
}
template<typename T,typename ...Args>
inline void rit(T& x,Args& ...args){ rit(x), rit(args...);}

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

const int mod1 = 1000000007;
const int mod2 = 1000000087;

int hh1[500005], pp1[500005];
int hh2[500005], pp2[500005];

int ghh1(int l, int r) { return (hh1[r] - hh1[l - 1] * 1ll * pp1[r - l + 1] % mod1 + mod1) % mod1; }
int ghh2(int l, int r) { return (hh2[r] - hh2[l - 1] * 1ll * pp2[r - l + 1] % mod2 + mod2) % mod2; }

char s[500005];
int facs[500005 * 21][2], tail[500005], zzz, precnt[500005], cnt[266];

int main() {
    pp1[0] = pp2[0] = 1;
    for (int i = 1; i < 500005; ++i) pp1[i] = pp1[i - 1] * 7902131ll % mod1;
    for (int i = 1; i < 500005; ++i) pp2[i] = pp2[i - 1] * 123ll % mod2;
    for (int i = 1; i <= 500000; ++i) tail[i] = i; zzz = 500001;
    // for (int i = 1; i <= 500000; ++i) for (int j = i; j <= 500000; j += i) {
    for (int i = 500000; i >= 1; --i) for (int j = i; j <= 500000; j += i) {
        facs[tail[j]][0] = i;
        facs[tail[j]][1] = zzz;
        tail[j] = zzz++;
    }
    int t; rit(t); while (t--) {
        int n; rit(n);
        for (int i = 1; i <= n; ++i) s[i] = gtx();
        for (int i = 1; i <= n; ++i) hh1[i] = (hh1[i - 1] * 7902131ll + s[i]) % mod1;
        for (int i = 1; i <= n; ++i) hh2[i] = (hh2[i - 1] * 123ll + s[i]) % mod2;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) ++cnt[s[i]];
        int mx = max_element(cnt, cnt + 266) - cnt;
        for (int i = 1; i <= n; ++i) precnt[i] = precnt[i - 1] + (s[i] == mx);
        int q; rit(q); while (q--) {
            int l, r; rit(l, r);
            int le = r - l + 1;
            int ap = __gcd(le, precnt[r] - precnt[l - 1]);
            for (int xx = ap; xx != tail[ap]; xx = facs[xx][1]) {
                int p = le / facs[xx][0];
                if (ghh1(l, r - p) == ghh1(l + p, r) && ghh2(l, r - p) == ghh2(l + p, r)) {
                    pit(p);
                    break;
                }
            }
        }
    }
}
