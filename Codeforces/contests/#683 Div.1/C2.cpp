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

auto getget = [] (int t) {
	int z = 0;
	while (t) t >>= 1, ++z;
	return z;
};

bool TreeCheck(vector<int> v) {
	int n = v.size();
	set<pair<int, int>> st;
	for (int i = 0; i < n; ++i) {
		int mn = INT_MAX;
		int z = -1;
		for (int j = 0; j < n; ++j) if (i != j) {
			if ((v[i] ^ v[j]) < mn) {
				mn = v[i] ^ v[j];
				z = j;
			}
		}
		PDE(i, v[i], z, mn);
		st.insert(minmax(z, i));
	}

	cout << st.size() << endl;
	for (auto [i, j] : st) {
		cout << v[i] << "(" << getget(v[i]) << ") " << v[j] << "(" << getget(v[j]) << ")";
		cout << endl;
	}
	return (int)st.size() == n - 1;
}

int solve(vector<int> v) {
	if (v.size() <= 2u) return 0;

	vector<vector<int>> cnt(35);
	for (int i : v) {
		int z = getget(i);
		cnt[z].push_back(i);
	}

	vector<int> bcost(35, 0);
	for (int i = 2; i <= 32; ++i) {
		if (cnt[i].size() <= 2u) continue;
		vector<int> v = cnt[i];
		for (int &j : v) j ^= (1 << (i - 1));
		bcost[i] = solve(v);
	}

	PDE(cnt);

	int ret = 0;
	for (int i = 0; i <= 32; ++i) if (cnt[i].size() > 1u) ret += cnt[i].size() - 1;

	PDE(ret);

	{
		for (int b = 0; b <= 32; ++b) {
			int tmp = 0;
			for (int i = 0; i < b; ++i) tmp += cnt[i].size();
			tmp += bcost[b];
			for (int i = b + 1; i <= 32; ++i) if (cnt[i].size() > 1u) tmp += cnt[i].size() - 1;
			ret = min(tmp, ret);
		}
	}

	PDE(ret);

	{
		for (int b = 0; b <= 32; ++b) {
			int tmp = 0;
			for (int i = 0; i < b; ++i) tmp += cnt[i].size();
			if (tmp > 0) --tmp;
			tmp += bcost[b];
			for (int i = b + 1; i <= 32; ++i) if (cnt[i].size() > 1u) tmp += cnt[i].size() - 1;
			ret = min(tmp, ret);
		}
	}

	PDE(v, bcost, ret);


	return ret;
}

int main() {
	srand(time(0) * clock() * rand());

    CPPinput;
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	cout << solve(v) << endl;
}
