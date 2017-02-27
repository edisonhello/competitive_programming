#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int n,m,q,sp[456][654],ks=1;
int main(){
    while(cin>>n>>m>>q,n){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                sp[i][j]=(1<<20);
            }
        }
        while(m--){
            int u,v,d;cin>>u>>v>>d;
            sp[u][v]=sp[v][u]=d;
        }
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=n;++j){
        //         cout<<setw(4)<<G[i][j]<<" ";
        //     }cout<<endl;
        // }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    // if(G[i][k]+G[k][j]<G[i][j]){
                        // G[i][j]=G[i][k]+G[k][j];
                        sp[j][k]=min({sp[j][k],max(sp[i][j],sp[i][k])});
                    // }
                }
            }
        }
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=n;++j){
        //         cout<<setw(4)<<sp[i][j]<<" ";
        //     }cout<<endl;
        // }
        if(ks>1)cout<<endl;
        cout<<"Case #"<<ks<<endl;++ks;
        while(q--){
            int u,v;cin>>u>>v;
            if(sp[u][v]>=(1<<20))cout<<"no path"<<endl;
            else cout<<sp[u][v]<<endl;
        }
    }
}
