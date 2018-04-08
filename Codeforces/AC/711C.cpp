#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[111][111][111],cl[111],cost[111][111];

int main(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>cl[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>cost[i][j];
        }
        cost[i][0]=1ll<<60;
    }

    memset(dp,0x3f,sizeof(dp));
    // for(int i=0;i<111;++i)dp[0][0][i]=0;
    dp[0][0][0]=0;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            if(cl[i]){
                for(int pc=0;pc<=m;++pc){
                    dp[i][j][cl[i]]=min(dp[i][j][cl[i]],dp[i-1][j-(pc!=cl[i])][pc]);
                }
            }
            else{
                for(int tc=1;tc<=m;++tc){
                    for(int pc=0;pc<=m;++pc){
                        dp[i][j][tc]=min(dp[i][j][tc],dp[i-1][j-(pc!=tc)][pc]+cost[i][tc]);
                    }
                }
            }
        }
    }

    ll mn=1ll<<60;
    for(int i=1;i<=m;++i)mn=min(mn,dp[n][k][i]);
    cout<<(mn==(1ll<<60)?-1:mn)<<endl;
}
