#include<bits/stdc++.h>
using namespace std;

string mp[555];
int stay[555][555],dp[555][555];
int pre[555],ori[555];

int main(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>mp[i];
    int orisum=0;
    for(int i=1;i<=n;++i){
        int L=-1,R=-1;
        for(int j=0;j<m;++j){
            pre[j+1]=pre[j]+(mp[i][j]=='1');
            if(mp[i][j]=='1'){
                R=j;
                if(L==-1)L=j;
            }
        }
        if(R>=0){
            ori[i]=R-L+1;
            orisum+=ori[i];
            // cout<<"ori is "<<ori[i]<<endl;
            for(int j=0;j<m;++j){
                for(int jj=j;jj<m;++jj){
                    int bye=pre[j]+pre[m]-pre[jj+1];
                    // cout<<"["<<j<<","<<jj<<"] bye "<<bye<<endl;
                    stay[i][bye]=max(stay[i][bye],ori[i]-(jj-j+1));
                }
            }
            stay[i][pre[m]]=max(stay[i][pre[m]],ori[i]);
            // for(int j=0;j<=k;++j)cout<<"i: "<<i<<" , bye "<<j<<" profit "<<stay[i][j]<<endl;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=k;++i)dp[0][i]=orisum;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            dp[i][j]=dp[i-1][j];
            for(int jj=1;jj<=j;++jj){
                dp[i][j]=min(dp[i][j],dp[i-1][j-jj]-stay[i][jj]);
            }
        }
    }
    // cout<<dp[2][8]<<endl;
    int ans=998877;
    for(int i=0;i<=k;++i)ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
}
