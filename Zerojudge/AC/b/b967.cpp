#include<bits/stdc++.h>
using namespace std;

int d[100006];
vector<int> G[100006];

void dfs(int now,int pa,int dd){
    d[now]=dd;
    for(int i:G[now]){
        if(i!=pa)dfs(i,now,dd+1);
    }
}

int main(){
    int n; while(cin>>n){
        for(int i=0;i<n;++i)G[i].clear();
        for(int i=1;i<n;++i){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0,0,0);
        int far,ddd=0;
        for(int i=0;i<n;++i)if(d[i]>ddd)ddd=d[i],far=i;
        dfs(far,far,0);
        ddd=0;
        for(int i=0;i<n;++i)if(d[i]>ddd)ddd=d[i],far=i;
        cout<<ddd<<endl;
    }
}
