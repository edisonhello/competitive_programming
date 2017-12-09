#include<bits/stdc++.h>
using namespace std;
int dp[222][222];
int nxt[222],app[222];

int go(int l,int r){
    if(l>r)return 0;
    if(l==r)return 1;
    if(dp[l][r])return dp[l][r];
    dp[l][r]=1+go(l+1,r);
    for(int i=nxt[l];i<=r && i;i=nxt[i]){
        dp[l][r]=min(dp[l][r],go(l+1,i-1)+go(i,r));
    }
    return dp[l][r];
}

int main(){
    int ts; cin>>ts; while(ts--){
        int n,m; cin>>n>>m;
        memset(dp,0,sizeof(dp));
        memset(app,0,sizeof(app));
        memset(nxt,0,sizeof(nxt));
        for(int i=1,cc;i<=n;++i){
            cin>>cc;
            if(app[cc])nxt[app[cc]]=i;
            app[cc]=i;
        }
        // for(int i=1;i<=n;++i)cout<<nxt[i]<<" "; cout<<endl;
        cout<<go(1,n)<<endl;
        /* for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        } */
    }
}
