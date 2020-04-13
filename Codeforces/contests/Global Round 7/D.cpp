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

int mod1, mod2;
int pp1[1000005], ipp1[1000005];
int pp2[1000005], ipp2[1000005];

string Solve(string s) {
	if (s.empty()) return 0;
	int mx = 1;
	int ncase = -1;
	int at = 0;
	int n = s.size();
	vector<int> hh1(n, 0), hh2(n, 0);
	string is = s;
	reverse(is.begin(), is.end());
	vector<int> ihh1(n, 0), ihh2(n, 0);

	hh1[0] = hh2[0] = s[0];
	ihh1[0] = ihh2[0] = is[0];
	for (int i = 1; i < n; ++i) {
		hh1[i] = (131ll * hh1[i - 1] + s[i]) % mod1;
		hh2[i] = (7902131ll * hh2[i - 1] + s[i]) % mod2;
		ihh1[i] = (131ll * ihh1[i - 1] + is[i]) % mod1;
		ihh2[i] = (7902131ll * ihh2[i - 1] + is[i]) % mod2;
	}

	auto GetHH = [&] (int l, int r) {
		return make_pair(
				(hh1[r] - (l ? hh1[l - 1] : 0) * 1ll * pp1[r - l + 1] % mod1 + mod1) % mod1,
				(hh2[r] - (l ? hh2[l - 1] : 0) * 1ll * pp2[r - l + 1] % mod2 + mod2) % mod2);
	};
	auto GetIHH = [&] (int l, int r) {
		return make_pair(
				(ihh1[n - 1 - l] - (n - 1 - r ? ihh1[n - 1 - r - 1] : 0) * 1ll * pp1[r - l + 1] % mod1 + mod1) % mod1,
				(ihh2[n - 1 - l] - (n - 1 - r ? ihh2[n - 1 - r - 1] : 0) * 1ll * pp2[r - l + 1] % mod2 + mod2) % mod2);
	};

	for (int i = 0; i < n; ++i) {
		if (i * 2 + 1 < n) {
			if (GetHH(0, i) == GetIHH(i + 1, i * 2 + 1)) {
				if ((i + 1) * 2 > mx) {
					mx = (i + 1) * 2;
					ncase = 1;
					at = i;
				} 
			}
		}
		if (i * 2 + 2 < n) {
			if (GetHH(0, i) == GetIHH(i + 2, i * 2 + 2)) {
				if ((i + 1) * 2 + 1 > mx) {
					mx = (i + 1) * 2 + 1;
					ncase = 2;
					at = i;
				}
			}
		}
	}

	// return mx;
	if (ncase == -1) return string(1, s[0]);
	return s.substr(0, mx);
}

vector<int> mods = {998244353, 1000000007, 1000000009, 1000000087, 1000000123, 1000000103, 1000000321};

int main() {
    CPPinput;
	srand(time(0) * clock() * clock() * clock() * clock() * clock());
	random_shuffle(mods.begin(), mods.end());
	mod1 = mods[0];
	mod2 = mods[1];

	pp1[0] = pp2[0] = 1;
	for (int i = 1; i <= 1000002; ++i) {
		pp1[i] = pp1[i - 1] * 131ll % mod1;
		pp2[i] = pp2[i - 1] * 7902131ll % mod2;
	}

	int t; cin >> t; while (t--) {
		string s; cin >> s;
		bool dif = 0;
		for (int i = 0; i < (int)s.size() / 2; ++i) {
			if (s[i] != s[s.size() - 1 - i]) {
				int alr = i * 2;
				string t;
				for (int k = i; k <= (int)s.size() - 1 - i; ++k) t += s[k];
				string rt1 = Solve(t);
				reverse(t.begin(), t.end());
				string rt2 = Solve(t);
				if (rt2.size() > rt1.size()) rt1.swap(rt2);
				cout << s.substr(0, i) << rt1 << s.substr((int)s.size() - i, i) << '\n';
				dif = 1;
				break;
			}
		}
		if (!dif) cout << s << '\n';
	}
}
