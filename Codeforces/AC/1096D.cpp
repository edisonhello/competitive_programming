#include<bits/stdc++.h>
using namespace std;

int a[100005];
long long dp[100005][6];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    for(int i=1;i<=n;++i)cin>>a[i-1];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<=4;++j){
            if(j==0){
                if(s[i]=='h'){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }
                else{
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                }
            }
            else if(j==1){
                if(s[i]=='a'){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }
                else{
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                }
            }
            else if(j==2){
                if(s[i]=='r'){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }
                else{
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                }
            }
            else if(j==3){
                if(s[i]=='d'){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }
                else{
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                }
            }
        }
    }
    cout<<min(min(min(dp[n][0],dp[n][1]),dp[n][2]),dp[n][3])<<endl;
}
