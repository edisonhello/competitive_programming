#include <bits/stdc++.h>
using namespace std;

int value[100005];
bool book_scanned[100005];

struct Library {
	vector<int> books;
	int signup_cost;
	int scan_limit;
	int lib_id;
	long long value_sum;
	int signuped_time;
	double value() {
		// return -(double)value_sum / signup_cost - (double)books.size() / scan_limit * 5;
		return -(double)value_sum / signup_cost;
	}
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
		cin >> book_count >> libs[i].signup_cost >> libs[i].scan_limit;
		libs[i].lib_id = i;
		for (int j = 0; j < book_count; ++j) {
			int t; cin >> t;
			libs[i].books.push_back(t);
			libs[i].value_sum += value[t];
		}
	}

	vector<Library *> o;
	for (int i = 0; i < l; ++i) o.push_back(&libs[i]);

	sort(o.begin(), o.end(), [&] (Library *a, Library *b) {
		return a->value() < b->value();
	});

	int current_time = 0;
	for (int i = 0; i < l; ++i) {
		sort(o[i]->books.begin(), o[i]->books.end(), [&] (const int a, const int b) {
			return value[a] > value[b];
		});

		current_time += o[i]->signup_cost;
		o[i]->signuped_time = current_time;
	}
	
	int lib_registed = l;
	for (int i = l - 1; i >= 0; --i) {
		int d_left = d - o[i]->signuped_time;
		int able_to_scan = d_left * o[i]->scan_limit;
		vector<int> actually_scan;
		for (int j = 0; j < (int)o[i]->books.size(); ++j) {
			if ((int)actually_scan.size() < able_to_scan) {
				if (book_scanned[o[i]->books[j]]) continue;
				actually_scan.push_back(o[i]->books[j]);
				book_scanned[o[i]->books[j]] = 1;
			}
		}

		o[i]->books = actually_scan;
		if (o[i]->books.empty()) lib_registed--;
	}

	cout << lib_registed << endl;
	for (int i = 0; i < l; ++i) {
		if (o[i]->books.empty()) continue;
		cout << o[i]->lib_id << ' ' << o[i]->books.size() << '\n';
		for (int j : o[i]->books) cout << j << ' ';
		cout << '\n';
	}
}
