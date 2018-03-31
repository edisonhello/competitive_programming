#include<bits/stdc++.h>
using namespace std;
#define ll long long

int w[5005][5005],n;
ll dp[2][5005][5005];

int main(){
//    freopen("in.txt","r",stdin);
    int m1,m2; cin>>n>>m1>>m2;
    while(m1--){
        int u,v,k; cin>>u>>v>>k;
        ++u, ++v;
        w[u+1][n+1]+=k;
        w[u+1][v]-=k;
        w[1][n+1]-=k;
        w[1][v]+=k;
    }
    while(m2--){
        int u,v,k; cin>>u>>v>>k;
        ++u, ++v;
        w[n+1][v+1]+=k;
        w[u][v+1]-=k;
        w[n+1][1]-=k;
        w[u][1]+=k;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
        }
    }

#define upd(a,b) a=min(a,b)
    memset(dp,0x3f,sizeof(dp));
    dp[1][1][1]=0;
    for(int i=2;i<=n;++i){
        for(int j=i-1;j>=1;--j){
            upd(dp[i&1][i][j],dp[(i-1)&1][i-1][j]+w[i-1][i]); // this up, prv up
            upd(dp[i&1][i][i-1],dp[(i-1)&1][j][i-1]+w[j][i]);   // this up, prv dwn
            upd(dp[i&1][j][i],dp[(i-1)&1][j][i-1]+w[i][i-1]); // this dwn, prv dwn
            upd(dp[i&1][i-1][i],dp[(i-1)&1][i-1][j]+w[i][j]);   // this dwn, prv up
        }
    }

//    for(int i=1;i<n;++i){
//        for(int j=1;j<=i;++j){
//            for(int k=1;k<=i;++k){
//                cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
//            }
//        }
//    }

    ll ans=1ll<<60;
    for(int i=1;i<n;++i){
        upd(ans,dp[(n-1)&1][i][n-1]+w[i][n]+w[n][n-1]);
        upd(ans,dp[(n-1)&1][n-1][i]+w[n-1][n]+w[n][i]);
    }
    cout<<ans<<endl;

//    for(int i=1;i<=n;++i){
////        w[i][i]=0;
//        for(int j=1;j<=n;++j){
//            cout<<setw(3)<<w[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}

