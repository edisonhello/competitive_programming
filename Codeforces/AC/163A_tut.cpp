#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;

ll _[5005],dp[5005][5005];
int main(){
    string s,t; cin>>s>>t;
    ll ans=0;
    for(int i=s.size()-1;i>=0;--i){
        for(int j=t.size()-1;j>=0;--j){
            dp[i][j]=dp[i][j+1];
            if(s[i]==t[j])dp[i][j]+=dp[i+1][j+1]+1;
            if(dp[i][j]>=mod)dp[i][j]-=mod;
        }
        ans+=dp[i][0];
    }
    cout<<ans%mod<<endl;
}
