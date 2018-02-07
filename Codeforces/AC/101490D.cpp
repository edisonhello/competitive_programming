#include<bits/stdc++.h>
using namespace std;

int dp[4004],t[4004];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>t[i];
    memset(dp,0x3f,sizeof(dp)); dp[0]=0;
    for(int i=1;i<=n;++i){
        int st=t[i]+1800,clz=st;
        for(int j=i;j<=n;++j){
            if(t[j]<=clz)clz+=20;
            else clz=t[j]+20;
            dp[j]=min(dp[j],dp[i-1]+clz-st+120);
        }
    }
    cout<<dp[n]<<endl;
}
