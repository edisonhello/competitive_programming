#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cstring>
#include<algorithm>

using namespace std;

short mp[5005][5005],dp[5005][5005],tg[5005];

int main(){
    int n,m;while(cin>>n>>m,n){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>mp[i][j];
                if(mp[i][j]==1)mp[i][j]=0;
                if(mp[i][j]==0)dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(dp[i][j]==0)continue;
                else dp[i][j]+=dp[i-1][j];
            }
        }
        int sz=0;
        for(int i=0;i<n;++i){
            memset(tg,0,sizeof(tg)); int nwh=0;
            for(int j=0;j<=m;++j){
                if(nwh<dp[i][j]){
                    for(++nwh;nwh<=dp[i][j];++nwh)tg[nwh]=j;
                    --nwh;
                }
                while(nwh>dp[i][j]){
                    sz=max({sz,min(j-tg[nwh],nwh)*min(j-tg[nwh],nwh)});
                    --nwh;
                }
                // cout<<i<<" "<<j<<" "<<sz<<" "<<nwh<<endl;
            }
        }
        cout<<sz<<endl;
    }
}
