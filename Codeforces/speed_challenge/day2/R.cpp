#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const ll mod=1000000007;
ll dp[123][123];

int main(){
    int n,k,d; cin>>n>>k>>d;
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int _k=1;_k<=k;++_k){
            for(int j=_k;j<=n;++j){
                dp[i][j]=(dp[i][j]+dp[i-1][j-_k])%mod;
            }
        }
    }
    
    ll tot=0;
    for(int i=1;i<=n;++i)tot+=dp[i][n];

    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    for(int i=1;i<=n;++i){
        for(int _k=1;_k<d;++_k){
            for(int j=_k;j<=n;++j){
                dp[i][j]=(dp[i][j]+dp[i-1][j-_k])%mod;
            }
        }
    }

    for(int i=1;i<=n;++i)tot-=dp[i][n];
    tot%=mod;
    cout<<(tot+mod)%mod;
}
