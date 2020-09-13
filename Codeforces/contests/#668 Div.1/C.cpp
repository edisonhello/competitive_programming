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

#define int long long 

int a[300005];

struct node {
	node *l, *r;
	int val, tag;
	node() : l(0), r(0), val(0), tag(0) {}
	void addtag(int v) { tag += v, val += v; }
	void push() {
		if (tag) {
			l->addtag(tag);
			r->addtag(tag);
			tag = 0;
		}
	}
	void pull() { val = max(l->val, r->val); }
} *root;

#define mid ((l + r) >> 1)
void build(node *now, int l, int r) {
	if (l == r) {
		now->val = a[l] - l;
		if (now->val > 0) now->val = -1000000000;
		PDE(l, now->val);
		return;
	}
	build(now->l = new node(), l, mid);
	build(now->r = new node(), mid + 1, r);
	now->pull();
}

int getr0(node *now, int l, int r) {
	PDE("getr0", l, r, now->val);
	if (l == r) {
		assert(now->val == 0);
		return l;
	}
	now->push();
	if (now->r->val == 0) return getr0(now->r, mid + 1, r);
	else return getr0(now->l, l, mid);
	now->pull();
}

void modify(node *now, int l, int r, int ml, int mr, int vv) {
	PDE("modify", l, r, ml, mr, vv);
	if (r < ml || mr < l) return;
	if (ml <= l && r <= mr) {
		now->addtag(vv);
		return;
	}
	now->push();
	modify(now->l, l, mid, ml, mr, vv);
	modify(now->r, mid + 1, r, ml, mr, vv);
	now->pull();
	PDE("modify result", l, r, ml, mr, vv, now->val);
}

pair<int, int> qs[300005];
int ans[300005];

int suf[300005];

int bit[300005];

void add(int x) {
	for (; x < 300005; x += lowbit(x))
		bit[x]++;
}

int query(int x) {
	int a = 0;
	for (; x; x -= lowbit(x))
		a += bit[x];
	return a;
}

int32_t main() {
    CPPinput;
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(root = new node(), 1, n);
	
	vector<int> to;
	while (root->val == 0) {
		PDE(root->val);
		int idx = getr0(root, 1, n);
		PDE(idx);
		modify(root, 1, n, idx, idx, -1000000000);
		modify(root, 1, n, idx + 1, n, 1);
		to.push_back(idx);

		++suf[idx];
	}

	PDE(to);

	for (int i = n; i >= 1; --i) suf[i] += suf[i + 1];

	for (int i = 0; i < q; ++i) cin >> qs[i].first >> qs[i].second;
	vector<int> allq(q); iota(allq.begin(), allq.end(), 0);
	for (int i = 0; i < q; ++i) ans[i] = to.size();

	// for (int i = 0; i < q; ++i) ans[i] -= suf[n - qs[i].second + 1];

	sort(allq.begin(), allq.end(), [&] (int qa, int qb) {
		return qs[qa].first > qs[qb].first;
	});

	PDE(allq);

	int cur_idx = n + 1;
	int nowi = 0;
	for (int i = 0; i < (int)to.size(); ++i) {
		int idx = to[i];
		cur_idx = min(cur_idx, idx);

		PDE(i, idx, cur_idx);

		add(idx);

		while (nowi < q) {
			if (qs[allq[nowi]].first >= cur_idx) {
				PDE(qs[allq[nowi]], cur_idx);
				PDE(nowi, allq[nowi]);
				ans[allq[nowi]] -= to.size() - i;
				PDE("front minus", to.size() - 1);
				ans[allq[nowi]] -= (query(n) - query(n - qs[allq[nowi]].second));
				PDE("back minus", (query(n) - query(n - qs[allq[nowi]].second)));
				++nowi;
			} else break;
		}
	}

	while (nowi < q) {
		PDE(qs[allq[nowi]], cur_idx);
		PDE(nowi, allq[nowi]);
		ans[allq[nowi]] -= (query(n) - query(n - qs[allq[nowi]].second));
		PDE("back minus", (query(n) - query(n - qs[allq[nowi]].second)));
		++nowi;
	}

	for (int i = 0; i < q; ++i) 
		cout << ans[i] << '\n';


}
