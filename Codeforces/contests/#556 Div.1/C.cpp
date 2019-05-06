#pragma GCC optimize("O3")
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

struct node {
    node *l, *r;
    int min_dep, max_dep;
    int val;
    node() : l(0), r(0), master(0), val(0) {}
    void set(int v) {
        min_dep = max_dep = v;
    }
    void pull() {
        min_dep = min(l->min_dep, r->min_dep);
        max_dep = max(l->max_dep, r->max_dep);
    }
    void push() {
        if (val) {
            l->addtag(val);
            r->addtag(val);
            val = 0;
        }
    }
    void addtag(int v) {
        min_dep += v;
        max_dep += v;
        val += v;
    }
} *root;

string s;
int dep[200005];

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r) {
        now->set(dep[l]);
        return;
    }
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid + 1, r);
    now->pull();
}

void modify(node *now, int l, int r, int ml, int mr, int v) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) {
        now->addtag(v);
        return;
    }
    now->push();
    modify(now->l, l, mid, ml, mr, v);
    modify(now->r, mid + 1, r, ml, mr, v);
    now->pull();
}

pair<int, int> query(node *now, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return make_pair(1e9, -1e9);
    if (ql <= l && r <= qr) return make_pair(now->min_dep, now->max_dep);
    pair<int, int> lq = query(now->l, l, mid, ql, qr), 
        rq = query(now->r, mid + 1, r, ql, qr);
    return make_pair(min(lq.first, rq.first), max(lq.second, rq.second));
}

int main() {
    CPPinput;
    int n, q; cin >> n >> q;
    cin >> s;
    n = (n * 2) - 2;
    s = " " + s;
    for (int i = 1; i <= n; ++i) {
        dep[i] = dep[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    build(root = new node(), 1, n);
    int ans = 0;
    while (q--) {
        int a, b; cin >> a >> b;
        if (s[a] == s[b]) {
            cout << ans << '\n';
            continue;
        }
        if (s[a] == '(') {

        }
    }
}
