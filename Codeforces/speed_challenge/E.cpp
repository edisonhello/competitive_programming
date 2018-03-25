#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[123][123];

int main(){
    int n; cin>>n;
    ll mx=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==1 || j==1)dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            mx=max(mx,dp[i][j]);
        }
    }
    cout<<mx<<endl;
}
