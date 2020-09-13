#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
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

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define fread fread_unlocked
#define fwrite fwrite_unlocked
inline char gtx() {
    const int N=4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    } return *p++;
}

template <typename T>
inline void rit(T &x) {
    char c; bool fg = 0;
    while (c = gtx(), (c < '0' && c != '-') || c > '9');
    c == '-' ? (fg = 1, x = 0) : (x = c & 15);
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    if (fg) x = -x;
}
template <typename T, typename ...Args>
inline void rit(T& x, Args& ...args) { rit(x), rit(args...); }

template <typename T>
inline void ruit(T &x) {
    char c;
    while (c = gtx(), c < '0' || c > '9');
    x = c & 15;
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
}
template <typename T, typename ...Args>
inline void ruit(T& x, Args& ...args) { ruit(x), ruit(args...); }

template <typename T>
inline bool rit_save(T &x) {
    char c; bool fg = 0;
    while (c = gtx(), (c < '0' && c != '-') || c > '9') if (c == EOF) return false;
    c == '-' ? (fg = 1, x = 0) : (x = c & 15);
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    if (fg) x = -x; return true;
}
template <typename T, typename ...Args>
inline bool rit_save(T& x, Args& ...args) { return rit_save(x) && rit_save(args...); }

template <typename T>
inline bool ruit_save(T &x) {
    char c;
    while (c = gtx(), c < '0' || c > '9') if (c == EOF) return false;
    x = c & 15;
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    return true;
}
template <typename T, typename ...Args>
inline bool ruit_save(T& x, Args& ...args) { return ruit_save(x) && ruit_save(args...); }

struct outputter {
    char buffer[4112], *ptr = buffer, *end = buffer + 4096;
    inline void writebyte(char c) {
        *ptr = c; ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr-buffer, stdout), ptr = buffer;
    }
    template <typename T> inline void writeint(T x, char endc = '\n') {
        if (!x) *ptr = '0', ++ptr;
        char *s = ptr, c; T t;
        while (x) { t = x / 10; c = x - 10 * t + '0'; *ptr = c, ++ptr, x = t; }
        char *f = ptr - 1; while (s < f) swap(*s, *f), ++s, --f;
        *ptr = endc, ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr - buffer, stdout), ptr = buffer;
    }

    template <typename T>
    inline void output(T x) { writeint(x, '\n'); }
    template <typename T,typename ...Args>
    inline void output(T x,Args ...args) { writeint(x, ' '); output(args...); }

    template <typename ...Args> inline void operator()(Args ...args) { output(args...); }
    outputter() {}
    ~outputter() { fwrite(buffer, sizeof(char), ptr - buffer, stdout); }
} pit;
#pragma GCC diagnostic pop

int st[20][500005];

int main() {
	int n; ruit(n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) ruit(v[i]);

	for (int i = 0; i < n; ++i) st[0][i] = v[i];
	for (int z = 1; z < 20; ++z) 
		for (int i = 0; i + (1 << z) - 1 < n; ++i) 
			st[z][i] = max(st[z - 1][i], st[z - 1][i + (1 << (z - 1))]);

	auto Query = [&] (int l, int r) {
		int z = 31 - __builtin_clz(r - l + 1);
		return max(st[z][l], st[z][r - (1 << z) + 1]);
	};

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		int mx = 0;
		int h = v[i];
		for (int d = 1, l = i + 1; l < n; ++d) {
			int r = l + d * 2 - 2;
			if (r >= n) r = n - 1;
			mx = max(mx, Query(l, r) + d - h);
			l = r + 1;
		}
		for (int d = 1, r = i - 1; r >= 0; ++d) {
			int l = r - d * 2 + 2;
			if (l < 0) l = 0;
			mx = max(mx, Query(l, r) + d - h);
			r = l - 1;
		}
		ans[i] = mx;
	}

	for (int i : ans) pit(i);
}
