#include<bits/stdc++.h>
using namespace std;

bool rail[404][404];
int dp[404][404],d[404];


int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        rail[u][v]=rail[v][u]=1;
    }
    auto go=[&](){
        queue<int> q; memset(d,0x3f,404*4);
        q.push(1); d[1]=0;
        while(q.size()){
            int now=q.front(); q.pop();
            for(int i=1;i<=n;++i){
                if(rail[i][now] && d[i]==0x3f3f3f3f){
                    d[i]=d[now]+1;
                    q.push(i);
                }
            }
        }
        return d[n];
    };
    int z1=go();
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)rail[i][j]^=1;
    for(int i=1;i<=n;++i)rail[i][i]=0;
    int z2=go();
    if(max(z1,z2)==0x3f3f3f3f)z1=z2=-1;
    cout<<max(z1,z2)<<endl;
}
