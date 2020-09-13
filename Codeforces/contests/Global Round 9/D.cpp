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

int mex(vector<int> &v) {
	set<int> st(v.begin(), v.end());
	for (int i = 0; ; ++i) if (!st.count(i)) return i;
}

int main() {
    CPPinput;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		vector<int> ops;
		vector<int> cnt(n + 1, 0);
		for (int i = 0; i < n; ++i) ++cnt[v[i]];

		for (int i = 0; i < n; ++i) {
			if (v[i] == i) continue;
			if (cnt[i] == 0) {
				ops.push_back(i);
				--cnt[v[i]];
				v[i] = mex(v);
				++cnt[v[i]];
			} else {
				for (int j = 0; j < n; ++j) if (v[j] == i && j != i) {
					int m = mex(v);
					while (m < j) {
						--cnt[v[m]];
						ops.push_back(m);
						v[m] = m;
						++cnt[v[m]];
						m = mex(v);
					}
					--cnt[v[j]];
					ops.push_back(j);
					v[j] = mex(v);
					++cnt[v[j]];
				}
				if (v[i] != i) {
					ops.push_back(i);
					--cnt[v[i]];
					v[i] = mex(v);
					++cnt[v[i]];
				}
			}
			PDE(i, v, ops);
		}

		PDE(v);

		cout << ops.size() << '\n';
		for (int i : ops) cout << i + 1 << ' ';
		cout << '\n';

		// for (int i = 0; i < n; ++i) {
		// 	int found = -1;
		// 	for (int j = 0; j < n; ++j) if (v[j] == i) found = j;
		// 	if (found != -1) continue;
		// 	for (int j = 0; j < n; ++j) if (v[j] > i) found = j;
		// 	if (found != -1) {
		// 		ops.push_back(found);
		// 		--cnt[v[found]];
		// 		v[found] = mex(v);
		// 		++cnt[v[found]];
		// 	} else {
		// 		for (int j = 0; j < i; ++j) if (cnt[j] > 1) {
		// 			for (int k = 0; k < n; ++k) if (v[k] == j) found = k;
		// 			assert(found != -1);
		// 			ops.push_back(found);
		// 			--cnt[v[found]];
		// 			v[found] = mex(v);
		// 			++cnt[v[found]];
		// 			break;
		// 		}
		// 	}
		// }

		// for (int i = n - 1; i >= 0; --i) {
		// 	ops.push_back(i);
		// 	v[i] = mex(v);
		// }

		// PDE(v);

		// for (int i = n - 1; i >= 0; --i) {
		// 	ops.push_back(i);
		// 	v[i] = mex(v);
		// }

		// set<int> all(v.begin(), v.end());
		// int mex = 0;
		// while (all.count(mex)) ++mex;

		// vector<int> vv = v;

		// for (int no = 0; no <= n; ++no) {
		// 	vector<int> op2;
		// 	int m = mex;
		// 	bool failed = 0;
		// 	v = vv;
		// 	auto Pos = [&] (int x) {
		// 		if (x == no) failed = 1;
		// 		if (x < no) return x;
		// 		else return x - 1;
		// 	};
		// 	auto Inc = [&] (vector<int> &v) {
		// 		for (int i = 1; i < n; ++i) if (v[i] < v[i - 1]) return false;
		// 		return true;
		// 	};

		// 	PDE(v, no);

		// 	for (int i = 0; i < n; ++i) {
		// 		int p = Pos(m);
		// 		if (failed) break;
		// 		swap(v[p], m);
		// 		op2.push_back(p);
		// 		PDE(i, p, v);
		// 		if (Inc(v)) break;
		// 	}

		// 	if (failed && !Inc(v)) continue;

		// 	PDE(v, failed);

		// 	cout << ops.size() + op2.size() << '\n';
		// 	for (int i : ops) cout << i + 1 << ' ';
		// 	for (int i : op2) cout << i + 1 << ' ';
		// 	cout << '\n';
		// 	break;
		// }
	}
}
