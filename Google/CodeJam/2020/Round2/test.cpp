#include <bits/stdc++.h>
using namespace std;
#include"/home/edison/Coding/cpp/template/debug.cpp"

int main() {
		auto QAQ = [&] (vector<int> v) {
			vector<vector<int>> vv;
			int nn = 0;
			for (auto i : v) {
				vv.emplace_back(vector<int>());
				while (i--) vv.back().push_back(nn++);
			}
			vector<int> nxt(nn, -1);
			vector<int> hole(nn, -1);
			for (auto &v : vv) {
				for (int i = 0; i < (int)v.size() - 1; ++i) nxt[v[i]] = v[i + 1];
			}

			int mx = 0;
			auto Dfs = [&] (auto self, vector<bool> &used) -> void {
				int fre = 0;
				for (bool i : used) fre += !i;
				for (int st = 0; st < (int)used.size(); ++st) {
					PDE(nxt, hole, st);
					{
						int now = st;
						vector<bool> touched(used.size(), false);
						touched[now] = true;
						int it = used.size() * 6;
						while (it--) {
							if (nxt[now] == -1) break;
							now = nxt[now];
							touched[now] = 1;
							if (hole[now] == -1) break;
							now = hole[now];
							touched[now] = 1;
						}
						int c = 0;
						for (bool i : touched) c += i;
						mx = max(mx, c);
						PDE(c, mx);
					}
					{
						int now = st;
						vector<bool> touched(used.size(), false);
						touched[now] = true;
						int it = used.size() * 6;
						while (it--) {
							if (hole[now] == -1) break;
							now = hole[now];
							touched[now] = 1;
							if (nxt[now] == -1) break;
							now = nxt[now];
							touched[now] = 1;
						}
						int c = 0;
						for (bool i : touched) c += i;
						mx = max(mx, c);
						PDE(c, mx);
					}
				}

				for (int i = 0; i < (int)used.size(); ++i) if (used[i] == 0) {
					for (int j = i + 1; j < (int)used.size(); ++j) if (used[j] == 0) {
						used[i] = used[j] = 1;
						hole[i] = j, hole[j] = i;
						self(self, used);
						used[i] = used[j] = 0;
						hole[i] = -1, hole[j] = -1;
					}
				}
			};
			vector<bool> used(nn, false);
			Dfs(Dfs, used);

			return mx;
		};


	vector<int> v = vector<int>{1, 1, 3, 3};
	cout << QAQ(v) << endl;
}
