#include<bits/stdc++.h>
using namespace std;

int dp[102][102][28];
bitset<28> v[102][102];

vector<pair<int,int>> G[102];

int dfs(int x,int y,int la){
    if(v[x][y][la])return dp[x][y][la];
    v[x][y][la]=1;
    set<int> go;
    for(auto &p:G[x]){
        if(p.second<la)continue;
        go.insert(dfs(y,p.first,p.second));
    }
    int val;
    for(int i=0;;++i)if(go.find(i)==go.end()){ val=i; break; }
    // cout<<x<<" "<<y<<" "<<la<<" : "<<val<<endl;
    return dp[x][y][la]=val;
}

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int a,b; char c; cin>>a>>b>>c;
        G[a].emplace_back(b,c-'a');
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        int r=dfs(i,j,0);
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        int r=dfs(i,j,0);
        if(r)cout<<"A";
        else cout<<"B";
        if(j==n)cout<<endl;
    }
}
