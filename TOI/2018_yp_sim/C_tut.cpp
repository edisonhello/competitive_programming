#include<bits/stdc++.h>
using namespace std;

int a[5][2002],dp[2002],pos[5][2002];

int main(){
    int n,k; cin>>n>>k;
    for(int i=0;i<k;++i)for(int j=1;j<=n;++j){
        cin>>a[i][j];
        pos[i][a[i][j]]=j;
    }
    int mx=0;
    for(int i=1;i<=n;++i){
        dp[a[0][i]]=1;
        for(int j=1;j<=n;++j){
            bool ok=1;
            for(int z=0;z<k;++z)if(pos[z][a[0][i]]<=pos[z][j])ok=0;
            if(ok)dp[a[0][i]]=max(dp[a[0][i]],dp[j]+1);
        }
        mx=max(mx,dp[a[0][i]]);
    }
    cout<<mx<<endl;
}
// AC
