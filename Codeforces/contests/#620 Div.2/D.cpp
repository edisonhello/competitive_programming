#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		{
			int l = 0, r = n + 1; 
			memset(a, 0, (n + 1) << 2);
			for (int i = n - 1; i >= 1; --i) if (s[i - 1] == '<') {
				int j = i;
				while (j > 1 && s[j - 1 - 1] == '<') --j;
				for (int k = j; k <= i; ++k) a[k] = ++l;
				i = j;
			}
			for (int i = 1; i <= n; ++i) if (!a[i]) a[i] = --r;
			for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n';
		}

		{
			int l = 0, r = n + 1;
			memset(a, 0, (n + 1) << 2);
			for (int i = 1; i < n; ++i) if (s[i - 1] == '<') {
				a[i] = ++l;
				if (i == n - 1 || s[i] != '<') {
					a[++i] = --r;
				}
			}
			for (int i = 1; i <= n; ++i) if (!a[i]) a[i] = --r;
			for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n';
		}
	}
}
