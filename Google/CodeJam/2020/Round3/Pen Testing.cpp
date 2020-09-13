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



int main() {
    CPPinput;
	int t, n, c; cin >> t >> n >> c;
	constexpr double kBound = 0.55;

	auto CalcExpect = [&] (const vector<bool> &empty) -> double {
		vector<int> ok;
		for (int i = 0; i < n; ++i) if (!empty[i]) ok.push_back(i);
		int tot = 0, cnt = 0;
		for (int i = 0; i < (int)ok.size(); ++i) for (int j = i + 1; j < (int)ok.size(); ++j) {
			++cnt;
			if (ok[i] + ok[j] >= n) ++tot;
		}

		return (double)tot / cnt;
	};

	vector<int> testing(t, 1);
	vector<int> testtime(t, 0);
	vector<vector<bool>> emptyed(t, vector<bool>(n, 0));

	vector<int> asking(t, 0);
	vector<int> response(t, 0);

	auto StillAsking = [&] () -> bool {
		for (int i = 0; i < t; ++i) if (asking[i]) return 1;
		return 0;
	};

	auto Ask = [&] () -> void {
		for (int i = 0; i < t; ++i) {
			if (asking[i]) cout << testing[i] << ' ';
			else cout << 0 << ' ';
		}
		cout << endl;
		fflush(stdout);
		// cerr << "Ask" << endl;
		// for (int i = 0; i < t; ++i) {
		// 	if (asking[i]) cerr << testing[i] << ' ';
		// 	else cerr << 0 << ' ';
		// }
		// cerr << endl;
		// cerr << "Resp" << endl;
		for (int i = 0; i < t; ++i) {
			cin >> response[i];
			if (response[i] == -1) exit(1);
			// cerr << response[i] << ' ';
		}
		// cerr << endl;
	};

	while (StillAsking()) {
		Ask();

		for (int i = 0; i < t; ++i) {
			if (asking[i] == 0) continue;
			if (response[i] == 0) {
				emptyed[i][testtime[i]] = 1;
				++testing[i];
				if (CalcExpect(emptyed[i]) >= kBound) {
					asking[i] = 0;
				} else if (testing[i] == 13) {
					asking[i] = 0;
				} else {
					testtime[i] = 0;
				}
			} else {
				++testtime[i];
			}
		}
	}

	for (int i = 0; i < t; ++i) cout << 0 << ' ';
	cout << endl;

	for (int i = 0; i < t; ++i) {
		cout << testing[i] << ' ' << testing[i] + 1 << ' ';
	}
	cout << endl;

}
