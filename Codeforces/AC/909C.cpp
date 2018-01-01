#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;
ll dp[5005][5005];
string st[5005];

int main(){
    int n; cin>>n;
    dp[0][1]=1;
    ll ans=0;
    for(int i=1;i<=n;++i){
        cin>>st[i];
        if(st[i-1]=="f"){
            for(int j=2;j<5005;++j)dp[i][j]+=dp[i-1][j-1];
        }
        else{
            ans=0;
            for(int j=5003;j>=1;--j){
                dp[i][j]=(dp[i-1][j]+dp[i][j+1])%mod;
                ans+=dp[i][j];
            }
        }
    }
    cout<<ans%mod<<endl;
}
