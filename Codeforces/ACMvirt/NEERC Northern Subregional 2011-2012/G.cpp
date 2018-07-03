#include<bits/stdc++.h>
using namespace std;

int k,clr[5005];
vector<int> G[5005];
int iic[14];

void dfs(int now,int pa,int want){
    // cout<<"dfs "<<now<<" "<<pa<<" "<<want<<endl;
    for(int i:G[now]){
        if(clr[i]==want)return;
    }
    clr[now]=want;
    for(int i:G[now]){
        if(i!=pa && !clr[i])dfs(i,now,want%k+1);
    }
}

int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    int n,m; cin>>n>>k>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end());
    for(int i=1;i<=k;++i)iic[i]=i;
    do{
        bool ok=1;
        for(int i=1;i<k;++i)if(*lower_bound(G[iic[i]].begin(),G[iic[i]].end(),iic[i+1])!=iic[i+1])ok=0;
        if(*lower_bound(G[iic[k]].begin(),G[iic[k]].end(),iic[1])!=iic[1])ok=0;
        if(ok)break;
    }while(next_permutation(iic+1,iic+1+k));
    for(int i=1;i<=k;++i)clr[iic[i]]=i;
    for(int i=1;i<=k;++i)for(int j:G[i])if(!clr[j])dfs(j,i,i%k+1);
    for(int i=1;i<=n;++i)cout<<clr[i]<<" "; cout<<endl;
}
