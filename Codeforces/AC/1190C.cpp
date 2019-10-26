// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define data sfkkfksfkkfk

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

struct data {
    int l[2], r[2];
    data() { l[0] = l[1] = 0x3f3f3f3f, r[0] = r[1] = -1; }
    void set(int a, int b, int c, int d) {
        l[0] = a, l[1] = b, r[0] = c, r[1] = d;
    }
    data set_pos(int L, int R, int v) {
        l[v] = min(l[v], L);
        r[v] = max(r[v], R);
        return *this;
    }
    bool single() {
        return minlen() <= 0;
    }
    int minlen() {
        return min(r[1] - l[1] + 1, r[0] - l[0] + 1);
    }
    data operator + (const data &x) const {
        data rt;
        rt.set(min(l[0], x.l[0]), min(l[1], x.l[1]), max(r[0], x.r[0]), max(r[1], x.r[1]));
        return rt;
    }
};

int a[100005];

struct node {
    node *l, *r;
    data d;
    node() : l(0), r(0), d() {}
} *root;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
    if (l == r) {
        now->d.l[a[l]] = now->d.r[a[l]] = l;
        return;
    }
    build(now->l = new node(), l, mid);
    build(now->r = new node(), mid + 1, r);
    now->d = now->l->d + now->r->d;
}
data query(node *now, int l, int r, int ql, int qr) {
    PDE("query", l, r, ql, qr);
    if (qr < l || r < ql) return data();
    if (ql <= l && r <= qr) return now->d;
    return query(now->l, l, mid, ql, qr) + query(now->r, mid + 1, r, ql, qr);
}

int main(){
    CPPinput;
    int n, m; cin >> n >> m;
    string s; cin >> s; s = " " + s;
    for (int i = 1; i <= n; ++i) a[i] = (s[i] == '1');
    build(root = new node(), 1, n);
    for (int i = 1; i + m - 1 <= n; ++i) {
        if ((query(root, 1, n, 1, i - 1) + query(root, 1, n, i + m, n)).single()) {
            cout << "tokitsukaze" << endl;
            exit(0);
        }
    }
    for (int i = 1; i + m - 1 <= n; ++i) {
        data L = query(root, 1, n, 1, i - 1);
        data R = query(root, 1, n, i + m, n);
        if ((L + data().set_pos(i, i + m - 1, 0) + R).minlen() <= m &&
            (L + data().set_pos(i, i + m - 1, 1) + R).minlen() <= m);
        else {
            cout << "once again" << endl;
            exit(0);
        }
    }
    cout << "quailty" << endl;
}
