#include<bits/stdc++.h>
using namespace std;

int d[123][123];

int main(){
    int ts; cin>>ts; while(ts--){
        int n,m; cin>>n>>m;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                d[i][j]=0x3f3f3f3f;
            }
            d[i][i]=0;
        }
        while(m--){
            int u,v,c; cin>>u>>v>>c;
            d[u][v]=d[v][u]=c;
        }
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        int mx=0;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)mx=max(mx,d[i][j]);
        cout<<mx<<endl;
    }
}
