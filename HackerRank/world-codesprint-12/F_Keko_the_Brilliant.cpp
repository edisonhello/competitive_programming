#include <bits/stdc++.h>

using namespace std;

int n,h[200005];
vector<int> G[200005];
set<int> st[200005];

void solll(){
    dfs(1,1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int h_i = 1; h_i <= n; h_i++){
       cin >> h[h_i];
    }
    for(int a0 = 0,x,y; a0 < n-1; a0++){
        cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
        // Write Your Code Here
    }
    solll();
    return 0;
}

