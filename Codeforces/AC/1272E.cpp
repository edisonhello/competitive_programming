#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
int a[200005];
bool vis[200005];
int ans[200005];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i - a[i] >= 1) g[i - a[i]].push_back(i);
		if (i + a[i] <= n) g[i + a[i]].push_back(i);
		ans[i] = -1;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if ((i + a[i] <= n && ((a[i + a[i]] ^ a[i]) & 1) == 1) || (i - a[i] >= 1 && ((a[i - a[i]] ^ a[i]) & 1) == 1)) {
			q.push(i);
			vis[i] = 1;
			ans[i] = 1;
		}
	}

	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i : g[now]) {
			if (!vis[i]) {
				ans[i] = ans[now] + 1;
				vis[i] = 1;
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
}
