#pragma GCC optimize("O3")
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

vector<int> Op(vector<int> &v, int a, int b) {
	vector<int> vv;
	vv.reserve(v.size());
	for (int i = a; i < a + b; ++i) vv.push_back(v[i]);
	for (int i = 0; i < a; ++i) vv.push_back(v[i]);
	for (int i = a + b; i < (int)v.size(); ++i) vv.push_back(v[i]);
	return vv;
}

uint64_t Hash(vector<int> &v) {
	uint64_t r = 0;
	for (uint64_t i : v) {
		r = (r << i) ^ r ^ (r >> i);
		r ^= 88129477;
		r *= 99182779182ull;
		r += 0x8abf72ull;
		r ^= 0x81ba7cf81ull;
		r ^= (r << i) ^ (r >> 13);
	}
	return r;
}

unordered_set<uint64_t> in;
unordered_map<uint64_t, pair<int, pair<int, int>>> rec;
int Dfs(vector<int> v) {
	uint64_t h = Hash(v);
	auto it = rec.find(h);
	if (it != rec.end()) return it->second.first;


	bool bad = 0;
	for (int i = 1; i < (int)v.size(); ++i) {
		if (v[i] < v[i - 1]) bad = 1;
	}
	if (!bad) return 0;

	if (in.count(h)) return 999999;
	in.insert(h);

	// cerr << "v : "; for (int i : v) cerr << i << ' '; cerr << endl;

	int mn = 999999;
	pair<int, int> to(-1, -1);
	for (int i = 1; i < (int)v.size(); ++i) for (int j = 1; i + j <= (int)v.size(); ++j) {
		// cerr << "i j " << i << ' ' << j << endl;
		vector<int> vv = Op(v, i, j);
		// cerr << "v "; for (int i : v) cerr << i << ' '; cerr << " go to "; for (int i : vv) cerr << i << ' '; cerr << endl;
		int r = Dfs(vv) + 1;
		// cerr << "r = " << r << endl;
		if (r < mn) {
			mn = r;
			to = make_pair(i, j);
		}
	}

	rec[h] = make_pair(mn, to);
	// cerr << "Get v = "; for (int i : v) cerr << i << ' '; cerr << "ans = " << mn << endl;
	return mn;
}

int main() {
    CPPinput;
	int t; cin >> t; for (int T = 1; T <= t; ++T) {
		int r, s; cin >> r >> s;
		vector<int> v;
		for (int i = 0; i < s; ++i) for (int j = 1; j <= r; ++j) v.push_back(j);

		int ans = Dfs(v);

		// vector<pair<int, int>> ans;
		// while (true) {
		// 	int it = v.size() - 1;
		// 	int i, j;
		// 	for (j = r; j >= 1; --j) 
		// 		for (i = 0; i < s; ++i) 
		// 			if (v[it] != j) goto FOUND;
		// 			else --it;
		// 	break;
FOUND:;
		// 	int jt = it;
		// 	while (v[jt] != j) --jt;
		// 	ans.emplace_back(jt + 1, it - jt);

		// 	// cerr << "it jt " << it << ' ' << jt << endl;

		// 	// cerr << "v : "; for (int i : v) cerr << i << ' '; cerr << " -> ";

		// 	vector<int> nv;
		// 	for (int y = jt + 1; y <= it; ++y) nv.push_back(v[y]);
		// 	for (int y = 0; y <= jt; ++y) nv.push_back(v[y]);
		// 	for (int y = it + 1; y < (int)v.size(); ++y) nv.push_back(v[y]);
		// 	v.swap(nv);

		// 	// cerr << "v : "; for (int i : v) cerr << i << ' '; cerr << endl;
		// }

		cout << "Case #" << T << ": " << ans << endl;
		while (rec.count(Hash(v))) {
			auto p = rec[Hash(v)].second;
			cout << p.first << ' ' << p.second << '\n';
			v = Op(v, p.first, p.second);
		}
	}
}
