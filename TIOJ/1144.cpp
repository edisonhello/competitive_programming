#include<bits/stdc++.h>
using namespace std;

inline void upd(int &x,int y){x=min(x,y);}
int d[202][202],dp[1002][3][202][202],req[1002];
int main(){
    int m; cin>>m;
    for(int i=1;i<=m;++i)for(int j=1;j<=m;++j)cin>>d[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][2][3]=dp[0][1][1][3]=dp[0][2][1][2]=0;
    int x,i=1; while(cin>>req[i]){
        for(int ip=1;ip<=m;++ip){
            for(int jp=1;jp<=m;++jp){
                dp[i][0][ip][jp]=dp[i-1][0][ip][jp]+d[i==1?1:req[i-1]][req[i]];
                dp[i][1][ip][jp]=dp[i-1][1][ip][jp]+d[i==1?2:req[i-1]][req[i]];
                dp[i][2][ip][jp]=dp[i-1][2][ip][jp]+d[i==1?3:req[i-1]][req[i]];
                cout<<i<<" "<<ip<<" "<<jp<<" "<<dp[i][0][ip][jp]<<" "<<dp[i][1][ip][jp]<<" "<<dp[i][2][ip][jp]<<endl;
                for(int z=1;z<=m;++z){
                    upd(dp[i][0][ip][jp],dp[i-1][1][req[i]][jp]+d[ip][req[i]]);
                    upd(dp[i][0][ip][jp],dp[i-1][2][ip][req[i]]+d[jp][req[i]]);
                    upd(dp[i][1][ip][jp],dp[i-1][0][req[i]][jp]+d[ip][req[i]]);
                    upd(dp[i][1][ip][jp],dp[i-1][2][ip][req[i]]+d[jp][req[i]]);
                    upd(dp[i][2][ip][jp],dp[i-1][0][req[i]][jp]+d[ip][req[i]]);
                    upd(dp[i][2][ip][jp],dp[i-1][1][ip][req[i]]+d[jp][req[i]]);
                }
                cout<<i<<" "<<ip<<" "<<jp<<" "<<dp[i][0][ip][jp]<<" "<<dp[i][1][ip][jp]<<" "<<dp[i][2][ip][jp]<<endl;
            }
        }
        ++i;
    }
    int ans=0x3f3f3f3f;
    for(int iz=0;iz<3;++iz)for(int j=1;j<=m;++j)for(int k=1;k<=m;++k)upd(ans,dp[i-1][iz][j][k]);
    cout<<ans<<endl;
}
