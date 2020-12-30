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

#define int long long

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

int32_t main() {
    CPPinput;
	int N, q; cin >> N >> q;
	string sep; cin >> sep;
	string s; cin >> s;
	// vector<ll> pp(1000005, 0);
	// pp[0] = 1;
	// for (int i = 1; i <= 1000000; ++i) pp[i] = pp[i - 1] * 1ll * P % mod;
	// const int iP = inv(P);
	// vector<ll> ipp(1000005, 0);
	// ipp[0] = iP;
	// for (int i = 1; i <= 1000000; ++i) ipp[i] = ipp[ i - 1] * 1ll * iP % mod;

	// vector<ll> hh(1000005, 0);
	// for (int i = 1; i <= 1000000; ++i) hh[i] = (hh[i - 1] + pp[i] * 1ll * s[__builtin_ctz(i)]) % mod;

	// vector<vector<int>> poss(26);
	// for (int i = s.size() - 1; i >= 0; --i) poss[s[i] - 'a'].push_back(i);

	vector<ll> pw2(1000006, 0);
	pw2[0] = 1;
	for (int i = 1; i <= 1000000; ++i) pw2[i] = pw2[i - 1] * 2 % mod;

	vector<vector<int>> preapp(26, vector<int>(23, 0));
	// for (int i = 0; i < 26; ++i) {
	// 	for (int j : poss[i]) {
	// 		int jj = min(j, 22);
	// 		(preapp[i][jj] += pw2[N - 1 - j]) >= mod ? preapp[i][jj] -= mod : 0;
	// 	}
	// 	for (int j = 21; j >= 0; --j) {
	// 		(preapp[i][j] += preapp[i][j + 1]) >= mod ? preapp[i][j] -= mod : 0;
	// 	}
	// }

	static map<int, vector<int>> mp;

	auto AddChar = [&] (int i) {
		int z = s[i] - 'a';
		int ii = min(i, 22ll);
		for (auto &v : preapp) for (int &i : v) (i += i) >= mod ? i -= mod : 0;
		for (int y = ii; y >= 0; --y) (preapp[z][y] += 1) %= mod;
	};

	auto Count = [&] (string t) {
		PDE("count", t);
		auto Dfs = [&] (auto Dfs, int it, string t) -> long long {
			if (t.size() == 1u) {
				return preapp[t[0] - 'a'][it];
			}
			string t1, t2;
			char want = s[it];
			bool allwant = true;
			for (int i = 0; i < (int)t.size(); i += 2) {
				if (t[i] != want) { allwant = false; break; }
			}
			if (allwant) {
				for (int i = 1; i < (int)t.size(); i += 2) t1 += t[i];
			}
			allwant = true;
			for (int i = 1; i < (int)t.size(); i += 2) {
				if (t[i] != want) { allwant = false; break; }
			}
			if (allwant) {
				for (int i = 0; i < (int)t.size(); i += 2) t2 += t[i];
			}

			if (t1.empty() && t2.empty()) return 0;
			if (t1.size() && t2.size()) {
				auto itr = mp.find(t.size());
				if (itr == mp.end()) {
					mp[t.size()] = vector<int>(23, -1);
					itr = mp.find(t.size());
				}
				if (itr->second[it] != -1) return itr->second[it];
				int sum = 0;
				sum += Dfs(Dfs, it + 1, t1);
				sum += Dfs(Dfs, it + 1, t2);
				if (sum >= mod) sum -= mod;
				return itr->second[it] = sum;
			} else if (t1.size()) {
				return Dfs(Dfs, it + 1, t1);
			} else {
				return Dfs(Dfs, it + 1, t2);
			}
		};

		return Dfs(Dfs, 0, t);

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
	for (auto q : qs) {
		int i = q.i;
		int n = q.n;
		string t = q.t;

		while (prevn < n) {
			AddChar(prevn);
			++prevn;
		}
		long long ans = 0;

		bool fail = 0;
		string tt;
		for (int of = 0; of <= (int)sep.size(); ++of) {
			fail = 0;
			tt.clear();
			for (int j = 0, k = of; j < (int)t.size(); ++j, k = k == sep.size() ? 0 : k + 1) {
				if (k == sep.size()) {
					tt += t[j];
					continue;
				}
				if (t[j] != sep[k]) {
					fail = 1;
					break;
				}
			}
			PDE(of, sep, fail, t);

			if (fail) continue;

			if (tt.empty()) {
				ans += pw2[n];
				if (ans >= mod) ans -= mod;
			} else {
				ans += Count(tt);
				if (ans >= mod) ans -= mod;
			}
		}

		anss[i] = ans;
	}

	for (int i = 0; i < q; ++i) {
		cout << anss[i] << '\n';
	}
}
