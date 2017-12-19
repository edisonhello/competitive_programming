#include<bits/stdc++.h>
using namespace std;

inline void upd(int &x,int y){x=min(x,y);}
int d[202][202],_dp[2][202][202],req[1002];
inline int &dp(int x,int y,int z){return _dp[x&1][max(y,z)][min(y,z)];}
int main(){
    int m; cin>>m;
    for(int i=1;i<=m;++i)for(int j=1;j<=m;++j)cin>>d[i][j];
    memset(_dp,0x3f,sizeof(_dp));
    req[0]=3; dp(0,1,2)=0;
    int x,n=1; while(cin>>req[n])++n; --n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            for(int k=1;k<=m;++k){
                upd(dp(i,j,k),dp(i-1,j,k)+d[req[i-1]][req[i]]);
                upd(dp(i,req[i-1],k),dp(i-1,j,k)+d[j][req[i]]);
                upd(dp(i,req[i-1],j),dp(i-1,j,k)+d[k][req[i]]);
                // cout<<i<<" "<<j<<" "<<k<<" "<<dp(i,j,k)<<endl;
            }
        }
        memset(_dp[!(i&1)],0x3f,sizeof(_dp[!(i&1)]));
    }
    
    int ans=0x3f3f3f3f;
    for(int j=1;j<=m;++j)for(int k=1;k<=m;++k)upd(ans,dp(n,j,k));
    cout<<ans<<endl;
}
