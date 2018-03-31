#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

int d[1001][1001],cnt[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(d,0x3f,sizeof(d));
    int n,m,u,v; cin>>n>>m;
    while(m--){
        cin>>u>>v;
        d[u][v]=d[v][u]=1;
    }
    for(int i=1;i<=n;++i)d[i][i]=0;
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            if(i==k)continue;
            for(int j=i+1;j<=n;++j){
                if(j==k)continue;
                if(d[i][j]==d[i][k]+d[k][j]){
                    // cout<<k<<" "<<i<<" "<<j<<" "<<d[i][j]<<" "<<d[i][k]<<" "<<d[k][j]<<endl;
                    ++cnt[k];
                }
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<(cnt[i]<<1)<<'\n';
}
