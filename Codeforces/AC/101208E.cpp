#include <bits/stdc++.h>
#define end jizz
using namespace std;

int par_id[1006];
int start[1006], end[1006];
int head[1006], tail[1006];
long long par_cnt[505][15][15];
long long par_cc[505];
long long cnt[15][15];
long long ccc;
bool exist[15];

int main() {
    int b, s;
    cin >> b >> s;
    string st;
    vector<string> v;
    v.push_back("R1");
    while (cin >> st) v.push_back(st);
    v.push_back("E");
    int k = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i][0] == 'V') {
            int val = 0;
            for (int j = 1; j < v[i].size(); ++j) val = val * 10 + v[i][j] - '0';
            k = max(k, val);
			exist[val] = 1;
        }
    }
    int ss = s;

    int cnt_par = 0;
    {
        stack<int> st;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i][0] == 'R') st.push(i);
            else if (v[i][0] == 'E') {
                par_id[st.top()] = cnt_par;
                par_id[i] = cnt_par;
                ++cnt_par;

                end[st.top()] = i;
                start[i] = st.top();

                st.pop();
            }
        }
    }

    auto Solve = [&](int zr) {
        // cerr << "zr = " << zr << endl;
		memset(head, 0, sizeof(head));
		memset(tail, 0, sizeof(tail));
        memset(cnt, 0, sizeof(cnt));
        memset(par_cnt, 0, sizeof(par_cnt));
        memset(par_cc, 0, sizeof(par_cc));
        auto is_0 = [&] (int x) -> bool { return zr & (1 << (x - 1)); };
        stack<int> st, rep_st, prev_st;
        int cur_par = -1;
        int rep_time = 0;
        int prev = 0;
		bool add = 0;
        // cerr << "jizz" << endl;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i][0] == 'R') {
                st.push(cur_par);
                cur_par = par_id[i];
				rep_st.push(rep_time);
                rep_time = 0;
                for (int j = 1; j < (int)v[i].size(); ++j) rep_time = rep_time * 10 + v[i][j] - '0';
                prev_st.push(prev);
                prev = 0;
            } else if (v[i][0] == 'E') {
				// cerr << "i = " << i << " E!" << endl;
                int chpar = cur_par;
                int chrep = rep_time;
                int chprev = prev;
                cur_par = st.top();
                rep_time = rep_st.top();
                prev = prev_st.top();
				// cerr << "cur_par rep_time prev => " << cur_par << ' ' << rep_time << ' ' << prev << endl;
                st.pop();
                rep_st.pop();
                prev_st.pop();
                if (st.empty()) break;
				// cerr << "restore prev " << prev << endl;

                if (head[cur_par] == 0) head[cur_par] = head[chpar];
                if (tail[chpar]) tail[cur_par] = tail[chpar];
				// cerr << "chpar tail " << tail[chpar] << " move to " << cur_par << endl;

                par_cc[cur_par] += par_cc[chpar] * 1ll * chrep;
                for (int i = 1; i <= k; ++i) for (int j = 1; j <= k; ++j) par_cnt[cur_par][i][j] += par_cnt[chpar][i][j] * 1ll * chrep;
                par_cnt[cur_par][tail[chpar]][head[chpar]] += chrep - 1;
				// cerr << "loop tail " << tail[chpar] << " head " << head[chpar] << " += " << chrep - 1 << endl;

				// cerr << "par_cnt " << cur_par << ' ' << prev << ' ' << head[chpar] << " ++" << endl;
                par_cnt[cur_par][prev][head[chpar]]++;
                if (tail[chpar]) prev = tail[chpar];
            } else {
                int x = v[i][1] - '0';
                if (v[i].size() > 2u) x = x * 10 + v[i][2] - '0';
                if (!is_0(x)) {
					// cerr << "Get x = " << x << endl;
                    if (head[cur_par] == 0) head[cur_par] = x;
                    tail[cur_par] = x;

                    par_cnt[cur_par][prev][x]++;
                    prev = x;
					add = 1;
                }
                par_cc[cur_par]++;
            }
        }

        for (int i = 1; i <= k; ++i) for (int j = 1; j <= k; ++j) {
            cnt[i][j] = par_cnt[par_id[0]][i][j];
            if (cnt[i][j] == 0) continue;
            // cerr << i << " " << j << " cnt = " << cnt[i][j] << endl;
        }
        ccc = par_cc[par_id[0]];

		if (zr == (1 << k) - 1) return ccc;

		vector<int> id(k + 1, -1);
		int nn = 0;
		for (int i = 1; i <= k; ++i) if (!(zr & (1 << (i - 1))) && exist[i]) id[nn++] = i;

		vector<long long> inset_cc(1 << nn);
		for (int z = 0; z < (1 << nn); ++z) {
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < k; ++j) {
					if ((z & (1 << i)) && (z & (1 << j))) inset_cc[z] += cnt[id[i]][id[j]];
				}
			}
		}

		// cerr << "nn = " << nn << endl;

		vector<long long> dp(1 << nn, -1e18);
		dp[0] = 0;
		for (int _ = 2; _ <= b; ++_) {
			vector<long long> tmp = dp;
			for (int z = 1; z < (1 << nn); ++z) {
				for (int y = z; y; (--y) &= z) {
					if (__builtin_popcount(y) <= ss) {
						// cerr << "y z " << y << ' ' << z << " old dp " << dp[z ^ y] << " cost " << inset_cc[y] << endl;
						tmp[z] = max(tmp[z], dp[z ^ y] + inset_cc[y]);
					}
				}
			}
			dp = tmp;
		}

		long long rt = ccc + inset_cc[(1 << nn) - 1] - dp[(1 << nn) - 1];
		// cerr << ccc << ' ' << inset_cc[(1 << nn) - 1] << ' ' << dp[(1 << nn) - 1] << endl;
		if (add) ++rt;

		// cerr << "Rt = " << rt << endl;

		return rt;
    };

    long long res = LLONG_MAX;
    ss = min(ss, k);
    for (int z = 0; z < (1 << k); ++z) {
        if (__builtin_popcount(z) > ss) continue;
        res = min(res, Solve(z));
    }
    cout << res << endl;
}
