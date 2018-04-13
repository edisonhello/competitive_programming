#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;
ll dp[1000006][2],h[1000006];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>h[i],--h[i]; 
    // dp[0][1]=1;
    ll ans=0;
    for(int i=1;i<=n;++i){
        if(h[i]>h[i+1]){
            dp[i][0]=(dp[i-1][1]+1)*(h[i]-h[i+1])%mod;
        }
        dp[i][1]=(dp[i-1][1]+1)*h[i]%mod;
        ans+=dp[i][0]+dp[i][1];
    }
    cout<<ans%mod<<endl;
}
