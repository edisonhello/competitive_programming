#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1000006],inte[1000006],prv[1000006];
ll dp[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    inte[1]=inte[n]=1;
    for(int i=2;i<n;++i){
        inte[i]=(a[i]>a[i-1] && a[i]>a[i+1])||(a[i]<a[i-1] && a[i]<a[i+1]);
    }
    prv[1]=0;
    for(int i=2;i<=n;++i){
        prv[i]=prv[i-1];
        if(inte[i-1])prv[i]=i-1;
    }

    for(int i=2;i<=n;++i){
        int mx=a[i],mn=a[i];
        dp[i]=dp[i-1];
        for(int j=i-1,z=0;j>=1 && z<=5;j=prv[j],++z){
            mx=max(mx,a[j]);
            mn=min(mn,a[j]);
            dp[i]=max(dp[i],dp[j-1]+mx-mn);
        }
    }
    cout<<dp[n]<<endl;
}
