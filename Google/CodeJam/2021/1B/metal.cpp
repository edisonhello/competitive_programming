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
#define WHR() printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), puts(""), fflush(stdout)
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

void update(int &u, int x) {
	u += x;
	if (u >= 1000000000) u = 1000000000;
}

int i_have(int lar, vector<int> rq, int A, int B) {
	vector<int> storage(lar + 5, 0);
	storage[lar] = 1;
	for (int i = lar; i >= 1; --i) {
		int u = storage[i];
		if (i < (int)rq.size()) u -= rq[i];
		if (u < 0) return false;
		if (i > A) update(storage[i - A], u);
		if (i > B) update(storage[i - B], u);
	}
	return true;
}

void solve() {
	int n, a, b; cin >> n >> a >> b;
	vector<int> rq(n + 2, 0);
	for (int i = 1; i <= n; ++i) cin >> rq[i];
	int g = __gcd(a, b);
	set<int> buk;
	for (int i = 1; i <= n; ++i) if (rq[i]) buk.insert(i % g);
	if (buk.size() > 1u) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	int off = *buk.begin();
	for (int lar = n; lar <= 1000; ++lar) {
		if (i_have(lar, rq, a, b)) {
			cout << lar << endl;
			return;
		}
	}
	exit(1);
}

void test() {
	return;
	int N = 1000;
	vector<int> sto(2 * N + 2, 0);
	sto[0] = 1;
	int A = 19, B = 20;
	for (int i = 0; i <= N; ++i) {
		sto[i + A] += sto[i];
		sto[i + B] += sto[i];
		PDE(i, sto[i]);
	}
}

int main() {
	test();

    CPPinput;
	int t; cin >> t; 
	for (int T = 1; T <= t; ++T) {
		cout << "Case #" << T << ": ";
		solve();
	}
}