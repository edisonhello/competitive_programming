#include<bits/stdc++.h>
using namespace std;

int color[200005];
vector<int> G[200005];

void dfs(int now,int pa){
    int ptr=1; while(ptr==color[now] || ptr==color[pa])++ptr;
    for(int i:G[now]){
        if(i==pa)continue;
        color[i]=ptr++; while(ptr==color[now] || ptr==color[pa])++ptr;
        dfs(i,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int mxclr=0;
    for(int i=1;i<=n;++i){
        mxclr=max(mxclr,(int)G[i].size()+1);
    }
    color[1]=1; dfs(1,1);
    cout<<mxclr<<endl;
    for(int i=1;i<=n;++i)cout<<color[i]<<" "; cout<<endl;
}
