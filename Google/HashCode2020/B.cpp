#include <bits/stdc++.h>
using namespace std;

int value[100005];

struct Library {
	vector<int> books;
	int signup_cost;
	int limit;
	int lib_id;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int b, l, d; cin >> b >> l >> d;
	vector<Library> libs(b);
	for (int i = 0; i < b; ++i) {
		cin >> value[i];
	}
	for (int i = 0; i < l; ++i) {
		int book_count;
		cin >> book_count >> libs[i].signup_cost >> libs[i].limit;
		libs[i].lib_id = i;
		for (int j = 0; j < book_count; ++j) {
			int t; cin >> t;
			libs[i].books.push_back(t);
		}
	}

	vector<Library *> o;
	for (int i = 0; i < l; ++i) o.push_back(&libs[i]);

	sort(o.begin(), o.end(), [&] (Library *a, Library *b) {
		return a->signup_cost < b->signup_cost;
	});

	cout << l << endl;
	for (int i = 0; i < l; ++i) {
		cout << o[i]->lib_id << ' ' << o[i]->books.size() << '\n';
		for (int j : o[i]->books) cout << j << ' ';
		cout << '\n';
	}
}
