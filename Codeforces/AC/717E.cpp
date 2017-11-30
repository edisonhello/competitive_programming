#include<bits/stdc++.h>
using namespace std;

int c[200006],need[200006];
vector<int> G[200006];

void dfs1(int now,int pa){
    if(c[now]==-1)need[now]=1;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now);
        if(need[i])need[now]=1;
    }
}
void dfs(int now,int pa){
    c[now]=-c[now];
    cout<<now<<" ";
    if(!need[now])return;
    for(int i:G[now]){
        if(i==pa)continue;
        if(!need[i])continue;
        dfs(i,now);
        cout<<now<<" ";
        c[now]=-c[now];
        if(c[i]==-1)cout<<i<<" "<<now<<" ",c[i]=-c[i],c[now]=-c[now];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,1);
    c[1]=-c[1];
    dfs(1,1);
    if(c[1]==-1)cout<<G[1][0]<<" "<<1<<" "<<G[1][0];
}
