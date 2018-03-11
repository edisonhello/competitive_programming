#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll dp[100005][2][10];


int main(){
    string s; while(cin>>s){
        // memset(dp[0],0,sizeof(int)*20);
        memset(dp[0],0,sizeof(dp));
        for(char &c:s){
            c-='0'; 
        }
        for(int i=0;i<s[0];++i){
            dp[0][0][i]=1;
        }
        dp[0][1][s[0]]=1;
        for(int i=1;i<s.size();++i){
            // memset(dp[i],0,sizeof(int)*20);
            ll pre=0;
            for(int j=0;j<=9;++j){
                pre=(pre+dp[i-1][0][j])%mod;
                dp[i][0][j]=(dp[i][0][j]+pre)%mod;
            }
            for(int j=s[i-1];j<s[i];++j){
                dp[i][0][j]=(dp[i][0][j]+dp[i-1][1][s[i-1]])%mod;
            }
            if(s[i]>=s[i-1])dp[i][1][s[i]]=(dp[i][1][s[i]]+dp[i-1][1][s[i-1]])%mod;
        }
        ll ans=0;
        for(int i=0;i<2;++i)for(int j=0;j<10;++j)ans+=dp[s.size()-1][i][j];
        // cout<<dp[s.size()-1][1][1]<<endl;
        cout<<(ans-1+mod)%mod<<endl;
    }
}
