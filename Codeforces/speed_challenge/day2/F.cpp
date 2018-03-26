#include<bits/stdc++.h>
using namespace std;

vector<int> G[100004];
int c[100005];
int m;

int dfs(int now,int pa,int cnt){
    if(c[now])cnt+=c[now];
    else cnt=0;
    if(cnt>m)return 0;
    if(now!=pa && G[now].size()==1){
        return 1;
    }
    int a=0;
    for(int i:G[now]){
        if(i!=pa)a+=dfs(i,now,cnt);
    }
    return a;
}

int main(){
    int n; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout<<dfs(1,1,0);
    
}
