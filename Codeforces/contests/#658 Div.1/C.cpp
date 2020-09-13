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

void solve() {
	int n, x, y; cin >> n >> x >> y;
	int z = n - y;
	int ox = x, oy = y, oz = z;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<int> append(n + 2, false);
	for (int i : v) append[i] = true;
	int noop = -1;
	for (int i = 1; i <= n + 1; ++i) if (!append[i]) noop = i;

	assert(noop != -1);

	vector<int> cnt(n + 2, 0);
	vector<vector<int>> poss(n + 2);
	for (int i = 0; i < n; ++i) {
		++cnt[v[i]];
		poss[v[i]].push_back(i);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> cntp;
	for (int i = 1; i <= n + 1; ++i) if (cnt[i]) cntp.push(make_pair(cnt[i], i));

	PDE(cntp);

	int filled = 0;

	vector<int> ans(n, -1);
	while (cntp.size()) {
		auto p = cntp.top(); cntp.pop();
		if (x > 0) {
			--p.first;
			ans[poss[p.second].back()] = v[poss[p.second].back()];
			poss[p.second].pop_back();
			--x;
			++filled;
		} else {
			cntp.push(p);
			break;
		}

		if (p.first > 0) cntp.push(p);
	}

	int fi_objs = 0;
	vector<int> objs = [&] (auto pq) {
		vector<pair<int, int>> vpp;
		while (pq.size()) {
			vpp.push_back(pq.top());
			pq.pop();
		}

		if (vpp.size()) fi_objs = vpp[0].first;

		vector<int> rt;
		for (auto &p : vpp) while (p.first--) rt.push_back(p.second);
		return rt;
	} (cntp);
	auto poss_backup = poss;

	PDE(ans);

	while (cntp.size()) {
		auto p = cntp.top(); cntp.pop();
		if (z > 0) {
			--p.first;
			ans[poss[p.second].back()] = noop;
			poss[p.second].pop_back();
			--z;
			++filled;
		} else {
			cntp.push(p);
			break;
		}

		if (p.first > 0) cntp.push(p);
	}

	int fi_empts = 0;
	vector<int> empts = [&] (auto pq) {
		vector<pair<int, int>> vpp;
		while (pq.size()) {
			vpp.push_back(pq.top());
			pq.pop();
		}

		if (vpp.size()) fi_empts = vpp[0].first;

		vector<int> rt;
		for (auto &p : vpp) while (p.first--) {
			rt.push_back(poss[p.second].back());
			poss[p.second].pop_back();
		}
		return rt;
	} (cntp);

	PDE(ans);

	if (oz == n || filled == n) {
		cout << "YES" << '\n';
		for (int i : ans) cout << i << ' ';
		cout << '\n';
		return;
	}

	if (objs.size()) {
		int fi_obj_z = objs[0];
		int start = 0;
		while (start < (int)empts.size() && v[empts[start]] == fi_obj_z) ++start;

		deque<int> dq;
		if (start == (int)empts.size()) {
			int se_obj_z = -1;
			for (int i = 0; i < (int)objs.size(); ++i) if (objs[i] != objs[0]) {
				se_obj_z = objs[i];
				break;
			}
			if (se_obj_z == -1) {
				PDE("QQ");
				cout << "NO" << '\n';
				return;
			} else {
				start = 0;
				while (start < (int)empts.size() && v[empts[start]] == se_obj_z) ++start;
				if (start == (int)empts.size()) {
					if (oz == n) {
						cout << "YES" << '\n';
						for (int i : ans) cout << i << ' ';
						cout << '\n';
					} else {
						PDE("QQQ");
						cout << "NO" << '\n';
					}
					return;
				} else {
					PDE(se_obj_z, start);
					dq.push_back(se_obj_z);
					dq.push_back(v[empts[start]]);
				}
			}
		} else {
			PDE(fi_obj_z, start);
			dq.push_back(fi_obj_z);
			dq.push_back(v[empts[start]]);
		}

		int it = 0;
		for (int _run = 0, now = start; !_run || now != start; ++_run, now = (now + 1) % empts.size()) {
			if (dq.back() != v[empts[now]]) dq.push_back(v[empts[now]]);
			if (v[empts[now]] == dq.front()) dq.pop_front();

			if (dq.empty()) {
				cout << "NO" << '\n';
				return;
			}
			ans[empts[now]] = dq.front();
			poss_backup[dq.front()].pop_back();

			if (poss_backup[dq.front()].empty()) dq.pop_front();
		}
	}

	PDE(ans);

	int checkx = 0;
	for (int i = 0; i < n; ++i) if (v[i] == ans[i]) ++checkx;
	if (checkx != ox) {
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';
	for (int i : ans) cout << i << ' ';
	cout << '\n';

	// vector<pair<int, int>> vpp;
	// while (cntp.size()) vpp.push_back(cntp.top()), cntp.pop();

	// PDE(vpp);

	// if (vpp.size()) {
	// 	int mxxp = vpp[0].first;
	// 	vector<int> vpos;
	// 	for (auto &p : vpp) {
	// 		while (p.first--) {
	// 			vpos.push_back(poss[p.second].back());
	// 			poss[p.second].pop_back();
	// 		}
	// 	}

	// 	PDE(mxxp, vpos);

	// 	if (mxxp > vpos.size() / 2) {
	// 		cout << "NO" << '\n';
	// 		return;
	// 	}

	// 	for (int i = 0; i < (int)vpos.size(); ++i) {
	// 		ans[vpos[i]] = v[vpos[(i + mxxp) % vpos.size()]];
	// 	}
	// }

	// cout << "YES" << '\n';
	// for (int i : ans) cout << i << ' ';
	// cout << '\n';


	// PDE("bruh");
}

int main() {
	CPPinput;
	int t; cin >> t; while (t--) solve();
}
