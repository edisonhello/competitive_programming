// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <utility>
#include <functional>
#include <complex>
#include <climits>
#include <random>
#include <thread>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <tuple>
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
#define pii pair<int, int>
#define vint vector<int>
#define vpii vector<pair<int, int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x, v) memset((x), (v), sizeof(x))
#define RZUNI(x) sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
#define FIN(fname) freopen(fname, "r", stdin)
#define FOUT(fname) freopen(fname, "w", stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl
#define data datadetedoto

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() printf("%s: Line %d", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), fflush(stdout)
#define DEBUG 1
#define exit(x) cout << "exit code " << x << endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x) & (-(x)))

void JIZZ(string output = ""){ cout << output; exit(0); }

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

struct node {
    node *l, *r;
    int mx, mn;
    void pull() {
        mx = max(l->mx, r->mx);
        mn = min(l->mn, r->mn);
    }
} *croot, *toroot;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r, vector<int> &ref) {
    if (l == r) {
        now->mx = now->mn = ref[l];
        return;
    }
    build(now->l = new node(), l, mid, ref);
    build(now->r = new node(), mid + 1, r, ref);
    now->pull();
}

int qmin(node *now, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 1000000006;
    if (ql <= l && r <= qr) return now->mn;
    return min(qmin(now->l, l, mid, ql, qr), qmin(now->r, mid + 1, r, ql, qr));
}
int qmax(node *now, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return -2;
    if (ql <= l && r <= qr) return now->mx;
    return max(qmax(now->l, l, mid, ql, qr), qmax(now->r, mid + 1, r, ql, qr));
}

int main() {
    CPPinput;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
    bool inf = true;
    for (int i = 0; i < n; ++i) if (a[i] * 2 < mx) {
        inf = false;
    }
    if (inf) {
        for (int i = 0; i < n; ++i) cout << -1 << ' ';
        cout << endl;
        exit(0);
    }
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    build(croot = new node(), 0, 3 * n - 1, a);
    vector<int> maxto(n * 3);
    for (int i = 0; i < n; ++i) {
        int L = i, R = 3 * n - 1;
        while (L < R) {
            int M = (L + R + 1) >> 1;
            if (qmin(croot, 0, 3 * n - 1, L, M) * 2 < a[i]) R = M - 1;
            else L = M;
        }
        maxto[i] = L;
        maxto[i + n] = L + n;
        maxto[i + n + n] = L + n + n;
    }
    PDE(maxto);
    build(toroot = new node(), 0, 3 * n - 1, maxto);
    for (int i = 0; i < n; ++i) {
        int L = i, R = 3 * n - 1;
        while (L < R) {
            int M = (L + R) >> 1;
            if (qmin(toroot, 0, 3 * n - 1, i, M) >= M) L = M + 1;
            else R = M;
        }
        cout << L - i << ' ';
    }
    cout << endl;

}
