#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;
ll exend[2][1000006],dp[1000006];
int main(){
    exend[0][0]=1;
    exend[0][1]=exend[1][1]=1;
    for(int i=2;i<=1000000;++i){
        exend[0][i]=(exend[0][i-1]+exend[1][i-1])%mod;
        exend[1][i]=(exend[0][i-1]+exend[0][i-2])%mod;
    }
    for(int i=3;i<=1000000;++i){
        dp[i]=(dp[i-1]*2+exend[0][i-3])%mod;
    }
    int t; cin>>t; while(t--){
        int n; cin>>n; cout<<dp[n]<<endl;
    }
}
