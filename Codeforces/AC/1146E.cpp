#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define vpii vector<pair<int,int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
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

struct node {
    node *l, *r;
    int tag;
    node() : l(0), r(0), tag(0) {}
    void push() {
        if (tag) {
            l->addtag(tag);
            r->addtag(tag);
            tag = 0;
        }
    }
    void addtag(int v) {
        if (l) {
            if (v == 3) {
                if (tag == 3) tag = 0;
                else tag = 3 - tag;
            } else {
                tag = v;
            }
        } else {
            if (v == 3) tag = 3 - tag;
            else tag = v;
        }
    }
} *root;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r) {
        now->tag = 1;
        return;
    }
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid + 1, r);
}

void add_tag(node *now, int l, int r, int ml, int mr) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) {
        now->addtag(2);
        return;
    }
    now->push();
    add_tag(now->l, l, mid, ml, mr);
    add_tag(now->r, mid + 1, r, ml, mr);
}
void clr_tag(node *now, int l, int r, int ml, int mr) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) {
        now->addtag(1);
        return;
    }
    now->push();
    clr_tag(now->l, l, mid, ml, mr);
    clr_tag(now->r, mid + 1, r, ml, mr);
}
void reverse(node *now, int l, int r, int ml, int mr) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) {
        now->addtag(3);
        return;
    }
    now->push();
    reverse(now->l, l, mid, ml, mr);
    reverse(now->r, mid + 1, r, ml, mr);
}

int query(node *now, int l, int r, int q) {
    if (l == r) return now->tag == 1 ? q - 100000 : -(q - 100000);
    now->push();
    if (q <= mid) return query(now->l, l, mid, q);
    else return query(now->r, mid + 1, r, q);
}

int a[100005];

int main(){
    int n, q; rit(n, q);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    build(root = new node(), 0, 200000);
    while (q--) {
        char c; int i; c = gtx(); rit(i);
        if (c == '>') {
            if (i > 0) {
                add_tag(root, 0, 200000, i + 1 + 100000, 200000);
                clr_tag(root, 0, 200000, 0, -i - 1 + 100000);
            } else {
                add_tag(root, 0, 200000, -i + 100000, 200000);
                clr_tag(root, 0, 200000, 0, i + 100000);
                reverse(root, 0, 200000, i + 1 + 100000, -i - 1 + 100000);
            }
        } else {
            if (i < 0) {
                add_tag(root, 0, 200000, 0, i - 1 + 100000);
                clr_tag(root, 0, 200000, -i + 1 + 100000, 200000);
            } else {
                add_tag(root, 0, 200000, 0, -i + 100000);
                clr_tag(root, 0, 200000, i + 100000, 200000);
                reverse(root, 0, 200000, -i + 1 + 100000, i - 1 + 100000);
            }
        }
    }
    for (int i = 1; i <= n; ++i) pit.writeint(query(root, 0, 200000, a[i] + 100000), ' ');
}
