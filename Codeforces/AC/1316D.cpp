#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> to[1005][1005];
char ans[1005][1005];

bool inside(int x, int y) {
	return min(x, y) >= 1 && max(x, y) <= n;
}

void dfs(int nx, int ny) {
	if (inside(nx - 1, ny) && to[nx - 1][ny] == to[nx][ny] && !ans[nx - 1][ny]) {
		ans[nx - 1][ny] = 'D';
		dfs(nx - 1, ny);
	}
	if (inside(nx + 1, ny) && to[nx + 1][ny] == to[nx][ny] && !ans[nx + 1][ny]) {
		ans[nx + 1][ny] = 'U';
		dfs(nx + 1, ny);
	}
	if (inside(nx, ny - 1) && to[nx][ny - 1] == to[nx][ny] && !ans[nx][ny - 1]) {
		ans[nx][ny - 1] = 'R';
		dfs(nx, ny - 1);
	}
	if (inside(nx, ny + 1) && to[nx][ny + 1] == to[nx][ny] && !ans[nx][ny + 1]) {
		ans[nx][ny + 1] = 'L';
		dfs(nx, ny + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> to[i][j].first >> to[i][j].second;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (to[i][j].first == i && to[i][j].second == j) {
				ans[i][j] = 'X';
				dfs(i, j);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!ans[i][j] && to[i][j].first != -1) {
				cout << "INVALID" << endl;
				exit(0);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i < n && !ans[i][j] && !ans[i + 1][j]) {
				ans[i][j] = 'D';
				ans[i + 1][j] = 'U';
				dfs(i, j);
				dfs(i + 1, j);
			} else if (j < n && !ans[i][j] && !ans[i][j + 1]) {
				ans[i][j] = 'R';
				ans[i][j + 1] = 'L';
				dfs(i, j);
				dfs(i, j + 1);
			} else if (!ans[i][j]) {
				cout << "INVALID" << endl;
				exit(0);
			}
		}
	}

	cout << "VALID" << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	
}
