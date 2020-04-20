#include <bits/stdc++.h>
using namespace std;

int value[100005];

struct Library {
	vector<int> books;
	int signup_cost;
	int limit;
	int lib_id;
	long long sum;
};

vector<Library> libs;
vector<int> ans_lid, ans_send;
vector<int> ans_bookid[100005];

int use[100005], ansl;

int Calc(int b, int d) {
	int nowday = 0;
	long long ans_value = 0;
	for (int i = 0; i < b; ++ i) use[i] = 0;
	for (int i = 0; i < ansl; ++ i) {
		int lid = ans_lid[i];
		nowday += libs[lid].signup_cost;
		int tmpday = nowday, cost = 0;
		for (int j = 0; j < ans_send[i]; ++ j) {
			int bookid = ans_bookid[i][j];
			if (tmpday < d && use[bookid] == 0) {
				cost ++;
				if (cost == libs[lid].limit)
					cost = 0, tmpday ++;
				use[bookid] = 1;
			}
		}
	}
	for (int i = 0; i < b; ++ i) if (use[i] == 1)
		ans_value += value[i];
	return ans_value;
}

int main(int argc, char **argv) {
	assert(argc == 4);

	ifstream Dfile, Afile;
	Dfile.open(argv[1]);
	Afile.open(argv[2]);
	int b, l, d;
	Dfile >> b >> l >> d;

	libs.resize(b);
	for (int i = 0; i < b; ++i)
		Dfile >> value[i];

	for (int i = 0; i < l; ++i) {
		int book_count;
		Dfile >> book_count >> libs[i].signup_cost >> libs[i].limit;
		libs[i].lib_id = i;
		libs[i].sum = 0;
		for (int j = 0; j < book_count; ++j) {
			int t; Dfile >> t;
			libs[i].books.push_back(t);
			libs[i].sum += value[t];
		}
	}

	Afile >> ansl;
	ans_lid.resize(ansl);
	ans_send.resize(ansl);

	for (int i = 0; i < ansl; ++ i) {
		int bookid;
		Afile >> ans_lid[i] >> ans_send[i];
		for (int j = 0; j < ans_send[i]; ++ j) {
			Afile >> bookid;
			ans_bookid[i].emplace_back(bookid);
		}
	}

	auto Output = [&] () {
		ofstream os(argv[3]);
		os << ansl << endl;
		for (int i = 0; i < ansl; ++i) {
			os << ans_lid[i] << ' ' << ans_send[i] << '\n';
			for (int j = 0; j < ans_send[i]; ++j) {
				os << ans_bookid[i][j] << ' ';
			}
			os << '\n';
		}
	};

	int times = 100000000, best = Calc(b, d);
	while (times --) {
		// shuffle one
		// int v1 = rand() % ansl;
		// int v2 = rand() % ansl;
		// swap(ans_lid[v1], ans_lid[v2]);
		// swap(ans_send[v1], ans_send[v2]);
		// swap(ans_bookid[v1], ans_bookid[v2]);
		// int new_value = Calc(b, d);
		// if (new_value > best) {
		// 	best = new_value;
		// 	cerr << "now best = " << best << endl;
		// 	Output();
		// } else {
		// 	swap(ans_lid[v1], ans_lid[v2]);
		// 	swap(ans_send[v1], ans_send[v2]);
		// 	swap(ans_bookid[v1], ans_bookid[v2]);
		// }

#ifdef _5SHUFFLE
		vector<pair<int, int>> vpp;
		for (int i = 0; i < 5; ++i) {
			int v1 = rand() % ansl;
			int v2 = rand() % ansl;
			swap(ans_lid[v1], ans_lid[v2]);
			swap(ans_send[v1], ans_send[v2]);
			swap(ans_bookid[v1], ans_bookid[v2]);
			vpp.emplace_back(v1, v2);
		}
		int new_value = Calc(b, d);
		if (new_value > best) {
			best = new_value;
			cerr << "now best = " << best << endl;
			Output();
		} else {
			for (int i = 4; i >= 0; --i) {
				int v1 = vpp[i].first, v2 = vpp[i].second;
				swap(ans_lid[v1], ans_lid[v2]);
				swap(ans_send[v1], ans_send[v2]);
				swap(ans_bookid[v1], ans_bookid[v2]);
			}
		}
#endif
		

#ifdef RSHUFFLE
		// random permutation
		int v1 = rand() % ansl;
		vector<int> old = ans_bookid[v1];
		random_shuffle(ans_bookid[v1].begin(), ans_bookid[v1].end());
		int new_value = Calc(b, d);
		if (new_value > best) {
			best = new_value;
			cerr << "now best = " << best << endl;
			Output();
		} else {
			ans_bookid[v1] = old;
		}
#endif
	}

	return 0;
}
