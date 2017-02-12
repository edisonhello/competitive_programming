#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cstring>
#include<algorithm>

using namespace std;

int mp[5][5005],dp[5][5005],tg[5005];

int main(){
    int n,m;while(cin>>n>>m,n){
        int sz=0;
        for(int i=0;i<n;++i){
            memset(tg,0,sizeof(tg)); int nwh=0;
            for(int j=0;j<m;++j){
                cin>>mp[i&1][j];
                if(mp[i&1][j]==1)mp[i&1][j]=0;
                if(mp[i&1][j]==0){
                    dp[i&1][j]=1;
                    if(i)dp[i&1][j]+=dp[!(i&1)][j];
                }
                else dp[i&1][j]=0;
            }
            for(int j=0;j<=m;++j){
                if(nwh<dp[i&1][j]){
                    for(++nwh;nwh<=dp[i&1][j];++nwh)tg[nwh]=j;
                    --nwh;
                }
                while(nwh>dp[i&1][j]){
                    sz=max({sz,min(j-tg[nwh],nwh)*min(j-tg[nwh],nwh)});
                    --nwh;
                }
            }
        }
        cout<<sz<<endl;
    }
}
