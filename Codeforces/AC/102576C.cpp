#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Med {
	priority_queue<int, vector<int>, less<int>> lo;
	priority_queue<int, vector<int>, greater<int>> hi;

	int Get() {
		assert(lo.size() || hi.size());
		if (lo.size() > hi.size()) return lo.top();
		else return hi.top();
	}
	void Push(int x) {
		if (lo.empty() && hi.empty()) lo.push(x);
		else if (lo.empty()) hi.push(x);
		else if (hi.empty()) lo.push(x);
		else if (x >= Get()) hi.push(x);
		else lo.push(x);

		while (lo.size() > hi.size() + 1) {
			hi.push(lo.top());
			lo.pop();
		}
		while (hi.size() > lo.size() + 1) {
			lo.push(hi.top());
			hi.pop();
		}
	}
	int size() { return lo.size() + hi.size(); }
	template <typename T> Med(vector<T> x = vector<T>()) {
		for (T i : x) Push(i);
	}

	long long Cost() {
		int base = max(0ll, Get());
		int tot = 0;
		while (lo.size()) {
			tot += abs(lo.top() - base);
			lo.pop();
		}
		while (hi.size()) {
			tot += abs(hi.top() - base);
			hi.pop();
		}
		return tot;
	}
};

Med *Merge(Med *a, Med *b) {
	if (a->size() < b->size()) swap(a, b);
	while (b->lo.size()) {
		a->Push(b->lo.top());
		b->lo.pop();
	}
	while (b->hi.size()) {
		a->Push(b->hi.top());
		b->hi.pop();
	}
	delete b;
	return a;
}

void Print(vector<Med *> v) {
	for (Med *m : v) {
		Med mm = *m;
		cerr << "[(";
		while (mm.lo.size()) {
			cerr << mm.lo.top() << ' ';
			mm.lo.pop();
		}
		cerr << ")(";
		while (mm.hi.size()) {
			cerr << mm.hi.top() << ' ';
			mm.hi.pop();
		}
		cerr << ")]";
	}
	cerr << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int z; cin >> z; while (z--) {
		int n, d; cin >> n >> d;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());

		for (int i = 0; i < n; ++i) v[i] -= 1ll * d * i;
		
		vector<Med *> q;
		q.emplace_back(new Med(vector<long long>{v[0]}));

		for (int i = 1; i < n; ++i) {
			if (v[i] >= q.back()->Get()) {
				q.push_back(new Med(vector<long long>{v[i]}));
			} else {
				Med *now = new Med(vector<long long>{v[i]});
				while (q.size() && now->Get() < q.back()->Get()) {
					now = Merge(q.back(), now);
					q.pop_back();
				}
				q.push_back(now);
			}

			// Print(q);
		}

		long long cost = 0;
		for (Med *m : q) cost += m->Cost();

		cout << cost << '\n';
	}
}
