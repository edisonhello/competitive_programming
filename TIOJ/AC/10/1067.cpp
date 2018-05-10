#include<bits/stdc++.h>
using namespace std;

int a[1004],dp[1004][10005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; while(cin>>n>>m,n){
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=0;i<m;++i)dp[0][i]=-1231232;
        dp[0][0]=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)dp[i+1][j]=-1231232;
            for(int j=0;j<m;++j){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                dp[i+1][(j*10+a[i+1])%m]=max(dp[i+1][(j*10+a[i+1])%m],dp[i][j]+1);
            }
        }
        int mx=0;
        for(int i=0;i<m;++i){
            if(__gcd(i,m)!=1)continue;
            mx=max(mx,dp[n][i]);
            // if(dp[n][i]==5) cout<<i<<endl;
        }
        cout<<mx<<endl;
    }
}
