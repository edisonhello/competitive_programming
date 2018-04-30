#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

long long dp[555][555],p2[555555];

int main(){
    int n,k; cin>>n>>k;
    p2[0]=1; for(int i=1;i<555555;++i)p2[i]=p2[i-1]*2%mod;
    for(int i=0;i<=n;++i)dp[i][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            for(int k=j-1;k<=i;++k){
                (dp[i][j]+=dp[k][j-1]*(p2[i-k]-1)%mod*p2[k*(i-k)]%mod)%=mod;
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
