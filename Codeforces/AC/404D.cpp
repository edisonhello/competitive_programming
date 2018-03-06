#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll dp[1000006][6];

int main(){
    string s; cin>>s;
    /* dp[0][0]=1;
    dp[0][1]=1; */
    if(s[0]=='0')dp[1][0]=1;
    else if(s[0]=='1')dp[1][1]=1;
    else if(s[0]=='*')dp[1][3]=1;
    else if(s[0]=='?')dp[1][0]=dp[1][1]=dp[1][3]=1;
    for(int i=1;i<s.size();++i){
        ll *ndp=dp[i+1],*pdp=dp[i];
        if(s[i]=='*'){
            ndp[3]=(pdp[1]+pdp[3])%mod;
        }
        else if(s[i]=='1'){
            ndp[1]=pdp[0]%mod;
            ndp[0]=pdp[3]%mod;
        }
        else if(s[i]=='2'){
            ndp[1]=pdp[3];
        }
        else if(s[i]=='0'){
            ndp[0]=pdp[0];
        }
        else if(s[i]=='?'){
            ndp[0]=(pdp[0]+pdp[3])%mod;
            ndp[1]=(pdp[0]+pdp[3])%mod;
            ndp[3]=(pdp[1]+pdp[3])%mod;
        }
        // cout<<i<<" "<<ndp[0]<<" "<<ndp[1]<<" "<<ndp[2]<<" "<<ndp[3]<<endl;
    }
    int n=s.size();
    cout<<(dp[n][0]+dp[n][3])%mod<<endl;
}
