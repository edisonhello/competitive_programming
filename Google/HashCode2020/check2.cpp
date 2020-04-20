#include <bits/stdc++.h>
using namespace std;

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

int value[100005];

int main(int argc, char **argv) {
	assert(argc == 3);
	ifstream td, output;

	td.open(argv[1]);
	output.open(argv[2]);

	int b, l, d; td >> b >> l >> d;
	for (int i = 0; i < b; ++i) td >> value[i];

	int o_l; output << o_l;

}
