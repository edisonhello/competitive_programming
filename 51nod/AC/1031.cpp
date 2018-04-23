#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

long long dp[1111];

int main(){
    int n; cin>>n;
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;++i)dp[i]=(dp[i-1]+dp[i-2])%mod;
    cout<<dp[n]<<endl;
}
