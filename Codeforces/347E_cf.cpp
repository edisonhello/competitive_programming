#include<bits/stdc++.h>
using namespace std;

int n,z[100005],a,b;
int dp[1000006];

int go(int x){
    if(x==b)return 0;
    if(x<b)return 1<<30;
    if(dp[x-b])return dp[x-b];
    dp[x-b]=go(x-1)+1;
    for(int i=0;i<n;++i){
        if(x%z[i])dp[x-b]=min(dp[x-b],go(x/z[i]*z[i])+1);
    }
    cout<<"go "<<x<<" : "<<dp[x-b]<<endl;
    return dp[x-b];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>z[i];
    cin>>a>>b;
    cout<<go(a)<<endl;
}
