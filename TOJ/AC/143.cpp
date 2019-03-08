#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
int c[100005];

bool dfs(int now,int nc){
    c[now]=nc;
    for(int i:G[now]){
        if(c[i]){
            if(c[i]==nc)return 1;
        }
        else if(dfs(i,3-nc))return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; while(cin>>n>>m){
        for(int i=0;i<n;++i)G[i].clear(),c[i]=0;
        while(m--){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool no=0;
        for(int i=0;i<n;++i)if(!c[i])no|=dfs(i,1);
        cout<<(no?"NO":"YES")<<'\n';
    }
}
