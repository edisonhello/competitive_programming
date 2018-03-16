#include<bits/stdc++.h>
using namespace std;

int dp[3][1004][203];
bitset<203> blk[1004];
// 0: walk from straight
// 1: walk from left
// 2: walk from right

int main(){
    int n,m;
    while(cin>>n>>m){
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<1004;++i)blk[i].reset();
        int b,e,k; cin>>b>>e>>k; while(k--){
            int x,y; cin>>x>>y;
            blk[x][y]=1;
        }
        dp[0][0][b]=0;
        dp[1][0][b]=dp[2][0][b]=1;
        for(int j=b+1;j<m;++j)if(!blk[0][j])dp[1][0][j]=min(dp[1][0][j],dp[1][0][j-1]); else break;
        for(int j=b-1;j>=0;--j)if(!blk[0][j])dp[2][0][j]=min(dp[2][0][j],dp[2][0][j+1]); else break;
        for(int j=0;j<m;++j)if(!blk[0][j])dp[0][0][j]=min(dp[0][0][j],min(dp[1][0][j],dp[2][0][j])+1);

        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(blk[i][j])continue;
                dp[0][i][j]=min(dp[0][i-1][j],min(dp[1][i-1][j],dp[2][i-1][j])+1);
                dp[1][i][j]=dp[0][i][j]+1;
                dp[2][i][j]=dp[0][i][j]+1;
            }
            for(int j=1;j<m;++j){
                if(blk[i][j])continue;
                dp[1][i][j]=min(dp[1][i][j],dp[1][i][j-1]);
            }
            for(int j=m-2;j>=0;--j){
                if(blk[i][j])continue;
                dp[2][i][j]=min(dp[2][i][j],dp[2][i][j+1]);
            }
            for(int j=0;j<m;++j){
                if(blk[i][j])continue;
                dp[0][i][j]=min(dp[0][i][j],min(dp[1][i][j],dp[2][i][j])+1);
            }
            /* for(int j=0;j<m;++j){
                cout<<i<<" "<<j<<" "<<dp[0][i][j]<<" "<<dp[1][i][j]<<" "<<dp[2][i][j]<<endl;
            } */
        }
        cout<<min(dp[0][n-1][e],min(dp[1][n-1][e],dp[2][n-1][e]))<<endl;
    }
}
