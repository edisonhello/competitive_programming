#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

int dp[10000007][4];
int main(){
    int n; cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<4;++j){
            for(int k=0;k<4;++k){
                if(j==k)continue;
                dp[i][j]+=dp[i-1][k];
                if(dp[i][j]>=mod)dp[i][j]-=mod;
            }
        }
    }
    cout<<dp[n][0]<<endl;
}
