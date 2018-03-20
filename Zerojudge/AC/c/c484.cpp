#pragma GCC optimize("no-stack-protector,Ofast")
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
    srand(time(0));
    int m; while(scanf("%d%d",&n,&m)==2){
        memset(noG,0,sizeof(noG));
        memset(match,-1,sizeof(match));
        for(int i=n+1;i<=n*(n+1);++i)G[i].clear();
        while(m--){
            int u,v,d; scanf("%d%d%d",&u,&v,&d);
            if(d==4)d=2,--v;
            if(d==1)d=3,--u;
            // ban[u*n+v]|=(1<<d);
            if(d==2)noG[u*n+v]|=1;
            if(d==3)noG[u*n+v]|=1<<1;
        }
if(n&1){puts("Kevin you cheat !"); continue;}
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
            if(!(noG[i*n+j]&1) && j<n){
                G[i*n+j].push_back(i*n+(j+1));
                G[i*n+(j+1)].push_back(i*n+j);
            }
            if(!(noG[i*n+j]&2) && i<n){
                G[i*n+j].push_back((i+1)*n+j);
                G[(i+1)*n+j].push_back(i*n+j);
            }
        }
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)random_shuffle(G[i*n+j].begin(),G[i*n+j].end());
        int cnt=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if((i+j)&1)continue;
                if(match[i*n+j]==-1){
                    v.reset();
                    if(dfs(i*n+j))++cnt;
                }
            }
        }
        if(cnt*2==n*n)puts("I win !");
        else puts("Kevin you cheat !");
    }
}
