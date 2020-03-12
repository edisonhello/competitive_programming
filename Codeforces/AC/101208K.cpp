#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

bool DEBUG = 0;

string s1, s2, s3;
int cal[3][2];
struct __data {
	bool res;
	string pre, in, post;

	void clear() {
		res = false;
		pre = in = post = "";
	}
} *dp[27][27][27][27][3][3][3];

vector<tuple<int, int, int, int, int, int, int>> visited;

bool Dfs(int i1, int i2, int i3, int len, int t1, int t2, int t3) {
	if (DEBUG) {
		cerr << "Dfs " << i1 << ' ' << i2 << ' ' << i3 << ' ' << len << ' ' << t1 << ' ' << t2 << ' ' << t3 << endl;
	}

	visited.emplace_back(i1, i2, i3, len, t1, t2, t3);

	auto &now_ptr = dp[i1][i2][i3][len][t1][t2][t3];
	if (now_ptr) return now_ptr->res;
	else now_ptr = new __data(), now_ptr->clear();
	auto &now = *now_ptr;

	if (len == 0) {
		now.res = 1;
		now.pre = now.in = now.post = "";
		return true;
	} else if (len == 1) {
		now.res = 1;
		now.pre = now.in = now.post = string(1, s1[i1]);
		return true;
	}

	auto GetLeft = [&] (const int type, const int offset) {
		if (type == 0) return offset + 1;
		return offset;
	};

	vector<int> c1(26, 0), c2(26, 0), c3(26, 0);
	int l1 = GetLeft(t1, i1), l2 = GetLeft(t2, i2), l3 = GetLeft(t3, i3);
	int diffidx1 = 0, diffidx2 = 0;

	for (int lsz = 0; lsz <= len - 1; ++lsz) {
		if (DEBUG) cerr << "lsz = " << lsz << endl;

		if (lsz) {
			char ch1 = s1[l1 + lsz - 1] - 'A';
			char ch2 = s2[l2 + lsz - 1] - 'A';
			char ch3 = s3[l3 + lsz - 1] - 'A';
			if (c1[ch1] == c2[ch1]) ++diffidx1;
			++c1[ch1];
			if (c1[ch1] == c2[ch1]) --diffidx1;

			if (c1[ch2] == c2[ch2]) ++diffidx1;
			if (c2[ch2] == c3[ch2]) ++diffidx2;
			++c2[ch2];
			if (c1[ch2] == c2[ch2]) --diffidx1;
			if (c2[ch2] == c3[ch2]) --diffidx2;

			if (c2[ch3] == c3[ch3]) ++diffidx2;
			++c3[ch3];
			if (c2[ch3] == c3[ch3]) --diffidx2;
		}

		auto GetRoot = [&] (const string &tree, const int type, const int offset) {
			if (type == 0) return tree[offset];
			else if (type == 1) return tree[offset + lsz];
			else return tree[offset + len - 1];
		};
		auto GetRight = [&] (const int type, const int offset) {
			if (type == 2) return offset + lsz;
			return offset + 1 + lsz;
		};

		char rt1 = GetRoot(s1, t1, i1), rt2 = GetRoot(s2, t2, i2), rt3 = GetRoot(s3, t3, i3);
		int r1 = GetRight(t1, i1), r2 = GetRight(t2, i2), r3 = GetRight(t3, i3);

		if (DEBUG) cerr << "roots = " << rt1 << ' ' << rt2 << ' ' << rt3 << endl;

		if (rt1 != rt2 || rt2 != rt3) continue;
		if (diffidx1 || diffidx2) continue;

		if (Dfs(l1, l2, l3, lsz, cal[t1][0], cal[t2][0], cal[t3][0]) &&
			Dfs(r1, r2, r3, len - lsz - 1, cal[t1][1], cal[t2][1], cal[t3][1])) {
			string root = string(1, rt1);
			auto &ls = *dp[l1][l2][l3][lsz][cal[t1][0]][cal[t2][0]][cal[t3][0]];
			auto &rs = *dp[r1][r2][r3][len - lsz - 1][cal[t1][1]][cal[t2][1]][cal[t3][1]];

			if (!now.res) {
				now.res = 1;
				now.pre = root + ls.pre + rs.pre;
				now.in = ls.in + root + rs.in;
				now.post = ls.post + rs.post + root;
			} else {
				string new_pre = root + ls.pre + rs.pre;
				if (new_pre < now.pre) {
					now.pre = new_pre;
					now.in = ls.in + root + rs.in;
					now.post = ls.post + rs.post + root;
				} else if (new_pre == now.pre) {
					string new_in = ls.in + root + rs.in;
					if (new_in < now.in) {
						now.in = new_in;
						now.post = ls.post + rs.post + root;
					}
				}
			}
		}
	}
	return now.res;
}

int main() {
	cin >> s1 >> s2 >> s3;
	int n = s1.size();

	int *_cal = cal[0];
	_cal[2] = _cal[3] = 1, _cal[4] = _cal[5] = 2;

	auto GetType = [&] (const int x) -> string {
		if (x == 0) return "Pre";
		else if (x == 1) return "In";
		else return "Post";
	};

	bool first = true;
	do {
		// if (_cal[0] == 0 && _cal[1] == 2 && _cal[2] == 1 && _cal[3] == 2 && _cal[4] == 1 && _cal[5] == 0) DEBUG = 1;
		// else DEBUG = 0;

		if (DEBUG) {
			cerr << "trying ";
			for (int i = 0; i < 6; ++i) cerr << GetType(_cal[i]) << ' ';
			cerr << endl;
		}

		visited.clear();

		if (Dfs(0, 0, 0, s1.size(), 0, 1, 2)) {
			if (!first) cout << '\n';
			else first = false;

			auto &now = *dp[0][0][0][s1.size()][0][1][2];
			assert(now.res);
			for (int i = 0; i < 6; ++i) cout << GetType(_cal[i]) << ' ';
			cout << '\n' << now.pre << '\n' << now.in << '\n' << now.post << '\n';
		}

		for (auto [q, w, e, r, t, y, u] : visited) {
			delete dp[q][w][e][r][t][y][u];
			dp[q][w][e][r][t][y][u] = 0;
		}

	} while (next_permutation(_cal, _cal + 6));
}
