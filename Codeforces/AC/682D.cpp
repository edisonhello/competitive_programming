#include<bits/stdc++.h>
using namespace std;
#define up(x,y) x=max(x,y)

int dp[1004][1004][11][2];

int main(){
    int n,m,K; cin>>n>>m>>K;
    string s,t; cin>>s>>t;
    int mx=0;
    for(int i=0;i<s.size();++i){
        for(int j=0;j<t.size();++j){
            if(s[i]==t[j]){
                for(int k=1;k<=K;++k){
                    up(dp[i][j][k][1],i&&j?max(dp[i-1][j-1][k][1],dp[i-1][j-1][k-1][0])+1:1);
                    up(dp[i][j][k][0],max(i?max(dp[i-1][j][k][0],dp[i-1][j][k][1]):0,j?max(dp[i][j-1][k][0],dp[i][j-1][k][1]):0));
                }
            }
            else{
                for(int k=1;k<=K;++k){
                    up(dp[i][j][k][0],max(i?max(dp[i-1][j][k][0],dp[i-1][j][k][1]):0,j?max(dp[i][j-1][k][0],dp[i][j-1][k][1]):0));
                }
            }
            for(int k=1;k<=K;++k){
                up(mx,dp[i][j][k][0]);
                up(mx,dp[i][j][k][1]);
                // cout<<i<<" "<<j<<" "<<k<<" ( "<<s[i]<<" , "<<t[j]<<" )"<<" : "<<dp[i][j][k][0]<<" "<<dp[i][j][k][1]<<endl;
            }
        }
    }
    cout<<mx<<endl;
}
