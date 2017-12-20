#include<bits/stdc++.h>
using namespace std;


int **a;
long long **pre,**dp;

long long get(int x1,int x2,int y1,int y2){
    if(x2<x1 || y2<y1)return 0;
    return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
}

int main(){
    int n,m; cin>>n>>m;
    a=new int*[n+2]; pre=new long long*[n+2]; dp=new long long*[n+2];
    for(int i=0;i<n+2;++i){
        a[i]=new int[m+2]; pre[i]=new long long[m+2]; dp[i]=new long long[m+2];
        for(int j=0;j<m+2;++j){
            pre[i][j]=dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
    if(n==1){
        long long now=0,mx=0;
        for(int i=1;i<=m;++i){
            now+=a[1][i];
            now=max(now,0ll);
            mx=max(mx,now);
        }
        cout<<mx<<endl;
        exit(0);
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)pre[i][j]=a[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
        for(int ii=0;ii<=i;++ii)for(int jj=0;jj<=j;++jj){
            dp[i][j]=max(dp[i][j],dp[ii][jj]+max(0ll,get(ii+1,i,jj+1,j)));
        }
        // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
    cout<<dp[n][m]<<endl;
}
