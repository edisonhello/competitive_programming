
#pragma GCC optimize("O3")
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

const int P = 131;

int pw(int b, int n, int m) {
	int a = 1;
	while (n) {
		if (n & 1) a = 1ll * a * b % m;
		b = 1ll * b * b % m; n >>= 1;
	}
	return a;
}
int inv(int x) { return pw(x, mod - 2, mod); }

int main() {
    CPPinput;
	int N, q; cin >> N >> q;
	string sep; cin >> sep;
	string s; cin >> s;

	auto AddChar = [&] (int i) {
		sep = sep + s[i] + sep;
	};

	struct Query {
		string t;
		int n;
		int i;
	};
	vector<Query> qs;
	for (int i = 0; i < q; ++i) {
		Query q;
		q.i = i;
		cin >> q.n >> q.t;
		qs.push_back(q);
	}

	sort(qs.begin(), qs.end(), [&] (const Query &a, const Query &b) {
		return a.n < b.n;
	});
	
	int prevn = 0;
	vector<int> anss(q, -1);
	for (auto &q : qs) {
		int i = q.i;
		int n = q.n;
		string &t = q.t;

		while (prevn < n) {
			AddChar(prevn);
			++prevn;
		}
		long long ans = 0;

		for (int i = 0; i + t.size() - 1 < (int)sep.size(); ++i) {
			bool ok = 1;
			for (int j = 0; j < (int)t.size(); ++j) {
				if (t[j] != sep[i + j]) { ok = 0; break; }
			}
			ans += ok;
		}

		anss[i] = ans;
	}

	for (int i = 0; i < q; ++i) {
		cout << anss[i] << '\n';
	}
}
