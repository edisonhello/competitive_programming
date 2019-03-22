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

pair<int, int> pt[1000006];
double ans = 1e9;

void go(int l, int r) {
    if (l >= r) return;
    if (r - l <= 50) {
        for (int i = l; i < r; ++i) for (int j = i + 1; j <= r; ++j)
            ans = min(ans, hypot(pt[i].first - pt[j].first, pt[i].second - pt[j].second));
        return;
    }
    int mid = (l + r) >> 1;
    go(l, mid);
    go(mid + 1, r);
    int ll = mid, rr = mid + 1;
    while (ll >= l && pt[mid].first - pt[ll].first <= ans) --ll;
    while (rr <= r && pt[rr].first - pt[mid + 1].first <= ans) ++rr;
    // cout << ll << " " << rr << " @ " << l << " " << r << endl;
    vector<int> idx; idx.reserve(rr - ll - 1);
    for (int i = ll + 1; i < rr; ++i) idx.push_back(i);
    sort(idx.begin(), idx.end(), [&] (const int &a, const int &b) { return pt[a].second < pt[b].second; });
    for (int i = 0; i < int(idx.size()); ++i) {
        int R = min(i + 7, int(idx.size()));
        // cout << "i = " << i << " , R = " << R << endl;
        for (int j = i + 1; j < R; ++j) ans = min(ans, hypot(pt[idx[j]].first - pt[idx[i]].first, pt[idx[j]].second - pt[idx[i]].second));
    }
}

int main() {
    int n; rit(n);
    for (int i = 0; i < n; ++i) rit(pt[i].first, pt[i].second);
    sort(pt, pt + n);
    go(0, n - 1);
    printf("%.6lf\n", ans);
}
