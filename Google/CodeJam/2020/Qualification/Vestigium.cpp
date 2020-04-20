#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, T = 0; cin >> t; while (t--) {
		int n; cin >> n;
		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) 
				cin >> v[i][j];

		int sum = 0, r = 0, c = 0;

		for (int i = 0; i < n; ++i) 
			sum += v[i][i];

		for (int i = 0; i < n; ++i) {
			set<int> st;
			for (int j = 0; j < n; ++j) 
				st.insert(v[i][j]);
			if ((int)st.size() != n) 
				++r;
			st.clear();
			for (int j = 0; j < n; ++j) 
				st.insert(v[j][i]);
			if ((int)st.size() != n) 
				++c;
		}

		cout << "Case #" << (++T) << ": " << sum << ' ' << r << ' ' << c << '\n';
	}
}
