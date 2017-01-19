#include<cstdio>
#include"lib1481.h"
#include<vector>
#include<utility>
using namespace std;

vector<pair<int,int>> G[2005];
bool v[2005];
int ans[20005],cnt;

void dfs(int now){
    if(v[now])return;
    v[now]=1;
    for(auto &i:G[now]){
        if(ans[i.second])continue;
        ans[i.second]=++cnt;
        dfs(i.first);
    }
}

int main(){
    Init();
    int n,k,i,st,ed;scanf("%d%d",&n,&k);
    for(i=1;i<=k;++i){
        scanf("%d%d",&st,&ed);
        G[st].push_back({ed,i});
        G[ed].push_back({st,i});
    }
    dfs(1);
    Possible();
    for(i=1;i<=k;++i)Number(ans[i]);
    Finish();
}
