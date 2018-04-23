#include<bits/stdc++.h>
using namespace std;

int a[555][555],dp[555][555];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)cin>>a[i][j];
    dp[1][1]=a[1][1];
    int mx=0;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j){
            dp[i][j]=a[i][j];
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
            if(i==n)mx=max(mx,dp[i][j]);
        }
    }
    cout<<mx<<endl;
}
