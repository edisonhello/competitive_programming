#include<bits/stdc++.h>
using namespace std;

int t[62][62][62],dp[1004][62][62];
int main(){
    int n,m,r; scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)cin>>t[i][j][k];
        for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)for(int l=1;l<=n;++l)t[i][k][l]=min(t[i][k][l],t[i][k][j]+t[i][j][l]);
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)dp[0][j][k]=min(dp[0][j][k],t[i][j][k]);
    for(int i=1;i<=1000;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)for(int l=1;l<=n;++l)dp[i][k][l]=min(dp[i][k][l],dp[i-1][k][j]+dp[0][j][l]);
    while(r--){
        int s,t,k; scanf("%d%d%d",&s,&t,&k);
        printf("%d\n",dp[k][s][t]);
    }
}
