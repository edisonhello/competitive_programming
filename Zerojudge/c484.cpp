#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;

int n,noG[222<<8],match[222<<8];
vector<int> G[222<<8];
bitset<(222<<8)> v;

bool dfs(int x){
    for(int i:G[x]){
        if(v[i])continue;
        v[i]=1;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=x;
            return 1;
        }
    }
    return 0;
}

int main(){
    int m; while(scanf("%d%d",&n,&m)==2){
        memset(noG,0,sizeof(noG));
        memset(match,-1,sizeof(match));
        for(int i=0;i<(222<<8);++i)G[i].clear();
        while(m--){
            int u,v,d; scanf("%d%d%d",&u,&v,&d);
            if(d==4)d=2,--v;
            if(d==1)d=3,--u;
            // ban[u<<8|v]|=(1<<d);
            if(d==2)noG[u<<8|v]|=1;
            if(d==3)noG[u<<8|v]|=1<<1;
        }
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
            if(!(noG[i<<8|j]&1) && j<n){
                G[i<<8|j].push_back(i<<8|(j+1));
                G[i<<8|(j+1)].push_back(i<<8|j);
            }
            if(!(noG[i<<8|j]&2) && i<n){
                G[i<<8|j].push_back((i+1)<<8|j);
                G[(i+1)<<8|j].push_back(i<<8|j);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if((i+j)&1)continue;
                if(match[i<<8|j]==-1){
                    v.reset();
                    if(dfs(i<<8|j))++cnt;
                }
            }
        }
        if(cnt*2==n*n)puts("I win !");
        else puts("Kevin you cheat !");
    }
}
